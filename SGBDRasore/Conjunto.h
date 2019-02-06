#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
#include <vector>
#include "gestorArchivos.h"

using namespace std;

class Conjunto : public unordered_set<string> {
private:
	string arch_conj;
public:
	//Constructor
	Conjunto(const string datos) : arch_conj(datos) {
		ifstream arch;
		arch.open(arch_conj);
		if (!arch.is_open())
			throw invalid_argument("Error CONJUNTO-Constructor-01: Pérdida de tabla de datos.\n");
		vector<string> lin;
		extraerLineas(arch, lin);
		insert(lin.begin(), lin.end());
		arch.close();
	}

	//Destructor
	~Conjunto() {
		clear();
	}

	//Inserta el elemento dado
	void insertaElem(const string &e) {
		auto it = find(e);
		if (it != end())
			throw domain_error("Error CONJUNTO-insertaElem-01: No se puede insertar un elemento ya existente.\n");
		emplace(e);
	}

	//Elimina el elemento dado
	void eliminaElem(const string &e) {
		auto it = find(e);
		if (it == end())
			throw domain_error("Error CONJUNTO-eliminaElem-01: El elemento a eliminar no existe.\n");
		erase(e);
	}

	//Elimina el elemento dado
	void eliminaElem(unordered_set<string>::const_iterator it) {
		if (it == end())
			throw domain_error("Error CONJUNTO-eliminaElem-02: Iterador no válido.\n");
		erase(it);
	}

	//Dado un flujo abierto, exporta el conjunto
	void exportSet(ofstream &f) {
		f << size() << '\n';
		for (auto it = begin(); it != end(); ++it)
			f << *it << '\n';
	}

	/*
	* Dado un flujo abierto, lee los centros del mismo e inserta los que no se encuentren ya
	* en el conjunto.
	*/
	void importSet(ifstream &f) {
		int n;
		string aux;
		f >> n;
		getline(f, aux);
		for (int i = 0; i < n; ++i) {
			getline(f, aux);
			if (find(aux) == end())
				insertaElem(aux);
		}
	}

	void close() {
		ofstream arch;
		arch.open(arch_conj);
		if (!arch.is_open())
			throw invalid_argument("Error CONJUNTO-close-01: Archivo de datos de la tabla corrupto.\n");
		arch << size() << '\n';
		for (auto it = begin(); it != end(); ++it)
			arch << *it << '\n';
		arch.close();
	}
};

#endif // !CONJUNTO_H