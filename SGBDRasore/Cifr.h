#ifndef CIFR_H
#define CIFR_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <fstream>

using namespace std;

const string CIFREX = "cifr.cifrex";
const string SECCP1 = "cifr_cp.cifrex";
const string SECCP2 = "sec_cp.cifrex";
const int NUMTABLAS = 4;
const int NUMVAR = 600;
const int ITER = 9;
const int GENERAL_KEY = 7;
const int INI_ASCII = int(' ');
const int FIN_ASCII = int('~');
const int ASCIICODE = int('~') + 1 - int(' ');

enum ID_TABLA {
	Estudiantes, Solicitudes, Resoluciones, SICUE
};

//Clase que gestiona el cifrado y descifrado de la base de datos completa
class Cifr : private vector<int> {
private:
	//Calcula el índice de cifrado siguiente de la misma tabla
	int sig(int index) const {
		return (index + NUMTABLAS) % (NUMTABLAS*NUMVAR);
	}

	//Calcula el índice de cifrado anterior de la misma tabla
	int ant(int index) const {
		if (index >= NUMTABLAS)
			return index - NUMTABLAS;
		else
			return NUMTABLAS * NUMVAR - (NUMTABLAS - index);
	}

	//Dado un flujo abierto, escribe en el mismo las claves del cifrado
	void saveOpenFlux(ofstream &arch) const {
		for (int i = 0; i < size(); ++i)
			arch << at(i) << '\n';
	}

	//Determina si el caracter en cuestión se encuentra dentro de la franja a cifrar
	bool isCharAdmitted(char a) const {
		return INI_ASCII <= int(a) && int(a) <= FIN_ASCII;
	}
public:
	//Constructor
	Cifr() {
		ifstream arch;
		arch.open(CIFREX);
		if (!arch.is_open())
			throw system_error(error_code(), "Error CIFR-Constructor-01: Pérdida de clave de cifrado.\n");
		importCifr(arch);
		arch.close();
		srand(time(NULL));
	}

	//Destructor
	~Cifr() {
		clear();
	}

	//Guarda en los archivos destinados a ser copia de seguridad las claves del cifrado
	void secSave() const {
		ofstream arch1, arch2;
		arch1.open(SECCP1);
		arch2.open(SECCP2);
		bool opened1 = arch1.is_open(), opened2 = arch2.is_open();
		if (opened1 && opened2) {
			saveOpenFlux(arch1);
			saveOpenFlux(arch2);
			arch1.close();
			arch2.close();
		}
		else if (opened1) {
			saveOpenFlux(arch1);
			arch1.close();
			throw system_error(error_code(), "Error CIFR-secSave-01: Archivo de copia de seguridad sec_cp corrupto\n");
		}
		else if (opened2) {
			saveOpenFlux(arch1);
			arch2.close();
			throw system_error(error_code(), "Error CIFR-secSave-02: Archivo de copia de seguridad cifr_cp corrupto.\n");
		}
		else
			throw system_error(error_code(), "Error CIFR-secSave-03: Archivos de copia de seguridad corruptos. Peligro de seguridad de los datos.\n");
	}

	//Encripta las filas de cada tabla caracter a caracter
	void encript(string &linea, int &index, const ID_TABLA &id) const {
		int resto = int(id);
		if (index >= NUMVAR)
			throw out_of_range("Error CIFR-encript-01: Índice de encriptado fuera de rango.\n");
		int ind = (index*NUMTABLAS + resto) % (NUMTABLAS*NUMVAR);
		int aux = 0;
		for (int i = 0; i < linea.size(); ++i) {
			if (isCharAdmitted(linea[i])) {
				for (int j = 0; j < ITER; ++j) {
					aux = int(linea[i]) + at(ind) + GENERAL_KEY;
					if (aux > FIN_ASCII)
						aux = INI_ASCII + aux - FIN_ASCII - 1;
					linea[i] = char(aux);
					ind = sig(ind);
				}
			}
		}
		index = (ind - resto) / NUMTABLAS;
	}

	//Desencripta las filas de cada tabla caracter a caracter
	void desencript(string &linea, int &index, const ID_TABLA &id) const {
		int resto = int(id);
		if (index >= NUMVAR)
			throw out_of_range("Error CIFR-desencript-01: Índice de desencriptado fuera de rango.\n");
		if (index == -1)
			index = NUMVAR - 1;
		int ind = (index*NUMTABLAS + resto) % (NUMTABLAS*NUMVAR);
		for (int i = linea.size() - 1; i >= 0; --i) {
			if (isCharAdmitted(linea[i])) {
				for (int j = 0; j < ITER; ++j) {
					if (linea[i] - at(ind) - GENERAL_KEY < INI_ASCII)
						linea[i] = char(FIN_ASCII - at(ind) - GENERAL_KEY + int(linea[i]) - INI_ASCII + 1);
					else
						linea[i] = char(int(linea[i]) - at(ind) - GENERAL_KEY);
					ind = ant(ind);
				}
			}
		}
		index = (ind - resto) / NUMTABLAS;
	}

	//Exporta el módulo de cifrado al flujo abierto
	void exportCifr(ofstream &f) {
		saveOpenFlux(f);
	}

	//Importa el módulo de cifrado del flujo abierto
	void importCifr(ifstream &f) {
		int aux;
		for (int i = 0; i < NUMTABLAS*NUMVAR; ++i) {
			f >> aux;
			push_back(aux);
		}
	}

	//Borra todos los datos del módulo de cifrado
	void borrarModulo() {
		clear();
	}

	//Lleva a cabo todos los procedimientos para el cierre seguro del módulo de cifrado
	void close() const {
		secSave();
		ofstream arch;
		arch.open(CIFREX);
		if (!arch.is_open())
			throw system_error(error_code(), "Error CIFR-close-01: Archivo de clave de cifrado cifr corrupto\n");
		saveOpenFlux(arch);
		arch.close();
	}

	//Renueva las claves de cifrado de la tabla correspondiente
	void updateKeys(const ID_TABLA &id) {
		int resto = int(id);
		for (int i = 0; i < NUMVAR; ++i)
			at(i*NUMTABLAS + resto) = rand() % (ASCIICODE - GENERAL_KEY - 1);
		secSave();
	}
};

#endif // !CIFR_H