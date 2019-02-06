#ifndef TSOLICITUDES_H
#define TSOLICITUDES_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "TablaCifr.h"
#include "TEstudiantes.h"
#include "TAsignaturas.h"
#include "TCentros.h"
#include "Cifr.h"
#include "Fecha.h"
#include "Conjunto.h"
#include "gestorArchivos.h"

using namespace std;

const string TABLE_SOL = "solic.rasr";
const string SOL_SECCP = "solic_seccp.rasr";
const string SOL_CP = "solic_cp.rasr";
const unsigned int NUM_CAMPOS_SOLIC = 9;
const string SEP_ASIG = ".....";

const string DEFAULT_DATE = "1/1/1";

struct Solicitud_valor {
	const string * DNI;
	const string * Tipo;
	const string * Documentacion;
	vector<unsigned int> Asignaturas;
	Fecha Entrada;
	Fecha Informe;
	unsigned int Centro;
	string Observaciones;

	Solicitud_valor(const string &idEst, const string &tip, const string &doc, const Fecha &ent, const 
		Fecha &inf, const unsigned int &idCentro, const string &obser, const TEstudiantes &Est, const 
		Conjunto &Tipos, const Conjunto &Doc) : Entrada(ent), Informe(inf), Centro(idCentro), 
		Observaciones(obser), Asignaturas() {
		try {
			auto it = Est.getIterOf(idEst);
			DNI = &it->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error SOLICITUD_VALOR-Constructor-01: DNI no existente.\n");
		}
		auto iter = Tipos.find(tip);
		if (iter == Tipos.end())
			throw invalid_argument("Error SOLICITUD_VALOR-Constructor-02: Tipo de solicitud no existente.\n");
		Tipo = &(*iter);

		auto iterador = Doc.find(doc);
		if (iterador == Doc.end())
			throw invalid_argument("Error SOLICITUD_VALOR-Constructor-03: Tipo de documentación de solicitud no existente.\n");
		Documentacion = &(*iterador);
	}

	Solicitud_valor(const string &idEst, const string &tip, const string &doc, const unsigned int &idCentro, 
		const string &obser, const TEstudiantes &Est, const Conjunto &Tipos, const Conjunto &Doc) : 
		Entrada(stringToDate(DEFAULT_DATE)), Informe(stringToDate(DEFAULT_DATE)), Centro(idCentro), 
			Observaciones(obser), Asignaturas() {
		try {
			auto it = Est.getIterOf(idEst);
			DNI = &it->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error SOLICITUD_VALOR-Constructor-01: DNI no existente.\n");
		}
		auto iter = Tipos.find(tip);
		if (iter == Tipos.end())
			throw invalid_argument("Error SOLICITUD_VALOR-Constructor-02: Tipo de solicitud no existente.\n");
		Tipo = &(*iter);

		auto iterador = Doc.find(doc);
		if (iterador == Doc.end())
			throw invalid_argument("Error SOLICITUD_VALOR-Constructor-03: Tipo de documentación de solicitud no existente.\n");
		Documentacion = &(*iterador);
	}

	void setEntrada(const Fecha &f) {
		Entrada = f;
	}
	
	void setInforme(const Fecha &f) {
		Informe = f;
	}

	bool hasEntradaDate() const {
		return dateToString(Entrada) != DEFAULT_DATE;
	}

	bool hasInformeDate() const {
		return dateToString(Informe) != DEFAULT_DATE;
	}

	string valueToString() const {
		string asignatura = "";
		for (int i = 0; i < Asignaturas.size(); ++i)
			asignatura += uintToString(Asignaturas[i]) + SEP_ASIG;
		if (Asignaturas.size() == 0)
			asignatura += SEP_ASIG;
		asignatura += uintToString(Asignaturas.size());
		return *DNI + SEPARADOR + *Tipo + SEPARADOR + asignatura + SEPARADOR + dateToString(Entrada) +
			SEPARADOR + dateToString(Informe) + SEPARADOR + uintToString(Centro) + SEPARADOR + Observaciones
			+ SEPARADOR + *Documentacion;
	}
};

class TSolicitudes : public TablaCifr<unsigned int, Solicitud_valor> {
private:
	const TAsignaturas * Subjects;
	const TEstudiantes * Students;
	const Conjunto * Types;
	const Conjunto * Documentation;

	//Obtiene el número de asignaturas de la solicitud en cuestión
	unsigned int getNumAsig(string &asign) const {
		int borrado = 0;
		string tamInv = "", tam = "";
		while (borrado < SEP_ASIG.size()) {
			if (borrado == 0 && asign.back() != SEP_ASIG.back())
				tamInv.push_back(asign.back());
			else
				++borrado;
			asign.pop_back();
		}
		for (int i = tamInv.size() - 1; i >= 0; --i)
			tam += tamInv[i];
		return stringToUint(tam);
	}

