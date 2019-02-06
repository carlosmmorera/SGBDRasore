#ifndef TESTUDIOS_H
#define TESTUDIOS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "TCentros.h"
#include "Conjunto.h"
#include "Tabla.h"
#include "gestorArchivos.h"

using namespace std;

const string TABLA_ESTUDIOS = "estudios.rasr";
const unsigned int NUM_CAMPOS_ESTUDIOS = 6;

struct Estudios_valor {
	string IdRuct;
	string Nombre;
	unsigned int centroId;
	const string *Ciclo;
	const string *Rama;

	Estudios_valor(const string &IdR, const string &nom, unsigned int centId, const string &cicl,
		const string &ram, const TCentros &Centro, const Conjunto &Ciclos, const Conjunto &Ramas) :
		IdRuct(IdR), Nombre(nom) {
		if (!Centro.isInTable(centId))
			throw invalid_argument("Error ESTUDIOS_VALOR-Constructor-01: Centro no existente.\n");
		centroId = centId;
		auto iter = Ciclos.find(cicl);
		if (iter == Ciclos.end())
			throw invalid_argument("Error ESTUDIOS_VALOR-Constructor-02: Ciclo no existente.\n");
		Ciclo = &(*iter);
		auto iterador = Ramas.find(ram);
		if (iterador == Ramas.end())
			throw invalid_argument("Error ESTUDIOS_VALOR-Constructor-03: Rama no existente.\n");
		Rama = &(*iterador);
	}

	string valueToString() const {
		return IdRuct + SEPARADOR + Nombre + SEPARADOR + uintToString(centroId) + SEPARADOR +
			*Ciclo + SEPARADOR + *Rama;
	}
};

class TEstudios : public Tabla<unsigned int, Estudios_valor> {
private:
	const TCentros * Centros;
	const Conjunto * Ciclos;
	const Conjunto * Ramas;

	//Inserta en la tabla la línea leída separada dada
	void insertLine(const vector<string> &lst) {
		Estudios_valor val(lst[1], lst[2], stringToUint(lst[3]), lst[4], lst[5], *Centros,
			*Ciclos, *Ramas);
		insertaFila(stringToUint(lst[0]), val);
	}
public:
	//Constructor
	TEstudios(const TCentros &Centro, const Conjunto &Ciclo, const Conjunto &Rama) :
		Tabla(TABLA_ESTUDIOS), Centros(&Centro), Ciclos(&Ciclo), Ramas(&Rama) {
		vector<string> lst(NUM_CAMPOS_ESTUDIOS);
		for (int i = 0; i < lineasArch.size(); ++i) {
			separateLine(lineasArch[i], lst, SEPARADOR);
			insertLine(lst);
		}
	}

	/*
	* Dado un flujo abierto, lee las titulaciones del mismo e inserta las que no se encuentren ya
	* en la tabla. Las que ya se encuentren los añade al vector de líneas de error.
	*/
	void importStudies(ifstream &f, vector<string> &errorLine) {
		int n;
		string aux;
		f >> n;
		getline(f, aux);
		vector<string> lst(NUM_CAMPOS_ESTUDIOS);
		for (int i = 0; i < n; ++i) {
			getline(f, aux);
			separateLine(aux, lst, SEPARADOR);
			if (!isInTable(stringToUint(lst[0])))
				insertLine(lst);
			else
				errorLine.push_back(aux);
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

	//Obtiene todos los nombres de los estudios guardados en la tabla
	void getAllNames(vector<string> &lst) {
		auto it = begin();
		while (it != end()) {
			lst.push_back(it->second.Nombre);
			++it;
		}
	}

	//Modifica cualquiera de los campos del valor
	void setValor(const unsigned int &clave, const string &tipoValor, const string &nuevoValor) {
		auto it = getIt(clave);
		if (tipoValor == "Nombre")
			it->second.Nombre = nuevoValor;
		else if (tipoValor == "Ciclo") {
			if (Ciclos->find(nuevoValor) == Ciclos->end())
				throw invalid_argument("Error TESTUDIOS-setValor-02: Ciclo no existente.\n");
			it->second.Ciclo = &nuevoValor;
		}
		else if (tipoValor == "Rama") {
			if (Ramas->find(nuevoValor) == Ramas->end())
				throw invalid_argument("Error TESTUDIOS-setValor-03: Rama no existente.\n");
			it->second.Rama = &nuevoValor;
		}
		else
			it->second.IdRuct = nuevoValor;
	}

	//Modifica el identificador del centro donde se imparte el estudio en cuestión
	void setValor(const unsigned int &clave, const unsigned int &nuevoValor) {
		auto it = getIt(clave);
		if (!Centros->isInTable(nuevoValor))
			throw invalid_argument("Error TESTUDIOS-setValor-01: Centro no existente.\n");
		it->second.centroId = nuevoValor;
	}

	string elemToString(const unsigned int &clave, const Estudios_valor &valor) {
		return uintToString(clave) + SEPARADOR + valor.valueToString();
	}
};

#endif