#ifndef WARNINGBOOL_H
#define WARNINGBOOL_H

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
	/// Resumen de warningBooleanDialog
	/// </summary>
	public ref class warningBooleanDialog : public System::Windows::Forms::Form
	{
	public:
		warningBooleanDialog(void)
		{
			InitializeComponent();
			doIt = NULL;
		}

		warningBooleanDialog(bool &b, string &message) {
			InitializeComponent();
			doIt = &b;
			this->Informationlabel->Text = gcnew String(message.c_str());
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~warningBooleanDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		bool *doIt;
	private: System::Windows::Forms::Label^  Informationlabel;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(warningBooleanDialog::typeid));
			this->Informationlabel = (gcnew System::Windows::Forms::Label());
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Informationlabel
			// 
			this->Informationlabel->AutoSize = true;
			this->Informationlabel->Location = System::Drawing::Point(49, 36);
			this->Informationlabel->Name = L"Informationlabel";
			this->Informationlabel->Size = System::Drawing::Size(42, 20);
			this->Informationlabel->TabIndex = 32;
			this->Informationlabel->Text = L"label";
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(667, 118);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 34;
			this->Cancelbutton->Text = L"No";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &warningBooleanDialog::Cancelbutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(555, 118);
			this->SaveButton->MinimumSize = System::Drawing::Size(92, 32);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(92, 32);
			this->SaveButton->TabIndex = 33;
			this->SaveButton->Text = L"Sí";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &warningBooleanDialog::SaveButton_Click);
			// 
			// warningBooleanDialog
			// 
			this->AcceptButton = this->SaveButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(770, 162);
			this->Controls->Add(this->Cancelbutton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->Informationlabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(753, 218);
			this->Name = L"warningBooleanDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Advertencia";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &warningBooleanDialog::warningBooleanDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		*doIt = false;
		Close();
	}
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	*doIt = true;
	Close();
}
private: System::Void warningBooleanDialog_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
#endif