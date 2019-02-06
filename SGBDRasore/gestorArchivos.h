#ifndef GESTOR_ARCHIVOS_H
#define GESTOR_ARCHIVOS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Fecha.h"

using namespace std;

//Periodos posibles de un SICUE
enum Periodo { Cuatrimestral, Anual };

//Separador que utilizaremos para extraer y guardar datos
const string SEPARADOR = "-----";

//Transforma un entero sin signo en una cadena de caracteres
string uintToString(const unsigned int &id);

//Extrae todas las líneas del flujo abierto
void extraerLineas(ifstream &arch, vector<string> &lineas);

//Separa las líneas en cada uno de sus campos
void separateLine(const string &linea, vector<string> &lst, const string &separad);

//Transforma una cadena de caracteres en un entero sin signo
unsigned int stringToUint(const string & str);

//Transforma una fecha en una cadena de caracteres
string dateToString(const Fecha &f);

//Transforma una cadena de caracteres en una fecha válida
Fecha stringToDate(const string &str);

//Transforma un periodo en una cadena de caracteres
string periodToString(Periodo p);

//Transforma una cadena de caracteres en un periodo
Periodo stringToPeriod(const string &str);

//Analiza si la fecha introducida es correcta
bool isDateCorrect(const string &date);

//Comprueba que el string dado sea un número
bool isANumber(const string &n);

//Convierte un booleano en una cadena de caracteres
string boolToString(bool b);

//Convierte una cadena de caracteres en un booleano
bool stringToBool(const string &s);

#endif // !GESTOR_ARCHIVOS_H
