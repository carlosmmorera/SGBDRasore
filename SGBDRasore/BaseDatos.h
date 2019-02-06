#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_set>
#include <stdexcept>
#include "Cifr.h"
#include "Conjunto.h"
#include "TEstudiantes.h"
#include "TCentros.h"
#include "TEstudios.h"
#include "TAsignaturas.h"
#include "TSolicitudes.h"
#include "TResoluciones.h"
#include "TSICUE.h"
#include "gestorArchivos.h"
using namespace std;

const string TABLE_DOC = "doc.rasr";
const string TABLE_TSOL = "typesol.rasr";
const string TABLE_TRES = "typeres.rasr";
const string TABLE_RECUR = "recur.rasr";
const string TABLE_RAMAS = "ramas.rasr";
const string TABLE_CICLOS = "ciclos.rasr";
const string TABLE_UNIVER = "univ.rasr";
const string TABLE_PROVINCIAS = "provin.rasr";

class BaseDatos {
private:
	Cifr *Encrypted;
	TEstudiantes *Students;
	TCentros *Centres;
	Conjunto *Documents;
	Conjunto *ApplicationType;
	Conjunto *ResolutionType;
	Conjunto *ResourceType;
	Conjunto *Fields;
	Conjunto *Periods;
	TEstudios *Studies;
	TAsignaturas *Subjects;
	TSolicitudes *Applications;
	TResoluciones *Resolutions;
	Conjunto *Universities;
	TSICUE *Sicue;
	string locExport;
	string locImport;

	//Comprueba si la solicitud con el identificador dado posee fecha de entrada
	bool hasEntranceDate(const unsigned int id) const {
		return Applications->getIterOf(id)->second.hasEntradaDate();
	}

	//Comprueba si la solicitud con el identificador dado posee fecha de petición de informe
	bool hasReportDate(const unsigned int id) const {
		return Applications->getIterOf(id)->second.hasInformeDate();
	}

	//Extrae los elementos repetidos en la base de datos del vector de líneas de error
	void extraeErrores(vector<string> &errorLines, vector<unsigned int> &numOfErrors) {
		bool isInTable = false;
		vector<string> errorL;
		vector<unsigned int> numOfE;
		unsigned int aux, contador = 0;;
		for (int i = 0; i < 7; ++i) {
			aux = 0;
			for (int j = 0; j < numOfErrors[i]; ++j) {
				switch (i) {
				case 0: isInTable = Centres->lineIsInTable(errorLines[contador]);
					break;
				case 1: isInTable = Studies->lineIsInTable(errorLines[contador]);
					break;
				case 2: isInTable = Students->lineIsInTable(errorLines[contador]);
					break;
				case 3: isInTable = Subjects->lineIsInTable(errorLines[contador]);
					break;
				case 4: isInTable = Sicue->lineIsInTable(errorLines[contador]);
					break;
				case 5: isInTable = Applications->lineIsInTable(errorLines[contador]);
					break;
				case 6: isInTable = Resolutions->lineIsInTable(errorLines[contador]);
					break;
				}
				if (!isInTable) {
					errorL.push_back(errorLines[contador]);
					++aux;
				}
				++contador;
			}
			numOfE.push_back(aux);
		}
		errorLines.clear();
		numOfErrors.clear();
		errorLines = errorL;
		numOfErrors = numOfE;
	}
public:
	//Constructor
	BaseDatos() {
		Encrypted = new Cifr();
		Centres = new TCentros();
		Documents = new Conjunto(TABLE_DOC);
		ApplicationType = new Conjunto(TABLE_TSOL);
		ResolutionType = new Conjunto(TABLE_TRES);
		ResourceType = new Conjunto(TABLE_RECUR);
		Fields = new Conjunto(TABLE_RAMAS);
		Periods = new Conjunto(TABLE_CICLOS);
		Studies = new TEstudios(*Centres, *Periods, *Fields);
		Students = new TEstudiantes(*Encrypted, *Studies);
		Subjects = new TAsignaturas(*Studies);
		Applications = new TSolicitudes(*Encrypted, *Subjects, *Students, *ApplicationType, *Documents);
		Resolutions = new TResoluciones(*Encrypted, *Students, *Applications, *ResolutionType, *ResourceType);
		Universities = new Conjunto(TABLE_UNIVER);
		Sicue = new TSICUE(*Encrypted, *Universities);
		locExport = "";
		locImport = "";
	}

