#ifndef RESOLUCIONES_H
#define RESOLUCIONES_H

#include <iostream>
#include <string>
#include <vector>
#include "TEstudiantes.h"
#include "TSolicitudes.h"
#include "Conjunto.h"
#include "Fecha.h"
#include "Cifr.h"
#include "TablaCifr.h"
#include "gestorArchivos.h"

using namespace std;

const string TABLE_RES = "resol.rasr";
const string RES_CP = "resol_cp.rasr";
const string RES_SECCP = "resol_seccp.rasr";
const unsigned int NUM_CAMPOS_RESOL = 8;

struct Resolucion_valor {
	const string * DNI;
	const unsigned int * Solicitud;
	const string * Tipo;
	Fecha Firma;
	Fecha Salida;
	const string * TipoRecurso;
	string Observaciones;

	Resolucion_valor(const string &dni, const unsigned int &sol, const string &tip, const Fecha &sign,
		const Fecha &sal, const string &recurso, const string &Obser, const TEstudiantes &Est, const
		TSolicitudes &Sol, const Conjunto &Resoluciones, const Conjunto &Recurso) : Firma(sign), Salida(sal) {
		try {
			auto it = Est.getIterOf(dni);
			DNI = &it->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error RESOLUCION_VALOR-Constructor-01: DNI no existente.\n");
		}
		try {
			auto iter = Sol.getIterOf(sol);
			Solicitud = &iter->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error RESOLUCION_VALOR-Constructor-02: Solicitud no existente.\n");
		}
		auto itera = Resoluciones.find(tip);
		if (itera == Resoluciones.end())
			throw invalid_argument("Error RESOLUCION_VALOR-Contructor-03: Tipo no existente.\n");
		Tipo = &(*itera);
		if (recurso != "") {
			auto iterador = Recurso.find(recurso);
			if (iterador == Recurso.end())
				throw invalid_argument("Error RESOLUCION_VALOR-Contructor-04: Tipo de recurso no existente.\n");
			TipoRecurso = &(*iterador);
		}
	}

	Resolucion_valor(const string &dni, const unsigned int &sol, const string &tip, const string &recurso, 
		const string &Obser, const TEstudiantes &Est, const TSolicitudes &Sol, const Conjunto &Resoluciones, 
		const Conjunto &Recurso) : Firma(stringToDate(DEFAULT_DATE)), Salida(stringToDate(DEFAULT_DATE)) {
		try {
			auto it = Est.getIterOf(dni);
			DNI = &it->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error RESOLUCION_VALOR-Constructor-01: DNI no existente.\n");
		}
		try {
			auto iter = Sol.getIterOf(sol);
			Solicitud = &iter->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error RESOLUCION_VALOR-Constructor-02: Solicitud no existente.\n");
		}
		auto itera = Resoluciones.find(tip);
		if (itera == Resoluciones.end())
			throw invalid_argument("Error RESOLUCION_VALOR-Contructor-03: Tipo no existente.\n");
		Tipo = &(*itera);
		if (recurso != "") {
			auto iterador = Recurso.find(recurso);
			if (iterador == Recurso.end())
				throw invalid_argument("Error RESOLUCION_VALOR-Contructor-04: Tipo de recurso no existente.\n");
			TipoRecurso = &(*iterador);
		}
	}

	void setFirma(const Fecha &f) {
		Firma = f;
	}

	void setSalida(const Fecha &f) {
		Salida = f;
	}

	bool hasFirmaDate() const {
		return dateToString(Firma) != DEFAULT_DATE;
	}

	bool hasSalidaDate() const {
		return dateToString(Salida) != DEFAULT_DATE;
	}

	string valueToString() const {
		return *DNI + SEPARADOR + uintToString(*Solicitud) + SEPARADOR + *Tipo + SEPARADOR +
			dateToString(Firma) + SEPARADOR + dateToString(Salida) + SEPARADOR + *TipoRecurso +
			SEPARADOR + Observaciones;
	}
};

class TResoluciones : public TablaCifr<unsigned int, Resolucion_valor> {
private:
	const TEstudiantes * Students;
	const TSolicitudes * Solic;
	const Conjunto * TiposResoluciones;
	const Conjunto * Recursos;

