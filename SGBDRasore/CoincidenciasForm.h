#ifndef COINCIDENCIASFORM_H
#define COINCIDENCIASFORM_H

#include <iostream>
#include <string>
#include <vector>
#include "BaseDatos.h"
#include "gestorArchivos.h"
#include "addStudiesForm.h"
#include "GrabarSolicitud.h"
#include "GrabarEstudiante.h"
#include "errorDialog.h"

enum ELIM_VAL {
	CENTRO_ELEM, TITUL_ELEM, SOLIC_ELEM, RESOLU_ELEM, RECURSO_ELEM, DOC_ELEM
};

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de CoincidenciasForm
	/// </summary>
	public ref class CoincidenciasForm : public System::Windows::Forms::Form
	{
	public:
		CoincidenciasForm(void)
		{
			InitializeComponent();
		}

		CoincidenciasForm(BaseDatos &base, bool &b, string &selected, ELIM_VAL e,
			vector<unordered_map<unsigned int, Estudios_valor>::const_iterator> &v) {
			InitializeComponent();
			bd = &base;
			modificado = &b;
			tipoElim = e;
			*modificado = false;
			vStudies = &v;
			vApplies = nullptr;
			vStudents = nullptr;
			string mensaje = (string) "Se han encontrado " + uintToString(vStudies->size())  + 
				" titulaciones que poseen el valor eliminado.\nSeleccione el valor por el " 
				+ "que lo quiere sustituir y pulse\n'Modificar todos' o  modifíquelos individualmente.";
			this->Textlabel->Text = gcnew String(mensaje.c_str());
			vector<string> comboBoxElem;
			switch (tipoElim){
			case CENTRO_ELEM:
				comboBoxElem = this->bd->getCentres();
				break;
			}
			for (int i = 0; i < comboBoxElem.size(); ++i)
				if (comboBoxElem[i] != selected)
					this->comboBox->Items->Add(gcnew String(comboBoxElem[i].c_str()));
		}

		CoincidenciasForm(BaseDatos &base, bool &b, string &selected, ELIM_VAL e,
			vector<unordered_map<unsigned int, Solicitud_valor>::const_iterator> &v) {
			InitializeComponent();
			bd = &base;
			modificado = &b;
			tipoElim = e;
			*modificado = false;
			vStudies = nullptr;
			vApplies = &v;
			vStudents = nullptr;
			string mensaje = (string) "Se han encontrado " + uintToString(vApplies->size()) +
				" solicitudes que poseen el valor eliminado.\nSeleccione el valor por el "
				+ "que lo quiere sustituir y pulse\n'Modificar todos' o  modifíquelos individualmente.";
			this->Textlabel->Text = gcnew String(mensaje.c_str());
			vector<string> comboBoxElem;
			switch (tipoElim) {
			case CENTRO_ELEM:
				comboBoxElem = this->bd->getCentres();
				break;
			case SOLIC_ELEM:
				comboBoxElem = this->bd->getApplicationTypes();
				break;
			case DOC_ELEM:
				comboBoxElem = this->bd->getDocumentation();
				break;
			}
			for (int i = 0; i < comboBoxElem.size(); ++i)
				if (comboBoxElem[i] != selected)
					this->comboBox->Items->Add(gcnew String(comboBoxElem[i].c_str()));
		}

		CoincidenciasForm(BaseDatos &base, bool &b, string &selected, ELIM_VAL e,
			vector<unordered_map<string, Estudiante_valor>::const_iterator> &v) {
			InitializeComponent();
			bd = &base;
			modificado = &b;
			tipoElim = e;
			*modificado = false;
			vStudies = nullptr;
			vApplies = nullptr;
			vStudents = &v;
			string mensaje = (string) "Se han encontrado " + uintToString(vStudents->size()) +
				" estudiantes que estudian la titulación eliminada.\nSeleccione el valor por el "
				+ "que lo quiere sustituir y pulse\n'Modificar todos' o  modifíquelos individualmente.";
			this->Textlabel->Text = gcnew String(mensaje.c_str());
			vector<string> comboBoxElem;
			switch (tipoElim) {
			case TITUL_ELEM:
				this->bd->getStudies(comboBoxElem);
				break;
			}
			for (int i = 0; i < comboBoxElem.size(); ++i)
				if (comboBoxElem[i] != selected)
					this->comboBox->Items->Add(gcnew String(comboBoxElem[i].c_str()));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~CoincidenciasForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		BaseDatos *bd;
		vector<unordered_map<unsigned int, Estudios_valor>::const_iterator> *vStudies;
		vector<unordered_map<unsigned int, Solicitud_valor>::const_iterator> *vApplies;
		vector<unordered_map<string, Estudiante_valor>::const_iterator> *vStudents;
		bool *modificado;
		ELIM_VAL tipoElim;
	private: System::Windows::Forms::Button^  ModIndividButton;
	private: System::Windows::Forms::Button^  ModAllbutton;

	private: System::Windows::Forms::Label^  Textlabel;
	private: System::Windows::Forms::ComboBox^  comboBox;


			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CoincidenciasForm::typeid));
			this->ModIndividButton = (gcnew System::Windows::Forms::Button());
			this->ModAllbutton = (gcnew System::Windows::Forms::Button());
			this->Textlabel = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// ModIndividButton
			// 
			this->ModIndividButton->Location = System::Drawing::Point(324, 162);
			this->ModIndividButton->Name = L"ModIndividButton";
			this->ModIndividButton->Size = System::Drawing::Size(210, 34);
			this->ModIndividButton->TabIndex = 0;
			this->ModIndividButton->Text = L"Modificar individualmente";
			this->ModIndividButton->UseVisualStyleBackColor = true;
			this->ModIndividButton->Click += gcnew System::EventHandler(this, &CoincidenciasForm::ModIndividButton_Click);
			// 
			// ModAllbutton
			// 
			this->ModAllbutton->Location = System::Drawing::Point(141, 162);
			this->ModAllbutton->Name = L"ModAllbutton";
			this->ModAllbutton->Size = System::Drawing::Size(153, 34);
			this->ModAllbutton->TabIndex = 1;
			this->ModAllbutton->Text = L"Modificar todos";
			this->ModAllbutton->UseVisualStyleBackColor = true;
			this->ModAllbutton->Click += gcnew System::EventHandler(this, &CoincidenciasForm::ModAllbutton_Click);
			// 
			// Textlabel
			// 
			this->Textlabel->AutoSize = true;
			this->Textlabel->Location = System::Drawing::Point(37, 22);
			this->Textlabel->Name = L"Textlabel";
			this->Textlabel->Size = System::Drawing::Size(51, 20);
			this->Textlabel->TabIndex = 2;
			this->Textlabel->Text = L"label1";
			// 
			// comboBox
			// 
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Location = System::Drawing::Point(41, 112);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(493, 28);
			this->comboBox->Sorted = true;
			this->comboBox->TabIndex = 3;
			// 
			// CoincidenciasForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 216);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->Textlabel);
			this->Controls->Add(this->ModAllbutton);
			this->Controls->Add(this->ModIndividButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CoincidenciasForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Advertencia de coincidencias";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &CoincidenciasForm::CoincidenciasForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CoincidenciasForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void ModAllbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->comboBox->SelectedItem == nullptr) {
			string mensaje = "Se debe seleccionar un elemento para sustituir al eliminado.";
			SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
			dError->ShowDialog();
			delete dError;
		}
		else {
			using namespace Runtime::InteropServices;
			string selected = (const char*)(Marshal::StringToHGlobalAnsi(this->comboBox->SelectedItem->ToString())).ToPointer();
			this->Hide();
			*modificado = true;
			if (vStudies != nullptr) {
				unsigned int c = this->bd->getCentreId(selected);
				for (int i = 0; i < vStudies->size(); ++i)
					this->bd->setCentreInStudy(vStudies->at(i)->first, c);
			}
			else if (vApplies != nullptr){
				if (tipoElim == CENTRO_ELEM) {
					unsigned int c = this->bd->getCentreId(selected);
					for (int i = 0; i < vApplies->size(); ++i)
						this->bd->setCentreInApplication(vApplies->at(i)->first, c);
				}
				else if (tipoElim == SOLIC_ELEM)
					for (int i = 0; i < vApplies->size(); ++i)
						this->bd->setTypeInApplication(vApplies->at(i)->first, selected);
				else
					for (int i = 0; i < vApplies->size(); ++i)
						this->bd->setDocInApplication(vApplies->at(i)->first, selected);

			}
			else {
				unsigned int stud = this->bd->getStudyID(selected);
				unsigned int oldStud = this->bd->getStudyOfStudent(vStudents->at(0)->first);
				for (int i = 0; i < vStudents->size(); ++i)
					this->bd->setStudyInStudent(vStudents->at(i)->first, stud);
				this->bd->modifyStudyInSubjects(oldStud, stud);
			}
			Close();
		}
	}
