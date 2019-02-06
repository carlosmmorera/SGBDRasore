#ifndef TABLA_H
#define TABLA_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "gestorArchivos.h"

using namespace std;

//Clase	que gestiona una tabla de datos genérica
template <class Tclave, class Tvalor>
class Tabla : private unordered_map<Tclave, Tvalor> {
	using unmap = unordered_map<Tclave, Tvalor>;
private:
	unsigned int numFilas;
	//Dado un flujo abierto, escribe en el mismo los datos de la tabla
	void saveOpenFlux(ofstream &arch) {
		arch << numFilas << '\n';
		for (auto it = unmap::begin(); it != unmap::end(); ++it)
			arch << elemToString(it->first, it->second) << '\n';
		arch.close();
	}
protected:
	vector<string> lineasArch;
	string arch_tabla;
	//Devuelve un iterador que apunta al elemento de la clave dada
	unmap::iterator getIt(const Tclave &clave) {
		if (unmap::find(clave) == unmap::end())
			throw invalid_argument("Error TABLA-getIt-01: Elemento buscado no existente.\n");
		return unmap::find(clave);
	}

	unmap::iterator begin() {
		return unmap::begin();
	}

	unmap::const_iterator cbegin() const {
		return unmap::cbegin();
	}

	unmap::iterator end() {
		return unmap::end();
	}

	unmap::const_iterator cend() const {
		return unmap::cend();
	}
public:
	//Constructor
	Tabla(const string datos) : arch_tabla(datos), numFilas(0) {
		ifstream arch;
		arch.open(arch_tabla);
		if (!arch.is_open())
			throw invalid_argument("Error TABLA-Constructor-01: Pérdida de tabla de datos.\n");
		extraerLineas(arch, lineasArch);
		arch.close();
	}

	//Inserta una nueva fila
	void insertaFila(const Tclave &clave, const Tvalor &val) {
		auto it = unmap::find(clave);
		if (it != unmap::end())
			throw domain_error("Error TABLA-insertaFila-01: No se puede insertar un elemento ya existente.\n");
		unmap::emplace(clave, val);
		++numFilas;
	}

	//Elimina la fila con la clave correspondiente
	void eliminaFila(const Tclave &clave) {
		auto it = unmap::find(clave);
		if (it == unmap::end())
			throw domain_error("Error TABLA-eliminaFila-01: El elemento a eliminar no existe.\n");
		unmap::erase(clave);
		--numFilas;
	}

	//Elimina la fila con la clave correspondiente
	void eliminaFila(unmap::const_iterator it) {
		if (it == unmap::end())
			throw domain_error("Error TABLA-eliminaFila-02: Iterador no válido.\n");
		unmap::erase(it);
		--numFilas;
	}

	//Borra la tabla completa
	void borrarTabla() {
		unmap::clear();
		numFilas = 0;
	}

	//Devuelve el número de filas de la tabla
	unsigned int getSize() const {
		return numFilas;
	}

	//Dado un flujo abierto, exporta la tabla sobre el flujo dado
	virtual void exportTable(ofstream &f) {
		f << numFilas << '\n';
		for (auto it = unmap::begin(); it != unmap::end(); ++it)
			f << elemToString(it->first, it->second) << '\n';
	}

	//Lleva a cabo todos los procedimientos para el cierre seguro del gestor de los datos de la tabla
	virtual void close() {
		ofstream arch;
		arch.open(arch_tabla);
		if (!arch.is_open())
			throw invalid_argument("Error TABLA-close-01: Archivo de datos de la tabla corrupto.\n");
		saveOpenFlux(arch);
	}

	//Obtiene un iterador constante al elemento asociado a la clave dada
	unmap::const_iterator getIterOf(const Tclave &clave) const {
		auto it = unmap::find(clave);
		if (it == unmap::end())
			throw invalid_argument("Error TABLA-getIterOf-01: Elemento buscado no existente.\n");
		return it;
	}

	//Devuelve el resultado de filtrar la tabla según los criterios de la función dada
	vector<unmap::const_iterator> filtra(bool(*selector)(unmap::const_iterator, const string&),
		const string &str) const {
		vector<unmap::const_iterator> filtrado;
		for (auto it = unmap::cbegin(); it != unmap::cend(); ++it)
			if (selector(it, str))
				filtrado.push_back(it);
		return filtrado;
	}

	//Devuelve el resultado de filtrar la tabla según los criterios de la función dada
	vector<unmap::const_iterator> filtra(bool(*selector)(unmap::const_iterator, unsigned int),
		unsigned int id) const {
		vector<unmap::const_iterator> filtrado;
		for (auto it = unmap::cbegin(); it != unmap::cend(); ++it)
			if (selector(it, id))
				filtrado.push_back(it);
		return filtrado;
	}

	//Comprueba si el elemento con clave dada está en la tabla
	bool isInTable(const Tclave &clave) const {
		auto it = unmap::find(clave);
		return it != unmap::end();
	}

	//Obtiene todos los números de solicitud
	unordered_set<Tclave> getClavesTabla() const {
		auto it = unmap::begin();
		unordered_set<Tclave> claves;
		while (it != unmap::end()) {
			claves.insert(it->first);
			++it;
		}
		return claves;
	}

	//Modifica la clave del elemento de la tabla dado
	void setClave(unmap::const_iterator it, const Tclave &nuevaClave) {
		if (it == unmap::cend())
			throw invalid_argument("Error TABLA-modificaClave-01: Iterador no válido.\n");
		insertaFila(nuevaClave, it->second);
		eliminaFila(it);
	}

	//Modifica la clave dada la antigua clave
	void setClave(const Tclave &clave, const Tclave &nuevaClave) {
		auto it = getIterOf(clave);
		insertaFila(nuevaClave, it->second);
		eliminaFila(it);
	}

	//Convierte el elemento de la tabla en una cadena de caracteres
	virtual string elemToString(const Tclave &clave, const Tvalor &valor) = 0;
};

#endif // !TABLA_H