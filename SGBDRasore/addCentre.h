#ifndef ADDCENTRE_H
#define ADDCENTRE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "BaseDatos.h"
#include "InformationDialog.h"
#include "warningBooleanDialog.h"
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
	/// Resumen de addCentre
	/// </summary>
	public ref class addCentre : public System::Windows::Forms::Form
	{
	public:
		addCentre(void)
		{
			InitializeComponent();
			bd = nullptr;
		}

		addCentre(BaseDatos &base) {
			InitializeComponent();
			bd = &base;
		}

		addCentre(BaseDatos &base, unsigned int c) {
			InitializeComponent();
			bd = &base;
			centro = c;
			this->IdtextBox->Text = gcnew String(uintToString(c).c_str());
			auto v = bd->getCentreData(c);
			this->NametextBox->Text = gcnew String(v[0].c_str());
			this->cargotextBox->Text = gcnew String(v[1].c_str());
			this->DirtextBox->Text = gcnew String(v[2].c_str());
			this->LoctextBox->Text = gcnew String(v[3].c_str());
			this->CPtextBox->Text = gcnew String(v[4].c_str());
			this->cAdmintextBox->Text = gcnew String(v[5].c_str());
			this->TlftextBox->Text = gcnew String(v[6].c_str());
			string m = "Modificar";
			this->SaveButton->Text = gcnew String(m.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~addCentre()
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
		unsigned int centro;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  TitleEstudiante;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Label^  Idlabel;
	private: System::Windows::Forms::TextBox^  IdtextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  NametextBox;
	private: System::Windows::Forms::TextBox^  cargotextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  LoctextBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  CPtextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  DirtextBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  cAdmintextBox;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  TlftextBox;

	private: System::Windows::Forms::Label^  label9;
			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(addCentre::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TitleEstudiante = (gcnew System::Windows::Forms::Label());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->Idlabel = (gcnew System::Windows::Forms::Label());
			this->IdtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->NametextBox = (gcnew System::Windows::Forms::TextBox());
			this->cargotextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->LoctextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->CPtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->DirtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cAdmintextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TlftextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(356, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(249, 20);
			this->label2->TabIndex = 45;
			this->label2->Text = L"------------------------------------------------";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 20);
			this->label1->TabIndex = 44;
			this->label1->Text = L"----------------------------------------";
			// 
			// TitleEstudiante
			// 
			this->TitleEstudiante->AutoSize = true;
			this->TitleEstudiante->Location = System::Drawing::Point(224, 19);
			this->TitleEstudiante->Name = L"TitleEstudiante";
			this->TitleEstudiante->Size = System::Drawing::Size(126, 20);
			this->TitleEstudiante->TabIndex = 43;
			this->TitleEstudiante->Text = L"Datos del centro";
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(493, 402);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 42;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &addCentre::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(350, 402);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(115, 32);
			this->SaveButton->TabIndex = 41;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &addCentre::SaveButton_Click);
			// 
			// Idlabel
			// 
			this->Idlabel->AutoSize = true;
			this->Idlabel->Location = System::Drawing::Point(26, 58);
			this->Idlabel->Name = L"Idlabel";
			this->Idlabel->Size = System::Drawing::Size(59, 20);
			this->Idlabel->TabIndex = 46;
			this->Idlabel->Text = L"Código";
			// 
			// IdtextBox
			// 
			this->IdtextBox->Location = System::Drawing::Point(109, 55);
			this->IdtextBox->Name = L"IdtextBox";
			this->IdtextBox->Size = System::Drawing::Size(184, 26);
			this->IdtextBox->TabIndex = 47;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(65, 20);
			this->label3->TabIndex = 48;
			this->label3->Text = L"Nombre";
			// 
			// NametextBox
			// 
			this->NametextBox->Location = System::Drawing::Point(109, 107);
			this->NametextBox->Name = L"NametextBox";
			this->NametextBox->Size = System::Drawing::Size(475, 26);
			this->NametextBox->TabIndex = 49;
			// 
			// cargotextBox
			// 
			this->cargotextBox->Location = System::Drawing::Point(109, 157);
			this->cargotextBox->Name = L"cargotextBox";
			this->cargotextBox->Size = System::Drawing::Size(475, 26);
			this->cargotextBox->TabIndex = 51;
			this->cargotextBox->Text = L"Sr/a Decano/a";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 20);
			this->label4->TabIndex = 50;
			this->label4->Text = L"Cargo";
			// 
			// LoctextBox
			// 
			this->LoctextBox->Location = System::Drawing::Point(109, 253);
			this->LoctextBox->Name = L"LoctextBox";
			this->LoctextBox->Size = System::Drawing::Size(184, 26);
			this->LoctextBox->TabIndex = 53;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 256);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 20);
			this->label5->TabIndex = 52;
			this->label5->Text = L"Localidad";
			// 
			// CPtextBox
			// 
			this->CPtextBox->Location = System::Drawing::Point(390, 253);
			this->CPtextBox->Name = L"CPtextBox";
			this->CPtextBox->Size = System::Drawing::Size(194, 26);
			this->CPtextBox->TabIndex = 55;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(331, 256);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 20);
			this->label6->TabIndex = 54;
			this->label6->Text = L"C.P.";
			// 
			// DirtextBox
			// 
			this->DirtextBox->Location = System::Drawing::Point(109, 205);
			this->DirtextBox->Name = L"DirtextBox";
			this->DirtextBox->Size = System::Drawing::Size(475, 26);
			this->DirtextBox->TabIndex = 57;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(26, 208);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(75, 20);
			this->label7->TabIndex = 56;
			this->label7->Text = L"Dirección";
			// 
			// cAdmintextBox
			// 
			this->cAdmintextBox->Location = System::Drawing::Point(185, 298);
			this->cAdmintextBox->Name = L"cAdmintextBox";
			this->cAdmintextBox->Size = System::Drawing::Size(399, 26);
			this->cAdmintextBox->TabIndex = 59;
			this->cAdmintextBox->Text = L"Sr/a Jefe/a de la Secretaría";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(26, 301);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(153, 20);
			this->label8->TabIndex = 58;
			this->label8->Text = L"Cargo administrativo";
			// 
			// TlftextBox
			// 
			this->TlftextBox->Location = System::Drawing::Point(228, 347);
			this->TlftextBox->Name = L"TlftextBox";
			this->TlftextBox->Size = System::Drawing::Size(175, 26);
			this->TlftextBox->TabIndex = 61;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(26, 350);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(186, 20);
			this->label9->TabIndex = 60;
			this->label9->Text = L"Teléfono de la Secretaría";
			// 
			// addCentre
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(608, 446);
			this->Controls->Add(this->TlftextBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->cAdmintextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->DirtextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->CPtextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->LoctextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->cargotextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->NametextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->IdtextBox);
			this->Controls->Add(this->Idlabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TitleEstudiante);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"addCentre";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Añadir Centro";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	using namespace Runtime::InteropServices;
	if (!isANumber((const char*)(Marshal::StringToHGlobalAnsi(this->IdtextBox->Text)).ToPointer())) {
		string mensaje = "El identificador del centro debe ser un número.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		int id = atoi((const char*)(Marshal::StringToHGlobalAnsi(this->IdtextBox->Text)).ToPointer());
		string nombre = (const char*)(Marshal::StringToHGlobalAnsi(this->NametextBox->Text)).ToPointer();
		string cargo = (const char*)(Marshal::StringToHGlobalAnsi(this->cargotextBox->Text)).ToPointer();
		string dir = (const char*)(Marshal::StringToHGlobalAnsi(this->DirtextBox->Text)).ToPointer();
		string loc = (const char*)(Marshal::StringToHGlobalAnsi(this->LoctextBox->Text)).ToPointer();
		string cp = (const char*)(Marshal::StringToHGlobalAnsi(this->CPtextBox->Text)).ToPointer();
		string cAdmin = (const char*)(Marshal::StringToHGlobalAnsi(this->cAdmintextBox->Text)).ToPointer();
		string tlf = (const char*)(Marshal::StringToHGlobalAnsi(this->TlftextBox->Text)).ToPointer();

		string botonTexto = "Guardar";
		if (this->SaveButton->Text == gcnew String(botonTexto.c_str())) {
			try {
				this->bd->insertCentre(id, nombre, cargo, dir, loc, cp, cAdmin, tlf);
				string m = "El centro ha sido añadido correctamente a la base de datos.";
				SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasore::InformationDialog(m);
				dialog->ShowDialog();
				delete dialog;
				Close();
			}
			catch (domain_error &e) {
				string mensaje = "El código de centro que se desea insertar ya se encuentra en la base de datos.\n¿Desea reemplazar los datos (se borrarían todos los datos relacionados con dicho código)?";
				bool doIt = false;
				SGBDRasore::warningBooleanDialog ^dialog = gcnew SGBDRasore::warningBooleanDialog(doIt, mensaje);
				dialog->ShowDialog();
				delete dialog;
				if (doIt) {
					this->bd->deleteCentre(id);
					this->bd->insertCentre(id, nombre, cargo, dir, loc, cp, cAdmin, tlf);
					string m = "El centro ha sido añadido correctamente a la base de datos.";
					SGBDRasore::InformationDialog ^dInfor = gcnew SGBDRasore::InformationDialog(m);
					dInfor->ShowDialog();
					delete dInfor;
					Close();
				}
			}
		}
		else if (id == centro) {
			this->bd->deleteCentre(centro);
			this->bd->insertCentre(id, nombre, cargo, dir, loc, cp, cAdmin, tlf);
			string m = "El centro ha sido modificado correctamente en la base de datos.";
			SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasore::InformationDialog(m);
			dialog->ShowDialog();
			delete dialog;
			Close();
		}
		else if (!this->bd->isUsedCentreId(id)) {
			this->bd->insertCentre(id, nombre, cargo, dir, loc, cp, cAdmin, tlf);
			this->bd->modifyCentreId(centro, id);
			this->bd->deleteCentre(centro);
			string m = "El centro ha sido modificado correctamente en la base de datos.";
			SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasore::InformationDialog(m);
			dialog->ShowDialog();
			delete dialog;
			Close();
		}
		else {
			string mensaje = "El código de centro que se desea insertar ya se encuentra en la base de datos.\n¿Desea reemplazar los datos (se borrarían todos los datos relacionados con dicho código)?";
			bool doIt = false;
			SGBDRasore::warningBooleanDialog ^dWar = gcnew SGBDRasore::warningBooleanDialog(doIt, mensaje);
			dWar->ShowDialog();
			delete dWar;
			if (doIt) {
				this->bd->deleteCentre(id);
				this->bd->insertCentre(id, nombre, cargo, dir, loc, cp, cAdmin, tlf);
				this->bd->modifyCentreId(centro, id);
				this->bd->deleteCentre(centro);
				string m = "El centro ha sido modificado correctamente en la base de datos.";
				SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasore::InformationDialog(m);
				dialog->ShowDialog();
				delete dialog;
				Close();
			}
		}
	}
}
};
}
#endif