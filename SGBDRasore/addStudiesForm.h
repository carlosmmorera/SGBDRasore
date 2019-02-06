#ifndef ADDSTUDIES_H
#define ADDSTUDIES_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "BaseDatos.h"
#include "InformationDialog.h"
#include "errorDialog.h"
#include "warningBooleanDialog.h"
#include "addCentre.h"
#include "addCiclo.h"
#include "addRama.h"
#include "gestorArchivos.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de addStudiesForm
	/// </summary>
	public ref class addStudiesForm : public System::Windows::Forms::Form
	{
	public:
		addStudiesForm(void)
		{
			InitializeComponent();
			bd = nullptr;
		}

		addStudiesForm(BaseDatos &base)
		{
			InitializeComponent();
			bd = &base;
			auto lst = bd->getCentres();
			for (int i = 0; i < lst.size(); ++i)
				this->CentrecomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getPeriods();
			for (int i = 0; i < lst.size(); ++i)
				this->CiclocomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getFields();
			for (int i = 0; i < lst.size(); ++i)
				this->RamacomboBox->Items->Add(gcnew String(lst[i].c_str()));
		}

		addStudiesForm(BaseDatos &base, unsigned int idStudy) {
			InitializeComponent();
			bd = &base;
			auto lst = bd->getCentres();
			for (int i = 0; i < lst.size(); ++i)
				this->CentrecomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getPeriods();
			for (int i = 0; i < lst.size(); ++i)
				this->CiclocomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getFields();
			for (int i = 0; i < lst.size(); ++i)
				this->RamacomboBox->Items->Add(gcnew String(lst[i].c_str()));
			ide = idStudy;
			auto v = bd->getStudyData(ide);
			this->IdtextBox->Text = gcnew String(uintToString(idStudy).c_str());
			this->idRtextBox->Text = gcnew String(v[0].c_str());
			this->NombretextBox->Text = gcnew String(v[1].c_str());
			this->CentrecomboBox->SelectedItem = gcnew String(v[2].c_str());
			this->CiclocomboBox->SelectedItem = gcnew String(v[3].c_str());
			this->RamacomboBox->SelectedItem = gcnew String(v[4].c_str());
			string m = "Modificar";
			this->SaveButton->Text = gcnew String(m.c_str());
		}

		addStudiesForm(BaseDatos &base, unordered_map<unsigned int, Estudios_valor>::const_iterator &it,
			bool &hacerLoMismo, string &accion, bool &modificado) {
			InitializeComponent();
			bd = &base;
			ide = it->first;
			goOn = &hacerLoMismo;
			mod = &modificado;
			*mod = false;
			changeAction = &accion;
			this->IdtextBox->Text = gcnew String(uintToString(it->first).c_str());
			this->IdtextBox->Enabled = false;
			this->idRtextBox->Text = gcnew String(it->second.IdRuct.c_str());
			this->idRtextBox->Enabled = false;
			this->NombretextBox->Text = gcnew String(it->second.Nombre.c_str());
			this->NombretextBox->Enabled = false;
			if (accion != "Centro") {
				this->CentrecomboBox->Items->Add(gcnew String(base.getCentreName(it->second.centroId).c_str()));
				this->CentrecomboBox->SelectedItem = gcnew String(base.getCentreName(it->second.centroId).c_str());
				this->CentrecomboBox->Enabled = false;
			}
			else {
				auto lst = bd->getCentres();
				for (int i = 0; i < lst.size(); ++i)
					if (lst[i] != base.getCentreName(it->second.centroId))
						this->CentrecomboBox->Items->Add(gcnew String(lst[i].c_str()));
			}
			this->CiclocomboBox->Items->Add(gcnew String((*(it->second.Ciclo)).c_str()));
			this->CiclocomboBox->SelectedItem = gcnew String((*(it->second.Ciclo)).c_str());
			this->CiclocomboBox->Enabled = false;
			this->RamacomboBox->Items->Add(gcnew String((*(it->second.Rama)).c_str()));
			this->RamacomboBox->SelectedItem = gcnew String((*(it->second.Rama)).c_str());
			this->RamacomboBox->Enabled = false;
			this->RepeatCheckBox->Visible = true;
			this->RepeatCheckBox->Enabled = true;
			string m = "Modificar";
			this->SaveButton->Text = gcnew String(m.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~addStudiesForm()
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
		unsigned int ide;
		bool *goOn;
		string * changeAction;
		bool *mod;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Label^  Codelabel;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  TitleEstudiante;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  addCentreButton;
	private: System::Windows::Forms::TextBox^  IdtextBox;
	private: System::Windows::Forms::TextBox^  idRtextBox;
	private: System::Windows::Forms::Label^  idRlabel;
	private: System::Windows::Forms::Label^  Namelabel;
	private: System::Windows::Forms::TextBox^  NombretextBox;
	private: System::Windows::Forms::Label^  Centrelabel;
	private: System::Windows::Forms::ComboBox^  CentrecomboBox;
	private: System::Windows::Forms::ComboBox^  CiclocomboBox;
	private: System::Windows::Forms::Label^  Ciclolabel;
	private: System::Windows::Forms::ComboBox^  RamacomboBox;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  addCicloButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripButton^  AddRamaButton;
	private: System::Windows::Forms::CheckBox^  RepeatCheckBox;



			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(addStudiesForm::typeid));
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->Codelabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TitleEstudiante = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->addCentreButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->addCicloButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->AddRamaButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->IdtextBox = (gcnew System::Windows::Forms::TextBox());
			this->idRtextBox = (gcnew System::Windows::Forms::TextBox());
			this->idRlabel = (gcnew System::Windows::Forms::Label());
			this->Namelabel = (gcnew System::Windows::Forms::Label());
			this->NombretextBox = (gcnew System::Windows::Forms::TextBox());
			this->Centrelabel = (gcnew System::Windows::Forms::Label());
			this->CentrecomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->CiclocomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Ciclolabel = (gcnew System::Windows::Forms::Label());
			this->RamacomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->RepeatCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(525, 314);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 36;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &addStudiesForm::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(397, 314);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(110, 32);
			this->SaveButton->TabIndex = 35;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &addStudiesForm::SaveButton_Click);
			// 
			// Codelabel
			// 
			this->Codelabel->AutoSize = true;
			this->Codelabel->Location = System::Drawing::Point(12, 77);
			this->Codelabel->Name = L"Codelabel";
			this->Codelabel->Size = System::Drawing::Size(59, 20);
			this->Codelabel->TabIndex = 37;
			this->Codelabel->Text = L"Código";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(372, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 20);
			this->label2->TabIndex = 40;
			this->label2->Text = L"---------------------------------------------";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 20);
			this->label1->TabIndex = 39;
			this->label1->Text = L"----------------------------------------";
			// 
			// TitleEstudiante
			// 
			this->TitleEstudiante->AutoSize = true;
			this->TitleEstudiante->Location = System::Drawing::Point(218, 45);
			this->TitleEstudiante->Name = L"TitleEstudiante";
			this->TitleEstudiante->Size = System::Drawing::Size(157, 20);
			this->TitleEstudiante->TabIndex = 38;
			this->TitleEstudiante->Text = L"Datos de la titulación";
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->addCentreButton,
					this->toolStripSeparator1, this->addCicloButton, this->toolStripSeparator2, this->AddRamaButton
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(628, 32);
			this->toolStrip1->TabIndex = 41;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// addCentreButton
			// 
			this->addCentreButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->addCentreButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addCentreButton.Image")));
			this->addCentreButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->addCentreButton->Name = L"addCentreButton";
			this->addCentreButton->Size = System::Drawing::Size(123, 29);
			this->addCentreButton->Text = L"Añadir centro";
			this->addCentreButton->Click += gcnew System::EventHandler(this, &addStudiesForm::addCentreButton_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 32);
			// 
			// addCicloButton
			// 
			this->addCicloButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->addCicloButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addCicloButton.Image")));
			this->addCicloButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->addCicloButton->Name = L"addCicloButton";
			this->addCicloButton->Size = System::Drawing::Size(108, 29);
			this->addCicloButton->Text = L"Añadir ciclo";
			this->addCicloButton->Click += gcnew System::EventHandler(this, &addStudiesForm::addCicloButton_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 32);
			// 
			// AddRamaButton
			// 
			this->AddRamaButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->AddRamaButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddRamaButton.Image")));
			this->AddRamaButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->AddRamaButton->Name = L"AddRamaButton";
			this->AddRamaButton->Size = System::Drawing::Size(113, 29);
			this->AddRamaButton->Text = L"Añadir rama";
			this->AddRamaButton->Click += gcnew System::EventHandler(this, &addStudiesForm::AddRamaButton_Click);
			// 
			// IdtextBox
			// 
			this->IdtextBox->Location = System::Drawing::Point(102, 77);
			this->IdtextBox->Name = L"IdtextBox";
			this->IdtextBox->Size = System::Drawing::Size(152, 26);
			this->IdtextBox->TabIndex = 42;
			// 
			// idRtextBox
			// 
			this->idRtextBox->Location = System::Drawing::Point(415, 77);
			this->idRtextBox->Name = L"idRtextBox";
			this->idRtextBox->Size = System::Drawing::Size(189, 26);
			this->idRtextBox->TabIndex = 44;
			// 
			// idRlabel
			// 
			this->idRlabel->AutoSize = true;
			this->idRlabel->Location = System::Drawing::Point(298, 77);
			this->idRlabel->Name = L"idRlabel";
			this->idRlabel->Size = System::Drawing::Size(107, 20);
			this->idRlabel->TabIndex = 43;
			this->idRlabel->Text = L"Código RUCT";
			// 
			// Namelabel
			// 
			this->Namelabel->AutoSize = true;
			this->Namelabel->Location = System::Drawing::Point(12, 129);
			this->Namelabel->Name = L"Namelabel";
			this->Namelabel->Size = System::Drawing::Size(65, 20);
			this->Namelabel->TabIndex = 45;
			this->Namelabel->Text = L"Nombre";
			// 
			// NombretextBox
			// 
			this->NombretextBox->Location = System::Drawing::Point(102, 126);
			this->NombretextBox->Name = L"NombretextBox";
			this->NombretextBox->Size = System::Drawing::Size(502, 26);
			this->NombretextBox->TabIndex = 46;
			this->NombretextBox->TextChanged += gcnew System::EventHandler(this, &addStudiesForm::textBox1_TextChanged);
			// 
			// Centrelabel
			// 
			this->Centrelabel->AutoSize = true;
			this->Centrelabel->Location = System::Drawing::Point(12, 178);
			this->Centrelabel->Name = L"Centrelabel";
			this->Centrelabel->Size = System::Drawing::Size(57, 20);
			this->Centrelabel->TabIndex = 47;
			this->Centrelabel->Text = L"Centro";
			// 
			// CentrecomboBox
			// 
			this->CentrecomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CentrecomboBox->FormattingEnabled = true;
			this->CentrecomboBox->Location = System::Drawing::Point(102, 175);
			this->CentrecomboBox->Name = L"CentrecomboBox";
			this->CentrecomboBox->Size = System::Drawing::Size(502, 28);
			this->CentrecomboBox->Sorted = true;
			this->CentrecomboBox->TabIndex = 48;
			// 
			// CiclocomboBox
			// 
			this->CiclocomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CiclocomboBox->FormattingEnabled = true;
			this->CiclocomboBox->Location = System::Drawing::Point(102, 223);
			this->CiclocomboBox->Name = L"CiclocomboBox";
			this->CiclocomboBox->Size = System::Drawing::Size(502, 28);
			this->CiclocomboBox->Sorted = true;
			this->CiclocomboBox->TabIndex = 50;
			// 
			// Ciclolabel
			// 
			this->Ciclolabel->AutoSize = true;
			this->Ciclolabel->Location = System::Drawing::Point(12, 226);
			this->Ciclolabel->Name = L"Ciclolabel";
			this->Ciclolabel->Size = System::Drawing::Size(43, 20);
			this->Ciclolabel->TabIndex = 49;
			this->Ciclolabel->Text = L"Ciclo";
			// 
			// RamacomboBox
			// 
			this->RamacomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->RamacomboBox->FormattingEnabled = true;
			this->RamacomboBox->Location = System::Drawing::Point(102, 268);
			this->RamacomboBox->Name = L"RamacomboBox";
			this->RamacomboBox->Size = System::Drawing::Size(502, 28);
			this->RamacomboBox->Sorted = true;
			this->RamacomboBox->TabIndex = 52;
			this->RamacomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &addStudiesForm::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 271);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 20);
			this->label3->TabIndex = 51;
			this->label3->Text = L"Rama";
			this->label3->Click += gcnew System::EventHandler(this, &addStudiesForm::label3_Click);
			// 
			// RepeatCheckBox
			// 
			this->RepeatCheckBox->AutoSize = true;
			this->RepeatCheckBox->Enabled = false;
			this->RepeatCheckBox->Location = System::Drawing::Point(16, 319);
			this->RepeatCheckBox->Name = L"RepeatCheckBox";
			this->RepeatCheckBox->Size = System::Drawing::Size(358, 24);
			this->RepeatCheckBox->TabIndex = 53;
			this->RepeatCheckBox->Text = L"Hacer lo mismo para los siguientes elementos";
			this->RepeatCheckBox->UseVisualStyleBackColor = true;
			this->RepeatCheckBox->Visible = false;
			// 
			// addStudiesForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(628, 358);
			this->Controls->Add(this->RepeatCheckBox);
			this->Controls->Add(this->RamacomboBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->CiclocomboBox);
			this->Controls->Add(this->Ciclolabel);
			this->Controls->Add(this->CentrecomboBox);
			this->Controls->Add(this->Centrelabel);
			this->Controls->Add(this->NombretextBox);
			this->Controls->Add(this->Namelabel);
			this->Controls->Add(this->idRtextBox);
			this->Controls->Add(this->idRlabel);
			this->Controls->Add(this->IdtextBox);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TitleEstudiante);
			this->Controls->Add(this->Codelabel);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"addStudiesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Añadir titulación";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &addStudiesForm::addStudiesForm_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addStudiesForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	using namespace Runtime::InteropServices;
	if (!isANumber((const char*)(Marshal::StringToHGlobalAnsi(this->IdtextBox->Text)).ToPointer())) {
		string mensaje = "El identificador de la titulación debe ser un número.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->CentrecomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar un centro en el que se imparte la titulación.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->CiclocomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar el ciclo de la titulación.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->RamacomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar la rama de la titulación.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		int id = atoi((const char*)(Marshal::StringToHGlobalAnsi(this->IdtextBox->Text)).ToPointer());
		string idR = (const char*)(Marshal::StringToHGlobalAnsi(this->idRtextBox->Text)).ToPointer();
		string  nombre = (const char*)(Marshal::StringToHGlobalAnsi(this->NombretextBox->Text)).ToPointer();
		string centro = (const char*)(Marshal::StringToHGlobalAnsi(this->CentrecomboBox->SelectedItem->ToString())).ToPointer();
		string ciclo = (const char*)(Marshal::StringToHGlobalAnsi(this->CiclocomboBox->SelectedItem->ToString())).ToPointer();
		string rama = (const char*)(Marshal::StringToHGlobalAnsi(this->RamacomboBox->SelectedItem->ToString())).ToPointer();
		string botonTexto = "Guardar";
		if (this->SaveButton->Text == gcnew String(botonTexto.c_str())) {
			try {
				this->bd->insertStudies(id, idR, nombre, centro, ciclo, rama);
				string m = "La titulación ha sido añadida correctamente a la base de datos.";
				SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasore::InformationDialog(m);
				dialog->ShowDialog();
				delete dialog;
				Close();
			}
			catch (invalid_argument &e) {
				string mensaje = e.what();
				mensaje.append("Añádalo a la base de datos.");
				SGBDRasore::errorDialog ^dialog = gcnew SGBDRasore::errorDialog(mensaje);
				dialog->ShowDialog();
				delete dialog;
			}
			catch (domain_error &e) {
				string mensaje = "El código de la titulación que se desea insertar ya se encuentra en la base de datos.\n¿Desea reemplazar los datos (se borrarían todos los datos relacionados con dicho código)?";
				bool doIt = false;
				SGBDRasore::warningBooleanDialog ^dialog = gcnew SGBDRasore::warningBooleanDialog(doIt, mensaje);
				dialog->ShowDialog();
				delete dialog;
				if (doIt) {
					this->bd->deleteStudies(id);
					this->bd->insertStudies(id, idR, nombre, centro, ciclo, rama);
					Close();
				}
			}
		}
		else if (this->RepeatCheckBox->Enabled == false) {
			try {
				if (id == ide) {
					this->bd->deleteStudies(ide);
					this->bd->insertStudies(id, idR, nombre, centro, ciclo, rama);
					string m = "La titulación ha sido modificada correctamente a la base de datos.";
					SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasore::InformationDialog(m);
					dialog->ShowDialog();
					delete dialog;
					Close();
				}
				else if (!this->bd->isUsedStudyId(id)) {
					this->bd->insertStudies(id, idR, nombre, centro, ciclo, rama);
					this->bd->modifyStudyId(ide, id);
					this->bd->deleteStudies(ide);
					string m = "La titulación ha sido modificada correctamente a la base de datos.";
					SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasore::InformationDialog(m);
					dialog->ShowDialog();
					delete dialog;
					Close();
				}
				else {
					string mensaje = "El código de la titulación que se desea insertar ya se encuentra en la base de datos.\n¿Desea reemplazar los datos (se borrarían todos los datos relacionados con dicho código)?";
					bool doIt = false;
					SGBDRasore::warningBooleanDialog ^dialog = gcnew SGBDRasore::warningBooleanDialog(doIt, mensaje);
					dialog->ShowDialog();
					delete dialog;
					if (doIt) {
						this->bd->deleteStudies(id);
						this->bd->insertStudies(id, idR, nombre, centro, ciclo, rama);
						this->bd->modifyStudyId(ide, id);
						this->bd->deleteStudies(ide);
						Close();
					}
				}
			}
			catch (invalid_argument &e) {
				string mensaje = e.what();
				mensaje.append("Añádalo a la base de datos.");
				SGBDRasore::errorDialog ^dialog = gcnew SGBDRasore::errorDialog(mensaje);
				dialog->ShowDialog();
				delete dialog;
			}
		}
		else {
			string aux;
			if (*changeAction == "Centro") {
				aux = (const char*)(Marshal::StringToHGlobalAnsi(this->CentrecomboBox->SelectedItem->ToString())).ToPointer();
				this->bd->setCentreInStudy(ide, this->bd->getCentreId(aux));
			}
			*goOn = this->RepeatCheckBox->Checked;
			if (*goOn)
				*changeAction = aux;
			*mod = true;
			Close();
		}
	}
}
private: System::Void addCentreButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	SGBDRasore::addCentre ^dialog = gcnew SGBDRasore::addCentre(*bd);
	dialog->ShowDialog();
	delete dialog;
	this->CentrecomboBox->Items->Clear();
	auto lst = bd->getCentres();
	for (int i = 0; i < lst.size(); ++i)
		this->CentrecomboBox->Items->Add(gcnew String(lst[i].c_str()));
	this->Show();
}
private: System::Void addCicloButton_Click(System::Object^  sender, System::EventArgs^  e) {
	SGBDRasore::addCiclo ^dialog = gcnew SGBDRasore::addCiclo(*bd);
	dialog->ShowDialog();
	delete dialog;
	this->CiclocomboBox->Items->Clear();
	auto lst = bd->getPeriods();
	for (int i = 0; i < lst.size(); ++i)
		this->CiclocomboBox->Items->Add(gcnew String(lst[i].c_str()));
}
private: System::Void AddRamaButton_Click(System::Object^  sender, System::EventArgs^  e) {
	SGBDRasore::addRama ^dialog = gcnew SGBDRasore::addRama(*bd);
	dialog->ShowDialog();
	delete dialog;
	this->RamacomboBox->Items->Clear();
	auto lst = bd->getFields();
	for (int i = 0; i < lst.size(); ++i)
		this->RamacomboBox->Items->Add(gcnew String(lst[i].c_str()));
}
};
}
#endif