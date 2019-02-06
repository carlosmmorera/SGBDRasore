#ifndef SICUE_H
#define SICUE_H

#include "BaseDatos.h"
#include <string>
#include <iostream>
#include <vector>
#include "addUnivForm.h"
#include "errorDialog.h"
#include "warningBooleanDialog.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de SICUEForm
	/// </summary>
	public ref class SICUEForm : public System::Windows::Forms::Form
	{
	public:
		SICUEForm(void)
		{
			bd = NULL;
			InitializeComponent();
		}

		SICUEForm(BaseDatos &base, string &d) {
			bd = &base;
			dni = &d;
			InitializeComponent();
			vector<string> v = bd->getUniversities();
			for (int i = 0; i < v.size(); ++i) {
				this->UniOcomboBox->Items->Add(gcnew String(v[i].c_str()));
				this->UniDcomboBox->Items->Add(gcnew String(v[i].c_str()));
			}
			string uniDefecto = "Universidad Complutense de Madrid";
			this->UniOcomboBox->SelectedItem = gcnew String(uniDefecto.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~SICUEForm()
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
		string *dni;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  TitleEstudiante;
	private: System::Windows::Forms::Label^  UniOlabel;
	private: System::Windows::Forms::ComboBox^  UniOcomboBox;
	private: System::Windows::Forms::ComboBox^  UniDcomboBox;
	private: System::Windows::Forms::Label^  UniDlabel;
	private: System::Windows::Forms::Label^  Estlabel;
	private: System::Windows::Forms::TextBox^  EsttextBox;
	private: System::Windows::Forms::Label^  Periodlabel;
	private: System::Windows::Forms::ComboBox^  PeriodcomboBox;
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripLabel^  addUniversity;
	private: System::Windows::Forms::TextBox^  CampustextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  BecacheckBox;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SICUEForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TitleEstudiante = (gcnew System::Windows::Forms::Label());
			this->UniOlabel = (gcnew System::Windows::Forms::Label());
			this->UniOcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->UniDcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->UniDlabel = (gcnew System::Windows::Forms::Label());
			this->Estlabel = (gcnew System::Windows::Forms::Label());
			this->EsttextBox = (gcnew System::Windows::Forms::TextBox());
			this->Periodlabel = (gcnew System::Windows::Forms::Label());
			this->PeriodcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->addUniversity = (gcnew System::Windows::Forms::ToolStripLabel());
			this->CampustextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->BecacheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(371, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 20);
			this->label2->TabIndex = 17;
			this->label2->Text = L"---------------------------------------------";
			this->label2->Click += gcnew System::EventHandler(this, &SICUEForm::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 20);
			this->label1->TabIndex = 16;
			this->label1->Text = L"----------------------------------------";
			this->label1->Click += gcnew System::EventHandler(this, &SICUEForm::label1_Click);
			// 
			// TitleEstudiante
			// 
			this->TitleEstudiante->AutoSize = true;
			this->TitleEstudiante->Location = System::Drawing::Point(234, 40);
			this->TitleEstudiante->Name = L"TitleEstudiante";
			this->TitleEstudiante->Size = System::Drawing::Size(131, 20);
			this->TitleEstudiante->TabIndex = 15;
			this->TitleEstudiante->Text = L"Datos del SICUE";
			this->TitleEstudiante->Click += gcnew System::EventHandler(this, &SICUEForm::TitleEstudiante_Click);
			// 
			// UniOlabel
			// 
			this->UniOlabel->AutoSize = true;
			this->UniOlabel->Location = System::Drawing::Point(11, 69);
			this->UniOlabel->Name = L"UniOlabel";
			this->UniOlabel->Size = System::Drawing::Size(162, 20);
			this->UniOlabel->TabIndex = 18;
			this->UniOlabel->Text = L"Universidad de origen";
			this->UniOlabel->Click += gcnew System::EventHandler(this, &SICUEForm::UniOlabel_Click);
			// 
			// UniOcomboBox
			// 
			this->UniOcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->UniOcomboBox->FormattingEnabled = true;
			this->UniOcomboBox->Location = System::Drawing::Point(15, 92);
			this->UniOcomboBox->Name = L"UniOcomboBox";
			this->UniOcomboBox->Size = System::Drawing::Size(590, 28);
			this->UniOcomboBox->Sorted = true;
			this->UniOcomboBox->TabIndex = 19;
			this->UniOcomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &SICUEForm::UniOcomboBox_SelectedIndexChanged);
			// 
			// UniDcomboBox
			// 
			this->UniDcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->UniDcomboBox->FormattingEnabled = true;
			this->UniDcomboBox->Location = System::Drawing::Point(16, 167);
			this->UniDcomboBox->Name = L"UniDcomboBox";
			this->UniDcomboBox->Size = System::Drawing::Size(590, 28);
			this->UniDcomboBox->Sorted = true;
			this->UniDcomboBox->TabIndex = 21;
			this->UniDcomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &SICUEForm::UniDcomboBox_SelectedIndexChanged);
			// 
			// UniDlabel
			// 
			this->UniDlabel->AutoSize = true;
			this->UniDlabel->Location = System::Drawing::Point(11, 144);
			this->UniDlabel->Name = L"UniDlabel";
			this->UniDlabel->Size = System::Drawing::Size(170, 20);
			this->UniDlabel->TabIndex = 20;
			this->UniDlabel->Text = L"Universidad de destino";
			this->UniDlabel->Click += gcnew System::EventHandler(this, &SICUEForm::UniDlabel_Click);
			// 
			// Estlabel
			// 
			this->Estlabel->AutoSize = true;
			this->Estlabel->Location = System::Drawing::Point(11, 276);
			this->Estlabel->Name = L"Estlabel";
			this->Estlabel->Size = System::Drawing::Size(255, 20);
			this->Estlabel->TabIndex = 22;
			this->Estlabel->Text = L"Estudios análogos a los de la UCM";
			this->Estlabel->Click += gcnew System::EventHandler(this, &SICUEForm::Estlabel_Click);
			// 
			// EsttextBox
			// 
			this->EsttextBox->Location = System::Drawing::Point(15, 299);
			this->EsttextBox->Name = L"EsttextBox";
			this->EsttextBox->Size = System::Drawing::Size(590, 26);
			this->EsttextBox->TabIndex = 23;
			this->EsttextBox->TextChanged += gcnew System::EventHandler(this, &SICUEForm::EsttextBox_TextChanged);
			// 
			// Periodlabel
			// 
			this->Periodlabel->AutoSize = true;
			this->Periodlabel->Location = System::Drawing::Point(11, 361);
			this->Periodlabel->Name = L"Periodlabel";
			this->Periodlabel->Size = System::Drawing::Size(63, 20);
			this->Periodlabel->TabIndex = 24;
			this->Periodlabel->Text = L"Periodo";
			this->Periodlabel->Click += gcnew System::EventHandler(this, &SICUEForm::Periodlabel_Click);
			// 
			// PeriodcomboBox
			// 
			this->PeriodcomboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->PeriodcomboBox->FormattingEnabled = true;
			this->PeriodcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Medio curso", L"Curso completo" });
			this->PeriodcomboBox->Location = System::Drawing::Point(99, 361);
			this->PeriodcomboBox->Name = L"PeriodcomboBox";
			this->PeriodcomboBox->Size = System::Drawing::Size(167, 28);
			this->PeriodcomboBox->TabIndex = 25;
			this->PeriodcomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &SICUEForm::PeriodcomboBox_SelectedIndexChanged);
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(503, 426);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 32;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &SICUEForm::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(393, 426);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(92, 32);
			this->SaveButton->TabIndex = 31;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &SICUEForm::SaveButton_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->addUniversity });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(618, 28);
			this->toolStrip1->TabIndex = 33;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// addUniversity
			// 
			this->addUniversity->Name = L"addUniversity";
			this->addUniversity->Size = System::Drawing::Size(214, 25);
			this->addUniversity->Text = L"Añadir nueva Universidad";
			this->addUniversity->Click += gcnew System::EventHandler(this, &SICUEForm::toolStripLabel1_Click);
			// 
			// CampustextBox
			// 
			this->CampustextBox->Location = System::Drawing::Point(16, 232);
			this->CampustextBox->Name = L"CampustextBox";
			this->CampustextBox->Size = System::Drawing::Size(590, 26);
			this->CampustextBox->TabIndex = 35;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 209);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(156, 20);
			this->label3->TabIndex = 34;
			this->label3->Text = L"Campus universitario";
			// 
			// BecacheckBox
			// 
			this->BecacheckBox->AutoSize = true;
			this->BecacheckBox->Location = System::Drawing::Point(420, 363);
			this->BecacheckBox->Name = L"BecacheckBox";
			this->BecacheckBox->Size = System::Drawing::Size(186, 24);
			this->BecacheckBox->TabIndex = 36;
			this->BecacheckBox->Text = L"Marcar si posee beca";
			this->BecacheckBox->UseVisualStyleBackColor = true;
			// 
			// SICUEForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(618, 470);
			this->Controls->Add(this->BecacheckBox);
			this->Controls->Add(this->CampustextBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->PeriodcomboBox);
			this->Controls->Add(this->Periodlabel);
			this->Controls->Add(this->EsttextBox);
			this->Controls->Add(this->Estlabel);
			this->Controls->Add(this->UniDcomboBox);
			this->Controls->Add(this->UniDlabel);
			this->Controls->Add(this->UniOcomboBox);
			this->Controls->Add(this->UniOlabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TitleEstudiante);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SICUEForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Grabar estudiante SICUE";
			this->Load += gcnew System::EventHandler(this, &SICUEForm::SICUEForm_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TitleEstudiante_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->UniOcomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar la universidad de origen del estudiante.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->UniDcomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar la universidad de destino del estudiante.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else if (this->PeriodcomboBox->SelectedItem == nullptr) {
		string mensaje = "Se debe seleccionar el periodo de la movilidad.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		using namespace Runtime::InteropServices;
		string uni_o = (const char*)(Marshal::StringToHGlobalAnsi(this->UniOcomboBox->SelectedItem->ToString())).ToPointer();
		string uni_d = (const char*)(Marshal::StringToHGlobalAnsi(this->UniDcomboBox->SelectedItem->ToString())).ToPointer();
		string estud = (const char*)(Marshal::StringToHGlobalAnsi(this->EsttextBox->Text)).ToPointer();
		string campus = (const char*)(Marshal::StringToHGlobalAnsi(this->CampustextBox->Text)).ToPointer();
		bool beca = this->BecacheckBox->Checked;
		string per = (const char*)(Marshal::StringToHGlobalAnsi(this->PeriodcomboBox->SelectedItem->ToString())).ToPointer();
		try {
			this->bd->insertSICUE(*dni, uni_o, uni_d, estud, campus, beca, per);
			Close();
		}
		catch (invalid_argument &e) {
			string mensaje = e.what();
			mensaje.append("Añada la universidad deseada a la base de datos.");
			SGBDRasore::errorDialog ^dialog = gcnew SGBDRasore::errorDialog(mensaje);
			dialog->ShowDialog();
			delete dialog;
		}
		catch (domain_error &e) {
			string mensaje = "El DNI que se desea insertar ya se encuentra en la base de datos como estudiante SICUE.\n¿Desea reemplazar los datos (se borrarían todos los datos relacionados con dicho DNI)?";
			bool doIt = false;
			SGBDRasore::warningBooleanDialog ^dialog = gcnew SGBDRasore::warningBooleanDialog(doIt, mensaje);
			dialog->ShowDialog();
			delete dialog;
			if (doIt) {
				this->bd->deleteSICUE(*dni);
				this->bd->insertSICUE(*dni, uni_o, uni_d, estud, campus, beca, per);
				Close();
			}
		}
	}
}
private: System::Void SICUEForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void PeriodcomboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Periodlabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void EsttextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Estlabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void UniDcomboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void UniDlabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void UniOcomboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void UniOlabel_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void toolStripLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
	SGBDRasore::addUnivForm ^dialog = gcnew SGBDRasore::addUnivForm(*bd);
	dialog->ShowDialog();
	delete dialog;
	this->UniOcomboBox->Items->Clear();
	this->UniDcomboBox->Items->Clear();
	vector<string> v = bd->getUniversities();
	for (int i = 0; i < v.size(); ++i) {
		this->UniOcomboBox->Items->Add(gcnew String(v[i].c_str()));
		this->UniDcomboBox->Items->Add(gcnew String(v[i].c_str()));
	}
}
};
}
#endif