#ifndef TABLA_CIFR_H
#define TABLA_CIFR_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "Cifr.h"
#include "Tabla.h"
#include "gestorArchivos.h"

using namespace std;

//Clase	que gestiona una tabla de datos genérica
template <class Tclave, class Tvalor>
class TablaCifr : public Tabla<Tclave, Tvalor> {
	using table = Tabla<Tclave, Tvalor>;
private:
	string cp_tabla;
	string seccp_tabla;
	ID_TABLA id;

	//Dado un flujo abierto, escribe en el mismo los datos de la tabla
	void saveOpenFlux(ofstream &arch) {
		arch << table::getSize() + 1 << '\n';
		int indice = 0;
		string aux;
		for (auto it = table::begin(); it != table::end(); ++it) {
			aux = elemToString(it->first, it->second);
			cifrado->encript(aux, index, id);
			arch << aux << '\n';
			if (indice < lineasCif.size())
				lineasCif[indice] = aux;
			else
				lineasCif.push_back(aux);
			++indice;
		}
		index -= 1;
		if (index < 0)
			index = NUMVAR - 1;
		arch << index;
		arch.close();
	}

	//Guarda la tabla en el archivo de datos principal
	void saveTable() {
		ofstream arch;
		arch.open(table::arch_tabla);
		if (!arch.is_open())
			throw invalid_argument("Error TABLACIFR-close-01: Archivo de datos de la tabla corrupto.\n");
		arch << table::getSize() + 1 << '\n';
		for (int i = 0; i < table::getSize(); ++i)
			arch << lineasCif[i] << '\n';
		arch << index;
		arch.close();
	}
protected:
	Cifr * cifrado;
	int index;
	vector<string> lineasCif;
public:
	//Constructor
	TablaCifr(Cifr &cifra, const string datos, const string cp_datos, const string seccp_datos,
		const ID_TABLA ident) : table::Tabla(datos), cifrado(&cifra), cp_tabla(cp_datos),
		seccp_tabla(seccp_datos), id(ident) {
		index = stringToUint(table::lineasArch[table::lineasArch.size() - 1]);
		table::lineasArch.pop_back();
	}

	//Guarda en los archivos destinados a ser copia de seguridad los datos de la tabla
	void secSave() {
		ofstream arch1, arch2;
		arch1.open(cp_tabla);
		arch2.open(seccp_tabla);
		cifrado->updateKeys(id);
		bool opened1 = arch1.is_open(), opened2 = arch2.is_open();
		if (opened1 && opened2) {
			saveOpenFlux(arch1);
			arch2 << table::getSize() + 1 << '\n';
			for (int i = 0; i < table::getSize(); ++i)
				arch2 << lineasCif[i] << '\n';
			arch2 << index;
			arch2.close();
		}
		else if (opened1) {
			saveOpenFlux(arch1);
			throw invalid_argument("Error TABLACIFR-secSave-01: Archivo de copia de datos corrupto.\n");
		}
		else if (opened2) {
			saveOpenFlux(arch2);
			throw invalid_argument("Error TABLACIFR-secSave-02: Archivo de copia de seguridad corrupto.\n");
		}
		else
			throw invalid_argument("Error TABLACIFR-secSave-03: Archivos de copia de seguridad corruptos. Peligro de seguridad de los datos.\n");
	}

	//Dado un flujo abierto, exporta la tabla sobre el flujo dado
	void exportTable(ofstream &f) {
		f << table::getSize() + 1 << '\n';
		string aux;
		for (auto it = table::begin(); it != table::end(); ++it) {
			aux = elemToString(it->first, it->second);
			cifrado->encript(aux, index, id);
			f << aux << '\n';
		}
		index -= 1;
		if (index < 0)
			index = NUMVAR - 1;
		f << index << '\n';
	}

	//Lleva a cabo todos los procedimientos para el cierre seguro del gestor de los datos de la tabla
	void close() {
		try {
			secSave();
		}
		catch (invalid_argument &e) {
			try {
				saveTable();
			}
			catch (invalid_argument &ia) {
				string str_e = e.what(), str_ia = ia.what();
				throw invalid_argument(str_e + str_ia);
			}
			throw e;
		}
		saveTable();
	}

	//Convierte el elemento de la tabla en una cadena de caracteres
	virtual string elemToString(const Tclave &clave, const Tvalor &valor) = 0;
};

#endif