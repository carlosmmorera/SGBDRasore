#ifndef GRABARRESOLUCION_H
#define GRABARRESOLUCION_H

#include <iostream>
#include <string>
#include "BaseDatos.h"
#include "gestorArchivos.h"
#include "InformationDialog.h"
#include "errorDialog.h"
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
	/// Resumen de GrabarResolucion
	/// </summary>
	public ref class GrabarResolucion : public System::Windows::Forms::Form
	{
	public:
		GrabarResolucion(void)
		{
			InitializeComponent();
		}

		GrabarResolucion(BaseDatos &base, const vector<string> &nSol) {
			InitializeComponent();
			bd = &base;
			for (int i = 0; i < nSol.size(); ++i)
				this->NSolcomboBox->Items->Add(gcnew String(nSol[i].c_str()));
			auto tRec = this->bd->getResourceTypes();
			for (int j = 0; j < tRec.size(); ++j)
				this->TipoReccomboBox->Items->Add(gcnew String(tRec[j].c_str()));
			auto tRes = this->bd->getResolutionTypes();
			for (int k = 0; k < tRes.size(); ++k)
				this->TipoRescomboBox->Items->Add(gcnew String(tRes[k].c_str()));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~GrabarResolucion()
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
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  addTypeResButton;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  TitleEstudiante;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  FirmatextBox;
	private: System::Windows::Forms::TextBox^  SalidatextBox;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  NSolcomboBox;
	private: System::Windows::Forms::ComboBox^  TipoReccomboBox;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  ObsertextBox;
	private: System::Windows::Forms::ComboBox^  TipoRescomboBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;


			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GrabarResolucion::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->addTypeResButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TitleEstudiante = (gcnew System::Windows::Forms::Label());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->FirmatextBox = (gcnew System::Windows::Forms::TextBox());
			this->SalidatextBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->NSolcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->TipoReccomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ObsertextBox = (gcnew System::Windows::Forms::TextBox());
			this->TipoRescomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toolStripButton1,
					this->toolStripSeparator1, this->addTypeResButton
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(618, 32);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(193, 29);
			this->toolStripButton1->Text = L"Añadir tipo de recurso";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &GrabarResolucion::toolStripButton1_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 32);
			// 
			// addTypeResButton
			// 
			this->addTypeResButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->addTypeResButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addTypeResButton.Image")));
			this->addTypeResButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->addTypeResButton->Name = L"addTypeResButton";
			this->addTypeResButton->Size = System::Drawing::Size(216, 29);
			this->addTypeResButton->Text = L"Añadir tipo de resolución";
			this->addTypeResButton->Click += gcnew System::EventHandler(this, &GrabarResolucion::addTypeResButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(378, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 20);
			this->label2->TabIndex = 36;
			this->label2->Text = L"---------------------------------------------";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(204, 20);
			this->label1->TabIndex = 35;
			this->label1->Text = L"---------------------------------------";
			// 
			// TitleEstudiante
			// 
			this->TitleEstudiante->AutoSize = true;
			this->TitleEstudiante->Location = System::Drawing::Point(206, 32);
			this->TitleEstudiante->Name = L"TitleEstudiante";
			this->TitleEstudiante->Size = System::Drawing::Size(166, 20);
			this->TitleEstudiante->TabIndex = 34;
			this->TitleEstudiante->Text = L"Datos de la resolución";
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(515, 295);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 38;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &GrabarResolucion::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(390, 295);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(107, 32);
			this->SaveButton->TabIndex = 37;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &GrabarResolucion::SaveButton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 66);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 20);
			this->label3->TabIndex = 39;
			this->label3->Text = L"Nº de la solicitud";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 20);
			this->label4->TabIndex = 41;
			this->label4->Text = L"Fecha de firma";
			// 
			// FirmatextBox
			// 
			this->FirmatextBox->Location = System::Drawing::Point(153, 111);
			this->FirmatextBox->Name = L"FirmatextBox";
			this->FirmatextBox->Size = System::Drawing::Size(138, 26);
			this->FirmatextBox->TabIndex = 42;
			// 
			// SalidatextBox
			// 
			this->SalidatextBox->Location = System::Drawing::Point(460, 111);
			this->SalidatextBox->Name = L"SalidatextBox";
			this->SalidatextBox->Size = System::Drawing::Size(146, 26);
			this->SalidatextBox->TabIndex = 44;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(325, 114);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(121, 20);
			this->label5->TabIndex = 43;
			this->label5->Text = L"Fecha de salida";
			// 
			// NSolcomboBox
			// 
			this->NSolcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->NSolcomboBox->FormattingEnabled = true;
			this->NSolcomboBox->Location = System::Drawing::Point(153, 63);
			this->NSolcomboBox->Name = L"NSolcomboBox";
			this->NSolcomboBox->Size = System::Drawing::Size(453, 28);
			this->NSolcomboBox->TabIndex = 45;
			// 
			// TipoReccomboBox
			// 
			this->TipoReccomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TipoReccomboBox->FormattingEnabled = true;
			this->TipoReccomboBox->Location = System::Drawing::Point(153, 156);
			this->TipoReccomboBox->Name = L"TipoReccomboBox";
			this->TipoReccomboBox->Size = System::Drawing::Size(453, 28);
			this->TipoReccomboBox->TabIndex = 47;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 159);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(118, 20);
			this->label6->TabIndex = 46;
			this->label6->Text = L"Tipo de recurso";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 252);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(114, 20);
			this->label7->TabIndex = 48;
			this->label7->Text = L"Observaciones";
			// 
			// ObsertextBox
			// 
			this->ObsertextBox->Location = System::Drawing::Point(153, 249);
			this->ObsertextBox->Name = L"ObsertextBox";
			this->ObsertextBox->Size = System::Drawing::Size(453, 26);
			this->ObsertextBox->TabIndex = 49;
			// 
			// TipoRescomboBox
			// 
			this->TipoRescomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->TipoRescomboBox->FormattingEnabled = true;
			this->TipoRescomboBox->Location = System::Drawing::Point(153, 198);
			this->TipoRescomboBox->Name = L"TipoRescomboBox";
			this->TipoRescomboBox->Size = System::Drawing::Size(453, 28);
			this->TipoRescomboBox->TabIndex = 51;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 201);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(137, 20);
			this->label8->TabIndex = 50;
			this->label8->Text = L"Tipo de resolución";
			// 
			// GrabarResolucion
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(618, 339);
			this->Controls->Add(this->TipoRescomboBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->ObsertextBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->TipoReccomboBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->NSolcomboBox);
			this->Controls->Add(this->SalidatextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->FirmatextBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TitleEstudiante);
			this->Controls->Add(this->toolStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GrabarResolucion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Grabar resolución";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void addTypeResButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	string mensaje = "resolución.";
	SGBDRasore::addTypeOf ^dialog = gcnew SGBDRasore::addTypeOf(*bd, mensaje);
	dialog->ShowDialog();
	delete dialog;
	this->TipoRescomboBox->Items->Clear();
	auto tRes = this->bd->getResolutionTypes();
	for (int k = 0; k < tRes.size(); ++k)
		this->TipoRescomboBox->Items->Add(gcnew String(tRes[k].c_str()));
	this->Show();
}
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	string mensaje = "recurso.";
	SGBDRasore::addTypeOf ^dialog = gcnew SGBDRasore::addTypeOf(*bd, mensaje);
	dialog->ShowDialog();
	delete dialog;
	this->TipoReccomboBox->Items->Clear();
	auto tRec = this->bd->getResourceTypes();
	for (int j = 0; j < tRec.size(); ++j)
		this->TipoReccomboBox->Items->Add(gcnew String(tRec[j].c_str()));
	this->Show();
}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->NSolcomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar la solicitud de la resolución.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->TipoRescomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar el tipo de la resolución.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->TipoReccomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar un tipo de recurso.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		using namespace Runtime::InteropServices;
		unsigned int nSol = stringToUint((const char*)(Marshal::StringToHGlobalAnsi(this->NSolcomboBox->SelectedItem->ToString())).ToPointer());
		string firma = (const char*)(Marshal::StringToHGlobalAnsi(this->FirmatextBox->Text)).ToPointer();
		string salida = (const char*)(Marshal::StringToHGlobalAnsi(this->SalidatextBox->Text)).ToPointer();
		string recurso = (const char*)(Marshal::StringToHGlobalAnsi(this->TipoReccomboBox->SelectedItem->ToString())).ToPointer();
		string res = (const char*)(Marshal::StringToHGlobalAnsi(this->TipoRescomboBox->SelectedItem->ToString())).ToPointer();
		string obser = (const char*)(Marshal::StringToHGlobalAnsi(this->ObsertextBox->Text)).ToPointer();
		if ((firma != "" && !isDateCorrect(firma)) || (salida != "" && !isDateCorrect(salida))) {
			string mensaje = "Formato de fecha introducida erróneo.\nDebe introducir una fecha de la forma dd/mm/aaaa";
			SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
			dError->ShowDialog();
			delete dError;
		}
		else{
			unsigned int ident = this->bd->insertResolution(nSol, firma, salida, res, recurso, obser);
			string mensaje = "La resolución ha sido añadida correctamente a la base de datos.\nEl identificador de la resolución grabada es: " + 
				uintToString(ident);
			SGBDRasore::InformationDialog ^dInfor = gcnew SGBDRasore::InformationDialog(mensaje);
			dInfor->ShowDialog();
			delete dInfor;
			Close();
		}
	}
}
};
}
#endif