	//Destructor
	~BaseDatos() {
		saveDataBase();
		delete Resolutions;
		delete Applications;
		delete Sicue;
		delete Universities;
		delete Subjects;
		delete Students;
		delete Studies;
		delete Periods;
		delete Fields;
		delete ResourceType;
		delete ApplicationType;
		delete Documents;
		delete Centres;
		delete Encrypted;
	}

	//Modifica la localización de la exporación
	void setLocationExport(const string &l) {
		locExport = l;
	}

	//Modifica la localización de la importación por la dada
	void setLocationImport(const string &l) {
		locImport = l;
	}

	//Devuelve la localización de exportación actual
	string getLocationExport() const  {
		return locExport;
	}

	//Devuelve la localización de la importación actual
	string getLocationImport() const {
		return locImport;
	}

	//Exporta la base de datos al archivo dado
	void exportDataBase()  {
		ofstream arch;
		arch.open(locExport);
		if (!arch.is_open())
			throw invalid_argument("Error BASEDATOS-exportDataBase-01: No se ha podido abrir el archivo al que exportar.\n");
		Encrypted->exportCifr(arch);
		Centres->exportTable(arch);
		Documents->exportSet(arch);
		ApplicationType->exportSet(arch);
		ResourceType->exportSet(arch);
		Fields->exportSet(arch);
		Periods->exportSet(arch);
		Studies->exportTable(arch);
		Students->exportTable(arch);
		Subjects->exportTable(arch);
		Universities->exportSet(arch);
		Sicue->exportTable(arch);
		Applications->exportTable(arch);
		Resolutions->exportTable(arch);
		arch.close();
	}

	/*
	* Importa la base de datos del archivo dado devolviendo el vector de aquellas líneas que no se han
	* podido insertar y el número de líneas erróneas de cada tabla con las siguientes posiciones:
	* 
	* - 0: Centros
	* - 1: Titulaciones
	* - 2: Estudiantes
	* - 3: Asignaturas
	* - 4: SICUE
	* - 5: Solicitudes
	* - 6: Resoluciones
	*/
	void importDataBase(vector<string> &errorLines, vector<unsigned int> &numOfErrors) {
		ifstream arch;
		arch.open(locImport);
		if (!arch.is_open())
			throw invalid_argument("Error BASEDATOS-importDataBase-01: No se ha podido abrir el archivo del que importar.\n");
		
		Encrypted->borrarModulo();
		Encrypted->importCifr(arch);
		
		unsigned int acum = 0;
		Centres->importCentres(arch, errorLines);
		numOfErrors.push_back(errorLines.size() - acum);
		acum = errorLines.size();

		Documents->importSet(arch);
		ApplicationType->importSet(arch);
		ResourceType->importSet(arch);
		Fields->importSet(arch);
		Periods->importSet(arch);

		Studies->importStudies(arch, errorLines);
		numOfErrors.push_back(errorLines.size() - acum);
		acum = errorLines.size();

		Students->importStudents(arch, errorLines);
		numOfErrors.push_back(errorLines.size() - acum);
		acum = errorLines.size();

		Subjects->importSubjects(arch, errorLines);
		numOfErrors.push_back(errorLines.size() - acum);
		acum = errorLines.size();

		Universities->importSet(arch);

		Sicue->importSicue(arch, errorLines);
		numOfErrors.push_back(errorLines.size() - acum);
		acum = errorLines.size();

		Applications->importApplications(arch, errorLines);
		numOfErrors.push_back(errorLines.size() - acum);
		acum = errorLines.size();

		Resolutions->importResolutions(arch, errorLines);
		numOfErrors.push_back(errorLines.size() - acum);
		acum = errorLines.size();
		arch.close();

		extraeErrores(errorLines, numOfErrors);
	}

	//Inserta las líneas de error creadas al importar quitando las coincidencias
	void insertErrorLines(const vector<string> &errorLines, const vector<unsigned int> &numOfErrors) {
		//por hacer
	}

	//Vacía la base de datos
	void clearDataBase() {
		Resolutions->borrarTabla();
		Applications->borrarTabla();
		Sicue->borrarTabla();
		Universities->clear();
		Subjects->borrarTabla();
		Students->borrarTabla();
		Studies->borrarTabla();
		Periods->clear();
		Fields->clear();
		ResourceType->clear();
		ApplicationType->clear();
		Documents->clear();
		Centres->borrarTabla();
	}