	//Inserta en la tabla la línea leída separada dada
	void insertLine(const vector<string> &lst, const vector<string> &vAsig) {
		Solicitud_valor val(lst[1], lst[2], lst[8], stringToDate(lst[4]), stringToDate(lst[5]),
			stringToUint(lst[6]), lst[7], *Students, *Types, *Documentation);
		for (int i = 0; i < vAsig.size(); ++i) {
			auto it = Subjects->getIterOf(stringToUint(vAsig[i]));
			val.Asignaturas.push_back(it->first);
		}
		insertaFila(stringToUint(lst[0]), val);
	}
public:
	//Constructor
	TSolicitudes(Cifr &cifra, const TAsignaturas &tAsig, const TEstudiantes &Est, const Conjunto &Tipos, 
		const Conjunto &Doc) : 	TablaCifr(cifra, TABLE_SOL, SOL_CP, SOL_SECCP, Solicitudes), Subjects(&tAsig),
		Students(&Est),	Types(&Tipos), Documentation(&Doc) {
		vector<string> lst(NUM_CAMPOS_SOLIC);
		for (int i = lineasArch.size() - 1; i >= 0; --i) {
			cifrado->desencript(lineasArch[i], index, Solicitudes);
			separateLine(lineasArch[i], lst, SEPARADOR);
			unsigned int numAsig = getNumAsig(lst[3]);
			vector<string> vAsig(numAsig);
			separateLine(lst[3], vAsig, SEP_ASIG);
			insertLine(lst, vAsig);
		}
	}

	/*
	* Dado un flujo abierto, lee las solicitudes del mismo e inserta las que no se encuentren ya
	* en la tabla. Las que ya se encuentren los añade al vector de líneas de error.
	*/
	void importApplications(ifstream &f, vector<string> &errorLine) {
		int numApp;
		string aux;
		f >> numApp;
		getline(f, aux);
		vector<string> lines(numApp);
		for (int i = 0; i < numApp; ++i)
			getline(f, lines[i]);
		index = stringToUint(lines[numApp - 1]);
		lines.pop_back();
		vector<string> lst(NUM_CAMPOS_SOLIC);
		for (int j = lines.size() - 1; j >= 0; --j) {
			cifrado->desencript(lines[j], index, Solicitudes);
			separateLine(lines[j], lst, SEPARADOR);
			if (!isInTable(stringToUint(lst[0]))) {
				unsigned int numAsig = getNumAsig(lst[3]);
				vector<string> vAsig(numAsig);
				separateLine(lst[3], vAsig, SEP_ASIG);
				insertLine(lst, vAsig);
			}
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

	//Modifica el valor correspondiente del campo valor
	void setValor(const unsigned int &clave, const string &tipoValor, const string &nuevoValor) {
		auto it = getIt(clave);
		if (tipoValor == "DNI") {
			try {
				auto iter = Students->getIterOf(nuevoValor);
				it->second.DNI = &iter->first;
			}
			catch (invalid_argument &e) {
				string mensaje = e.what();
				throw invalid_argument(mensaje + "Error TSOLICITUDES-SetValor-01: DNI no existente\n.");
			}
		}
		else if (tipoValor == "Tipo") {
			auto iter = Types->find(nuevoValor);
			if (iter == Types->end())
				throw invalid_argument("Error TSOLICITUDES-SetValor-02: Tipo de solicitud no existente\n");
			it->second.Tipo = &(*iter);
		}
		else if (tipoValor == "Documentación") {
			auto iter = Documentation->find(nuevoValor);
			if (iter == Documentation->end())
				throw invalid_argument("Error TSOLICITUDES-SetValor-03: Tipo de documentación no existente\n");
			it->second.Documentacion = &(*iter);
		}
		else it->second.Observaciones = nuevoValor;
	}

	void setValor(const unsigned int &clave, const string &tipoValor, const Fecha &nuevoValor) {
		auto it = getIt(clave);
		if (tipoValor == "Entrada")
			it->second.Entrada = nuevoValor;
		else
			it->second.Informe = nuevoValor;
	}

	//Modifica el identificador del centro de la solicitud
	void setValor(const unsigned int &clave, const unsigned int &nuevoValor) {
		auto it = getIt(clave);
		it->second.Centro = nuevoValor;
	}

	//Añade una asignatura a la solicitud dada
	void addSubject(const unsigned int &clave, const unsigned int subject) {
		auto it = getIt(clave);
		auto iter = Subjects->getIterOf(subject);
		it->second.Asignaturas.push_back(iter->first);
	}

	string elemToString(const unsigned int &clave, const Solicitud_valor &valor) {
		return uintToString(clave) + SEPARADOR + valor.valueToString();
	}
};
#endif