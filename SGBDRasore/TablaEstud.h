#ifndef TABLAESTUDFORM_H
#define TABLAESTUDFORM_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_set>
#include <map>
#include "BaseDatos.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de TablaEstud
	/// </summary>
	public ref class TablaEstud : public System::Windows::Forms::Form
	{
	public:
		TablaEstud(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		TablaEstud(BaseDatos &base) {
			InitializeComponent();
			bd = &base;
			unordered_set<string> dnis = base.getDNIS();
			int i = 0;
			bool aux;
			auto it = dnis.begin();
			this->vistaTabla->Columns->Add("Apellido1", "Apellido1");
			this->vistaTabla->Columns->Add("Apellido2", "Apellido2");
			this->vistaTabla->Columns->Add("Nombre", "Nombre");
			this->vistaTabla->Columns->Add("DNI", "DNI");
			this->vistaTabla->Columns->Add("Solicitud", "Solicitud");
			this->vistaTabla->Columns->Add("Resolucion", "Resolucion");
			map<string, string> nombresStud;
			while (it != dnis.end()) {
				vector<string> lst = base.getStudentData(*it, aux);
				if (!aux) {
					string nombre = lst[1] + ' ' + lst[2] + ' ' + lst[0];
					nombresStud.insert(std::pair<string, string>(nombre, *it));
				}
				++it;
			}

			std::map<string,string>::iterator ite = nombresStud.begin();
			while (ite != nombresStud.end()) {
				vector<string> dat = base.getStudentData(ite->second, aux);
				this->vistaTabla->Rows->Add();
				this->vistaTabla->Rows[i]->Cells[0]->Value = gcnew String(dat[1].c_str());
				this->vistaTabla->Rows[i]->Cells[1]->Value = gcnew String(dat[2].c_str());
				this->vistaTabla->Rows[i]->Cells[2]->Value = gcnew String(dat[0].c_str());
				this->vistaTabla->Rows[i]->Cells[3]->Value = gcnew String(ite->second.c_str());
				if (base.getAppFromStudent(ite->second).size() > 0)
					this->vistaTabla->Rows[i]->Cells[4]->Value = "SI";
				else
					this->vistaTabla->Rows[i]->Cells[4]->Value = "NO";
				if (base.getResolFromStudent(ite->second).size() > 0)
					this->vistaTabla->Rows[i]->Cells[5]->Value = "SI";
				else
					this->vistaTabla->Rows[i]->Cells[5]->Value = "NO";
				++i;
				++ite;
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~TablaEstud()
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
	private: System::Windows::Forms::Button^  Cancelbutton;
	private: System::Windows::Forms::DataGridView^  vistaTabla;
			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TablaEstud::typeid));
			this->Cancelbutton = (gcnew System::Windows::Forms::Button());
			this->vistaTabla = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vistaTabla))->BeginInit();
			this->SuspendLayout();
			// 
			// Cancelbutton
			// 
			this->Cancelbutton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->Cancelbutton->Location = System::Drawing::Point(893, 366);
			this->Cancelbutton->Name = L"Cancelbutton";
			this->Cancelbutton->Size = System::Drawing::Size(91, 32);
			this->Cancelbutton->TabIndex = 64;
			this->Cancelbutton->Text = L"Salir";
			this->Cancelbutton->UseVisualStyleBackColor = true;
			this->Cancelbutton->Click += gcnew System::EventHandler(this, &TablaEstud::Cancelbutton_Click);
			// 
			// vistaTabla
			// 
			this->vistaTabla->AllowUserToAddRows = false;
			this->vistaTabla->AllowUserToDeleteRows = false;
			this->vistaTabla->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->vistaTabla->Location = System::Drawing::Point(12, 12);
			this->vistaTabla->MultiSelect = false;
			this->vistaTabla->Name = L"vistaTabla";
			this->vistaTabla->RowTemplate->Height = 28;
			this->vistaTabla->Size = System::Drawing::Size(972, 348);
			this->vistaTabla->TabIndex = 65;
			// 
			// TablaEstud
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->Cancelbutton;
			this->ClientSize = System::Drawing::Size(1010, 420);
			this->Controls->Add(this->vistaTabla);
			this->Controls->Add(this->Cancelbutton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TablaEstud";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Tabla de Estudiantes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vistaTabla))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Cancelbutton_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	};
}
#endif