#ifndef GRABARESTUDIANTE_H
#define GRABARESTUDIANTE_H

#include "BaseDatos.h"
#include "SICUEForm.h"
#include <iostream>
#include <vector>
#include <string>
#include "InformationDialog.h"
#include "addStudiesForm.h"
#include "errorDialog.h"
#include "warningBooleanDialog.h"
#include "GrabarSolicitud.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de GrabarSolicitud
	/// </summary>
	public ref class GrabarEstudiante : public System::Windows::Forms::Form
	{
	public:
		GrabarEstudiante()
		{
			bd = NULL;
			InitializeComponent();
		}

		GrabarEstudiante(BaseDatos &base)
		{
			bd = &base;
			InitializeComponent();
			vector<string> lst;
			this->bd->getStudies(lst);
			for (int i = 0; i < lst.size(); ++i)
				this->EstudioscomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = this->bd->getProvinces();
			for (int i = 0; i < lst.size(); ++i)
				this->ProvcomboBox->Items->Add(gcnew String(lst[i].c_str()));
			string provDefecto = "Madrid";
			this->ProvcomboBox->SelectedItem = gcnew String(provDefecto.c_str());
		}

		GrabarEstudiante(BaseDatos&base, unordered_map<string, Estudiante_valor>::const_iterator &it,
			bool &hacerLoMismo, string &accion, bool &modificado) {
			InitializeComponent();
			bd = &base;
			dni = &(it->first);
			goOn = &hacerLoMismo;
			mod = &modificado;
			*mod = false;
			changeAction = &accion;
			this->DNItextBox->Text = gcnew String(it->first.c_str());
			this->DNItextBox->Enabled = false;
			this->NombretextBox->Text = gcnew String(it->second.Nombre.c_str());
			this->NombretextBox->Enabled = false;
			this->ApellidotextBox1->Text = gcnew String(it->second.Apellido1.c_str());
			this->ApellidotextBox1->Enabled = false;
			this->ApellidotextBox2->Text = gcnew String(it->second.Apellido2.c_str());
			this->ApellidotextBox2->Enabled = false;
			this->EmailtextBox->Text = gcnew String(it->second.Email.c_str());
			this->EmailtextBox->Enabled = false;
			this->TlftextBox->Text = gcnew String(it->second.Telefono.c_str());
			this->TlftextBox->Enabled = false;
			this->DirtextBox->Text = gcnew String(it->second.Direccion.c_str());
			this->DirtextBox->Enabled = false;
			this->LoctextBox->Text = gcnew String(it->second.Localidad.c_str());
			this->LoctextBox->Enabled = false;
			this->CPtextBox->Text = gcnew String(it->second.CP.c_str());
			this->CPtextBox->Enabled = false;
			this->PaistextBox->Text = gcnew String(it->second.Pais.c_str());
			this->PaistextBox->Enabled = false;
			this->ProvcomboBox->Items->Add(gcnew String(it->second.Provincia.c_str()));
			this->ProvcomboBox->SelectedItem = gcnew String(it->second.Provincia.c_str());
			this->ProvcomboBox->Enabled = false;
			this->ObsertextBox->Text = gcnew String(it->second.Observaciones.c_str());
			this->ObsertextBox->Enabled = false;
			this->SICUEcheckBox->Checked = this->bd->isStudentSicue(*dni);
			vector<string> lst;
			this->bd->getStudies(lst);
			for (int i = 0; i < lst.size(); ++i)
				if (lst[i] != this->bd->getStudyName(it->second.Estudios))
					this->EstudioscomboBox->Items->Add(gcnew String(lst[i].c_str()));
			this->RepeatCheckBox->Visible = true;
			this->RepeatCheckBox->Enabled = true;
			string m = "Modificar";
			this->SaveButton->Text = gcnew String(m.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrabarEstudiante()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  DNIlabel;
	private: System::Windows::Forms::TextBox^  DNItextBox;
	private: System::Windows::Forms::Label^  TitleEstudiante;
	private: System::Windows::Forms::Label^  NombreLabel;
	private: System::Windows::Forms::TextBox^  NombretextBox;
	private: System::Windows::Forms::Label^  Apellidolabel1;
	private: System::Windows::Forms::TextBox^  ApellidotextBox1;
	private: System::Windows::Forms::TextBox^  ApellidotextBox2;
	private: System::Windows::Forms::Label^  Apellidolabel2;
	private: System::Windows::Forms::TextBox^  TlftextBox;
	private: System::Windows::Forms::Label^  TlfLabel;
	private: System::Windows::Forms::TextBox^  EmailtextBox;
	private: System::Windows::Forms::Label^  EmailLabel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  Dirlabel;
	private: System::Windows::Forms::TextBox^  DirtextBox;
	private: System::Windows::Forms::TextBox^  CPtextBox;

	private: System::Windows::Forms::Label^  CPlabel;

	private: System::Windows::Forms::TextBox^  LoctextBox;

	private: System::Windows::Forms::Label^  Loclabel;
	private: System::Windows::Forms::TextBox^  PaistextBox;


	private: System::Windows::Forms::Label^  Paislabel;



	private: System::Windows::Forms::Label^  Provlabel;
	private: System::Windows::Forms::Label^  Estudioslabel;
	private: System::Windows::Forms::ComboBox^  EstudioscomboBox;

	protected:

	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		BaseDatos *bd;
		bool *goOn;
		string * changeAction;
		bool *mod;
		const string * dni;
	private: System::Windows::Forms::TextBox^  ObsertextBox;
	private: System::Windows::Forms::Label^  Obserlabel;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::CheckBox^  SICUEcheckBox;
	private: System::Windows::Forms::ComboBox^  ProvcomboBox;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  addStudiesButton;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GrabarEstudiante::typeid));
			this->DNIlabel = (gcnew System::Windows::Forms::Label());
			this->DNItextBox = (gcnew System::Windows::Forms::TextBox());
			this->TitleEstudiante = (gcnew System::Windows::Forms::Label());
			this->NombreLabel = (gcnew System::Windows::Forms::Label());
			this->NombretextBox = (gcnew System::Windows::Forms::TextBox());
			this->Apellidolabel1 = (gcnew System::Windows::Forms::Label());
			this->ApellidotextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ApellidotextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->Apellidolabel2 = (gcnew System::Windows::Forms::Label());
			this->TlftextBox = (gcnew System::Windows::Forms::TextBox());
			this->TlfLabel = (gcnew System::Windows::Forms::Label());
			this->EmailtextBox = (gcnew System::Windows::Forms::TextBox());
			this->EmailLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Dirlabel = (gcnew System::Windows::Forms::Label());
			this->DirtextBox = (gcnew System::Windows::Forms::TextBox());
			this->CPtextBox = (gcnew System::Windows::Forms::TextBox());
			this->CPlabel = (gcnew System::Windows::Forms::Label());
			this->LoctextBox = (gcnew System::Windows::Forms::TextBox());
			this->Loclabel = (gcnew System::Windows::Forms::Label());
			this->PaistextBox = (gcnew System::Windows::Forms::TextBox());
			this->Paislabel = (gcnew System::Windows::Forms::Label());
			this->Provlabel = (gcnew System::Windows::Forms::Label());
			this->Estudioslabel = (gcnew System::Windows::Forms::Label());
			this->EstudioscomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ObsertextBox = (gcnew System::Windows::Forms::TextBox());
			this->Obserlabel = (gcnew System::Windows::Forms::Label());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SICUEcheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ProvcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->addStudiesButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->RepeatCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// DNIlabel
			// 
			this->DNIlabel->AutoSize = true;
			this->DNIlabel->Location = System::Drawing::Point(32, 91);
			this->DNIlabel->Name = L"DNIlabel";
			this->DNIlabel->Size = System::Drawing::Size(37, 20);
			this->DNIlabel->TabIndex = 0;
			this->DNIlabel->Text = L"DNI";
			this->DNIlabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::DNIlabel_Click);
			// 
			// DNItextBox
			// 
			this->DNItextBox->Location = System::Drawing::Point(125, 88);
			this->DNItextBox->Name = L"DNItextBox";
			this->DNItextBox->Size = System::Drawing::Size(182, 26);
			this->DNItextBox->TabIndex = 1;
			this->DNItextBox->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::DNItextBox_TextChanged);
			// 
			// TitleEstudiante
			// 
			this->TitleEstudiante->AutoSize = true;
			this->TitleEstudiante->Location = System::Drawing::Point(246, 49);
			this->TitleEstudiante->Name = L"TitleEstudiante";
			this->TitleEstudiante->Size = System::Drawing::Size(156, 20);
			this->TitleEstudiante->TabIndex = 2;
			this->TitleEstudiante->Text = L"Datos del estudiante";
			this->TitleEstudiante->Click += gcnew System::EventHandler(this, &GrabarEstudiante::TitleEstudiante_Click);
			// 
			// NombreLabel
			// 
			this->NombreLabel->AutoSize = true;
			this->NombreLabel->Location = System::Drawing::Point(341, 91);
			this->NombreLabel->Name = L"NombreLabel";
			this->NombreLabel->Size = System::Drawing::Size(65, 20);
			this->NombreLabel->TabIndex = 3;
			this->NombreLabel->Text = L"Nombre";
			this->NombreLabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::NombreLabel_Click);
			// 
			// NombretextBox
			// 
			this->NombretextBox->Location = System::Drawing::Point(434, 88);
			this->NombretextBox->Name = L"NombretextBox";
			this->NombretextBox->Size = System::Drawing::Size(182, 26);
			this->NombretextBox->TabIndex = 4;
			this->NombretextBox->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::NombretextBox_TextChanged);
			// 
			// Apellidolabel1
			// 
			this->Apellidolabel1->AutoSize = true;
			this->Apellidolabel1->Location = System::Drawing::Point(32, 147);
			this->Apellidolabel1->Name = L"Apellidolabel1";
			this->Apellidolabel1->Size = System::Drawing::Size(78, 20);
			this->Apellidolabel1->TabIndex = 5;
			this->Apellidolabel1->Text = L"Apellido 1";
			this->Apellidolabel1->Click += gcnew System::EventHandler(this, &GrabarEstudiante::Apellidolabel1_Click);
			// 
			// ApellidotextBox1
			// 
			this->ApellidotextBox1->Location = System::Drawing::Point(125, 141);
			this->ApellidotextBox1->Name = L"ApellidotextBox1";
			this->ApellidotextBox1->Size = System::Drawing::Size(182, 26);
			this->ApellidotextBox1->TabIndex = 6;
			this->ApellidotextBox1->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::ApellidotextBox1_TextChanged);
			// 
			// ApellidotextBox2
			// 
			this->ApellidotextBox2->Location = System::Drawing::Point(434, 141);
			this->ApellidotextBox2->Name = L"ApellidotextBox2";
			this->ApellidotextBox2->Size = System::Drawing::Size(182, 26);
			this->ApellidotextBox2->TabIndex = 8;
			this->ApellidotextBox2->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::ApellidotextBox2_TextChanged);
			// 
			// Apellidolabel2
			// 
			this->Apellidolabel2->AutoSize = true;
			this->Apellidolabel2->Location = System::Drawing::Point(341, 144);
			this->Apellidolabel2->Name = L"Apellidolabel2";
			this->Apellidolabel2->Size = System::Drawing::Size(78, 20);
			this->Apellidolabel2->TabIndex = 7;
			this->Apellidolabel2->Text = L"Apellido 2";
			this->Apellidolabel2->Click += gcnew System::EventHandler(this, &GrabarEstudiante::Apellidolabel2_Click);
			// 
			// TlftextBox
			// 
			this->TlftextBox->Location = System::Drawing::Point(434, 200);
			this->TlftextBox->Name = L"TlftextBox";
			this->TlftextBox->Size = System::Drawing::Size(182, 26);
			this->TlftextBox->TabIndex = 12;
			this->TlftextBox->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::TlftextBox_TextChanged);
			// 
			// TlfLabel
			// 
			this->TlfLabel->AutoSize = true;
			this->TlfLabel->Location = System::Drawing::Point(341, 203);
			this->TlfLabel->Name = L"TlfLabel";
			this->TlfLabel->Size = System::Drawing::Size(71, 20);
			this->TlfLabel->TabIndex = 11;
			this->TlfLabel->Text = L"Teléfono";
			this->TlfLabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::TlfLabel_Click);
			// 
			// EmailtextBox
			// 
			this->EmailtextBox->Location = System::Drawing::Point(125, 200);
			this->EmailtextBox->Name = L"EmailtextBox";
			this->EmailtextBox->Size = System::Drawing::Size(182, 26);
			this->EmailtextBox->TabIndex = 10;
			this->EmailtextBox->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::EmailtextBox_TextChanged);
			// 
			// EmailLabel
			// 
			this->EmailLabel->AutoSize = true;
			this->EmailLabel->Location = System::Drawing::Point(32, 203);
			this->EmailLabel->Name = L"EmailLabel";
			this->EmailLabel->Size = System::Drawing::Size(48, 20);
			this->EmailLabel->TabIndex = 9;
			this->EmailLabel->Text = L"Email";
			this->EmailLabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::EmailLabel_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 20);
			this->label1->TabIndex = 13;
			this->label1->Text = L"----------------------------------------";
			this->label1->Click += gcnew System::EventHandler(this, &GrabarEstudiante::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(419, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 20);
			this->label2->TabIndex = 14;
			this->label2->Text = L"---------------------------------------------";
			this->label2->Click += gcnew System::EventHandler(this, &GrabarEstudiante::label2_Click);
			// 
			// Dirlabel
			// 
			this->Dirlabel->AutoSize = true;
			this->Dirlabel->Location = System::Drawing::Point(32, 258);
			this->Dirlabel->Name = L"Dirlabel";
			this->Dirlabel->Size = System::Drawing::Size(75, 20);
			this->Dirlabel->TabIndex = 15;
			this->Dirlabel->Text = L"Dirección";
			this->Dirlabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::Dirlabel_Click);
			// 
			// DirtextBox
			// 
			this->DirtextBox->Location = System::Drawing::Point(125, 252);
			this->DirtextBox->Name = L"DirtextBox";
			this->DirtextBox->Size = System::Drawing::Size(491, 26);
			this->DirtextBox->TabIndex = 16;
			this->DirtextBox->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::DirtextBox_TextChanged);
			// 
			// CPtextBox
			// 
			this->CPtextBox->Location = System::Drawing::Point(434, 304);
			this->CPtextBox->Name = L"CPtextBox";
			this->CPtextBox->Size = System::Drawing::Size(182, 26);
			this->CPtextBox->TabIndex = 20;
			this->CPtextBox->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::CPtextBox_TextChanged);
			// 
			// CPlabel
			// 
			this->CPlabel->AutoSize = true;
			this->CPlabel->Location = System::Drawing::Point(341, 307);
			this->CPlabel->Name = L"CPlabel";
			this->CPlabel->Size = System::Drawing::Size(38, 20);
			this->CPlabel->TabIndex = 19;
			this->CPlabel->Text = L"C.P.";
			this->CPlabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::label3_Click);
			// 
			// LoctextBox
			// 
			this->LoctextBox->Location = System::Drawing::Point(125, 304);
			this->LoctextBox->Name = L"LoctextBox";
			this->LoctextBox->Size = System::Drawing::Size(182, 26);
			this->LoctextBox->TabIndex = 18;
			this->LoctextBox->TextChanged += gcnew System::EventHandler(this, &GrabarEstudiante::LoctextBox_TextChanged);
			// 
			// Loclabel
			// 
			this->Loclabel->AutoSize = true;
			this->Loclabel->Location = System::Drawing::Point(32, 310);
			this->Loclabel->Name = L"Loclabel";
			this->Loclabel->Size = System::Drawing::Size(77, 20);
			this->Loclabel->TabIndex = 17;
			this->Loclabel->Text = L"Localidad";
			this->Loclabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::Loclabel_Click);
			// 
			// PaistextBox
			// 
			this->PaistextBox->Location = System::Drawing::Point(434, 357);
			this->PaistextBox->Name = L"PaistextBox";
			this->PaistextBox->Size = System::Drawing::Size(182, 26);
			this->PaistextBox->TabIndex = 24;
			this->PaistextBox->Text = L"España";
			// 
			// Paislabel
			// 
			this->Paislabel->AutoSize = true;
			this->Paislabel->Location = System::Drawing::Point(341, 360);
			this->Paislabel->Name = L"Paislabel";
			this->Paislabel->Size = System::Drawing::Size(39, 20);
			this->Paislabel->TabIndex = 23;
			this->Paislabel->Text = L"País";
			// 
			// Provlabel
			// 
			this->Provlabel->AutoSize = true;
			this->Provlabel->Location = System::Drawing::Point(32, 363);
			this->Provlabel->Name = L"Provlabel";
			this->Provlabel->Size = System::Drawing::Size(72, 20);
			this->Provlabel->TabIndex = 21;
			this->Provlabel->Text = L"Provincia";
			this->Provlabel->Click += gcnew System::EventHandler(this, &GrabarEstudiante::Provlabel_Click);
			// 
			// Estudioslabel
			// 
			this->Estudioslabel->AutoSize = true;
			this->Estudioslabel->Location = System::Drawing::Point(32, 409);
			this->Estudioslabel->Name = L"Estudioslabel";
			this->Estudioslabel->Size = System::Drawing::Size(71, 20);
			this->Estudioslabel->TabIndex = 25;
			this->Estudioslabel->Text = L"Estudios";
			// 
			// EstudioscomboBox
			// 
			this->EstudioscomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->EstudioscomboBox->FormattingEnabled = true;
			this->EstudioscomboBox->Location = System::Drawing::Point(125, 406);
			this->EstudioscomboBox->Name = L"EstudioscomboBox";
			this->EstudioscomboBox->Size = System::Drawing::Size(491, 28);
			this->EstudioscomboBox->Sorted = true;
			this->EstudioscomboBox->TabIndex = 26;
			this->EstudioscomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &GrabarEstudiante::EstudioscomboBox_SelectedIndexChanged);
			// 
			// ObsertextBox
			// 
			this->ObsertextBox->Location = System::Drawing::Point(152, 460);
			this->ObsertextBox->Name = L"ObsertextBox";
			this->ObsertextBox->Size = System::Drawing::Size(464, 26);
			this->ObsertextBox->TabIndex = 28;
			// 
			// Obserlabel
			// 
			this->Obserlabel->AutoSize = true;
			this->Obserlabel->Location = System::Drawing::Point(32, 463);
			this->Obserlabel->Name = L"Obserlabel";
			this->Obserlabel->Size = System::Drawing::Size(114, 20);
			this->Obserlabel->TabIndex = 27;
			this->Obserlabel->Text = L"Observaciones";
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(415, 555);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(92, 32);
			this->SaveButton->TabIndex = 29;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &GrabarEstudiante::SaveButton_Click);
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(525, 555);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 30;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &GrabarEstudiante::Cancelbutton_Click);
			// 
			// SICUEcheckBox
			// 
			this->SICUEcheckBox->AutoSize = true;
			this->SICUEcheckBox->Location = System::Drawing::Point(251, 504);
			this->SICUEcheckBox->Name = L"SICUEcheckBox";
			this->SICUEcheckBox->Size = System::Drawing::Size(365, 24);
			this->SICUEcheckBox->TabIndex = 31;
			this->SICUEcheckBox->Text = L"Solicitud de estudiante SICUE (marcar si lo es)";
			this->SICUEcheckBox->UseVisualStyleBackColor = true;
			this->SICUEcheckBox->CheckedChanged += gcnew System::EventHandler(this, &GrabarEstudiante::checkBox1_CheckedChanged);
			// 
			// ProvcomboBox
			// 
			this->ProvcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->ProvcomboBox->FormattingEnabled = true;
			this->ProvcomboBox->Location = System::Drawing::Point(125, 360);
			this->ProvcomboBox->Name = L"ProvcomboBox";
			this->ProvcomboBox->Size = System::Drawing::Size(182, 28);
			this->ProvcomboBox->Sorted = true;
			this->ProvcomboBox->TabIndex = 32;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addStudiesButton });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(665, 32);
			this->toolStrip1->TabIndex = 33;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// addStudiesButton
			// 
			this->addStudiesButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->addStudiesButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addStudiesButton.Image")));
			this->addStudiesButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->addStudiesButton->Name = L"addStudiesButton";
			this->addStudiesButton->Size = System::Drawing::Size(197, 29);
			this->addStudiesButton->Text = L"Añadir nueva titulación";
			this->addStudiesButton->Click += gcnew System::EventHandler(this, &GrabarEstudiante::addStudiesButton_Click);
			// 
			// RepeatCheckBox
			// 
			this->RepeatCheckBox->AutoSize = true;
			this->RepeatCheckBox->Enabled = false;
			this->RepeatCheckBox->Location = System::Drawing::Point(36, 560);
			this->RepeatCheckBox->Name = L"RepeatCheckBox";
			this->RepeatCheckBox->Size = System::Drawing::Size(358, 24);
			this->RepeatCheckBox->TabIndex = 54;
			this->RepeatCheckBox->Text = L"Hacer lo mismo para los siguientes elementos";
			this->RepeatCheckBox->UseVisualStyleBackColor = true;
			this->RepeatCheckBox->Visible = false;
			// 
			// GrabarEstudiante
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(665, 602);
			this->Controls->Add(this->RepeatCheckBox);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->ProvcomboBox);
			this->Controls->Add(this->SICUEcheckBox);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->ObsertextBox);
			this->Controls->Add(this->Obserlabel);
			this->Controls->Add(this->EstudioscomboBox);
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
			this->Name = L"GrabarEstudiante";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Grabar estudiante";
			this->Load += gcnew System::EventHandler(this, &GrabarEstudiante::GrabarEstudiante_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DNItextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void EstudioscomboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->ProvcomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar la provincia de residencia del estudiante.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->EstudioscomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar la titulación del estudiante.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		using namespace Runtime::InteropServices;
		string botonTexto = "Guardar";
		if (this->SaveButton->Text == gcnew String(botonTexto.c_str())) {
			string  dni = (const char*)(Marshal::StringToHGlobalAnsi(this->DNItextBox->Text)).ToPointer();
			string  name = (const char*)(Marshal::StringToHGlobalAnsi(this->NombretextBox->Text)).ToPointer();
			string  surname1 = (const char*)(Marshal::StringToHGlobalAnsi(this->ApellidotextBox1->Text)).ToPointer();
			string  surname2 = (const char*)(Marshal::StringToHGlobalAnsi(this->ApellidotextBox2->Text)).ToPointer();
			string  email = (const char*)(Marshal::StringToHGlobalAnsi(this->EmailtextBox->Text)).ToPointer();
			string  tlf = (const char*)(Marshal::StringToHGlobalAnsi(this->TlftextBox->Text)).ToPointer();
			string  dir = (const char*)(Marshal::StringToHGlobalAnsi(this->DirtextBox->Text)).ToPointer();
			string  loc = (const char*)(Marshal::StringToHGlobalAnsi(this->LoctextBox->Text)).ToPointer();
			string  cp = (const char*)(Marshal::StringToHGlobalAnsi(this->CPtextBox->Text)).ToPointer();
			string  prov = (const char*)(Marshal::StringToHGlobalAnsi(this->ProvcomboBox->SelectedItem->ToString())).ToPointer();
			string  pais = (const char*)(Marshal::StringToHGlobalAnsi(this->PaistextBox->Text)).ToPointer();
			string  obser = (const char*)(Marshal::StringToHGlobalAnsi(this->ObsertextBox->Text)).ToPointer();
			string stud = (const char*)(Marshal::StringToHGlobalAnsi(this->EstudioscomboBox->SelectedItem->ToString())).ToPointer();
			try {
				unsigned int ident = this->bd->insertStudent(dni, name, surname1, surname2, tlf, email, dir, loc, cp, prov, pais, obser, stud);
				if (this->SICUEcheckBox->Checked) {
					this->Hide();
					SGBDRasore::SICUEForm ^dialog = gcnew SGBDRasore::SICUEForm(*bd, dni);
					dialog->ShowDialog();
					delete dialog;
					string m = "El estudiante ha sido añadido correctamente a la base de datos.\nEl identificador del estudiante grabado es: " +
						uintToString(ident);
					SGBDRasore::InformationDialog ^d = gcnew SGBDRasore::InformationDialog(m);
					d->ShowDialog();
					Close();
					delete d;
				}
				else {
					bool doIt = false;
					string m = "El estudiante ha sido añadido correctamente a la base de datos.\nEl identificador del estudiante grabado es: " +
						uintToString(ident) + "\n¿Desea continuar tramitando una solicitud?";
					SGBDRasore::warningBooleanDialog ^dialog = gcnew SGBDRasore::warningBooleanDialog(doIt, m);
					dialog->ShowDialog();
					delete dialog;
					if (doIt) {
						this->Hide();
						SGBDRasore::GrabarSolicitud ^d = gcnew SGBDRasore::GrabarSolicitud(*bd, dni);
						d->ShowDialog();
						delete d;
						Close();
					}
					else
						Close();
				}
			}
			catch (invalid_argument &e) {
				string mensaje = e.what();
				mensaje.append("Añada la titulación deseada a la base de datos.");
				SGBDRasore::errorDialog ^dialog = gcnew SGBDRasore::errorDialog(mensaje);
				dialog->ShowDialog();
				delete dialog;
			}
			catch (domain_error &e) {
				string mensaje = "El DNI que se desea insertar ya se encuentra en la base de datos.\n¿Desea reemplazar los datos (se borrarían todos los datos relacionados con dicho DNI)?";
				bool doIt = false;
				SGBDRasore::warningBooleanDialog ^dialog = gcnew SGBDRasore::warningBooleanDialog(doIt, mensaje);
				dialog->ShowDialog();
				delete dialog;
				if (doIt) {
					this->bd->deleteStudent(dni);
					unsigned int iden = this->bd->insertStudent(dni, name, surname1, surname2, tlf, email, dir, loc, cp, prov, pais, obser, stud);
					if (this->SICUEcheckBox->Checked) {
						this->Hide();
						SGBDRasore::SICUEForm ^dSicue = gcnew SGBDRasore::SICUEForm(*bd, dni);
						dSicue->ShowDialog();
						delete dSicue;
						string m = "El estudiante ha sido añadido correctamente a la base de datos.\nEl identificador del estudiante grabado es: " +
							uintToString(iden);
						SGBDRasore::InformationDialog ^dInfor = gcnew SGBDRasore::InformationDialog(m);
						dInfor->ShowDialog();
						delete dInfor;
						Close();
					}
					else {
						bool grabar = false;
						string m = "El estudiante ha sido añadido correctamente a la base de datos.\nEl identificador del estudiante grabado es: " +
							uintToString(iden) + "\n¿Desea continuar tramitando una solicitud?";
						SGBDRasore::warningBooleanDialog ^dWarn = gcnew SGBDRasore::warningBooleanDialog(grabar, m);
						dWarn->ShowDialog();
						delete dWarn;
						if (grabar) {
							this->Hide();
							SGBDRasore::GrabarSolicitud ^d = gcnew SGBDRasore::GrabarSolicitud(*bd, dni);
							d->ShowDialog();
							delete d;
							Close();
						}
						else
							Close();
					}
				}
			}
		}
		else {
			string aux;
			unsigned int s;
			if (*changeAction == "Titulación") {
				aux = (const char*)(Marshal::StringToHGlobalAnsi(this->EstudioscomboBox->SelectedItem->ToString())).ToPointer();
				s = this->bd->getStudyID(aux);
				this->bd->setStudyInStudent(*dni, s);
				auto vApp = this->bd->getAppFromStudent(*dni);
				for (int i = 0; i < vApp.size(); ++i)
					for (int j = 0; j < vApp[i]->second.Asignaturas.size(); ++j)
						this->bd->setStudyOfSubject(vApp[i]->second.Asignaturas[j], s);
			}
			*goOn = this->RepeatCheckBox->Checked;
			if (*goOn)
				*changeAction = aux;
			*mod = true;
			Close();
		}
	}
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void addStudiesButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	SGBDRasore::addStudiesForm ^dialog = gcnew SGBDRasore::addStudiesForm(*bd);
	dialog->ShowDialog();
	delete dialog;
	this->EstudioscomboBox->Items->Clear();
	vector<string> lst;
	this->bd->getStudies(lst);
	for (int i = 0; i < lst.size(); ++i)
		this->EstudioscomboBox->Items->Add(gcnew String(lst[i].c_str()));
	this->Show();
}
private: System::Void GrabarEstudiante_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void TitleEstudiante_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void DNIlabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void NombreLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void NombretextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Apellidolabel1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ApellidotextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Apellidolabel2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ApellidotextBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void EmailLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void EmailtextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void TlfLabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void TlftextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Dirlabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void DirtextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Loclabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LoctextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CPtextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Provlabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
#endif