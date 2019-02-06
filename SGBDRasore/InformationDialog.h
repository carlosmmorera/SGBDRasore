#ifndef INFORMATIOND_H
#define INFORMATIOND_H

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
	/// Resumen de InformationDialog
	/// </summary>
	public ref class InformationDialog : public System::Windows::Forms::Form
	{
	public:
		InformationDialog(void)
		{
			InitializeComponent();
		}

		InformationDialog(const string &message) {
			InitializeComponent();
			this->Informationlabel->Text = gcnew String(message.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~InformationDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  AcceptButton;
	private: System::Windows::Forms::Label^  Informationlabel;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(InformationDialog::typeid));
			this->AcceptButton = (gcnew System::Windows::Forms::Button());
			this->Informationlabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AcceptButton
			// 
			this->AcceptButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->AcceptButton->Location = System::Drawing::Point(547, 102);
			this->AcceptButton->Name = L"AcceptButton";
			this->AcceptButton->Size = System::Drawing::Size(92, 32);
			this->AcceptButton->TabIndex = 30;
			this->AcceptButton->Text = L"Aceptar";
			this->AcceptButton->UseVisualStyleBackColor = true;
			this->AcceptButton->Click += gcnew System::EventHandler(this, &InformationDialog::AcceptButton_Click);
			// 
			// Informationlabel
			// 
			this->Informationlabel->AutoSize = true;
			this->Informationlabel->Location = System::Drawing::Point(26, 39);
			this->Informationlabel->Name = L"Informationlabel";
			this->Informationlabel->Size = System::Drawing::Size(42, 20);
			this->Informationlabel->TabIndex = 31;
			this->Informationlabel->Text = L"label";
			this->Informationlabel->Click += gcnew System::EventHandler(this, &InformationDialog::Informationlabel_Click);
			// 
			// InformationDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->CancelButton = this->AcceptButton;
			this->ClientSize = System::Drawing::Size(651, 146);
			this->Controls->Add(this->Informationlabel);
			this->Controls->Add(this->AcceptButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"InformationDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Información";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Informationlabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void AcceptButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	};
}
#endif