	//Recarga todas las tablas de la base de datos
	void reloadDataBase() {
		delete Resolutions;
		delete Applications;
		delete Sicue;
		delete Universities;
		delete Subjects;
		delete Students;
		delete Studies;
		delete Periods;
		delete Fields;
		delete ResourceType;
		delete ApplicationType;
		delete Documents;
		delete Centres;
		delete Encrypted;
		Encrypted = new Cifr();
		Centres = new TCentros();
		Documents = new Conjunto(TABLE_DOC);
		ApplicationType = new Conjunto(TABLE_TSOL);
		ResolutionType = new Conjunto(TABLE_TRES);
		ResourceType = new Conjunto(TABLE_RECUR);
		Fields = new Conjunto(TABLE_RAMAS);
		Periods = new Conjunto(TABLE_CICLOS);
		Studies = new TEstudios(*Centres, *Periods, *Fields);
		Students = new TEstudiantes(*Encrypted, *Studies);
		Subjects = new TAsignaturas(*Studies);
		Applications = new TSolicitudes(*Encrypted, *Subjects, *Students, *ApplicationType, *Documents);
		Resolutions = new TResoluciones(*Encrypted, *Students, *Applications, *ResolutionType, *ResourceType);
		Universities = new Conjunto(TABLE_UNIVER);
		Sicue = new TSICUE(*Encrypted, *Universities);
	}

	//Obtiene los datos del estudiante con dni dado y si es sicue o no
	vector<string> getStudentData(const string &dni, bool &isSicue) {
		auto it = Students->getIterOf(dni);
		vector<string> lst;
		lst.push_back(it->second.Nombre);
		lst.push_back(it->second.Apellido1);
		lst.push_back(it->second.Apellido2);
		lst.push_back(it->second.Email);
		lst.push_back(it->second.Telefono);
		lst.push_back(it->second.Direccion);
		lst.push_back(it->second.Localidad);
		lst.push_back(it->second.CP);
		lst.push_back(it->second.Provincia);
		lst.push_back(it->second.Pais);
		lst.push_back(Studies->getIterOf(it->second.Estudios)->second.Nombre);
		lst.push_back(it->second.Observaciones);
		lst.push_back(uintToString(it->second.Id));
		isSicue = isStudentSicue(dni);
		return lst;
	}

	//Obtiene los datos del estudiante SICUE con el dni dado
	vector<string> getSicueData(const string &dni, bool &beca) {
		auto it = Sicue->getIterOf(dni);
		vector<string> lst;
		lst.push_back(*(it->second.univ_origen));
		lst.push_back(*(it->second.univ_destino));
		lst.push_back(it->second.estudios_analogos);
		lst.push_back(periodToString(it->second.periodo));
		lst.push_back(it->second.campus);
		beca = it->second.beca;
		return lst;
	}

	//Obtiene los datos de la solicitud con el dni dado
	vector<string> getApplicationData(const string &dni) {
		auto v = Applications->filtra([](unordered_map<unsigned int, Solicitud_valor>::const_iterator it, const string
			&str) {
			return *(it->second.DNI) == str;
		}, dni);
		vector<string> lst;
		lst.push_back(uintToString(v[0]->first));
		lst.push_back(*(v[0]->second.Tipo));
		string asignaturas = "";
		for (int i = 0; i < v[0]->second.Asignaturas.size(); ++i)
			asignaturas += getSubjectName(v[0]->second.Asignaturas[i]) + ";";
		lst.push_back(asignaturas);
		if (hasEntranceDate(v[0]->first))
			lst.push_back(dateToString(v[0]->second.Entrada));
		else
			lst.push_back("");
		if (hasReportDate(v[0]->first))
			lst.push_back(dateToString(v[0]->second.Informe));
		else
			lst.push_back("");
		lst.push_back(Centres->getIterOf(v[0]->second.Centro)->second.Nombre);
		lst.push_back(v[0]->second.Observaciones);
		lst.push_back(*(v[0]->second.Documentacion));
		return lst;
	}

	//Obtiene los datos de la resolución con el id de solicitud dado
	vector<string> getResolData(unsigned int id) {
		auto v = Resolutions->filtra([](unordered_map<unsigned int, Resolucion_valor>::const_iterator it, unsigned int
			sol) {
			return *(it->second.Solicitud) == sol;
		}, id);
		vector<string> resData;
		resData.push_back(uintToString(v[0]->first));
		if (v[0]->second.hasFirmaDate())
			resData.push_back(dateToString(v[0]->second.Firma));
		else
			resData.push_back("");
		if (v[0]->second.hasSalidaDate())
			resData.push_back(dateToString(v[0]->second.Salida));
		else
			resData.push_back("");
		resData.push_back(*(v[0]->second.TipoRecurso));
		resData.push_back(*(v[0]->second.Tipo));
		resData.push_back(v[0]->second.Observaciones);
		return resData;
	}

