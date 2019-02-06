#ifndef ADDUNIV_H
#define ADDUNIV_H

#include "BaseDatos.h"
#include <iostream>
#include <string>
#include <stdexcept>
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
	/// Resumen de addUnivForm
	/// </summary>
	public ref class addUnivForm : public System::Windows::Forms::Form
	{
	public:
		addUnivForm(void)
		{
			bd = NULL;
			InitializeComponent();
		}

		addUnivForm(BaseDatos &base)
		{
			bd = &base;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~addUnivForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  NametextBox;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		BaseDatos *bd;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(addUnivForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NametextBox = (gcnew System::Windows::Forms::TextBox());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre";
			// 
			// NametextBox
			// 
			this->NametextBox->Location = System::Drawing::Point(35, 61);
			this->NametextBox->Name = L"NametextBox";
			this->NametextBox->Size = System::Drawing::Size(464, 26);
			this->NametextBox->TabIndex = 1;
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(417, 108);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 34;
			this->Cancelbutton->Text = L"Cancelar";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &addUnivForm::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(307, 108);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(92, 32);
			this->SaveButton->TabIndex = 33;
			this->SaveButton->Text = L"Guardar";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &addUnivForm::SaveButton_Click);
			// 
			// addUnivForm
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(529, 161);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->NametextBox);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"addUnivForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Añadir Universidad";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	using namespace Runtime::InteropServices;
	string univ = (const char*)(Marshal::StringToHGlobalAnsi(this->NametextBox->Text)).ToPointer();
	try {
		this->bd->insertUniversity(univ);
		Close();
	}
	catch (domain_error &e) {
		string mensaje = "La universidad que se intenta insertar ya existe en la base de datos.";
		SGBDRasore::errorDialog ^dialog = gcnew SGBDRasore::errorDialog(mensaje);
		dialog->ShowDialog();
		delete dialog;
	}
}
};
}
#endif