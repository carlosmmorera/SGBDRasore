#ifndef GRABARSOLICITUD_H
#define GRABARSOLICITUD_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "BaseDatos.h"
#include "gestorArchivos.h"
#include "InformationDialog.h"
#include "errorDialog.h"
#include "warningBooleanDialog.h"
#include "addCentre.h"
#include "addTypeOf.h"

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
	public ref class GrabarSolicitud : public System::Windows::Forms::Form
	{
	public:
		GrabarSolicitud(void)
		{
			InitializeComponent();
			bd = nullptr;
		}

		GrabarSolicitud(BaseDatos &base, const string &str) {
			InitializeComponent();
			bd = &base;
			this->DNItextBox->Text = gcnew String(str.c_str());
			auto lst = bd->getApplicationTypes();
			for (int i = 0; i < lst.size(); ++i)
				this->TipocomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getCentres();
			for (int i = 0; i < lst.size(); ++i)
				this->CentrecomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getDocumentation();
			for (int i = 0; i < lst.size(); ++i)
				this->DoccomboBox->Items->Add(gcnew String(lst[i].c_str()));
		}

		GrabarSolicitud(BaseDatos &base) {
			InitializeComponent();
			bd = &base;
			auto lst = bd->getApplicationTypes();
			for (int i = 0; i < lst.size(); ++i)
				this->TipocomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getCentres();
			for (int i = 0; i < lst.size(); ++i)
				this->CentrecomboBox->Items->Add(gcnew String(lst[i].c_str()));
			lst = bd->getDocumentation();
			for (int i = 0; i < lst.size(); ++i)
				this->DoccomboBox->Items->Add(gcnew String(lst[i].c_str()));
		}

		GrabarSolicitud(BaseDatos &base, unordered_map<unsigned int, Solicitud_valor>::const_iterator &it,
			bool &hacerLoMismo, string &accion, bool &modificado) {
			InitializeComponent();
			bd = &base;
			ide = it->first;
			goOn = &hacerLoMismo;
			changeAction = &accion;
			mod = &modificado;
			*mod = false;
			this->DNItextBox->Text = gcnew String((*(it->second.DNI)).c_str());
			this->DNItextBox->Enabled = false;
			if (accion != "Tipo") {
				this->TipocomboBox->Items->Add(gcnew String((*(it->second.Tipo)).c_str()));
				this->TipocomboBox->SelectedItem = gcnew String((*(it->second.Tipo)).c_str());
				this->TipocomboBox->Enabled = false;
			}
			else {
				auto lst = bd->getApplicationTypes();
				for (int i = 0; i < lst.size(); ++i)
					if (lst[i] != *it->second.Tipo)
						this->TipocomboBox->Items->Add(gcnew String(lst[i].c_str()));
			}
			if (accion != "Centro") {
				this->CentrecomboBox->Items->Add(gcnew String(base.getCentreName(it->second.Centro).c_str()));
				this->CentrecomboBox->SelectedItem = gcnew String(base.getCentreName(it->second.Centro).c_str());
				this->CentrecomboBox->Enabled = false;
			}
			else {
				auto lst = bd->getCentres();
				for (int i = 0; i < lst.size(); ++i)
					if (lst[i] != base.getCentreName(it->second.Centro))
						this->CentrecomboBox->Items->Add(gcnew String(lst[i].c_str()));
			}
			if (accion != "Documentación") {
				this->DoccomboBox->Items->Add(gcnew String((*it->second.Documentacion).c_str()));
				this->DoccomboBox->SelectedItem = gcnew String((*it->second.Documentacion).c_str());
				this->DoccomboBox->Enabled = false;
			}
			else {
				auto lst = bd->getDocumentation();
				for (int i = 0; i < lst.size(); ++i)
					if (lst[i] != *it->second.Documentacion)
						this->DoccomboBox->Items->Add(gcnew String(lst[i].c_str()));
			}
			if (it->second.hasEntradaDate())
				this->EntradatextBox->Text = gcnew String(dateToString(it->second.Entrada).c_str());
			this->EntradatextBox->Enabled = false;
			if (it->second.hasInformeDate())
				this->InformetextBox->Text = gcnew String(dateToString(it->second.Informe).c_str());
			this->InformetextBox->Enabled = false;
			this->ObsertextBox->Text = gcnew String(it->second.Observaciones.c_str());
			this->ObsertextBox->Enabled = false;
			string asignat = "";
			for (int i = 0; i < it->second.Asignaturas.size(); ++i)
				asignat = base.getSubjectName(it->second.Asignaturas[i]) + ";";
			this->AsigtextBox->Text = gcnew String(asignat.c_str());
			this->AsigtextBox->Enabled = false;
			this->RepeatCheckBox->Visible = true;
			this->RepeatCheckBox->Enabled = true;
			string m = "Modificar";
			this->SaveButton->Text = gcnew String(m.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrabarSolicitud()
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
		string *changeAction;
		bool *mod;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  TitleEstudiante;
	private: System::Windows::Forms::TextBox^  DNItextBox;
	private: System::Windows::Forms::Label^  DNIlabel;
	private: System::Windows::Forms::Label^  Tipolabel;
	private: System::Windows::Forms::ComboBox^  TipocomboBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  EntradatextBox;
	private: System::Windows::Forms::TextBox^  InformetextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  CentrecomboBox;
	private: System::Windows::Forms::Label^  Centrelabel;
	private: System::Windows::Forms::TextBox^  ObsertextBox;
	private: System::Windows::Forms::Label^  Obserlabel;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  TipoButton;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  CentroButton;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  AsigtextBox;
	private: System::Windows::Forms::ComboBox^  DoccomboBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ToolStripButton^  DoctoolStripButton;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GrabarSolicitud::typeid));
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TitleEstudiante = (gcnew System::Windows::Forms::Label());
			this->DNItextBox = (gcnew System::Windows::Forms::TextBox());
			this->DNIlabel = (gcnew System::Windows::Forms::Label());
			this->Tipolabel = (gcnew System::Windows::Forms::Label());
			this->TipocomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->EntradatextBox = (gcnew System::Windows::Forms::TextBox());
			this->InformetextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->CentrecomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Centrelabel = (gcnew System::Windows::Forms::Label());
			this->ObsertextBox = (gcnew System::Windows::Forms::TextBox());
			this->Obserlabel = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->TipoButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->DoctoolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->CentroButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->AsigtextBox = (gcnew System::Windows::Forms::TextBox());
			this->DoccomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->RepeatCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(526, 428);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 35;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &GrabarSolicitud::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(401, 428);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(107, 32);
			this->SaveButton->TabIndex = 34;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &GrabarSolicitud::SaveButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(385, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 20);
			this->label2->TabIndex = 33;
			this->label2->Text = L"---------------------------------------------";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(14, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 20);
			this->label1->TabIndex = 32;
			this->label1->Text = L"----------------------------------------";
			// 
			// TitleEstudiante
			// 
			this->TitleEstudiante->AutoSize = true;
			this->TitleEstudiante->Location = System::Drawing::Point(228, 39);
			this->TitleEstudiante->Name = L"TitleEstudiante";
			this->TitleEstudiante->Size = System::Drawing::Size(151, 20);
			this->TitleEstudiante->TabIndex = 31;
			this->TitleEstudiante->Text = L"Datos de la solicitud";
			// 
			// DNItextBox
			// 
			this->DNItextBox->Location = System::Drawing::Point(166, 77);
			this->DNItextBox->Name = L"DNItextBox";
			this->DNItextBox->Size = System::Drawing::Size(182, 26);
			this->DNItextBox->TabIndex = 37;
			// 
			// DNIlabel
			// 
			this->DNIlabel->AutoSize = true;
			this->DNIlabel->Location = System::Drawing::Point(21, 80);
			this->DNIlabel->Name = L"DNIlabel";
			this->DNIlabel->Size = System::Drawing::Size(118, 20);
			this->DNIlabel->TabIndex = 36;
			this->DNIlabel->Text = L"DNI Estudiante";
			// 
			// Tipolabel
			// 
			this->Tipolabel->AutoSize = true;
			this->Tipolabel->Location = System::Drawing::Point(21, 126);
			this->Tipolabel->Name = L"Tipolabel";
			this->Tipolabel->Size = System::Drawing::Size(39, 20);
			this->Tipolabel->TabIndex = 38;
			this->Tipolabel->Text = L"Tipo";
			// 
			// TipocomboBox
			// 
			this->TipocomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TipocomboBox->FormattingEnabled = true;
			this->TipocomboBox->Location = System::Drawing::Point(166, 123);
			this->TipocomboBox->Name = L"TipocomboBox";
			this->TipocomboBox->Size = System::Drawing::Size(353, 28);
			this->TipocomboBox->TabIndex = 39;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 219);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 20);
			this->label3->TabIndex = 40;
			this->label3->Text = L"Fecha de entrada";
			// 
			// EntradatextBox
			// 
			this->EntradatextBox->Location = System::Drawing::Point(164, 216);
			this->EntradatextBox->Name = L"EntradatextBox";
			this->EntradatextBox->Size = System::Drawing::Size(108, 26);
			this->EntradatextBox->TabIndex = 41;
			this->EntradatextBox->Text = L"01/01/2010";
			// 
			// InformetextBox
			// 
			this->InformetextBox->Location = System::Drawing::Point(498, 216);
			this->InformetextBox->Name = L"InformetextBox";
			this->InformetextBox->Size = System::Drawing::Size(108, 26);
			this->InformetextBox->TabIndex = 43;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(278, 219);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(214, 20);
			this->label4->TabIndex = 42;
			this->label4->Text = L"Fecha de petición de informe";
			// 
			// CentrecomboBox
			// 
			this->CentrecomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->CentrecomboBox->FormattingEnabled = true;
			this->CentrecomboBox->Location = System::Drawing::Point(164, 265);
			this->CentrecomboBox->Name = L"CentrecomboBox";
			this->CentrecomboBox->Size = System::Drawing::Size(453, 28);
			this->CentrecomboBox->Sorted = true;
			this->CentrecomboBox->TabIndex = 50;
			// 
			// Centrelabel
			// 
			this->Centrelabel->AutoSize = true;
			this->Centrelabel->Location = System::Drawing::Point(19, 268);
			this->Centrelabel->Name = L"Centrelabel";
			this->Centrelabel->Size = System::Drawing::Size(57, 20);
			this->Centrelabel->TabIndex = 49;
			this->Centrelabel->Text = L"Centro";
			this->Centrelabel->Click += gcnew System::EventHandler(this, &GrabarSolicitud::Centrelabel_Click);
			// 
			// ObsertextBox
			// 
			this->ObsertextBox->Location = System::Drawing::Point(164, 379);
			this->ObsertextBox->Name = L"ObsertextBox";
			this->ObsertextBox->Size = System::Drawing::Size(453, 26);
			this->ObsertextBox->TabIndex = 52;
			// 
			// Obserlabel
			// 
			this->Obserlabel->AutoSize = true;
			this->Obserlabel->Location = System::Drawing::Point(19, 382);
			this->Obserlabel->Name = L"Obserlabel";
			this->Obserlabel->Size = System::Drawing::Size(114, 20);
			this->Obserlabel->TabIndex = 51;
			this->Obserlabel->Text = L"Observaciones";
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->TipoButton, this->toolStripSeparator1,
					this->DoctoolStripButton, this->toolStripSeparator2, this->CentroButton
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(631, 32);
			this->toolStrip1->TabIndex = 53;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// TipoButton
			// 
			this->TipoButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->TipoButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TipoButton.Image")));
			this->TipoButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->TipoButton->Name = L"TipoButton";
			this->TipoButton->Size = System::Drawing::Size(201, 29);
			this->TipoButton->Text = L"Añadir tipo de solicitud";
			this->TipoButton->Click += gcnew System::EventHandler(this, &GrabarSolicitud::TipoButton_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 32);
			// 
			// DoctoolStripButton
			// 
			this->DoctoolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->DoctoolStripButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DoctoolStripButton.Image")));
			this->DoctoolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->DoctoolStripButton->Name = L"DoctoolStripButton";
			this->DoctoolStripButton->Size = System::Drawing::Size(233, 29);
			this->DoctoolStripButton->Text = L"Añadir tipo documentación";
			this->DoctoolStripButton->Click += gcnew System::EventHandler(this, &GrabarSolicitud::DoctoolStripButton_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 32);
			// 
			// CentroButton
			// 
			this->CentroButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->CentroButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CentroButton.Image")));
			this->CentroButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->CentroButton->Name = L"CentroButton";
			this->CentroButton->Size = System::Drawing::Size(126, 29);
			this->CentroButton->Text = L"Añadir Centro";
			this->CentroButton->Click += gcnew System::EventHandler(this, &GrabarSolicitud::CentroButton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 310);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(565, 20);
			this->label5->TabIndex = 54;
			this->label5->Text = L"Añadir asignaturas a la solicitud (escribir cada una de ellas separándolas por \';"
				L"\')";
			// 
			// AsigtextBox
			// 
			this->AsigtextBox->Location = System::Drawing::Point(23, 333);
			this->AsigtextBox->Name = L"AsigtextBox";
			this->AsigtextBox->Size = System::Drawing::Size(594, 26);
			this->AsigtextBox->TabIndex = 55;
			// 
			// DoccomboBox
			// 
			this->DoccomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->DoccomboBox->FormattingEnabled = true;
			this->DoccomboBox->Location = System::Drawing::Point(166, 170);
			this->DoccomboBox->Name = L"DoccomboBox";
			this->DoccomboBox->Size = System::Drawing::Size(353, 28);
			this->DoccomboBox->TabIndex = 57;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 173);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(121, 20);
			this->label6->TabIndex = 56;
			this->label6->Text = L"Documentación";
			// 
			// RepeatCheckBox
			// 
			this->RepeatCheckBox->AutoSize = true;
			this->RepeatCheckBox->Enabled = false;
			this->RepeatCheckBox->Location = System::Drawing::Point(25, 433);
			this->RepeatCheckBox->Name = L"RepeatCheckBox";
			this->RepeatCheckBox->Size = System::Drawing::Size(358, 24);
			this->RepeatCheckBox->TabIndex = 58;
			this->RepeatCheckBox->Text = L"Hacer lo mismo para los siguientes elementos";
			this->RepeatCheckBox->UseVisualStyleBackColor = true;
			this->RepeatCheckBox->Visible = false;
			// 
			// GrabarSolicitud
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(631, 475);
			this->Controls->Add(this->RepeatCheckBox);
			this->Controls->Add(this->DoccomboBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->AsigtextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->ObsertextBox);
			this->Controls->Add(this->Obserlabel);
			this->Controls->Add(this->CentrecomboBox);
			this->Controls->Add(this->Centrelabel);
			this->Controls->Add(this->InformetextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->EntradatextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TipocomboBox);
			this->Controls->Add(this->Tipolabel);
			this->Controls->Add(this->DNItextBox);
			this->Controls->Add(this->DNIlabel);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TitleEstudiante);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GrabarSolicitud";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Grabar solicitud";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Centrelabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}