	//Obtiene los datos del centro con el id dado
	vector<string> getCentreData(unsigned int id) {
		auto it = Centres->getIterOf(id);
		vector<string> lst;
		lst.push_back(it->second.Nombre);
		lst.push_back(it->second.Cargo);
		lst.push_back(it->second.Direccion);
		lst.push_back(it->second.Localidad);
		lst.push_back(it->second.CP);
		lst.push_back(it->second.CargoAdmin);
		lst.push_back(it->second.TlfSecretaria);
		return lst;
	}

	//Obtiene los datos de la titulación con el id dado
	vector<string> getStudyData(unsigned int id) {
		auto it = Studies->getIterOf(id);
		vector<string> lst;
		lst.push_back(it->second.IdRuct);
		lst.push_back(it->second.Nombre);
		lst.push_back(getCentreName(it->second.centroId));
		lst.push_back(*(it->second.Ciclo));
		lst.push_back(*(it->second.Rama));
		return lst;
	}

	//Obtiene el identificador del estudio del estudiante cuyo DNI es el dado
	unsigned int getStudyOfStudent(const string &dni) const {
		try {
			auto it = Students->getIterOf(dni);
			return it->second.Estudios;
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			throw invalid_argument(mensaje + "Error BASEDATOS-getStudyOfStudent-01: El DNI no corresponde a ningún estudiante registrado en la base de datos.");
		}
	}

	//Obtiene el identificador del centro cuyo nombre es el dado
	unsigned int getCentreId(const string &name) {
		auto v = Centres->filtra([](unordered_map<unsigned int, Centros_valor>::const_iterator it, const string
			&str) {
			return it->second.Nombre == str;
		}, name);
		return v[0]->first;
	}

	//Obtiene el nombre del centro cuyo id es el dado
	string getCentreName(unsigned int id) {
		auto ite = Centres->getIterOf(id);
		return ite->second.Nombre;
	}

	//Obtiene el nombre de la asignatura cuyo id es el dado
	string getSubjectName(unsigned int id) {
		return Subjects->getIterOf(id)->second.Nombre;
	}

	//Obtiene el nombre del estudio con el id dado
	string getStudyName(unsigned int id) {
		return Studies->getIterOf(id)->second.Nombre;
	}

	//Obtiene el identificador de la titulación cuyo nombre es el dado
	unsigned int getStudyID(const string &name) {
		auto v = Studies->filtra([](unordered_map<unsigned int, Estudios_valor>::const_iterator it, const string
			&str) {
			return it->second.Nombre == str;
		}, name);
		return v[0]->first;
	}

	//Comprueba si el DNI dado ha presentado una solicitud
	bool isThereAnApplication(const string &dni) {
		auto v = Applications->filtra([](unordered_map<unsigned int, Solicitud_valor>::const_iterator it, const string
			&str) {
			return *(it->second.DNI) == str;
		}, dni);
		return v.size() > 0;
	}

	//Comprueba si la solicitud con id dado posee una resolución
	bool isThereAResolution(unsigned int sol) {
		auto v = Resolutions->filtra([](unordered_map<unsigned int, Resolucion_valor>::const_iterator it, unsigned int
			s) {
			return *(it->second.Solicitud) == s;
		}, sol);
		return v.size() > 0;
	}

	//Comprueba si hay un centro con el identificador dado
	bool isUsedCentreId(const unsigned int id) const {
		return Centres->isInTable(id);
	}

	//Comprueba si hay una titulación con el id dado
	bool isUsedStudyId(const unsigned int id) const {
		return Studies->isInTable(id);
	}

	//Comprueba si el estudiante con el dni dado es un estudiante SICUE
	bool isStudentSicue(const string &dni) const {
		return Sicue->isInTable(dni);
	}

	//Obtiene todos los estudios almacenados en la base de datos
	void getStudies(vector<string> &lst) {
		Studies->getAllNames(lst);
		sort(lst.begin(), lst.end());
	}

	//Obtiene los nombres de todas las universidades
	vector<string> getUniversities() const {
		auto it = Universities->begin();
		vector<string> lst;
		while (it != Universities->end()) {
			lst.push_back(*it);
			++it;
		}
		sort(lst.begin(), lst.end());
		return lst;
	}

