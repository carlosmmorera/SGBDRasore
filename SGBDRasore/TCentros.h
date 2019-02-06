#ifndef TCENTROS_H
#define TCENTROS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tabla.h"
#include "gestorArchivos.h"

using namespace std;

const string TABLE_CENTROS = "centros.rasr";
const unsigned int NUM_CAMPOS_CENTROS = 8;

struct Centros_valor {
	string Nombre;
	string Cargo;
	string Direccion;
	string Localidad;
	string CP;
	string CargoAdmin;
	string TlfSecretaria;

	//Constructor
	Centros_valor(const string &nom, string carg = "Sr/a Decano/a", string dir = "", string loc = "",
		string codPost = "", string cargAd = "Sr/a Jefe/a de la Secretaría", string tlf = "") :
		Nombre(nom), Cargo(carg), Direccion(dir), Localidad(loc), CP(codPost), CargoAdmin(cargAd),
		TlfSecretaria(tlf) {}

	string valueToString() const {
		return Nombre + SEPARADOR + Cargo + SEPARADOR + Direccion + SEPARADOR + Localidad + SEPARADOR
			+ CP + SEPARADOR + CargoAdmin + SEPARADOR + TlfSecretaria;
	}
};

class TCentros : public Tabla<unsigned int, Centros_valor> {
private:
	//Inserta en la tabla la línea leída separada dada
	void insertLine(const vector<string> &lst) {
		Centros_valor val(lst[1], lst[2], lst[3], lst[4], lst[5], lst[6], lst[7]);
		insertaFila(stringToUint(lst[0]), val);
	}
public:
	//Constructor
	TCentros() : Tabla(TABLE_CENTROS) {
		vector<string> lst(NUM_CAMPOS_CENTROS);
		for (int i = 0; i < lineasArch.size(); ++i) {
			separateLine(lineasArch[i], lst, SEPARADOR);
			insertLine(lst);
		}
	}

	/*
	* Dado un flujo abierto, lee los centros del mismo e inserta los que no se encuentren ya
	* en la tabla. Los que ya estén los agrega al vector de líneas de error
	*/
	void importCentres(ifstream &f, vector<string> &errorsLine) {
		int n;
		string aux;
		f >> n;
		getline(f, aux);
		vector<string> lst(NUM_CAMPOS_CENTROS);
		for (int i = 0; i < n; ++i) {
			getline(f, aux);
			separateLine(aux, lst, SEPARADOR);
			if (!isInTable(stringToUint(lst[0])))
				insertLine(lst);
			else
				errorsLine.push_back(aux);
		}
	}

	//Comprueba si la línea dada corresponde a un elemento de la tabla
	bool lineIsInTable(const string &l) {
		//Obtengo la clave de la línea
		string clave = "";
		int ind = 0;
		while (l[ind] != SEPARADOR[0]) {
			clave += l[ind];
			++ind;
		}
		unsigned int cl = stringToUint(clave);
		auto it = getIterOf(cl);
		return l == elemToString(it->first, it->second);
	}

	//Modifica cualquiera de los campos del valor
	void setValor(const unsigned int &clave, const string &tipoValor, const string &nuevoValor) {
		auto it = getIt(clave);
		if (tipoValor == "Nombre")
			it->second.Nombre = nuevoValor;
		else if (tipoValor == "Cargo")
			it->second.Cargo = nuevoValor;
		else if (tipoValor == "Direccion")
			it->second.Direccion = nuevoValor;
		else if (tipoValor == "Localidad")
			it->second.Localidad = nuevoValor;
		else if (tipoValor == "CP")
			it->second.CP = nuevoValor;
		else if (tipoValor == "CargoAdmin")
			it->second.CargoAdmin == nuevoValor;
		else
			it->second.TlfSecretaria = nuevoValor;
	}

	vector<string> getAllNames() {
		vector<string> lst;
		auto it = begin();
		while (it != end()) {
			lst.push_back(it->second.Nombre);
			++it;
		}
		return lst;
	}

	string elemToString(const unsigned int &clave, const Centros_valor &valor) {
		return uintToString(clave) + SEPARADOR + valor.valueToString();
	}
};

#endif // !CENTROS_H
