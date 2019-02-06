#ifndef TESTUDIANTES_H
#define TESTUDIANTES_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "TablaCifr.h"
#include "Cifr.h"
#include "gestorArchivos.h"
#include "TEstudios.h"

using namespace std;

const string TABLE_ESTUD = "estud.rasr";
const string ESTUD_SECCP = "estudcp.rasr";
const string ESTUD_CP = "estud_seccp.rasr";
const unsigned int NUM_CAMPOS_ESTUDIANTE = 14;

struct Estudiante_valor {
	unsigned int Id;
	string Nombre;
	string Apellido1;
	string Apellido2;
	string Telefono;
	string Email;
	string Direccion;
	string Localidad;
	string CP;
	string Provincia;
	string Pais;
	unsigned int Estudios;
	string Observaciones;

	//Constructor
	Estudiante_valor(const string &nom, const string &ap1, unsigned int est, const TEstudios &Estud, 
		unsigned int ide = 0, string ap2 = "", string tlf = "", string mail = "", string dir = "", 
		string loc = "", string codPost = "", string prov = "", string country = "España", 
		string obser = "") : Id(ide), Nombre(nom), Apellido1(ap1), Apellido2(ap2), Telefono(tlf), 
		Email(mail), Direccion(dir), Localidad(loc), CP(codPost), Provincia(prov), Pais(country),
		Observaciones(obser) {
		try {
			auto it = Estud.getIterOf(est);
			Estudios = it->first;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error ESTUDIANTE_VALOR-Constructor-01: Estudios no existentes.\n");
		}
	}

	string valueToString() const {
		return uintToString(Id) + SEPARADOR + Nombre + SEPARADOR + Apellido1 + SEPARADOR + Apellido2
			+ SEPARADOR + Telefono + SEPARADOR + Email + SEPARADOR + Direccion + SEPARADOR + Localidad
			+ SEPARADOR + CP + SEPARADOR + Provincia + SEPARADOR + Pais + SEPARADOR + 
			uintToString(Estudios) + SEPARADOR + Observaciones;
	}
};

class TEstudiantes : public TablaCifr<string, Estudiante_valor> {
private:
	const TEstudios * Estudios;

	//Inserta en la tabla la línea leída separada dada
	void insertLine(const vector<string> &lst) {
		Estudiante_valor val(lst[2], lst[3], stringToUint(lst[12]), *Estudios,
			stringToUint(lst[1]), lst[4], lst[5], lst[6], lst[7], lst[8], lst[9],
			lst[10], lst[11], lst[13]);
		insertaFila(lst[0], val);
	}
public:
	//Constructor
	TEstudiantes(Cifr &cifra, const TEstudios &Est) : 
		TablaCifr(cifra, TABLE_ESTUD, ESTUD_CP, ESTUD_SECCP, Estudiantes), Estudios(&Est) {
		vector<string> lst(NUM_CAMPOS_ESTUDIANTE);
		for (int i = lineasArch.size() - 1; i >= 0; --i) {
			cifrado->desencript(lineasArch[i], index, Estudiantes);
			separateLine(lineasArch[i], lst, SEPARADOR);
			insertLine(lst);
		}
	}

	/*
	* Dado un flujo abierto, lee los estudiantes del mismo e inserta los que no se encuentren ya
	* en la tabla. Los que ya se encuentren los añade al vector de líneas de error.
	*/
	void importStudents(ifstream &f, vector<string> &errorLine) {
		int numStudent;
		string aux;
		f >> numStudent;
		getline(f, aux);
		vector<string> lines(numStudent);
		for (int i = 0; i < numStudent; ++i)
			getline(f, lines[i]);
		index = stringToUint(lines[numStudent - 1]);
		lines.pop_back();
		vector<string> lst(NUM_CAMPOS_ESTUDIANTE);
		for (int j = lines.size() - 1; j >= 0; --j) {
			cifrado->desencript(lines[j], index, Estudiantes);
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

	//Modifica cualquiera de los campos del valor
	void setValor(const string &clave, const string &tipoValor, const string &nuevoValor) {
		auto it = getIt(clave);
		if (tipoValor == "Nombre")
			it->second.Nombre = nuevoValor;
		else if (tipoValor == "Apellido1")
			it->second.Apellido1 = nuevoValor;
		else if (tipoValor == "Apellido2")
			it->second.Apellido2 = nuevoValor;
		else if (tipoValor == "Telefono")
			it->second.Telefono = nuevoValor;
		else if (tipoValor == "Email")
			it->second.Email = nuevoValor;
		else if (tipoValor == "Direccion")
			it->second.Direccion = nuevoValor;
		else if (tipoValor == "Localidad")
			it->second.Localidad = nuevoValor;
		else if (tipoValor == "CP")
			it->second.CP = nuevoValor;
		else if (tipoValor == "Provincia")
			it->second.Provincia == nuevoValor;
		else if (tipoValor == "Pais")
			it->second.Pais == nuevoValor;
		else
			it->second.Observaciones = nuevoValor;
	}

	//Modifica el identificado de los estudios
	void setValor(const string &clave, const unsigned int &nuevoValor) {
		auto it = getIt(clave);
		if (!Estudios->isInTable(nuevoValor))
			throw invalid_argument("Error ESTUDIANTE_VALOR-setValor-01: Estudios no existentes.\n");
		it->second.Estudios = nuevoValor;

	}

	string elemToString(const string &clave, const Estudiante_valor &valor) {
		return clave + SEPARADOR + valor.valueToString();
	}
};

#endif