	//Obtiene los nombres de todas las provincias
	vector<string> getProvinces() const {
		ifstream prov;
		int numProv;
		prov.open(TABLE_PROVINCIAS);
		if (!prov.is_open())
			throw invalid_argument("Error BASEDATOS-getProvinces-01: No se ha podido abrir el archivo de las provincias.\n");
		prov >> numProv;
		vector<string> lst(numProv);
		for (int i = 0; i < numProv; ++i)
			prov >> lst[i];
		sort(lst.begin(), lst.end());
		prov.close();
		return lst;
	}

	//Obtiene todos los dnis de los estudiantes
	unordered_set<string> getDNIS() const {
		return Students->getClavesTabla();
	}

	//Obtiene los nombres de todas las ramas
	vector<string> getFields() const {
		auto it = Fields->begin();
		vector<string> lst;
		while (it != Fields->end()) {
			lst.push_back(*it);
			++it;
		}
		sort(lst.begin(), lst.end());
		return lst;
	}

	//Obtiene todos los ciclos
	vector<string> getPeriods() const {
		auto it = Periods->begin();
		vector<string> lst;
		while (it != Periods->end()) {
			lst.push_back(*it);
			++it;
		}
		sort(lst.begin(), lst.end());
		return lst;
	}

	//Obtiene todos los tipos de solicitud
	vector<string> getApplicationTypes() const {
		auto it = ApplicationType->begin();
		vector<string> lst;
		while (it != ApplicationType->end()) {
			lst.push_back(*it);
			++it;
		}
		sort(lst.begin(), lst.end());
		return lst;
	}

	//Obtiene los nombres de todos los centros
	vector<string> getCentres() const {
		return Centres->getAllNames();
	}

	//Obtiene todos los tipos de documentación
	vector<string> getDocumentation() const {
		auto it = Documents->begin();
		vector<string> lst;
		while (it != Documents->end()) {
			lst.push_back(*it);
			++it;
		}
		sort(lst.begin(), lst.end());
		return lst;
	}

	//Obtiene todos los tipos de resoluciones
	vector<string> getResolutionTypes() const {
		auto it = ResolutionType->begin();
		vector<string> lst;
		while (it != ResolutionType->end()) {
			lst.push_back(*it);
			++it;
		}
		sort(lst.begin(), lst.end());
		return lst;
	}

	//Obtiene todos los tipos de recursos
	vector<string> getResourceTypes() const{
		auto it = ResourceType->begin();
		vector<string> lst;
		while (it != ResourceType->end()) {
			lst.push_back(*it);
			++it;
		}
		sort(lst.begin(), lst.end());
		return lst;
	}

	//Obtiene los números de todas las solicitudes que no tienen resolución
	vector<string> getAppWithoutRes() const {
		unordered_set<unsigned int> numApp = Applications->getClavesTabla();
		unordered_set<unsigned int> numRes = Resolutions->getClavesTabla();
		auto it = numRes.begin();
		while (it != numRes.end()) {
			auto res = Resolutions->getIterOf(*it);
			numApp.erase(*(res->second.Solicitud));
			++it;
		}
		vector<string> result;
		auto ite = numApp.begin();
		while (ite != numApp.end()) {
			result.push_back(uintToString(*ite));
			++ite;
		}
		return result;
	}

	//Obtiene los números de todas las resoluciones
	unordered_set<unsigned int> getResolIds() const {
		return Resolutions->getClavesTabla();
	}

	//Inserta los datos de un nuevo estudiantes en la base de datos y devuelve el identificador del estudiante insertado
	unsigned int insertStudent(const string &dni, const string &name, const string &surname1, const string
		&surname2, const string &phone, const string &email, const string &address, const string
		&locality, const string &CP, const string &province, const string &country, const string
		&observations, const string &study) {
		int id = Students->getSize() + 1;
		auto v = Studies->filtra([](unordered_map<unsigned int, Estudios_valor>::const_iterator it,
			const string &std) {
			return it->second.Nombre == std;
		}, study);
		
		if (v.size() == 0)
			throw invalid_argument("Error BASEDATOS-insertStudent-01: Estudio buscado no existente.\n");
		else if (v.size() > 1)
			throw invalid_argument("Error BASEDATOS-insertStudent-02: Estudio duplicado.\n");

		unsigned int studiesId = v[0]->first;
		Estudiante_valor val(name, surname1, studiesId, *Studies, id, surname2, phone, email, 
			address, locality, CP, province, country, observations);
		Students->insertaFila(dni, val);
		return id;
	}