private: System::Void ModIndividButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	if (vStudies != nullptr) {
		string accion = "Centro";
		bool hacerLoMismo = false;
		unsigned int c;
		*modificado = true;
		for (int indice = 0; indice < vStudies->size(); ++indice) {
			if (!hacerLoMismo) {
				SGBDRasore::addStudiesForm ^dialog = gcnew SGBDRasore::addStudiesForm(*bd, vStudies->at(indice),
					hacerLoMismo, accion, *modificado);
				dialog->ShowDialog();
				delete dialog;
				while (!*modificado) {
					string m = "Es necesario que facilite un nuevo centro para la titulación.";
					SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
					inforD->ShowDialog();
					delete inforD;
					SGBDRasore::addStudiesForm ^dAddStd = gcnew SGBDRasore::addStudiesForm(*bd, vStudies->at(indice),
						hacerLoMismo, accion, *modificado);
					dAddStd->ShowDialog();
					delete dAddStd;
				}
				if (hacerLoMismo)
					c = this->bd->getCentreId(accion);
			}
			else
				this->bd->setCentreInStudy(vStudies->at(indice)->first, c);
		}
	}
	else if (vApplies != nullptr) {
		string accion;
		bool hacerLoMismo = false;
		*modificado = true;
		unsigned int c;
		if (tipoElim == CENTRO_ELEM)
			accion = "Centro";
		else if (tipoElim == SOLIC_ELEM)
			accion = "Tipo";
		else if (tipoElim == DOC_ELEM)
			accion = "Documentación";
		for (int indice = 0; indice < vApplies->size(); ++indice) {
			if (!hacerLoMismo) {
				SGBDRasore::GrabarSolicitud ^grabSol = gcnew SGBDRasore::GrabarSolicitud(*bd, vApplies->at(indice),
					hacerLoMismo, accion, *modificado);
				grabSol->ShowDialog();
				delete grabSol;
				while (!*modificado) {
					string m;
					if (accion != "Documentación")
						m = "Es necesario que facilite un nuevo " + accion + " para la solicitud.";
					else
						m = "Es necesario que facilite un nuevo tipo de documentación para la solicitud.";
					SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
					inforD->ShowDialog();
					delete inforD;
					SGBDRasore::GrabarSolicitud ^grabSolD = gcnew SGBDRasore::GrabarSolicitud(*bd, vApplies->at(indice),
						hacerLoMismo, accion, *modificado);
					grabSolD->ShowDialog();
					delete grabSolD;
				}
				if (hacerLoMismo && tipoElim == CENTRO_ELEM)
					c = this->bd->getCentreId(accion);
			}
			else if (tipoElim == CENTRO_ELEM)
				this->bd->setCentreInApplication(vApplies->at(indice)->first, c);
			else if (tipoElim == SOLIC_ELEM)
				this->bd->setTypeInApplication(vApplies->at(indice)->first, accion);
			else if (tipoElim == DOC_ELEM)
				this->bd->setDocInApplication(vApplies->at(indice)->first, accion);
		}
	}
	else {
		string accion = "Titulación";
		bool hacerLoMismo = false;
		unsigned int s;
		*modificado = true;
		for (int indice = 0; indice < vStudents->size(); ++indice) {
			if (!hacerLoMismo) {
				SGBDRasore::GrabarEstudiante ^dialog = gcnew SGBDRasore::GrabarEstudiante(*bd, vStudents->at(indice),
					hacerLoMismo, accion, *modificado);
				dialog->ShowDialog();
				delete dialog;
				while (!*modificado) {
					string m = "Es necesario que facilite una nueva titulación para el estudiante.";
					SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
					inforD->ShowDialog();
					delete inforD;
					SGBDRasore::GrabarEstudiante ^dAddStd = gcnew SGBDRasore::GrabarEstudiante(*bd, vStudents->at(indice),
						hacerLoMismo, accion, *modificado);
					dAddStd->ShowDialog();
					delete dAddStd;
				}
				if (hacerLoMismo)
					s = this->bd->getStudyID(accion);
			}
			else {
				this->bd->setStudyInStudent(vStudents->at(indice)->first, s);
				auto vApp = this->bd->getAppFromStudent(vStudents->at(indice)->first);
				for (int i = 0; i < vApp.size(); ++i)
					for (int j = 0; j < vApp[i]->second.Asignaturas.size(); ++j)
						this->bd->setStudyOfSubject(vApp[i]->second.Asignaturas[j], s);
			}
		}
	}
	Close();
}
};
}
#endif