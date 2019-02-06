#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <iostream>
#include <string>

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de errorDialog
	/// </summary>
	public ref class errorDialog : public System::Windows::Forms::Form
	{
	public:
		errorDialog(void)
		{
			InitializeComponent();
		}

		errorDialog(string &message) {
			InitializeComponent();
			this->Informationlabel->Text = gcnew String(message.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~errorDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  Informationlabel;
	protected:
	private: System::Windows::Forms::Button^  AcceptButton;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(errorDialog::typeid));
			this->Informationlabel = (gcnew System::Windows::Forms::Label());
			this->AcceptButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Informationlabel
			// 
			this->Informationlabel->AutoSize = true;
			this->Informationlabel->Location = System::Drawing::Point(21, 24);
			this->Informationlabel->Name = L"Informationlabel";
			this->Informationlabel->Size = System::Drawing::Size(42, 20);
			this->Informationlabel->TabIndex = 33;
			this->Informationlabel->Text = L"label";
			// 
			// AcceptButton
			// 
			this->AcceptButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->AcceptButton->Location = System::Drawing::Point(777, 90);
			this->AcceptButton->Name = L"AcceptButton";
			this->AcceptButton->Size = System::Drawing::Size(92, 32);
			this->AcceptButton->TabIndex = 32;
			this->AcceptButton->Text = L"Aceptar";
			this->AcceptButton->UseVisualStyleBackColor = true;
			this->AcceptButton->Click += gcnew System::EventHandler(this, &errorDialog::AcceptButton_Click);
			// 
			// errorDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->AcceptButton;
			this->ClientSize = System::Drawing::Size(893, 134);
			this->Controls->Add(this->Informationlabel);
			this->Controls->Add(this->AcceptButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(915, 190);
			this->Name = L"errorDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Error";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AcceptButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	};
}
#endif