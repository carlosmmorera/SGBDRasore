#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <stdexcept>

using namespace std;

const unsigned int MESES[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const unsigned int NUM_MESES = 12;
const unsigned int FEBRERO = 2;

class Fecha {
private:
	unsigned int dia;
	unsigned int mes;
	unsigned int anyo;

	bool anyoBisiesto(unsigned int a) const {
		return a % 4 == 0;
	}

	bool fechaCorrecta(unsigned int d, unsigned int m, unsigned int a) const {
		if (m > NUM_MESES || d == 0 || m == 0 || a == 0)
			return false;
		else if (m != FEBRERO || !anyoBisiesto(a))
			return d <= MESES[m - 1];
		else
			return d <= MESES[m - 1] + 1;
	}
public:
	//Constructor
	Fecha(unsigned int d, unsigned int m, unsigned int a) {
		if (!fechaCorrecta(d, m, a))
			throw invalid_argument("Error FECHA-Constructor-01: Fecha inválida.\n");
		dia = d;
		mes = m;
		anyo = a;
	}

	//Se obtiene el día
	unsigned int getDia() const {
		return dia;
	}

	//Se obtiene el mes
	unsigned int getMes() const {
		return mes;
	}

	//Se obtiene el año
	unsigned int getAnyo() const {
		return anyo;
	}

	//Da nuevos valores para la fecha
	void setFecha(unsigned int d, unsigned int m, unsigned int a) {
		if (!fechaCorrecta(d, m, a))
			throw invalid_argument("Error FECHA-Constructor-01: Fecha inválida.\n");
		dia = d;
		mes = m;
		anyo = a;
	}
};

#endif