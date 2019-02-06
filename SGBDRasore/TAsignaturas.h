#ifndef TASIGNATURAS_H
#define TASIGNATURAS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "TEstudios.h"
#include "Tabla.h"
#include "gestorArchivos.h"

using namespace std;

const string TABLA_ASIGNATURAS = "asig.rasr";
const unsigned int NUM_CAMPOS_ASIG = 3;

struct Asignaturas_valor {
	string Nombre;
	unsigned int Estudio;

	Asignaturas_valor(const string &nom, const unsigned int &est, const TEstudios &TEst) : Nombre(nom) {
		if (!TEst.isInTable(est))
			throw invalid_argument("Error ASIGNATURAS_VALOR-Constructor-01: Estudio no existente\n.");
		Estudio = est;
	}

	string valueToString() const {
		return Nombre + SEPARADOR + uintToString(Estudio);
	}
};

class TAsignaturas : public Tabla<unsigned int, Asignaturas_valor> {
private:
	const TEstudios * Estudios;

	//Inserta en la tabla la línea leída separada dada
	void insertLine(const vector<string> &lst) {
		Asignaturas_valor val(lst[1], stringToUint(lst[2]), *Estudios);
		insertaFila(stringToUint(lst[0]), val);
	}
public:
	//Constructor
	TAsignaturas(const TEstudios &Est) : Tabla(TABLA_ASIGNATURAS), Estudios(&Est) {
		vector<string> lst(NUM_CAMPOS_ASIG);
		for (int i = 0; i < lineasArch.size(); ++i) {
			separateLine(lineasArch[i], lst, SEPARADOR);
			insertLine(lst);
		}
	}

	/*
	* Dado un flujo abierto, lee las asignaturas del mismo e inserta las que no se encuentren ya
	* en la tabla. Las que ya se encuentren los añade al vector de líneas de error.
	*/
	void importSubjects(ifstream &f, vector<string> &errorLine) {
		int n;
		string aux;
		f >> n;
		getline(f, aux);
		vector<string> lst(NUM_CAMPOS_ASIG);
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
		if (l == elemToString(it->first, it->second))
			return true;
		vector<string> lst(NUM_CAMPOS_ASIG);
		separateLine(l, lst, SEPARADOR);
		Asignaturas_valor val(lst[1], stringToUint(lst[2]), *Estudios);
		auto v = filtra([](unordered_map<unsigned int, Asignaturas_valor>::const_iterator it, const string &n) {
				return n == it->second.valueToString();
			}, val.valueToString());
		return v.size() > 0;
	}

	//Modifica cualquiera de los campos del valor
	void setValor(const unsigned int &clave, const string &nuevoValor) {
		auto it = getIt(clave);
		it->second.Nombre = nuevoValor;
	}

	//Modifica cualquiera de los campos del valor
	void setValor(const unsigned int &clave, const unsigned int &nuevoValor) {
		auto it = getIt(clave);
		if (!Estudios->isInTable(nuevoValor))
			throw invalid_argument("Error TASIGNATURAS-SetValor-01: Estudio no existente.\n");
		it->second.Estudio = nuevoValor;
	}

	string elemToString(const unsigned int &clave, const Asignaturas_valor &valor) {
		return uintToString(clave) + SEPARADOR + valor.valueToString();
	}
};

#endif // !TASIGNATURAS_H