	//Inserta en la tabla la línea leída separada dada
	void insertLine(const vector<string> &lst) {
		Resolucion_valor val(lst[1], stringToUint(lst[2]), lst[3], stringToDate(lst[4]),
			stringToDate(lst[5]), lst[6], lst[7], *Students, *Solic, *TiposResoluciones, *Recursos);
		insertaFila(stringToUint(lst[0]), val);
	}
public:
	//Constructor
	TResoluciones(Cifr &cifra, const TEstudiantes &Est, const TSolicitudes &Sol, const Conjunto &TipRes,
		const Conjunto &Recur) : TablaCifr(cifra, TABLE_RES, RES_CP, RES_SECCP, Resoluciones), Students(&Est),
		Solic(&Sol), TiposResoluciones(&TipRes), Recursos(&Recur) {
		vector<string> lst(NUM_CAMPOS_RESOL);
		for (int i = lineasArch.size() - 1; i >= 0; --i) {
			cifrado->desencript(lineasArch[i], index, Resoluciones);
			separateLine(lineasArch[i], lst, SEPARADOR);
			insertLine(lst);
		}
	}

	/*
	* Dado un flujo abierto, lee las resoluciones del mismo e inserta las que no se encuentren ya
	* en la tabla. Las que ya se encuentren los añade al vector de líneas de error.
	*/
	void importResolutions(ifstream &f, vector<string> &errorLine) {
		int numResolutions;
		string aux;
		f >> numResolutions;
		getline(f, aux);
		vector<string> lines(numResolutions);
		for (int i = 0; i < numResolutions; ++i)
			getline(f, lines[i]);
		index = stringToUint(lines[numResolutions - 1]);
		lines.pop_back();
		vector<string> lst(NUM_CAMPOS_RESOL);
		for (int j = lines.size() - 1; j >= 0; --j) {
			cifrado->desencript(lines[j], index, Resoluciones);
			separateLine(lines[j], lst, SEPARADOR);
			if (!isInTable(stringToUint(lst[0])))
				insertLine(lst);
			else
				errorLine.push_back(lines[j]);
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

	void setValor(const unsigned int &clave, const string &tipoValor, const string &nuevoValor) {
		auto it = getIt(clave);
		if (tipoValor == "DNI") {
			try {
				auto iter = Students->getIterOf(nuevoValor);
				it->second.DNI = &iter->first;
			}
			catch (invalid_argument &e) {
				string mensaje = e.what();
				throw invalid_argument(mensaje + "Error TRESOLUCIONES-SetValor-01: DNI no existente\n.");
			}
		}
		else if (tipoValor == "Tipo") {
			auto iter = TiposResoluciones->find(nuevoValor);
			if (iter == TiposResoluciones->end())
				throw invalid_argument("Error TRESOLUCIONES-SetValor-02: Tipo de resolución no existente\n.");
			it->second.Tipo = &(*iter);
		}
		else if (tipoValor == "Recurso") {
			if (nuevoValor != "") {
				auto iter = Recursos->find(nuevoValor);
				if (iter == Recursos->end())
					throw invalid_argument("Error TRESOLUCIONES-SetValor-03: Tipo de recurso no existente\n.");
				it->second.TipoRecurso = &(*iter);
			}
			else
				it->second.TipoRecurso = NULL;
		}
		else
			it->second.Observaciones = nuevoValor;
	}

	void setValor(const unsigned int &clave, const string &tipoValor, const Fecha &nuevoValor) {
		auto it = getIt(clave);
		if (tipoValor == "Firma")
			it->second.Firma = nuevoValor;
		else
			it->second.Salida = nuevoValor;
	}

	void setValor(const unsigned int &clave, const unsigned int &nuevoValor) {
		auto it = getIt(clave);
		try {
			auto iter = Solic->getIterOf(nuevoValor);
			it->second.Solicitud = &iter->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error TRESOLUCIONES-SetValor-04: Solicitud no existente\n.");
		}
	}

	string elemToString(const unsigned int &clave, const Resolucion_valor &valor) {
		return uintToString(clave) + SEPARADOR + valor.valueToString();
	}
};

#endif // !RESOLUCIONES_H