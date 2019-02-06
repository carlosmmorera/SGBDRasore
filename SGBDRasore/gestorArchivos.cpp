#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include "gestorArchivos.h"

string uintToString(const unsigned int &id) {
	string resultado = "", aux = "";
	unsigned int cociente = id / 10;
	unsigned int resto = id % 10;
	while (cociente > 0) {
		aux += char(resto + int('0'));
		resto = cociente % 10;
		cociente = cociente / 10;
	}
	aux += char(resto + int('0'));
	for (int i = aux.size() - 1; i >= 0; --i)
		resultado += aux[i];
	return resultado;
}

void extraerLineas(ifstream &arch, vector<string> &lineas) {
	string aux = "";
	unsigned int numLin;
	arch >> numLin;
	getline(arch, aux);
	for (int i = 0; i < numLin; ++i) {
		getline(arch, aux);
		lineas.push_back(aux);
	}
}

void separateLine(const string &linea, vector<string> &lst, const string &separad) {
	if (lst.size() > 0) {
		string aux = "";
		string aux2 = "";
		int sep = 0;
		int indice = 0;
		for (int i = 0; i < linea.size(); ++i) {
			if (linea[i] != separad[sep]) {
				if (sep != 0) {
					aux += aux2;
					aux2 = "";
					sep = 0;
				}
				aux += linea[i];
			}
			else if (sep < separad.size() - 1) {
				aux2 += linea[i];
				++sep;
			}
			else {
				lst[indice] = aux;
				aux = "";
				aux2 = "";
				sep = 0;
				++indice;
			}
		}
		lst[indice] = aux;
	}
}

unsigned int stringToUint(const string & str) {
	unsigned int pot = 1;
	unsigned int num = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		if (!isdigit(str[i]))
			throw invalid_argument("Error gestorArchivos-stringToUint-01: Caracter no dígito imposible de convertir.\n");
		num += (int(str[i]) - int('0'))*pot;
		pot = pot * 10;
	}
	return num;
}

string dateToString(const Fecha &f) {
	return uintToString(f.getDia()) + '/' + uintToString(f.getMes()) + '/' + uintToString(f.getAnyo());
}

Fecha stringToDate(const string &str) {
	string dia = "", mes = "", anyo = "";
	int numBarras = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '/')
			++numBarras;
		else {
			if (numBarras == 0)
				dia += str[i];
			else if (numBarras == 1)
				mes += str[i];
			else anyo += str[i];
		}
	}

	return Fecha(stringToUint(dia), stringToUint(mes), stringToUint(anyo));
}

string periodToString(Periodo p)
{
	switch (p) {
	case Cuatrimestral: return "Medio curso";
	case Anual: return "Curso completo";
	default: throw invalid_argument("Error GESTOR_ARCHIVOS-periodToString-01: Error en el periodo.\n");
	}
}

Periodo stringToPeriod(const string & str)
{
	if (str == "Medio curso")
		return Cuatrimestral;
	else if (str == "Curso completo")
		return Anual;
	else
		throw invalid_argument("Error GESTOR_ARCHIVOS-stringToPeriod-01: Error en el periodo.\n");
}

bool isDateCorrect(const string & date)
{	
	string dia = "", mes = "", anyo = "";
	int numBarras = 0, i = 0;
	bool error = false;
	while (i < date.size() && !error) {
		if (date[i] == '/')
			++numBarras;
		else {
			error = !isdigit(date[i]);
			if (!error) {
				if (numBarras == 0)
					dia += date[i];
				else if (numBarras == 1)
					mes += date[i];
				else anyo += date[i];
			}
		}
		++i;
	}
	error = error || dia.size() == 0 || mes.size() == 0 || anyo.size() == 0;
	if (error)
		return false;
	unsigned int d = stringToUint(dia);
	unsigned int m = stringToUint(mes);
	unsigned int a = stringToUint(anyo);
	if (m > NUM_MESES || d == 0 || m == 0 || a == 0)
		return false;
	else if (m != FEBRERO || a % 4 != 0)
		return d <= MESES[m - 1];
	else
		return d <= MESES[m - 1] + 1;
}

bool isANumber(const string & n)
{
	if (n.size() == 0)
		return false;
	bool error = false;
	int i = 0;
	while (!error && i < n.size()) {
		error = !isdigit(n[i]);
		++i;
	}
	return !error;
}

string boolToString(bool b)
{	
	if (b)
		return "1";
	else
		return "0";
}

bool stringToBool(const string & s)
{
	return s == "1";
}
