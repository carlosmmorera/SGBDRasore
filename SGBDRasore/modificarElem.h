#ifndef MODIFICARELEM_H
#define MODIFICARELEM_H

#include <iostream>
#include <vector>
#include <string>
#include "BaseDatos.h"
#include "addCentre.h"
#include "addStudiesForm.h"
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
	/// Resumen de modificarElem
	/// </summary>
	public ref class modificarElem : public System::Windows::Forms::Form
	{
	public:
		modificarElem(void)
		{
			InitializeComponent();
			bd = NULL;
			tipo = NULL;
		}

		modificarElem(BaseDatos &base, string &str) {
			InitializeComponent();
			bd = &base;
			tipo = &str;
			string mensaje;
			vector<string> v;
			if (*tipo == "titulación") {
				mensaje = "Seleccione el nombre de la titulación que desea modificar.";
				this->bd->getStudies(v);
			}
			else{
				mensaje = "Seleccione el nombre del centro que desea modificar.";
				v = this->bd->getCentres();
			}
			this->TextoLabel->Text = gcnew String(mensaje.c_str());
			for (int i = 0; i < v.size(); ++i)
				this->comboBox->Items->Add(gcnew String(v[i].c_str()));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~modificarElem()
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
	private: System::Windows::Forms::Label^  TextoLabel;
	private: System::Windows::Forms::ComboBox^  comboBox;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(modificarElem::typeid));
			this->TextoLabel = (gcnew System::Windows::Forms::Label());
			this->comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// TextoLabel
			// 
			this->TextoLabel->AutoSize = true;
			this->TextoLabel->Location = System::Drawing::Point(27, 21);
			this->TextoLabel->Name = L"TextoLabel";
			this->TextoLabel->Size = System::Drawing::Size(87, 20);
			this->TextoLabel->TabIndex = 0;
			this->TextoLabel->Text = L"TextoLabel";
			// 
			// comboBox
			// 
			this->comboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox->FormattingEnabled = true;
			this->comboBox->Location = System::Drawing::Point(31, 58);
			this->comboBox->Name = L"comboBox";
			this->comboBox->Size = System::Drawing::Size(546, 28);
			this->comboBox->Sorted = true;
			this->comboBox->TabIndex = 1;
			this->comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &modificarElem::comboBox_SelectedIndexChanged);
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(475, 104);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 32;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &modificarElem::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(342, 104);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(115, 32);
			this->SaveButton->TabIndex = 31;
			this->SaveButton->Text = L"Seleccionar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &modificarElem::SaveButton_Click);
			// 
			// modificarElem
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(597, 148);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->comboBox);
			this->Controls->Add(this->TextoLabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"modificarElem";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Modificar elemento";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->comboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar el elemento a modificar.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		using namespace Runtime::InteropServices;
		string selected = (const char*)(Marshal::StringToHGlobalAnsi(this->comboBox->SelectedItem->ToString())).ToPointer();
		this->Hide();
		if (*tipo == "centro") {
			unsigned int c = this->bd->getCentreId(selected);
			SGBDRasore::addCentre ^dialog = gcnew SGBDRasore::addCentre(*bd, c);
			dialog->ShowDialog();
			delete dialog;
		}
		else {
			unsigned int study = this->bd->getStudyID(selected);
			SGBDRasore::addStudiesForm ^dialog = gcnew SGBDRasore::addStudiesForm(*bd, study);
			dialog->ShowDialog();
			delete dialog;
		}
		Close();
	}
}
private: System::Void comboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
#endif