	//Inserta una fila en la tabla SICUE
	void insertSICUE(const string &dni, const string &uni_o, const string &uni_d, const string
		&estud, const string &campus, bool beca, const string &periodo) {
		SICUE_valor val(uni_o, uni_d, estud, *Universities, campus, beca, stringToPeriod(periodo));
		Sicue->insertaFila(dni, val);
	}

	//Inserta una nueva universidad
	void insertUniversity(const string &name) {
		Universities->insertaElem(name);
	}

	//Inserta un nuevo tipo de solicitud
	void insertApplicationType(const string &type) {
		ApplicationType->insertaElem(type);
	}

	//Inserta un nuevo tipo de resolución
	void insertResolutionType(const string &type) {
		ResolutionType->insertaElem(type);
	}

	//Inserta un nuevo tipo de recurso
	void insertResourceType(const string &type) {
		ResourceType->insertaElem(type);
	}

	//Inserta un nuevo tipo de documentación
	void insertDocumentation(const string &doc) {
		Documents->insertaElem(doc);
	}

	//Inserta una nueva titulación
	void insertStudies(unsigned int id, const string &idR, const string &name, const string &centro, const string
	&ciclo, const string &rama) {
		auto v = Centres->filtra([](unordered_map<unsigned int, Centros_valor>::const_iterator it,
			const string &str) {
			return it->second.Nombre == str;
		}, centro);

		if (v.size() == 0)
			throw invalid_argument("Error BASEDATOS-insertStudies-01: Centro buscado no existente.\n");
		else if (v.size() > 1)
			throw invalid_argument("Error BASEDATOS-insertStudies-02: Centro duplicado.\n");

		unsigned int c = v[0]->first;

		Estudios_valor val(idR, name, c, ciclo, rama, *Centres, *Periods, *Fields);
		Studies->insertaFila(id, val);
	}

	//Inserta un nuevo centro
	void insertCentre(unsigned int id, const string &nombre, const string &cargo, const string &dir, const string
	&localidad, const string &CP, const string &cadmin, const string &tlf) {
		Centros_valor val(nombre, cargo, dir, localidad, CP, cadmin, tlf);
		Centres->insertaFila(id, val);
	}

	//Inserta un nuevo ciclo
	void insertPeriod(const string &p) {
		Periods->insertaElem(p);
	}

	//Inserta una nueva rama
	void insertField(const string &f) {
		Fields->insertaElem(f);
	}

	//Inserta una nueva solicitud y devuelve el identificador de la solicitud insertada
	unsigned int insertApplication(const string &dni, const string &tipo, const string &entrada, const string &informe,
		const string &centro, const string &observ, const string &asignaturas, unsigned int estudio, const
		string &doc){
		auto v = Centres->filtra([](unordered_map<unsigned int, Centros_valor>::const_iterator it,
			const string &str) {
			return it->second.Nombre == str;
		}, centro);

		if (v.size() == 0)
			throw invalid_argument("Error BASEDATOS-insertStudies-01: Centro buscado no existente.\n");
		else if (v.size() > 1)
			throw invalid_argument("Error BASEDATOS-insertStudies-02: Centro duplicado.\n");

		unsigned int c = v[0]->first;
		int id = Applications->getSize() + 1;
		if (entrada != "" && informe != "") {
			Solicitud_valor val(dni, tipo, doc, stringToDate(entrada), stringToDate(informe), c, observ, *Students,
				*ApplicationType, *Documents);
			Applications->insertaFila(id, val);
		}
		else {
			Solicitud_valor val(dni, tipo, doc, c, observ, *Students, *ApplicationType, *Documents);
			if (entrada != "")
				val.setEntrada(stringToDate(entrada));
			if (informe != "")
				val.setInforme(stringToDate(informe));
			Applications->insertaFila(id, val);
		}

		//Separamos las asignaturas
		vector<string> asig;
		string aux = "";
		for (int i = 0; i < asignaturas.size(); ++i) {
			if (asignaturas[i] != ';')
				aux += asignaturas[i];
			else {
				asig.push_back(aux);
				aux = "";
			}
		}
		if (asignaturas.size() > 0 && asignaturas[asignaturas.size() - 1] != ';')
			asig.push_back(aux);

		//Incluimos cada asignatura en la solicitud
		for (int i = 0; i < asig.size(); ++i) {
			//Busco todas las asignaturas con el mismo nombre
			auto v = Subjects->filtra([](unordered_map<unsigned int, Asignaturas_valor>::const_iterator it, const
				string &nombre) {
				return it->second.Nombre == nombre;
			}, asig[i]);
			int j = 0;
			//Busco alguna que este asociada a la misma titulación
			while (j < v.size() && !(v[j]->second.Estudio == estudio))
				++j;
			int idSubject;
			//Si no la encuentro la añado a la tabla de asignaturas
			if (j == v.size()) {
				idSubject = Subjects->getSize();
				Asignaturas_valor valor(asig[i], estudio, *Studies);
				Subjects->insertaFila(idSubject, valor);
			}
			//Si la encuentro obtengo su identificador
			else
				idSubject = v[j]->first;
			Applications->addSubject(id, idSubject);
		}
		return id;
	}

