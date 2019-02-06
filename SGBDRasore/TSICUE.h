#ifndef TSICUE_H
#define TSICUE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Conjunto.h"
#include "TablaCifr.h"
#include "Cifr.h"
#include "gestorArchivos.h"

using namespace std;

const string TABLE_SICUE = "sicue.rasr";
const string SICUE_CP = "sicuecp.rasr";
const string SICUE_SECCP = "sicue_seccp.rasr";
const unsigned int NUM_CAMPOS_SICUE = 7;

struct SICUE_valor {
	const string *univ_origen;
	const string *univ_destino;
	string estudios_analogos;
	string campus;
	bool beca;
	Periodo periodo;

	//Constructor
	SICUE_valor(const string &un_o, const string &un_d, const string &est, const Conjunto &Universidades,
		const string &c, bool b, const Periodo &p = Cuatrimestral) : estudios_analogos(est), campus(c), 
		beca(b), periodo(p) {
		auto iter = Universidades.find(un_o);
		if (iter == Universidades.end())
			throw invalid_argument("Error SICUE_VALOR-Constructor-01: Universidad de origen no existente.\n");
		univ_origen = &(*iter);

		auto iterador = Universidades.find(un_d);
		if (iterador == Universidades.end())
			throw invalid_argument("Error SICUE_VALOR-Constructor-02: Universidad de destino no existente.\n");
		univ_destino = &(*iterador);
	}

	string valueToString() const {
		return *univ_origen + SEPARADOR + *univ_destino + SEPARADOR + estudios_analogos + SEPARADOR
			+ campus + SEPARADOR + boolToString(beca) + SEPARADOR + periodToString(periodo);
	}
};

class TSICUE : public TablaCifr<string, SICUE_valor> {
private:
	const Conjunto *Universidades;

	//Inserta en la tabla la línea leída separada dada
	void insertLine(const vector<string> &lst) {
		SICUE_valor val(lst[1], lst[2], lst[3], *Universidades, lst[4], stringToBool(lst[5]),
			stringToPeriod(lst[6]));
		insertaFila(lst[0], val);
	}
public:
	//Constructor
	TSICUE(Cifr &cifra, const Conjunto &Univ) :
		TablaCifr(cifra, TABLE_SICUE, SICUE_CP, SICUE_SECCP, SICUE), Universidades(&Univ) {
		vector<string> lst(NUM_CAMPOS_SICUE);
		for (int i = lineasArch.size() - 1; i >= 0; --i) {
			cifrado->desencript(lineasArch[i], index, SICUE);
			separateLine(lineasArch[i], lst, SEPARADOR);
			insertLine(lst);
		}
	}

	/*
	* Dado un flujo abierto, lee los SICUE del mismo e inserta los que no se encuentren ya
	* en la tabla. Los que ya se encuentren los añade al vector de líneas de error.
	*/
	void importSicue(ifstream &f, vector<string> &errorLine) {
		int numStudent;
		string aux;
		f >> numStudent;
		getline(f, aux);
		vector<string> lines(numStudent);
		for (int i = 0; i < numStudent; ++i)
			getline(f, lines[i]);
		index = stringToUint(lines[numStudent - 1]);
		lines.pop_back();
		vector<string> lst(NUM_CAMPOS_SICUE);
		for (int j = lines.size() - 1; j >= 0; --j) {
			cifrado->desencript(lines[j], index, SICUE);
			separateLine(lines[j], lst, SEPARADOR);
			if (!isInTable(lst[0]))
				insertLine(lst);
			else
				errorLine.push_back(lines[j]);
		}
	}

	//Comprueba si la línea dada corresponde a un elemento de la tabla
	bool lineIsInTable(const string &l) {
		//Obtengo la clave de la línea
		string clave = "", aux = "";
		int ind = 0, coinc = 0;
		while (coinc < SEPARADOR.size()) {
			if (l[ind] == SEPARADOR[coinc]) {
				aux += l[ind];
				++coinc;
			}
			else {
				if (coinc > 0) {
					clave += aux;
					aux = "";
					coinc = 0;
				}
				clave += l[ind];
			}
			++ind;
		}
		auto it = getIterOf(clave);
		return l == elemToString(it->first, it->second);
	}

	string elemToString(const string &clave, const SICUE_valor &valor) {
		return clave + SEPARADOR + valor.valueToString();
	}
};

#endif