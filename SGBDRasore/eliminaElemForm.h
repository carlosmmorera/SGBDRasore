#ifndef ELIMINAELEMFORM_H
#define ELIMINAELEMFORM_H

#include <iostream>
#include <string>
#include <vector>
#include "BaseDatos.h"
#include "InformationDialog.h"
#include "warningBooleanDialog.h"
#include "CoincidenciasForm.h"
#include "errorDialog.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de eliminaElemForm
	/// </summary>
	public ref class eliminaElemForm : public System::Windows::Forms::Form
	{
	public:
		eliminaElemForm(void)
		{
			InitializeComponent();
			bd = NULL;
			tipo = NULL;
		}

		eliminaElemForm(BaseDatos &base, string &type) {
			InitializeComponent();
			bd = &base;
			tipo = &type;
			string mensaje;
			vector<string> v;
			if (*tipo == "titulación") {
				mensaje = "Seleccione el nombre de la titulación que desea eliminar.";
				this->bd->getStudies(v);
			}
			else if (*tipo == "centro"){
				mensaje = "Seleccione el nombre del centro que desea eliminar.";
				v = this->bd->getCentres();
			}
			else if (*tipo == "solicitud") {
				mensaje = "Seleccione el tipo de solicitud que desea eliminar.";
				v = this->bd->getApplicationTypes();
			}
			else if (*tipo == "resolución") {
				mensaje = "Seleccione el tipo de resolución que desea eliminar.";
				v = this->bd->getResolutionTypes();
			}
			else if (*tipo == "recurso") {
				mensaje = "Seleccione el tipo de recurso que desea eliminar.";
				v = this->bd->getResourceTypes();
			}
			else {
				mensaje = "Seleccione el tipo de documentación que desea eliminar.";
				v = this->bd->getDocumentation();
			}
			this->TextoLabel->Text = gcnew String(mensaje.c_str());
			for (int i = 0; i < v.size(); ++i)
				this->comboBox->Items->Add(gcnew String(v[i].c_str()));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~eliminaElemForm()
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
		string *tipo;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::Label^  TextoLabel;




			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(eliminaElemForm::typeid));
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->TextoLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(465, 114);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 36;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &eliminaElemForm::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(332, 114);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(115, 32);
			this->SaveButton->TabIndex = 35;
			this->SaveButton->Text = L"Seleccionar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &eliminaElemForm::SaveButton_Click);
			// 
			// comboBox
			// 
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Location = System::Drawing::Point(21, 68);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(546, 28);
			this->comboBox->Sorted = true;
			this->comboBox->TabIndex = 34;
			// 
			// TextoLabel
			// 
			this->TextoLabel->AutoSize = true;
			this->TextoLabel->Location = System::Drawing::Point(17, 31);
			this->TextoLabel->Name = L"TextoLabel";
			this->TextoLabel->Size = System::Drawing::Size(87, 20);
			this->TextoLabel->TabIndex = 33;
			this->TextoLabel->Text = L"TextoLabel";
			// 
			// eliminaElemForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(589, 173);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->TextoLabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"eliminaElemForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Eliminar elemento";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->comboBox->SelectedItem != nullptr) {
		using namespace Runtime::InteropServices;
		string selected = (const char*)(Marshal::StringToHGlobalAnsi(this->comboBox->SelectedItem->ToString())).ToPointer();
		string mensaje = "Se va a proceder a eliminar el elemento seleccionado. ¿Está seguro de querer continuar?";
		bool doIt = false;
		SGBDRasore::warningBooleanDialog ^warnDialog = gcnew SGBDRasore::warningBooleanDialog(doIt, mensaje);
		warnDialog->ShowDialog();
		delete warnDialog;
		if (doIt) {
			this->Hide();
			bool modificado = false;
			if (*tipo == "titulación") {
				unsigned int study = this->bd->getStudyID(selected);
				auto vStudents = this->bd->getStudentsStudying(study);
				if (vStudents.size() > 0) {
					while (!modificado) {
						SGBDRasore::CoincidenciasForm ^coincForm = gcnew SGBDRasore::CoincidenciasForm(*bd, modificado,
							selected, TITUL_ELEM, vStudents);
						coincForm->ShowDialog();
						delete coincForm;
						if (!modificado) {
							string m = "Es necesario que modifique los estudiantes con la titulación eliminada.";
							SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
							inforD->ShowDialog();
							delete inforD;
						}
					}
				}
				this->bd->deleteStudies(study);
				string m = "La titulación ha sido eliminada correctamente de la base de datos.";
				SGBDRasore::InformationDialog ^infoDia = gcnew SGBDRasore::InformationDialog(m);
				infoDia->ShowDialog();
				delete infoDia;
			}
			else if (*tipo == "centro") {
				unsigned int c = this->bd->getCentreId(selected);
				auto vStudies = this->bd->getStudiesInCentre(c);
				auto vApplic = this->bd->getAppToCentre(c);
				if (vStudies.size() > 0) {
					while (!modificado) {
						SGBDRasore::CoincidenciasForm ^coincForm = gcnew SGBDRasore::CoincidenciasForm(*bd, modificado,
							selected, CENTRO_ELEM, vStudies);
						coincForm->ShowDialog();
						delete coincForm;
						if (!modificado) {
							string m = "Es necesario que modifique las titulaciones con el centro eliminado.";
							SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
							inforD->ShowDialog();
							delete inforD;
						}
					}
				}
				if (vApplic.size() > 0) {
					modificado = false;
					while (!modificado) {
						SGBDRasore::CoincidenciasForm ^coincForm = gcnew SGBDRasore::CoincidenciasForm(*bd, modificado,
							selected, CENTRO_ELEM, vApplic);
						coincForm->ShowDialog();
						delete coincForm;
						if (!modificado) {
							string m = "Es necesario que modifique las solicitudes con el centro eliminado.";
							SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
							inforD->ShowDialog();
							delete inforD;
						}
					}
				}
				this->bd->deleteCentre(c);
				string m = "El centro ha sido eliminado correctamente de la base de datos.";
				SGBDRasore::InformationDialog ^infoDia = gcnew SGBDRasore::InformationDialog(m);
				infoDia->ShowDialog();
				delete infoDia;
			}
			else if (*tipo == "solicitud") {
				auto vApplic = this->bd->getAppOfType(selected);
				if (vApplic.size() > 0) {
					modificado = false;
					while (!modificado) {
						SGBDRasore::CoincidenciasForm ^coincForm = gcnew SGBDRasore::CoincidenciasForm(*bd, modificado,
							selected, SOLIC_ELEM, vApplic);
						coincForm->ShowDialog();
						delete coincForm;
						if (!modificado) {
							string m = "Es necesario que modifique las solicitudes con el tipo eliminado.";
							SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
							inforD->ShowDialog();
							delete inforD;
						}
					}
				}
				this->bd->deleteTypeOfApp(selected);
				string m = "El tipo de solicitud ha sido eliminado correctamente de la base de datos.";
				SGBDRasore::InformationDialog ^infoDia = gcnew SGBDRasore::InformationDialog(m);
				infoDia->ShowDialog();
				delete infoDia;
			}
			else if (*tipo == "resolución") {

			}
			else if (*tipo == "recurso") {

			}
			else {
				auto vApplic = this->bd->getAppWithDoc(selected);
				if (vApplic.size() > 0) {
					modificado = false;
					while (!modificado) {
						SGBDRasore::CoincidenciasForm ^coincForm = gcnew SGBDRasore::CoincidenciasForm(*bd, modificado,
							selected, DOC_ELEM, vApplic);
						coincForm->ShowDialog();
						delete coincForm;
						if (!modificado) {
							string m = "Es necesario que modifique las solicitudes con la documentación eliminada.";
							SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
							inforD->ShowDialog();
							delete inforD;
						}
					}
				}
				this->bd->deleteDocumentation(selected);
				string m = "El tipo de documentación ha sido eliminado correctamente de la base de datos.";
				SGBDRasore::InformationDialog ^infoDia = gcnew SGBDRasore::InformationDialog(m);
				infoDia->ShowDialog();
				delete infoDia;
			}
			Close();
		}
	}
	else {
		string mensaje = "Se debe seleccionar un elemento a eliminar.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
}
};
}
#endif