	//Inserta una nueva resolución y devuelve el identificador de la resolución insertada
	unsigned int insertResolution(unsigned int nSol, const string &firma, const string &salida, const string &res,
		const string &rec, const string &obser) {
		string dni = *(Applications->getIterOf(nSol)->second.DNI);
		unsigned int id = Resolutions->getSize() + 1;
		if (firma != "" && salida != "") {
			Resolucion_valor val(dni, nSol, res, stringToDate(firma), stringToDate(salida), rec, obser, *Students,
				*Applications, *ResolutionType, *ResourceType);
			Resolutions->insertaFila(id, val);
		}
		else {
			Resolucion_valor val(dni, nSol, res, rec, obser, *Students,	*Applications, *ResolutionType, *ResourceType);
			if (firma != "")
				val.setFirma(stringToDate(firma));
			if (salida != "")
				val.setSalida(stringToDate(salida));
			Resolutions->insertaFila(id, val);
		}
		return id;
	}

	//Actualiza en las tablas que dependen del dato el campo de identificador de centro si este se cambia
	void modifyCentreId(unsigned int oldId, unsigned int newId) {
		auto vStud = getStudiesInCentre(oldId);
		for (int i = 0; i < vStud.size(); ++i)
			Studies->setValor(vStud[i]->first, newId);
		auto vSolic = getAppToCentre(oldId);
		for (int i = 0; i < vSolic.size(); ++i)
			Applications->setValor(vSolic[i]->first, newId);
	}

	//Actualiza la tabla de asignaturas cuando se modifica la titulación en la que se encuentran
	void modifyStudyInSubjects(unsigned int oldStudy, unsigned int newStudy) {
		auto vSubjects = Subjects->filtra([](unordered_map<unsigned int, Asignaturas_valor>::const_iterator it,
			unsigned int estudios) {
			return it->second.Estudio == estudios;
		}, oldStudy);
		for (int i = 0; i < vSubjects.size(); ++i)
			Subjects->setValor(vSubjects[i]->first, newStudy);
	}

	//Actualiza en las tablas que dependen del dato el campo de identificador de estudio si este se cambia
	void modifyStudyId(unsigned int oldId, unsigned int newId) {
		auto vStudents = Students->filtra([](unordered_map<string, Estudiante_valor>::const_iterator it, unsigned
			int estudios) {
			return it->second.Estudios == estudios;
		}, oldId);
		for (int i = 0; i < vStudents.size(); ++i)
			Students->setValor(vStudents[i]->first, newId);
		modifyStudyInSubjects(oldId, newId);
	}

	//Elimina el estudiante con el DNI dado
	void deleteStudent(const string &dni) {
		Students->eliminaFila(dni);
	}

	//Elimina el estudiante SICUE con el DNI dado
	void deleteSICUE(const string &dni) {
		Sicue->eliminaFila(dni);
	}

	//Elimina el centro del código dado
	void deleteCentre(unsigned int code) {
		Centres->eliminaFila(code);
	}

	//Elimina el tipo de solicitud dado
	void deleteTypeOfApp(const string &type) {
		ApplicationType->eliminaElem(type);
	}

	//Elimina el tipo de documentación dado
	void deleteDocumentation(const string &d) {
		Documents->eliminaElem(d);
	}

	//Elimina la titulación con el código dado
	void deleteStudies(unsigned int id) {
		Studies->eliminaFila(id);
	}

	//Elimina toda la tabla de estudiantes
	void dropTableStudents() {
		Students->borrarTabla();
		Sicue->borrarTabla();
	}

