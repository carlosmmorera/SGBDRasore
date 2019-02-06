#ifndef CONSULTAFORM_H
#define CONSULTAFORM_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "BaseDatos.h"
#include "errorDialog.h"
#include "InformationDialog.h"
#include "warningBooleanDialog.h"
#include "gestorArchivos.h"
#include "TablaEstud.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de ConsultaForm
	/// </summary>
	public ref class ConsultaForm : public System::Windows::Forms::Form
	{
	public:
		ConsultaForm(void)
		{
			InitializeComponent();
			bd = NULL;
		}

		ConsultaForm(BaseDatos &base) {
			InitializeComponent();
			bd = &base;

			vector<string> lst;
			this->bd->getStudies(lst);
			for (int i = 0; i < lst.size(); ++i)
				this->EstudioscomboBox->Items->Add(gcnew String(lst[i].c_str()));
			auto prov = this->bd->getProvinces();
			for (int i = 0; i < prov.size(); ++i)
				this->ProvcomboBox->Items->Add(gcnew String(prov[i].c_str()));
			auto tipRec = this->bd->getResourceTypes();
			for (int i = 0; i < tipRec.size(); ++i)
				this->TipoReccomboBox->Items->Add(gcnew String(tipRec[i].c_str()));
			auto tipRes = this->bd->getResolutionTypes();
			for (int i = 0; i < tipRes.size(); ++i)
				this->TipoRescomboBox->Items->Add(gcnew String(tipRes[i].c_str()));
			auto univ = base.getUniversities();
			for (int i = 0; i < univ.size(); ++i) {
				this->UniOcomboBox->Items->Add(gcnew String(univ[i].c_str()));
				this->UniDcomboBox->Items->Add(gcnew String(univ[i].c_str()));
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ConsultaForm()
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
	private: System::Windows::Forms::CheckBox^  SICUEcheckBox;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::TextBox^  ObsertextBox;
	private: System::Windows::Forms::Label^  Obserlabel;
	private: System::Windows::Forms::Label^  Estudioslabel;
	private: System::Windows::Forms::TextBox^  PaistextBox;
	private: System::Windows::Forms::Label^  Paislabel;
	private: System::Windows::Forms::Label^  Provlabel;
	private: System::Windows::Forms::TextBox^  CPtextBox;
	private: System::Windows::Forms::Label^  CPlabel;
	private: System::Windows::Forms::TextBox^  LoctextBox;
	private: System::Windows::Forms::Label^  Loclabel;
	private: System::Windows::Forms::TextBox^  DirtextBox;
	private: System::Windows::Forms::Label^  Dirlabel;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  TlftextBox;
	private: System::Windows::Forms::Label^  TlfLabel;
	private: System::Windows::Forms::TextBox^  EmailtextBox;
	private: System::Windows::Forms::Label^  EmailLabel;
	private: System::Windows::Forms::TextBox^  ApellidotextBox2;
	private: System::Windows::Forms::Label^  Apellidolabel2;
	private: System::Windows::Forms::TextBox^  ApellidotextBox1;
	private: System::Windows::Forms::Label^  Apellidolabel1;
	private: System::Windows::Forms::TextBox^  NombretextBox;
	private: System::Windows::Forms::Label^  NombreLabel;
	private: System::Windows::Forms::Label^  TitleEstudiante;
	private: System::Windows::Forms::TextBox^  DNItextBox;
	private: System::Windows::Forms::Label^  DNIlabel;


	private: System::Windows::Forms::Label^  Periodlabel;
	private: System::Windows::Forms::Label^  Estlabel;
	private: System::Windows::Forms::Label^  UniDlabel;
	private: System::Windows::Forms::Label^  UniOlabel;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;


	private: System::Windows::Forms::TextBox^  AnaEstudtextBox;

	private: System::Windows::Forms::TextBox^  AsigtextBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  ObserSoltextBox;

	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  Centrelabel;
	private: System::Windows::Forms::TextBox^  InformetextBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  EntradatextBox;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  Tipolabel;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  TipoSoltextBox;
	private: System::Windows::Forms::TextBox^  CentroSoltextBox;
	private: System::Windows::Forms::TextBox^  NSoltextBox;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  NEstudtextBox;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  DoctextBox;

	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Button^  ModifButton;
	private: System::Windows::Forms::Button^  SaveModifbutton;
	private: System::Windows::Forms::CheckBox^  BecacheckBox;
private: System::Windows::Forms::TextBox^  CampustextBox;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::ComboBox^  TipoRescomboBox;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::TextBox^  ResObsertextBox;

private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::ComboBox^  TipoReccomboBox;
private: System::Windows::Forms::Label^  label19;

private: System::Windows::Forms::TextBox^  SalidatextBox;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::TextBox^  FirmatextBox;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::TextBox^  NRestextBox;
private: System::Windows::Forms::Button^  Tablabutton;
private: System::Windows::Forms::ComboBox^  EstudioscomboBox;
private: System::Windows::Forms::ComboBox^  ProvcomboBox;
private: System::Windows::Forms::ComboBox^  UniOcomboBox;
private: System::Windows::Forms::ComboBox^  UniDcomboBox;
private: System::Windows::Forms::ComboBox^  PeriodcomboBox;




			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ConsultaForm::typeid));
			this->SICUEcheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->ObsertextBox = (gcnew System::Windows::Forms::TextBox());
			this->Obserlabel = (gcnew System::Windows::Forms::Label());
			this->Estudioslabel = (gcnew System::Windows::Forms::Label());
			this->PaistextBox = (gcnew System::Windows::Forms::TextBox());
			this->Paislabel = (gcnew System::Windows::Forms::Label());
			this->Provlabel = (gcnew System::Windows::Forms::Label());
			this->CPtextBox = (gcnew System::Windows::Forms::TextBox());
			this->CPlabel = (gcnew System::Windows::Forms::Label());
			this->LoctextBox = (gcnew System::Windows::Forms::TextBox());
			this->Loclabel = (gcnew System::Windows::Forms::Label());
			this->DirtextBox = (gcnew System::Windows::Forms::TextBox());
			this->Dirlabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TlftextBox = (gcnew System::Windows::Forms::TextBox());
			this->TlfLabel = (gcnew System::Windows::Forms::Label());
			this->EmailtextBox = (gcnew System::Windows::Forms::TextBox());
			this->EmailLabel = (gcnew System::Windows::Forms::Label());
			this->ApellidotextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->Apellidolabel2 = (gcnew System::Windows::Forms::Label());
			this->ApellidotextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Apellidolabel1 = (gcnew System::Windows::Forms::Label());
			this->NombretextBox = (gcnew System::Windows::Forms::TextBox());
			this->NombreLabel = (gcnew System::Windows::Forms::Label());
			this->TitleEstudiante = (gcnew System::Windows::Forms::Label());
			this->DNItextBox = (gcnew System::Windows::Forms::TextBox());
			this->DNIlabel = (gcnew System::Windows::Forms::Label());
			this->Periodlabel = (gcnew System::Windows::Forms::Label());
			this->Estlabel = (gcnew System::Windows::Forms::Label());
			this->UniDlabel = (gcnew System::Windows::Forms::Label());
			this->UniOlabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->AnaEstudtextBox = (gcnew System::Windows::Forms::TextBox());
			this->AsigtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ObserSoltextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Centrelabel = (gcnew System::Windows::Forms::Label());
			this->InformetextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->EntradatextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Tipolabel = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->TipoSoltextBox = (gcnew System::Windows::Forms::TextBox());
			this->CentroSoltextBox = (gcnew System::Windows::Forms::TextBox());
			this->NSoltextBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->NEstudtextBox = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->DoctextBox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->ModifButton = (gcnew System::Windows::Forms::Button());
			this->SaveModifbutton = (gcnew System::Windows::Forms::Button());
			this->BecacheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CampustextBox = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->TipoRescomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->ResObsertextBox = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->TipoReccomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->SalidatextBox = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->FirmatextBox = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->NRestextBox = (gcnew System::Windows::Forms::TextBox());
			this->Tablabutton = (gcnew System::Windows::Forms::Button());
			this->EstudioscomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ProvcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->UniOcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->UniDcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->PeriodcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// SICUEcheckBox
			// 
			this->SICUEcheckBox->AutoSize = true;
			this->SICUEcheckBox->Enabled = false;
			this->SICUEcheckBox->Location = System::Drawing::Point(347, 463);
			this->SICUEcheckBox->Name = L"SICUEcheckBox";
			this->SICUEcheckBox->Size = System::Drawing::Size(250, 24);
			this->SICUEcheckBox->TabIndex = 63;
			this->SICUEcheckBox->Text = L"Solicitud de estudiante SICUE";
			this->SICUEcheckBox->UseVisualStyleBackColor = true;
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(1148, 837);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 62;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &ConsultaForm::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(1039, 837);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(92, 32);
			this->SaveButton->TabIndex = 61;
			this->SaveButton->Text = L"Buscar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &ConsultaForm::SaveButton_Click);
			// 
			// ObsertextBox
			// 
			this->ObsertextBox->Enabled = false;
			this->ObsertextBox->Location = System::Drawing::Point(133, 412);
			this->ObsertextBox->Name = L"ObsertextBox";
			this->ObsertextBox->Size = System::Drawing::Size(464, 26);
			this->ObsertextBox->TabIndex = 60;
			// 
			// Obserlabel
			// 
			this->Obserlabel->AutoSize = true;
			this->Obserlabel->Location = System::Drawing::Point(13, 415);
			this->Obserlabel->Name = L"Obserlabel";
			this->Obserlabel->Size = System::Drawing::Size(114, 20);
			this->Obserlabel->TabIndex = 59;
			this->Obserlabel->Text = L"Observaciones";
			// 
			// Estudioslabel
			// 
			this->Estudioslabel->AutoSize = true;
			this->Estudioslabel->Location = System::Drawing::Point(13, 368);
			this->Estudioslabel->Name = L"Estudioslabel";
			this->Estudioslabel->Size = System::Drawing::Size(71, 20);
			this->Estudioslabel->TabIndex = 57;
			this->Estudioslabel->Text = L"Estudios";
			// 
			// PaistextBox
			// 
			this->PaistextBox->Enabled = false;
			this->PaistextBox->Location = System::Drawing::Point(415, 316);
			this->PaistextBox->Name = L"PaistextBox";
			this->PaistextBox->Size = System::Drawing::Size(182, 26);
			this->PaistextBox->TabIndex = 56;
			// 
			// Paislabel
			// 
			this->Paislabel->AutoSize = true;
			this->Paislabel->Location = System::Drawing::Point(322, 319);
			this->Paislabel->Name = L"Paislabel";
			this->Paislabel->Size = System::Drawing::Size(39, 20);
			this->Paislabel->TabIndex = 55;
			this->Paislabel->Text = L"País";
			// 
			// Provlabel
			// 
			this->Provlabel->AutoSize = true;
			this->Provlabel->Location = System::Drawing::Point(13, 322);
			this->Provlabel->Name = L"Provlabel";
			this->Provlabel->Size = System::Drawing::Size(72, 20);
			this->Provlabel->TabIndex = 54;
			this->Provlabel->Text = L"Provincia";
			// 
			// CPtextBox
			// 
			this->CPtextBox->Enabled = false;
			this->CPtextBox->Location = System::Drawing::Point(415, 263);
			this->CPtextBox->Name = L"CPtextBox";
			this->CPtextBox->Size = System::Drawing::Size(182, 26);
			this->CPtextBox->TabIndex = 53;
			// 
			// CPlabel
			// 
			this->CPlabel->AutoSize = true;
			this->CPlabel->Location = System::Drawing::Point(322, 266);
			this->CPlabel->Name = L"CPlabel";
			this->CPlabel->Size = System::Drawing::Size(38, 20);
			this->CPlabel->TabIndex = 52;
			this->CPlabel->Text = L"C.P.";
			// 
			// LoctextBox
			// 
			this->LoctextBox->Enabled = false;
			this->LoctextBox->Location = System::Drawing::Point(106, 263);
			this->LoctextBox->Name = L"LoctextBox";
			this->LoctextBox->Size = System::Drawing::Size(182, 26);
			this->LoctextBox->TabIndex = 51;
			// 
			// Loclabel
			// 
			this->Loclabel->AutoSize = true;
			this->Loclabel->Location = System::Drawing::Point(13, 269);
			this->Loclabel->Name = L"Loclabel";
			this->Loclabel->Size = System::Drawing::Size(77, 20);
			this->Loclabel->TabIndex = 50;
			this->Loclabel->Text = L"Localidad";
			// 
			// DirtextBox
			// 
			this->DirtextBox->Enabled = false;
			this->DirtextBox->Location = System::Drawing::Point(106, 211);
			this->DirtextBox->Name = L"DirtextBox";
			this->DirtextBox->Size = System::Drawing::Size(491, 26);
			this->DirtextBox->TabIndex = 49;
			// 
			// Dirlabel
			// 
			this->Dirlabel->AutoSize = true;
			this->Dirlabel->Location = System::Drawing::Point(13, 217);
			this->Dirlabel->Name = L"Dirlabel";
			this->Dirlabel->Size = System::Drawing::Size(75, 20);
			this->Dirlabel->TabIndex = 48;
			this->Dirlabel->Text = L"Dirección";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(389, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 20);
			this->label2->TabIndex = 47;
			this->label2->Text = L"---------------------------------------------";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 20);
			this->label1->TabIndex = 46;
			this->label1->Text = L"----------------------------------------";
			// 
			// TlftextBox
			// 
			this->TlftextBox->Enabled = false;
			this->TlftextBox->Location = System::Drawing::Point(415, 159);
			this->TlftextBox->Name = L"TlftextBox";
			this->TlftextBox->Size = System::Drawing::Size(182, 26);
			this->TlftextBox->TabIndex = 45;
			// 
			// TlfLabel
			// 
			this->TlfLabel->AutoSize = true;
			this->TlfLabel->Location = System::Drawing::Point(322, 162);
			this->TlfLabel->Name = L"TlfLabel";
			this->TlfLabel->Size = System::Drawing::Size(71, 20);
			this->TlfLabel->TabIndex = 44;
			this->TlfLabel->Text = L"Teléfono";
			// 
			// EmailtextBox
			// 
			this->EmailtextBox->Enabled = false;
			this->EmailtextBox->Location = System::Drawing::Point(106, 159);
			this->EmailtextBox->Name = L"EmailtextBox";
			this->EmailtextBox->Size = System::Drawing::Size(182, 26);
			this->EmailtextBox->TabIndex = 43;
			// 
			// EmailLabel
			// 
			this->EmailLabel->AutoSize = true;
			this->EmailLabel->Location = System::Drawing::Point(13, 162);
			this->EmailLabel->Name = L"EmailLabel";
			this->EmailLabel->Size = System::Drawing::Size(48, 20);
			this->EmailLabel->TabIndex = 42;
			this->EmailLabel->Text = L"Email";
			// 
			// ApellidotextBox2
			// 
			this->ApellidotextBox2->Enabled = false;
			this->ApellidotextBox2->Location = System::Drawing::Point(415, 100);
			this->ApellidotextBox2->Name = L"ApellidotextBox2";
			this->ApellidotextBox2->Size = System::Drawing::Size(182, 26);
			this->ApellidotextBox2->TabIndex = 41;
			// 
			// Apellidolabel2
			// 
			this->Apellidolabel2->AutoSize = true;
			this->Apellidolabel2->Location = System::Drawing::Point(322, 103);
			this->Apellidolabel2->Name = L"Apellidolabel2";
			this->Apellidolabel2->Size = System::Drawing::Size(78, 20);
			this->Apellidolabel2->TabIndex = 40;
			this->Apellidolabel2->Text = L"Apellido 2";
			// 
			// ApellidotextBox1
			// 
			this->ApellidotextBox1->Enabled = false;
			this->ApellidotextBox1->Location = System::Drawing::Point(106, 100);
			this->ApellidotextBox1->Name = L"ApellidotextBox1";
			this->ApellidotextBox1->Size = System::Drawing::Size(182, 26);
			this->ApellidotextBox1->TabIndex = 39;
			// 
			// Apellidolabel1
			// 
			this->Apellidolabel1->AutoSize = true;
			this->Apellidolabel1->Location = System::Drawing::Point(13, 106);
			this->Apellidolabel1->Name = L"Apellidolabel1";
			this->Apellidolabel1->Size = System::Drawing::Size(78, 20);
			this->Apellidolabel1->TabIndex = 38;
			this->Apellidolabel1->Text = L"Apellido 1";
			// 
			// NombretextBox
			// 
			this->NombretextBox->Enabled = false;
			this->NombretextBox->Location = System::Drawing::Point(415, 47);
			this->NombretextBox->Name = L"NombretextBox";
			this->NombretextBox->Size = System::Drawing::Size(182, 26);
			this->NombretextBox->TabIndex = 37;
			// 
			// NombreLabel
			// 
			this->NombreLabel->AutoSize = true;
			this->NombreLabel->Location = System::Drawing::Point(322, 50);
			this->NombreLabel->Name = L"NombreLabel";
			this->NombreLabel->Size = System::Drawing::Size(65, 20);
			this->NombreLabel->TabIndex = 36;
			this->NombreLabel->Text = L"Nombre";
			// 
			// TitleEstudiante
			// 
			this->TitleEstudiante->AutoSize = true;
			this->TitleEstudiante->Location = System::Drawing::Point(227, 8);
			this->TitleEstudiante->Name = L"TitleEstudiante";
			this->TitleEstudiante->Size = System::Drawing::Size(156, 20);
			this->TitleEstudiante->TabIndex = 35;
			this->TitleEstudiante->Text = L"Datos del estudiante";
			// 
			// DNItextBox
			// 
			this->DNItextBox->Location = System::Drawing::Point(106, 47);
			this->DNItextBox->Name = L"DNItextBox";
			this->DNItextBox->Size = System::Drawing::Size(182, 26);
			this->DNItextBox->TabIndex = 34;
			// 
			// DNIlabel
			// 
			this->DNIlabel->AutoSize = true;
			this->DNIlabel->Location = System::Drawing::Point(13, 50);
			this->DNIlabel->Name = L"DNIlabel";
			this->DNIlabel->Size = System::Drawing::Size(37, 20);
			this->DNIlabel->TabIndex = 33;
			this->DNIlabel->Text = L"DNI";
			// 
			// Periodlabel
			// 
			this->Periodlabel->AutoSize = true;
			this->Periodlabel->Location = System::Drawing::Point(640, 266);
			this->Periodlabel->Name = L"Periodlabel";
			this->Periodlabel->Size = System::Drawing::Size(63, 20);
			this->Periodlabel->TabIndex = 75;
			this->Periodlabel->Text = L"Periodo";
			// 
			// Estlabel
			// 
			this->Estlabel->AutoSize = true;
			this->Estlabel->Location = System::Drawing::Point(642, 162);
			this->Estlabel->Name = L"Estlabel";
			this->Estlabel->Size = System::Drawing::Size(140, 20);
			this->Estlabel->TabIndex = 73;
			this->Estlabel->Text = L"Estudios análogos";
			// 
			// UniDlabel
			// 
			this->UniDlabel->AutoSize = true;
			this->UniDlabel->Location = System::Drawing::Point(640, 103);
			this->UniDlabel->Name = L"UniDlabel";
			this->UniDlabel->Size = System::Drawing::Size(170, 20);
			this->UniDlabel->TabIndex = 71;
			this->UniDlabel->Text = L"Universidad de destino";
			// 
			// UniOlabel
			// 
			this->UniOlabel->AutoSize = true;
			this->UniOlabel->Location = System::Drawing::Point(640, 50);
			this->UniOlabel->Name = L"UniOlabel";
			this->UniOlabel->Size = System::Drawing::Size(162, 20);
			this->UniOlabel->TabIndex = 69;
			this->UniOlabel->Text = L"Universidad de origen";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1000, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(234, 20);
			this->label3->TabIndex = 68;
			this->label3->Text = L"---------------------------------------------";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(640, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(209, 20);
			this->label4->TabIndex = 67;
			this->label4->Text = L"----------------------------------------";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(863, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(131, 20);
			this->label5->TabIndex = 66;
			this->label5->Text = L"Datos del SICUE";
			// 
			// AnaEstudtextBox
			// 
			this->AnaEstudtextBox->Enabled = false;
			this->AnaEstudtextBox->Location = System::Drawing::Point(788, 159);
			this->AnaEstudtextBox->Name = L"AnaEstudtextBox";
			this->AnaEstudtextBox->Size = System::Drawing::Size(448, 26);
			this->AnaEstudtextBox->TabIndex = 79;
			// 
			// AsigtextBox
			// 
			this->AsigtextBox->Enabled = false;
			this->AsigtextBox->Location = System::Drawing::Point(786, 608);
			this->AsigtextBox->Name = L"AsigtextBox";
			this->AsigtextBox->Size = System::Drawing::Size(448, 26);
			this->AsigtextBox->TabIndex = 97;
			this->AsigtextBox->TextChanged += gcnew System::EventHandler(this, &ConsultaForm::AsigtextBox_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(641, 611);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 20);
			this->label6->TabIndex = 96;
			this->label6->Text = L"Asignaturas";
			this->label6->Click += gcnew System::EventHandler(this, &ConsultaForm::label6_Click);
			// 
			// ObserSoltextBox
			// 
			this->ObserSoltextBox->Enabled = false;
			this->ObserSoltextBox->Location = System::Drawing::Point(784, 663);
			this->ObserSoltextBox->Name = L"ObserSoltextBox";
			this->ObserSoltextBox->Size = System::Drawing::Size(448, 26);
			this->ObserSoltextBox->TabIndex = 95;
			this->ObserSoltextBox->TextChanged += gcnew System::EventHandler(this, &ConsultaForm::ObserSoltextBox_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(643, 669);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(114, 20);
			this->label7->TabIndex = 94;
			this->label7->Text = L"Observaciones";
			this->label7->Click += gcnew System::EventHandler(this, &ConsultaForm::label7_Click);
			// 
			// Centrelabel
			// 
			this->Centrelabel->AutoSize = true;
			this->Centrelabel->Location = System::Drawing::Point(643, 552);
			this->Centrelabel->Name = L"Centrelabel";
			this->Centrelabel->Size = System::Drawing::Size(57, 20);
			this->Centrelabel->TabIndex = 92;
			this->Centrelabel->Text = L"Centro";
			this->Centrelabel->Click += gcnew System::EventHandler(this, &ConsultaForm::Centrelabel_Click);
			// 
			// InformetextBox
			// 
			this->InformetextBox->Enabled = false;
			this->InformetextBox->Location = System::Drawing::Point(1096, 502);
			this->InformetextBox->Name = L"InformetextBox";
			this->InformetextBox->Size = System::Drawing::Size(136, 26);
			this->InformetextBox->TabIndex = 91;
			this->InformetextBox->TextChanged += gcnew System::EventHandler(this, &ConsultaForm::InformetextBox_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(940, 505);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(144, 20);
			this->label8->TabIndex = 90;
			this->label8->Text = L"Petición de informe";
			this->label8->Click += gcnew System::EventHandler(this, &ConsultaForm::label8_Click);
			// 
			// EntradatextBox
			// 
			this->EntradatextBox->Enabled = false;
			this->EntradatextBox->Location = System::Drawing::Point(784, 502);
			this->EntradatextBox->Name = L"EntradatextBox";
			this->EntradatextBox->Size = System::Drawing::Size(150, 26);
			this->EntradatextBox->TabIndex = 89;
			this->EntradatextBox->TextChanged += gcnew System::EventHandler(this, &ConsultaForm::EntradatextBox_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(643, 505);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(135, 20);
			this->label9->TabIndex = 88;
			this->label9->Text = L"Fecha de entrada";
			this->label9->Click += gcnew System::EventHandler(this, &ConsultaForm::label9_Click);
			// 
			// Tipolabel
			// 
			this->Tipolabel->AutoSize = true;
			this->Tipolabel->Location = System::Drawing::Point(643, 461);
			this->Tipolabel->Name = L"Tipolabel";
			this->Tipolabel->Size = System::Drawing::Size(122, 20);
			this->Tipolabel->TabIndex = 86;
			this->Tipolabel->Text = L"Tipo de solicitud";
			this->Tipolabel->Click += gcnew System::EventHandler(this, &ConsultaForm::Tipolabel_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(1005, 319);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(234, 20);
			this->label11->TabIndex = 83;
			this->label11->Text = L"---------------------------------------------";
			this->label11->Click += gcnew System::EventHandler(this, &ConsultaForm::label11_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(634, 319);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(209, 20);
			this->label12->TabIndex = 82;
			this->label12->Text = L"----------------------------------------";
			this->label12->Click += gcnew System::EventHandler(this, &ConsultaForm::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(848, 319);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(151, 20);
			this->label13->TabIndex = 81;
			this->label13->Text = L"Datos de la solicitud";
			this->label13->Click += gcnew System::EventHandler(this, &ConsultaForm::label13_Click);
			// 
			// TipoSoltextBox
			// 
			this->TipoSoltextBox->Enabled = false;
			this->TipoSoltextBox->Location = System::Drawing::Point(784, 461);
			this->TipoSoltextBox->Name = L"TipoSoltextBox";
			this->TipoSoltextBox->Size = System::Drawing::Size(448, 26);
			this->TipoSoltextBox->TabIndex = 98;
			this->TipoSoltextBox->TextChanged += gcnew System::EventHandler(this, &ConsultaForm::TipoSoltextBox_TextChanged);
			// 
			// CentroSoltextBox
			// 
			this->CentroSoltextBox->Enabled = false;
			this->CentroSoltextBox->Location = System::Drawing::Point(784, 549);
			this->CentroSoltextBox->Name = L"CentroSoltextBox";
			this->CentroSoltextBox->Size = System::Drawing::Size(448, 26);
			this->CentroSoltextBox->TabIndex = 99;
			this->CentroSoltextBox->TextChanged += gcnew System::EventHandler(this, &ConsultaForm::CentroSoltextBox_TextChanged);
			// 
			// NSoltextBox
			// 
			this->NSoltextBox->Enabled = false;
			this->NSoltextBox->Location = System::Drawing::Point(797, 365);
			this->NSoltextBox->Name = L"NSoltextBox";
			this->NSoltextBox->Size = System::Drawing::Size(146, 26);
			this->NSoltextBox->TabIndex = 101;
			this->NSoltextBox->TextChanged += gcnew System::EventHandler(this, &ConsultaForm::NSoltextBox_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(643, 368);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(148, 20);
			this->label10->TabIndex = 100;
			this->label10->Text = L"Número de solicitud";
			this->label10->Click += gcnew System::EventHandler(this, &ConsultaForm::label10_Click);
			// 
			// NEstudtextBox
			// 
			this->NEstudtextBox->Enabled = false;
			this->NEstudtextBox->Location = System::Drawing::Point(186, 461);
			this->NEstudtextBox->Name = L"NEstudtextBox";
			this->NEstudtextBox->Size = System::Drawing::Size(146, 26);
			this->NEstudtextBox->TabIndex = 103;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(14, 464);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(166, 20);
			this->label14->TabIndex = 102;
			this->label14->Text = L"Número de estudiante";
			// 
			// DoctextBox
			// 
			this->DoctextBox->Enabled = false;
			this->DoctextBox->Location = System::Drawing::Point(786, 412);
			this->DoctextBox->Name = L"DoctextBox";
			this->DoctextBox->Size = System::Drawing::Size(446, 26);
			this->DoctextBox->TabIndex = 105;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(643, 418);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(121, 20);
			this->label15->TabIndex = 104;
			this->label15->Text = L"Documentación";
			// 
			// ModifButton
			// 
			this->ModifButton->Enabled = false;
			this->ModifButton->Location = System::Drawing::Point(413, 825);
			this->ModifButton->Name = L"ModifButton";
			this->ModifButton->Size = System::Drawing::Size(92, 32);
			this->ModifButton->TabIndex = 106;
			this->ModifButton->Text = L"Modificar";
			this->ModifButton->UseVisualStyleBackColor = true;
			this->ModifButton->Visible = false;
			// 
			// SaveModifbutton
			// 
			this->SaveModifbutton->Enabled = false;
			this->SaveModifbutton->Location = System::Drawing::Point(525, 825);
			this->SaveModifbutton->Name = L"SaveModifbutton";
			this->SaveModifbutton->Size = System::Drawing::Size(92, 32);
			this->SaveModifbutton->TabIndex = 107;
			this->SaveModifbutton->Text = L"Guardar";
			this->SaveModifbutton->UseVisualStyleBackColor = true;
			this->SaveModifbutton->Visible = false;
			// 
			// BecacheckBox
			// 
			this->BecacheckBox->AutoSize = true;
			this->BecacheckBox->Enabled = false;
			this->BecacheckBox->Location = System::Drawing::Point(1115, 265);
			this->BecacheckBox->Name = L"BecacheckBox";
			this->BecacheckBox->Size = System::Drawing::Size(119, 24);
			this->BecacheckBox->TabIndex = 108;
			this->BecacheckBox->Text = L"Posee beca";
			this->BecacheckBox->UseVisualStyleBackColor = true;
			// 
			// CampustextBox
			// 
			this->CampustextBox->Enabled = false;
			this->CampustextBox->Location = System::Drawing::Point(786, 211);
			this->CampustextBox->Name = L"CampustextBox";
			this->CampustextBox->Size = System::Drawing::Size(448, 26);
			this->CampustextBox->TabIndex = 110;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(640, 214);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(68, 20);
			this->label16->TabIndex = 109;
			this->label16->Text = L"Campus";
			// 
			// TipoRescomboBox
			// 
			this->TipoRescomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TipoRescomboBox->Enabled = false;
			this->TipoRescomboBox->FormattingEnabled = true;
			this->TipoRescomboBox->Location = System::Drawing::Point(164, 721);
			this->TipoRescomboBox->Name = L"TipoRescomboBox";
			this->TipoRescomboBox->Size = System::Drawing::Size(453, 28);
			this->TipoRescomboBox->TabIndex = 125;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(23, 724);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(137, 20);
			this->label17->TabIndex = 124;
			this->label17->Text = L"Tipo de resolución";
			// 
			// ResObsertextBox
			// 
			this->ResObsertextBox->Enabled = false;
			this->ResObsertextBox->Location = System::Drawing::Point(164, 776);
			this->ResObsertextBox->Name = L"ResObsertextBox";
			this->ResObsertextBox->Size = System::Drawing::Size(453, 26);
			this->ResObsertextBox->TabIndex = 123;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(23, 779);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(114, 20);
			this->label18->TabIndex = 122;
			this->label18->Text = L"Observaciones";
			// 
			// TipoReccomboBox
			// 
			this->TipoReccomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TipoReccomboBox->Enabled = false;
			this->TipoReccomboBox->FormattingEnabled = true;
			this->TipoReccomboBox->Location = System::Drawing::Point(164, 663);
			this->TipoReccomboBox->Name = L"TipoReccomboBox";
			this->TipoReccomboBox->Size = System::Drawing::Size(453, 28);
			this->TipoReccomboBox->TabIndex = 121;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(23, 666);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(118, 20);
			this->label19->TabIndex = 120;
			this->label19->Text = L"Tipo de recurso";
			// 
			// SalidatextBox
			// 
			this->SalidatextBox->Enabled = false;
			this->SalidatextBox->Location = System::Drawing::Point(471, 608);
			this->SalidatextBox->Name = L"SalidatextBox";
			this->SalidatextBox->Size = System::Drawing::Size(146, 26);
			this->SalidatextBox->TabIndex = 118;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(333, 611);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(121, 20);
			this->label20->TabIndex = 117;
			this->label20->Text = L"Fecha de salida";
			// 
			// FirmatextBox
			// 
			this->FirmatextBox->Enabled = false;
			this->FirmatextBox->Location = System::Drawing::Point(164, 608);
			this->FirmatextBox->Name = L"FirmatextBox";
			this->FirmatextBox->Size = System::Drawing::Size(138, 26);
			this->FirmatextBox->TabIndex = 116;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(23, 611);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(115, 20);
			this->label21->TabIndex = 115;
			this->label21->Text = L"Fecha de firma";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(23, 552);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(140, 20);
			this->label22->TabIndex = 114;
			this->label22->Text = L"Nº de la resolución";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(389, 505);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(234, 20);
			this->label23->TabIndex = 113;
			this->label23->Text = L"---------------------------------------------";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(18, 505);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(204, 20);
			this->label24->TabIndex = 112;
			this->label24->Text = L"---------------------------------------";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(217, 505);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(166, 20);
			this->label25->TabIndex = 111;
			this->label25->Text = L"Datos de la resolución";
			// 
			// NRestextBox
			// 
			this->NRestextBox->Enabled = false;
			this->NRestextBox->Location = System::Drawing::Point(164, 549);
			this->NRestextBox->Name = L"NRestextBox";
			this->NRestextBox->Size = System::Drawing::Size(146, 26);
			this->NRestextBox->TabIndex = 126;
			// 
			// Tablabutton
			// 
			this->Tablabutton->Location = System::Drawing::Point(885, 837);
			this->Tablabutton->Name = L"Tablabutton";
			this->Tablabutton->Size = System::Drawing::Size(134, 32);
			this->Tablabutton->TabIndex = 127;
			this->Tablabutton->Text = L"Sacar Tabla";
			this->Tablabutton->UseVisualStyleBackColor = true;
			this->Tablabutton->Click += gcnew System::EventHandler(this, &ConsultaForm::Tablabutton_Click);
			// 
			// EstudioscomboBox
			// 
			this->EstudioscomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EstudioscomboBox->Enabled = false;
			this->EstudioscomboBox->FormattingEnabled = true;
			this->EstudioscomboBox->Location = System::Drawing::Point(106, 365);
			this->EstudioscomboBox->Name = L"EstudioscomboBox";
			this->EstudioscomboBox->Size = System::Drawing::Size(491, 28);
			this->EstudioscomboBox->TabIndex = 128;
			// 
			// ProvcomboBox
			// 
			this->ProvcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ProvcomboBox->Enabled = false;
			this->ProvcomboBox->FormattingEnabled = true;
			this->ProvcomboBox->Location = System::Drawing::Point(106, 319);
			this->ProvcomboBox->Name = L"ProvcomboBox";
			this->ProvcomboBox->Size = System::Drawing::Size(196, 28);
			this->ProvcomboBox->TabIndex = 129;
			// 
			// UniOcomboBox
			// 
			this->UniOcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->UniOcomboBox->Enabled = false;
			this->UniOcomboBox->FormattingEnabled = true;
			this->UniOcomboBox->Location = System::Drawing::Point(818, 47);
			this->UniOcomboBox->Name = L"UniOcomboBox";
			this->UniOcomboBox->Size = System::Drawing::Size(414, 28);
			this->UniOcomboBox->TabIndex = 130;
			// 
			// UniDcomboBox
			// 
			this->UniDcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->UniDcomboBox->Enabled = false;
			this->UniDcomboBox->FormattingEnabled = true;
			this->UniDcomboBox->Location = System::Drawing::Point(818, 100);
			this->UniDcomboBox->Name = L"UniDcomboBox";
			this->UniDcomboBox->Size = System::Drawing::Size(414, 28);
			this->UniDcomboBox->TabIndex = 131;
			// 
			// PeriodcomboBox
			// 
			this->PeriodcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->PeriodcomboBox->Enabled = false;
			this->PeriodcomboBox->FormattingEnabled = true;
			this->PeriodcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Medio curso", L"Curso completo" });
			this->PeriodcomboBox->Location = System::Drawing::Point(788, 261);
			this->PeriodcomboBox->Name = L"PeriodcomboBox";
			this->PeriodcomboBox->Size = System::Drawing::Size(296, 28);
			this->PeriodcomboBox->TabIndex = 132;
			// 
			// ConsultaForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(1246, 901);
			this->Controls->Add(this->PeriodcomboBox);
			this->Controls->Add(this->UniDcomboBox);
			this->Controls->Add(this->UniOcomboBox);
			this->Controls->Add(this->ProvcomboBox);
			this->Controls->Add(this->EstudioscomboBox);
			this->Controls->Add(this->Tablabutton);
			this->Controls->Add(this->NRestextBox);
			this->Controls->Add(this->TipoRescomboBox);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->ResObsertextBox);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->TipoReccomboBox);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->SalidatextBox);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->FirmatextBox);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->CampustextBox);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->BecacheckBox);
			this->Controls->Add(this->SaveModifbutton);
			this->Controls->Add(this->ModifButton);
			this->Controls->Add(this->DoctextBox);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->NEstudtextBox);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->NSoltextBox);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->CentroSoltextBox);
			this->Controls->Add(this->TipoSoltextBox);
			this->Controls->Add(this->AsigtextBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->ObserSoltextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->Centrelabel);
			this->Controls->Add(this->InformetextBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->EntradatextBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Tipolabel);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->AnaEstudtextBox);
			this->Controls->Add(this->Periodlabel);
			this->Controls->Add(this->Estlabel);
			this->Controls->Add(this->UniDlabel);
			this->Controls->Add(this->UniOlabel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->SICUEcheckBox);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->ObsertextBox);
			this->Controls->Add(this->Obserlabel);
			this->Controls->Add(this->Estudioslabel);
			this->Controls->Add(this->PaistextBox);
			this->Controls->Add(this->Paislabel);
			this->Controls->Add(this->Provlabel);
			this->Controls->Add(this->CPtextBox);
			this->Controls->Add(this->CPlabel);
			this->Controls->Add(this->LoctextBox);
			this->Controls->Add(this->Loclabel);
			this->Controls->Add(this->DirtextBox);
			this->Controls->Add(this->Dirlabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TlftextBox);
			this->Controls->Add(this->TlfLabel);
			this->Controls->Add(this->EmailtextBox);
			this->Controls->Add(this->EmailLabel);
			this->Controls->Add(this->ApellidotextBox2);
			this->Controls->Add(this->Apellidolabel2);
			this->Controls->Add(this->ApellidotextBox1);
			this->Controls->Add(this->Apellidolabel1);
			this->Controls->Add(this->NombretextBox);
			this->Controls->Add(this->NombreLabel);
			this->Controls->Add(this->TitleEstudiante);
			this->Controls->Add(this->DNItextBox);
			this->Controls->Add(this->DNIlabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(1268, 615);
			this->Name = L"ConsultaForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Consulta";
			this->Load += gcnew System::EventHandler(this, &ConsultaForm::ConsultaForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	using namespace Runtime::InteropServices;
	string  dni = (const char*)(Marshal::StringToHGlobalAnsi(this->DNItextBox->Text)).ToPointer();
	bool isSicue = false;
	try {
		auto v = this->bd->getStudentData(dni, isSicue);
		this->NombretextBox->Text = gcnew String(v[0].c_str());
		this->ApellidotextBox1->Text = gcnew String(v[1].c_str());
		this->ApellidotextBox2->Text = gcnew String(v[2].c_str());
		this->EmailtextBox->Text = gcnew String(v[3].c_str());
		this->TlftextBox->Text = gcnew String(v[4].c_str());
		this->DirtextBox->Text = gcnew String(v[5].c_str());
		this->LoctextBox->Text = gcnew String(v[6].c_str());
		this->CPtextBox->Text = gcnew String(v[7].c_str());
		this->ProvcomboBox->SelectedItem = gcnew String(v[8].c_str());
		this->PaistextBox->Text = gcnew String(v[9].c_str());
		this->EstudioscomboBox->SelectedItem = gcnew String(v[10].c_str());
		this->ObsertextBox->Text = gcnew String(v[11].c_str());
		this->NEstudtextBox->Text = gcnew String(v[12].c_str());
		this->SICUEcheckBox->Checked = isSicue;
		vector<string> lst;
		bool beca = false;
		if (isSicue)
			lst = this->bd->getSicueData(dni, beca);
		else
			for (int j = 0; j < NUM_CAMPOS_SICUE - 2; ++j)
				lst.push_back("");
		if (isSicue) {
			this->UniOcomboBox->SelectedItem = gcnew String(lst[0].c_str());
			this->UniDcomboBox->SelectedItem = gcnew String(lst[1].c_str());
			this->PeriodcomboBox->SelectedItem = gcnew String(lst[3].c_str());
		}
		else {
			this->UniOcomboBox->SelectedIndex = -1;
			this->UniDcomboBox->SelectedIndex = -1;
			this->PeriodcomboBox->SelectedIndex = -1;
		}
		this->AnaEstudtextBox->Text = gcnew String(lst[2].c_str());
		this->CampustextBox->Text = gcnew String(lst[4].c_str());
		this->BecacheckBox->Checked = beca;

		vector<string> appData;
		vector<string> resolData;
		bool isThereResol = false;
		if (bd->isThereAnApplication(dni)) {
			appData = this->bd->getApplicationData(dni);
			if (this->bd->isThereAResolution(stringToUint(appData[0]))) {
				resolData = this->bd->getResolData(stringToUint(appData[0]));
				isThereResol = true;
			}
			else
				for (int j = 0; j < NUM_CAMPOS_RESOL; ++j)
					resolData.push_back("");
		}
		else {
			for (int j = 0; j < NUM_CAMPOS_SOLIC - 1; ++j)
				appData.push_back("");
			for (int j = 0; j < NUM_CAMPOS_RESOL; ++j)
				resolData.push_back("");
		}
		this->NSoltextBox->Text = gcnew String(appData[0].c_str());
		this->TipoSoltextBox->Text = gcnew String(appData[1].c_str());
		this->AsigtextBox->Text = gcnew String(appData[2].c_str());
		this->EntradatextBox->Text = gcnew String(appData[3].c_str());
		this->InformetextBox->Text = gcnew String(appData[4].c_str());
		this->CentroSoltextBox->Text = gcnew String(appData[5].c_str());
		this->ObserSoltextBox->Text = gcnew String(appData[6].c_str());
		this->DoctextBox->Text = gcnew String(appData[7].c_str());
		
		this->NRestextBox->Text = gcnew String(resolData[0].c_str());
		this->FirmatextBox->Text = gcnew String(resolData[1].c_str());
		this->SalidatextBox->Text = gcnew String(resolData[2].c_str());
		if (isThereResol) {
			this->TipoReccomboBox->SelectedItem = gcnew String(resolData[3].c_str());
			this->TipoRescomboBox->SelectedItem = gcnew String(resolData[4].c_str());
		}
		else {
			this->TipoReccomboBox->SelectedIndex = -1;
			this->TipoRescomboBox->SelectedIndex = -1;
		}
		this->ResObsertextBox->Text = gcnew String(resolData[5].c_str());
	}
	catch (invalid_argument &e) {
		string m = "No existe ningún estudiante con el DNI introducido.";
		SGBDRasore::errorDialog ^d = gcnew SGBDRasore::errorDialog(m);
		d->ShowDialog();
		delete d;
	}
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void uniDtextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ConsultaForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ObserSoltextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void AsigtextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Centrelabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CentroSoltextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label9_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void EntradatextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void InformetextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Tipolabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void TipoSoltextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void NSoltextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Tablabutton_Click(System::Object^  sender, System::EventArgs^  e) {
	SGBDRasore::TablaEstud ^tab = gcnew SGBDRasore::TablaEstud(*this->bd);
	tab->ShowDialog();
	delete tab;
}
};
}
#endif