private: System::Void TipoButton_Click(System::Object^  sender, System::EventArgs^  e) {
	string mensaje = "solicitud.";
	SGBDRasore::addTypeOf ^dialog = gcnew SGBDRasore::addTypeOf(*bd, mensaje);
	dialog->ShowDialog();
	delete dialog;
	this->TipocomboBox->Items->Clear();
	auto lst = bd->getApplicationTypes();
	for (int i = 0; i < lst.size(); ++i)
		this->TipocomboBox->Items->Add(gcnew String(lst[i].c_str()));
}
private: System::Void CentroButton_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->TipocomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar el tipo de la solicitud.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->DoccomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar el tipo de documentación de la solicitud.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->CentrecomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar el centro de la solicitud.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		string botonTexto = "Guardar";
		if (this->SaveButton->Text == gcnew String(botonTexto.c_str())) {
			using namespace Runtime::InteropServices;
			string  dni = (const char*)(Marshal::StringToHGlobalAnsi(this->DNItextBox->Text)).ToPointer();
			try {
				unsigned int study = bd->getStudyOfStudent(dni);
				string tipo = (const char*)(Marshal::StringToHGlobalAnsi(this->TipocomboBox->SelectedItem->ToString())).ToPointer();
				string doc = (const char*)(Marshal::StringToHGlobalAnsi(this->DoccomboBox->SelectedItem->ToString())).ToPointer();
				string entrada = (const char*)(Marshal::StringToHGlobalAnsi(this->EntradatextBox->Text)).ToPointer();
				string informe = (const char*)(Marshal::StringToHGlobalAnsi(this->InformetextBox->Text)).ToPointer();
				string centro = (const char*)(Marshal::StringToHGlobalAnsi(this->CentrecomboBox->SelectedItem->ToString())).ToPointer();
				string asignaturas = (const char*)(Marshal::StringToHGlobalAnsi(this->AsigtextBox->Text)).ToPointer();
				string obser = (const char*)(Marshal::StringToHGlobalAnsi(this->ObsertextBox->Text)).ToPointer();

				if ((entrada != "" && !isDateCorrect(entrada)) || (informe != "" && !isDateCorrect(informe))) {
					string mensaje = "Formato de fecha introducida erróneo.\nDebe introducir una fecha de la forma dd/mm/aaaa";
					SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
					dError->ShowDialog();
					delete dError;
				}
				else {
					unsigned int ident = this->bd->insertApplication(dni, tipo, entrada, informe, centro, obser, asignaturas, study, doc);
					string mensaje = "La solicitud ha sido añadida correctamente a la base de datos.\nEl identificador de la solicitud grabada es: "
						+ uintToString(ident);
					SGBDRasore::InformationDialog ^dInfor = gcnew SGBDRasore::InformationDialog(mensaje);
					dInfor->ShowDialog();
					delete dInfor;
					Close();
				}
			}
			catch (invalid_argument &e) {
				string mensaje = e.what();
				SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
				dError->ShowDialog();
				delete dError;
			}
		}
		else {
			string aux;
			using namespace Runtime::InteropServices;
			if (*changeAction == "Centro") {
				aux = (const char*)(Marshal::StringToHGlobalAnsi(this->CentrecomboBox->SelectedItem->ToString())).ToPointer();
				this->bd->setCentreInApplication(ide, this->bd->getCentreId(aux));
			}
			else if (*changeAction == "Tipo") {
				aux = (const char*)(Marshal::StringToHGlobalAnsi(this->TipocomboBox->SelectedItem->ToString())).ToPointer();
				this->bd->setTypeInApplication(ide, aux);
			}
			else if (*changeAction == "Documentación") {
				aux = (const char*)(Marshal::StringToHGlobalAnsi(this->DoccomboBox->SelectedItem->ToString())).ToPointer();
				this->bd->setDocInApplication(ide, aux);
			}
			*goOn = this->RepeatCheckBox->Checked;
			if (*goOn)
				*changeAction = aux;
			*mod = true;
			Close();
		}
	}
}
private: System::Void DoctoolStripButton_Click(System::Object^  sender, System::EventArgs^  e) {
	string mensaje = "documentación.";
	SGBDRasore::addTypeOf ^dialog = gcnew SGBDRasore::addTypeOf(*bd, mensaje);
	dialog->ShowDialog();
	delete dialog;
	this->DoccomboBox->Items->Clear();
	auto lst = bd->getDocumentation();
	for (int i = 0; i < lst.size(); ++i)
		this->DoccomboBox->Items->Add(gcnew String(lst[i].c_str()));
}
};
}
#endif