	//Elimina toda la tabla de solicitudes
	void dropTableApplications() {
		Applications->borrarTabla();
	}

	//Elimina toda la tabla de resoluciones
	void dropTableResolution() {
		Resolutions->borrarTabla();
	}

	//Obtiene todos los estudios que se llevan a cabo en el centro con id dada
	vector<unordered_map<unsigned int, Estudios_valor>::const_iterator> getStudiesInCentre(unsigned int id) const {
		return Studies->filtra([](unordered_map<unsigned int, Estudios_valor>::const_iterator it, unsigned
			int centro) {
			return it->second.centroId == centro;
		}, id);
	}

	//Obtiene todas las solicitudes registradas en el centro con id dada
	vector<unordered_map<unsigned int, Solicitud_valor>::const_iterator> getAppToCentre(unsigned int id) const {
		return Applications->filtra([](unordered_map<unsigned int, Solicitud_valor>::const_iterator it, unsigned
			int centro) {
			return it->second.Centro == centro;
		}, id);
	}

	//Obtiene todas las solicitudes registradas del tipo dado
	vector<unordered_map<unsigned int, Solicitud_valor>::const_iterator> getAppOfType(const string &t) const {
		return Applications->filtra([](unordered_map<unsigned int, Solicitud_valor>::const_iterator it, const
			string &tipo) {
			return *it->second.Tipo == tipo;
		}, t);
	}

	//Obtiene todas las solicitudes registradas con la documentación dada
	vector<unordered_map<unsigned int, Solicitud_valor>::const_iterator> getAppWithDoc(const string &d) const {
		return Applications->filtra([](unordered_map<unsigned int, Solicitud_valor>::const_iterator it, const
			string &doc) {
			return *it->second.Documentacion == doc;
		}, d);
	}

	//Obtiene todos los estudiantes que cursan el estudio con el id dado
	vector<unordered_map<string, Estudiante_valor>::const_iterator> getStudentsStudying(unsigned int study) const {
		return Students->filtra([](unordered_map<string, Estudiante_valor>::const_iterator it, unsigned int
			st) {
			return it->second.Estudios == st;
		}, study);
	}

	//Obtiene todas las solicitudes del estudiante con el dni dado
	vector<unordered_map<unsigned int, Solicitud_valor>::const_iterator> getAppFromStudent(const string &dni) const {
		return Applications->filtra([](unordered_map<unsigned int, Solicitud_valor>::const_iterator it, const
			string &d) {
			return *it->second.DNI == d;
		}, dni);
	}

	//Obtiene todas las resoluciones del estudiante con el dni dado
	vector<unordered_map<unsigned int, Resolucion_valor>::const_iterator> getResolFromStudent(const string &dni) const {
		return Resolutions->filtra([](unordered_map<unsigned int, Resolucion_valor>::const_iterator it, const
			string &d) {
			return *it->second.DNI == d;
		}, dni);
	}

	//Modifica el centro en el estudio con id dado
	void setCentreInStudy(unsigned int id,  unsigned int centre) {
		Studies->setValor(id, centre);
	}

	//Modifica el centro en la solicitud con id dado
	void setCentreInApplication(unsigned int id, unsigned int centre) {
		Applications->setValor(id, centre);
	}

	//Modifica el tipo en la solicitud con id dado
	void setTypeInApplication(unsigned int id, const string &type) {
		Applications->setValor(id, "Tipo", type);
	}

	//Modifica la documentación de la solicitud con id dado
	void setDocInApplication(unsigned int id, const string &doc) {
		Applications->setValor(id, "Documentación", doc);
	}

	//Modifica la titulación que estudia el estudiante con dni dado
	void setStudyInStudent(const string &dni, unsigned int study) {
		Students->setValor(dni, study);
	}

	//Modifica la titulación de la asignatura con id dado
	void setStudyOfSubject(unsigned int idSub, unsigned int study) {
		Subjects->setValor(idSub, study);
	}

	//Lleva a cabo todas las funciones necesarias para cerrar correctamente la base de datos
	void saveDataBase() {
		Students->close();
		Centres->close();
		Documents->close();
		ApplicationType->close();
		ResolutionType->close();
		ResourceType->close();
		Fields->close();
		Periods->close();
		Studies->close();
		Subjects->close();
		Applications->close();
		Resolutions->close();
		Universities->close();
		Sicue->close();
		Encrypted->close();
	}
};
#endif