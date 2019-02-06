#ifndef MYFORM_H
#define MYFORM_H

#include <iostream>
#include <vector>
#include <string>
#include "BaseDatos.h"
#include "GrabarEstudiante.h"
#include "InformationDialog.h"
#include "addTypeOf.h"
#include "addStudiesForm.h"
#include "addCentre.h"
#include "GrabarSolicitud.h"
#include "warningBooleanDialog.h"
#include "ConsultaForm.h"
#include "modificarElem.h"
#include "addUnivForm.h"
#include "eliminaElemForm.h"
#include "GrabarResolucion.h"

namespace SGBDRasore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			bd = new BaseDatos();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			delete bd;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonGrabar;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^  labelGrabar;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::Label^  labelModificar;
	private: System::Windows::Forms::Label^  labelExportar;
	private: System::Windows::Forms::Label^  labelBuscar;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		BaseDatos *bd;
	private: System::Windows::Forms::Label^  GrabEstlabel;
	private: System::Windows::Forms::Button^  GrabEstbutton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  Consultabutton;
	private: System::Windows::Forms::ToolStripDropDownButton^  ArchivoButton;
	private: System::Windows::Forms::ToolStripMenuItem^  guardarMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportarMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importarMenuItem;




	private: System::Windows::Forms::ToolStripDropDownButton^  EditarButton;
	private: System::Windows::Forms::ToolStripMenuItem^  centroToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeSolicitudToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeResoluci�nToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeRecursoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  titulaci�nToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;




	private: System::Windows::Forms::ToolStripDropDownButton^  ModificarDownButton;
	private: System::Windows::Forms::ToolStripMenuItem^  copiaDeSeguridadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportarYVaciarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sustituirDatosAlmacenadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  a�adirDatosALosAlmacenadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  titulaci�nToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  centroToolStripMenuItem1;



	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeDocumentaci�nToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^  EliminarDownButton;
	private: System::Windows::Forms::ToolStripMenuItem^  titulaci�nToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  centroToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeSolicitudToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeResoluci�nToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeRecursoToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeDocumentaci�nToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  universidadesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  recargarToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  exportFileDialog;
	private: System::Windows::Forms::OpenFileDialog^  importDialog;
	private: System::Windows::Forms::ToolStripMenuItem^  reemplazarActualesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mantenerToolStripMenuItem;










	private: System::Windows::Forms::ToolStripMenuItem^  mantenerTablasB�sicasToolStripMenuItem;
	private: System::Windows::Forms::Button^  GrabResButton;
private: System::Windows::Forms::Button^  buttonExtraer;










			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->buttonGrabar = (gcnew System::Windows::Forms::Button());
			this->labelGrabar = (gcnew System::Windows::Forms::Label());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->ArchivoButton = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->recargarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportarMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copiaDeSeguridadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportarYVaciarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenerTablasB�sicasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importarMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sustituirDatosAlmacenadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->a�adirDatosALosAlmacenadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reemplazarActualesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->EditarButton = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->titulaci�nToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->centroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeSolicitudToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeResoluci�nToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeRecursoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeDocumentaci�nToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->universidadesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ModificarDownButton = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->titulaci�nToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->centroToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->EliminarDownButton = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->titulaci�nToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->centroToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeSolicitudToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeResoluci�nToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeRecursoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeDocumentaci�nToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labelModificar = (gcnew System::Windows::Forms::Label());
			this->labelExportar = (gcnew System::Windows::Forms::Label());
			this->labelBuscar = (gcnew System::Windows::Forms::Label());
			this->GrabEstlabel = (gcnew System::Windows::Forms::Label());
			this->GrabEstbutton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Consultabutton = (gcnew System::Windows::Forms::Button());
			this->exportFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->importDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->GrabResButton = (gcnew System::Windows::Forms::Button());
			this->buttonExtraer = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonGrabar
			// 
			resources->ApplyResources(this->buttonGrabar, L"buttonGrabar");
			this->buttonGrabar->Name = L"buttonGrabar";
			this->buttonGrabar->UseVisualStyleBackColor = true;
			this->buttonGrabar->Click += gcnew System::EventHandler(this, &MyForm::buttonGrabar_Click);
			// 
			// labelGrabar
			// 
			resources->ApplyResources(this->labelGrabar, L"labelGrabar");
			this->labelGrabar->Name = L"labelGrabar";
			this->labelGrabar->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->ArchivoButton, this->toolStripSeparator1,
					this->EditarButton, this->toolStripSeparator2, this->ModificarDownButton, this->toolStripSeparator3, this->EliminarDownButton
			});
			resources->ApplyResources(this->toolStrip1, L"toolStrip1");
			this->toolStrip1->Name = L"toolStrip1";
			// 
			// ArchivoButton
			// 
			this->ArchivoButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ArchivoButton->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->recargarToolStripMenuItem,
					this->guardarMenuItem, this->exportarMenuItem, this->importarMenuItem
			});
			resources->ApplyResources(this->ArchivoButton, L"ArchivoButton");
			this->ArchivoButton->Name = L"ArchivoButton";
			// 
			// recargarToolStripMenuItem
			// 
			this->recargarToolStripMenuItem->Name = L"recargarToolStripMenuItem";
			resources->ApplyResources(this->recargarToolStripMenuItem, L"recargarToolStripMenuItem");
			this->recargarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::recargarToolStripMenuItem_Click);
			// 
			// guardarMenuItem
			// 
			this->guardarMenuItem->Name = L"guardarMenuItem";
			resources->ApplyResources(this->guardarMenuItem, L"guardarMenuItem");
			this->guardarMenuItem->Click += gcnew System::EventHandler(this, &MyForm::guardarMenuItem_Click);
			// 
			// exportarMenuItem
			// 
			this->exportarMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->copiaDeSeguridadToolStripMenuItem,
					this->exportarYVaciarToolStripMenuItem, this->mantenerTablasB�sicasToolStripMenuItem
			});
			this->exportarMenuItem->Name = L"exportarMenuItem";
			resources->ApplyResources(this->exportarMenuItem, L"exportarMenuItem");
			// 
			// copiaDeSeguridadToolStripMenuItem
			// 
			this->copiaDeSeguridadToolStripMenuItem->Name = L"copiaDeSeguridadToolStripMenuItem";
			resources->ApplyResources(this->copiaDeSeguridadToolStripMenuItem, L"copiaDeSeguridadToolStripMenuItem");
			this->copiaDeSeguridadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copiaDeSeguridadToolStripMenuItem_Click);
			// 
			// exportarYVaciarToolStripMenuItem
			// 
			this->exportarYVaciarToolStripMenuItem->Name = L"exportarYVaciarToolStripMenuItem";
			resources->ApplyResources(this->exportarYVaciarToolStripMenuItem, L"exportarYVaciarToolStripMenuItem");
			this->exportarYVaciarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportarYVaciarToolStripMenuItem_Click);
			// 
			// mantenerTablasB�sicasToolStripMenuItem
			// 
			this->mantenerTablasB�sicasToolStripMenuItem->Name = L"mantenerTablasB�sicasToolStripMenuItem";
			resources->ApplyResources(this->mantenerTablasB�sicasToolStripMenuItem, L"mantenerTablasB�sicasToolStripMenuItem");
			this->mantenerTablasB�sicasToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::mantenerTablasB�sicasToolStripMenuItem_Click);
			// 
			// importarMenuItem
			// 
			this->importarMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->sustituirDatosAlmacenadosToolStripMenuItem,
					this->a�adirDatosALosAlmacenadosToolStripMenuItem
			});
			this->importarMenuItem->Name = L"importarMenuItem";
			resources->ApplyResources(this->importarMenuItem, L"importarMenuItem");
			// 
			// sustituirDatosAlmacenadosToolStripMenuItem
			// 
			this->sustituirDatosAlmacenadosToolStripMenuItem->Name = L"sustituirDatosAlmacenadosToolStripMenuItem";
			resources->ApplyResources(this->sustituirDatosAlmacenadosToolStripMenuItem, L"sustituirDatosAlmacenadosToolStripMenuItem");
			this->sustituirDatosAlmacenadosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sustituirDatosAlmacenadosToolStripMenuItem_Click);
			// 
			// a�adirDatosALosAlmacenadosToolStripMenuItem
			// 
			this->a�adirDatosALosAlmacenadosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->reemplazarActualesToolStripMenuItem,
					this->mantenerToolStripMenuItem
			});
			this->a�adirDatosALosAlmacenadosToolStripMenuItem->Name = L"a�adirDatosALosAlmacenadosToolStripMenuItem";
			resources->ApplyResources(this->a�adirDatosALosAlmacenadosToolStripMenuItem, L"a�adirDatosALosAlmacenadosToolStripMenuItem");
			this->a�adirDatosALosAlmacenadosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::a�adirDatosALosAlmacenadosToolStripMenuItem_Click);
			// 
			// reemplazarActualesToolStripMenuItem
			// 
			this->reemplazarActualesToolStripMenuItem->Name = L"reemplazarActualesToolStripMenuItem";
			resources->ApplyResources(this->reemplazarActualesToolStripMenuItem, L"reemplazarActualesToolStripMenuItem");
			this->reemplazarActualesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::reemplazarActualesToolStripMenuItem_Click);
			// 
			// mantenerToolStripMenuItem
			// 
			this->mantenerToolStripMenuItem->Name = L"mantenerToolStripMenuItem";
			resources->ApplyResources(this->mantenerToolStripMenuItem, L"mantenerToolStripMenuItem");
			this->mantenerToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::mantenerToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			resources->ApplyResources(this->toolStripSeparator1, L"toolStripSeparator1");
			// 
			// EditarButton
			// 
			this->EditarButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->EditarButton->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->titulaci�nToolStripMenuItem,
					this->centroToolStripMenuItem, this->tipoDeSolicitudToolStripMenuItem, this->tipoDeResoluci�nToolStripMenuItem, this->tipoDeRecursoToolStripMenuItem,
					this->tipoDeDocumentaci�nToolStripMenuItem, this->universidadesToolStripMenuItem
			});
			resources->ApplyResources(this->EditarButton, L"EditarButton");
			this->EditarButton->Name = L"EditarButton";
			// 
			// titulaci�nToolStripMenuItem
			// 
			this->titulaci�nToolStripMenuItem->Name = L"titulaci�nToolStripMenuItem";
			resources->ApplyResources(this->titulaci�nToolStripMenuItem, L"titulaci�nToolStripMenuItem");
			this->titulaci�nToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::titulaci�nToolStripMenuItem_Click);
			// 
			// centroToolStripMenuItem
			// 
			this->centroToolStripMenuItem->Name = L"centroToolStripMenuItem";
			resources->ApplyResources(this->centroToolStripMenuItem, L"centroToolStripMenuItem");
			this->centroToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::centroToolStripMenuItem_Click);
			// 
			// tipoDeSolicitudToolStripMenuItem
			// 
			this->tipoDeSolicitudToolStripMenuItem->Name = L"tipoDeSolicitudToolStripMenuItem";
			resources->ApplyResources(this->tipoDeSolicitudToolStripMenuItem, L"tipoDeSolicitudToolStripMenuItem");
			this->tipoDeSolicitudToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tipoDeSolicitudToolStripMenuItem_Click);
			// 
			// tipoDeResoluci�nToolStripMenuItem
			// 
			this->tipoDeResoluci�nToolStripMenuItem->Name = L"tipoDeResoluci�nToolStripMenuItem";
			resources->ApplyResources(this->tipoDeResoluci�nToolStripMenuItem, L"tipoDeResoluci�nToolStripMenuItem");
			this->tipoDeResoluci�nToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tipoDeResoluci�nToolStripMenuItem_Click);
			// 
			// tipoDeRecursoToolStripMenuItem
			// 
			this->tipoDeRecursoToolStripMenuItem->Name = L"tipoDeRecursoToolStripMenuItem";
			resources->ApplyResources(this->tipoDeRecursoToolStripMenuItem, L"tipoDeRecursoToolStripMenuItem");
			this->tipoDeRecursoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tipoDeRecursoToolStripMenuItem_Click);
			// 
			// tipoDeDocumentaci�nToolStripMenuItem
			// 
			this->tipoDeDocumentaci�nToolStripMenuItem->Name = L"tipoDeDocumentaci�nToolStripMenuItem";
			resources->ApplyResources(this->tipoDeDocumentaci�nToolStripMenuItem, L"tipoDeDocumentaci�nToolStripMenuItem");
			this->tipoDeDocumentaci�nToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tipoDeDocumentaci�nToolStripMenuItem_Click);
			// 
			// universidadesToolStripMenuItem
			// 
			this->universidadesToolStripMenuItem->Name = L"universidadesToolStripMenuItem";
			resources->ApplyResources(this->universidadesToolStripMenuItem, L"universidadesToolStripMenuItem");
			this->universidadesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::universidadesToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			resources->ApplyResources(this->toolStripSeparator2, L"toolStripSeparator2");
			// 
			// ModificarDownButton
			// 
			this->ModificarDownButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->ModificarDownButton->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->titulaci�nToolStripMenuItem1,
					this->centroToolStripMenuItem1
			});
			resources->ApplyResources(this->ModificarDownButton, L"ModificarDownButton");
			this->ModificarDownButton->Name = L"ModificarDownButton";
			// 
			// titulaci�nToolStripMenuItem1
			// 
			this->titulaci�nToolStripMenuItem1->Name = L"titulaci�nToolStripMenuItem1";
			resources->ApplyResources(this->titulaci�nToolStripMenuItem1, L"titulaci�nToolStripMenuItem1");
			this->titulaci�nToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::titulaci�nToolStripMenuItem1_Click);
			// 
			// centroToolStripMenuItem1
			// 
			this->centroToolStripMenuItem1->Name = L"centroToolStripMenuItem1";
			resources->ApplyResources(this->centroToolStripMenuItem1, L"centroToolStripMenuItem1");
			this->centroToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::centroToolStripMenuItem1_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			resources->ApplyResources(this->toolStripSeparator3, L"toolStripSeparator3");
			// 
			// EliminarDownButton
			// 
			this->EliminarDownButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->EliminarDownButton->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->titulaci�nToolStripMenuItem2,
					this->centroToolStripMenuItem2, this->tipoDeSolicitudToolStripMenuItem1, this->tipoDeResoluci�nToolStripMenuItem1, this->tipoDeRecursoToolStripMenuItem1,
					this->tipoDeDocumentaci�nToolStripMenuItem1
			});
			resources->ApplyResources(this->EliminarDownButton, L"EliminarDownButton");
			this->EliminarDownButton->Name = L"EliminarDownButton";
			// 
			// titulaci�nToolStripMenuItem2
			// 
			this->titulaci�nToolStripMenuItem2->Name = L"titulaci�nToolStripMenuItem2";
			resources->ApplyResources(this->titulaci�nToolStripMenuItem2, L"titulaci�nToolStripMenuItem2");
			this->titulaci�nToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::titulaci�nToolStripMenuItem2_Click);
			// 
			// centroToolStripMenuItem2
			// 
			this->centroToolStripMenuItem2->Name = L"centroToolStripMenuItem2";
			resources->ApplyResources(this->centroToolStripMenuItem2, L"centroToolStripMenuItem2");
			this->centroToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::centroToolStripMenuItem2_Click);
			// 
			// tipoDeSolicitudToolStripMenuItem1
			// 
			this->tipoDeSolicitudToolStripMenuItem1->Name = L"tipoDeSolicitudToolStripMenuItem1";
			resources->ApplyResources(this->tipoDeSolicitudToolStripMenuItem1, L"tipoDeSolicitudToolStripMenuItem1");
			this->tipoDeSolicitudToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::tipoDeSolicitudToolStripMenuItem1_Click);
			// 
			// tipoDeResoluci�nToolStripMenuItem1
			// 
			resources->ApplyResources(this->tipoDeResoluci�nToolStripMenuItem1, L"tipoDeResoluci�nToolStripMenuItem1");
			this->tipoDeResoluci�nToolStripMenuItem1->Name = L"tipoDeResoluci�nToolStripMenuItem1";
			this->tipoDeResoluci�nToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::tipoDeResoluci�nToolStripMenuItem1_Click);
			// 
			// tipoDeRecursoToolStripMenuItem1
			// 
			resources->ApplyResources(this->tipoDeRecursoToolStripMenuItem1, L"tipoDeRecursoToolStripMenuItem1");
			this->tipoDeRecursoToolStripMenuItem1->Name = L"tipoDeRecursoToolStripMenuItem1";
			this->tipoDeRecursoToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::tipoDeRecursoToolStripMenuItem1_Click);
			// 
			// tipoDeDocumentaci�nToolStripMenuItem1
			// 
			this->tipoDeDocumentaci�nToolStripMenuItem1->Name = L"tipoDeDocumentaci�nToolStripMenuItem1";
			resources->ApplyResources(this->tipoDeDocumentaci�nToolStripMenuItem1, L"tipoDeDocumentaci�nToolStripMenuItem1");
			this->tipoDeDocumentaci�nToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::tipoDeDocumentaci�nToolStripMenuItem1_Click);
			// 
			// labelModificar
			// 
			resources->ApplyResources(this->labelModificar, L"labelModificar");
			this->labelModificar->Name = L"labelModificar";
			this->labelModificar->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// labelExportar
			// 
			resources->ApplyResources(this->labelExportar, L"labelExportar");
			this->labelExportar->Name = L"labelExportar";
			// 
			// labelBuscar
			// 
			resources->ApplyResources(this->labelBuscar, L"labelBuscar");
			this->labelBuscar->Name = L"labelBuscar";
			// 
			// GrabEstlabel
			// 
			resources->ApplyResources(this->GrabEstlabel, L"GrabEstlabel");
			this->GrabEstlabel->Name = L"GrabEstlabel";
			// 
			// GrabEstbutton
			// 
			resources->ApplyResources(this->GrabEstbutton, L"GrabEstbutton");
			this->GrabEstbutton->Name = L"GrabEstbutton";
			this->GrabEstbutton->UseVisualStyleBackColor = true;
			this->GrabEstbutton->Click += gcnew System::Even|HAj$leS(this, &MyForm::GrabEstbutton_Click);
			// 
			// �ab'l1
		)/�0
	RAwources->Qp0dyResources(this->label1, L"la�El�2);
			this�>l#bel1->Name = L"laben1�:H			thiS-�tacal1->Click += gcnew System::EventJafeler(tlic. &MyFoRm�*label1_Click_2);
			// 
			// Consultarw4tnn
			// 
		bgsources->Aqp�{�mr-urces(thas:Consultabutto�, "Consultab}tTkn");
			phyq-<Cgosultabutton->Name = L"Consu|t!jqtdmn";
			this-:Clsultabutton->UseVisualSty|eickColor =$tbwe;
			thir-��fp}ltabutton->Click += gcnew SySv�u;:EventHandler(this, &MyForm::Cons5lt@bu4toO_Click);
			// 
			/' E�`ortFileDialog
			// 
			this->exp/rtgileDialog->@evcultExt = L"rasr";
		RasOu�ses->ApplyResources(tlic/>expgrTBileDianoo- L"%ppnvtFmluFialog");	�	Tlis->exportF�leialog->FileOk += gcnew System::Compon�ntoleL>:CancelEventHaod�er(vhar, &MyForm::exportFileDiele_FileOk);
)	// 
	)+/ imporTD�qlog
			// 	this->importFiimkg-<mfauLu��t = L"rasr";
			this->importDialo'->gileName = L"openFileDiaLo�2;
			resour�eso>ApplyResourCe�8this->importDialog, L"importDialog")?		this->imporpD9clNg->DIl�_o�;= gcnew System::ComponendM/lel::CancelEventHandler(this, &MyForm::impost�ialog_fi�uOk);
			// 
			// EricSe�BUpton
		/'!
I	resources-?A�plXResources(thaw*ErabResButton, L"GrabVec@utton"�;H			tpi!>GrabResButton->Name < �"GrabResButton";
			this->GrabResBut4on>�seisuAl�dy,eB@c{C/dor = true;
			this->G�abec@utton->Click!+� g�ne5 System::E6enUHandler(this, &MyForm�:G0abResButtonOC,ack);
			// 
			// butt�n�:t0aer(+/ 
			reco5zces->ApplyResources(this->bwt|nnMxTvaer, L"`u|uonExtraer");
	�|hIw->buttonExtraer->Name = L"buttonExtraer";
			this->juTponExtraer->UseVisualStyleacJColor = true+J�	om`,
(		// M9FoSm
			// 
			resources->ApplyRds�urgec*this, L"$this")�
K		thkse?aP�oQca,eMNde"=(Rystem::Windows::Forms::AutoSca,eMNde::Font;	
	this-�Ba!kColor = System::Drawing::SystemColors::Control;
�		6his->Controls->Add�ph;q->btt�onExtraer);
			this->Contro|sm6Add(this->GrabResBudt/n);
			this->Conprns->Add(this->Con�ul6abutton)�
K		t(iS�Sontr�lso>Add(this->label1)9�	t*ms=<Controls->A`d8vhiw-.ErabEstbuut�n	?
			this->CgnTvols->AldHphHs->GrabEstlafe|+;
)	thhs�>Contso�s->Edt*this-l�redBUgc!z);
�		6ii�->Controls->Add)t�is->labelExportar)+J		this->Controls->Add,txks->labelModif)caS);
			thiw-.Aontrols->Add(txi3%>toolStrip1);
			this->Controls->Add(this->labelGrabar);
			this->Controlc-~Idd,txks->"utUonGrabar);
			thhs�>HelpButton = true�
K		this->Name = L"MyForm";M�([vhis->Load += gcnew Syrt�m::EventHandlmrPh�c, &MyForm::MyVo0eWMoad);�
	K	this->toolStrip1->Re{uMoLY~out(false);
			this->toomS�rip-�@erformLayout();
		dis-�Re1umeLayout(false);
			this->PerformLayout();
-
�}
#prag�` �ndrefi�n)p�yvitE> System::Void MyFormLo@d(Syst%m:Object~ �cender, System::EventArgs^  e) {
	}
	private: Sywtuo::Void label1_ClickS�ctem::Object^  sender, Sys~eE?:EventArgs^ `e){
	}
	private: System::Voie �utto~G2ibar_Click(System::Object^  sender, Sysue�::EventAsg�^  e) {
this->Ii�e();
		SGBDRasore::GrabarSolic)tuE ^dialog = gcnew SGBDRaSO��:::ab@rSolicitud(.bt+;
		dialog->ShowDialog();
	t�is->Show(!;-		delete"da`log;
	iZpRmvate: Syspe}8:Voil Lebel1_Click_1(System::Object^  sendurl(Syct%e::E~eNpArgs^  e) ;
(}
	private: S�st'-::Wo�t Gr!bER�bu�to,_Click(SysTe�*:Objuc4V  sendep,(Rystem::EventrgZ^ $e+ s
		4hhR�>Hkdm));
		SGBDRasore*:zabarEstudiante ^dialog = gcnew [Gb@Rasore::GrabarGs|tdianre0)bd-;		dialog->ShowDialOg�9;
		thiS-�Chow();
		ddl�te dialog;
	}
private: System8:^nid lAb�|[Click_2(System::Object^  sender, System::EventArgs^" }(`s
}
privctm; Qy{ueM:�Fghd guardarMenuItem_Click(System::Obje�t^b sender, System::Eve~�z%{^ de){
	this->bd->saveDataBasg(%:]
	Zuring menSa�u =!"�odos los datos se han guardado satisfac4orHale�te.";
	SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasOr�*:InformationDialog(men�aj');
	dialog->ShowDaaLkg();
	de|e4m diAl�w;K}�+private: Systei:*Toid 4iXN�qSolicitudToolStrypmnuItem_Click(S9st�m:xObject~ �cender, System::Evefte�wq `m) {
	string mensaje = "solicitud.";
	SGBDRasore::addTypeOf ^dialog = gcnew SGBDRasore::addTypeOf(*bd, mensaje-;	dialog->Sho7Di@log();
	delede`lialog;
}
privat�: ys4em:Void tipoDeResoluci�oT�olStripMenuItem_Glyak(Sy{tEi::Object^  senddr� System::veOtArgs^  e) {
	stRi�w m%ns@je = "resolqcy�n.2;M	SGBDRasore:>atfTypeOf ^dialog =0g!fmv SGB@rq�re2:A`dTypgOn)*bd, mensaje);
	dialog->SHo�Tialog()3*delete dialoe;}
private: System::Void tipoDeRecursoToolStripMenuItem_Cli�k(ystem:2OBnebt�  senderl SXstee:AvejtQpgs^  g)(z
	str�ngbmensaJe�- "recurso."{(�GBDRasore::atdqpmOF$^dialog = gcnew SGBD�as-re::addTypeOf(*bd, mmnSaju+;
	dialog->ShowDiahow*)?delete dialog;-
�
private: Sywtuo::Void titulaci�nTno�StripMenuItem_Click(System::Object^  sender, System::EventArgs~ �u) {
	this->HadE,);
	SGBDRcsgse:a�tStudiesForm ^dialog ? b�Tw SGBDRa{oRa::addStudiesFoRm�:bd);
	dialog->ShowDialOg�9;
	thhs�>Show();
	delete diilOc:�}@v)~ate: �ys6em:;V�id centroToolStripMenuI4em~Click(Sysde-2:Object^  sdn�er, System::EventArgs^� ek ;
(this->Hide();
	SGBDRasore::adeC�ntre ^dialog = gcnew SGBDRasore::addCenTr�8*bd)+Jdialog->ShowLiAhgh!;
	this->Show();
	leLate dialog;
}
pbi6ite: System::Void eqt}eiantesToolStripMenuItem_Click(System::Object^� s'nder, Sxs�dm�:EventArgc^`(e) {
	joOh eo�t = false;
	string mens`j� = "�u proceder� i BkrzaR$todos l�s &�to1 de los est}dIeot�s grabados y no se(pO`r�n`zecuperar.\n�Est� seguro de querer c�nt*n�ar/"{
	SEBLSasove*8warningBol%inDialog ^dialow }(gcnew SB�sa1ore::warniog�o�le#nDialog(doIt, mdn�aje);
	liAhog->ShowD)alNg();
	if (doIt)	
vhar->b�->&ropTableStudentq(!:
	delete di�lo%;
}
privadez(System::Void solici|qDqqTooltrHpMenuMtuo_Sl)kk(System8:Gcject^  sender, System::Ev�ntrg�^ be) {
	bool do�t  falsa;	�tr+ng mensaje`= Se prmcmeer� a borrar un��s los datos de las solicitudes grabadas y no qg yN`z�N$recupdr�r.\n�Est� seguro de qt��e0 con�in7ar?*;-	SOBDV�Co�}:sarningBooleanDialog ^dialog = gcnew SGBDRasore::warNi�wRmoleaoD�alog(doIt, menqabd);
	dialog->ShowDialoc(99
	i& (EoYti
		thiw-.`d->dropTab|explications();
	delete Di�|og;
}
xsivate: System:>Vkd Re�lucionesToolStripMenuItem_Click(System::Object^  sender, SySt�}::Evun4Irgs^  e) {
	bool doIt = false;
	string mensaje = "Se proceder� a borrar todos los datos de las resolucionew qnmacenadas y no se podr�n recUp�baS.\n�Est�$s5euSo $e PueRe�0continucr7#;
	SGBDRaso�e:xwarNi�wBoglEenDialog ^dialog =(gCjew SGBDRasore::sibLmngBooleanDaaLkg(doI|, iensaje);
	dialOg�.ShowDma|mg();	If (doIt9J	this->bd->dropUc�ddResolution();
	delete d9a,Fg;M
},
privitE> Systeo:2Woid Consultabutton_Click(Systumz2Object^  smnDar, System::EventArcsN"!e� {
	this->Hide();
	SGBDRasore::ConsultaForm ^ti!dog = gcn%w rGBDRasore::ConsultaForm(*bd);
	dialgm6ShowDialog();
	this->Sio�();
	delete(dIelog;
}JprHvate:(SYwtem::Void titulaci�nToolStripManeKtem1_Click)S�stem::Object^  sender, System*:~entArgs^  e) {
)t�ys->HiDe�9;
	string mensaje = "�ytulaci�n";
	SGBDRasore::modificarElem ^dialog = gcnew SGBDRasore::Mo�ygi�azDlem(*bd, mensaje);
	dialog->ShowTi!dog();
	t(is>Show)�J)`Dlete dialog;
}
priva�e:bSypt�l::Toae centroToolStripMenuItem1_Click(System::Object^  s�nd'r, System::EvandCrgs^  �9({-	this->Hide();
	string mensaje�= `centrg"	SGBDRaqozd::modificarElem$^tkalog = ecfdw S�Dssore::modificarElem(*bd, mensaje);
	dialog->ShowFiimog();
	this->Show();�	d'let� d+alog;
}
private: System::Voit 4apoDgDgr�-m,taci�nToolQtzhpMenuItem_Click(System::Object~ �culder, System::EventArgs^  e) {
	string mensa�e( &documenda#a�n.";
	sG�TRasore::addTyxeob ^dialog = gcnew SGBDRa3orD::addTypeOf(*bd, menqabd);
	dialog-S�wDialog((;�
	delete dialog;
}
private: System:*V/ad universidadesToml[Ur�`MenuItem_Click(System::Object�  1ender, Sys4Em�*EventArgs^ 0ei({
)WGBDRasore::addUnivForm$tk@log = gcnew SGBDRasore::addUnivForm(*bd);
	dialog->ShowDialkg8+;
	delete dialog;
}
priva4e:System:2VOmd titulaci�nToomS�ripMenuItem2_Click(System::Object^  sender, sy�dem::EventQr'{^  e) {
	string tipo =0"4atulaci�n";
	SGBDRasore::eliminaElemForm ^dialog = gcnew SGBDRasore::eliminaElemForm(*bd, tipo);
	dialog->ShowDialog();
	delete dialog;
}
private: System::Void centroToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
	string tipo = "centro";
	SGBDRasore::eliminaElemForm ^dialog = gcnew SGBDRasore::eliminaElemForm(*bd, tipo);
	dialog->ShowDialog();
	delete dialog;
}
private: System::Void tipoDeSolicitudToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	string tipo = "solicitud";
	SGBDRasore::eliminaElemForm ^dialog = gcnew SGBDRasore::eliminaElemForm(*bd, tipo);
	dialog->ShowDialog();
	delete dialog;
}
private: System::Void tipoDeResoluci�nToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	string tipo = "resoluci�n";
	SGBDRasore::eliminaElemForm ^dialog = gcnew SGBDRasore::eliminaElemForm(*bd, tipo);
	dialog->ShowDialog();
	delete dialog;
}
private: System::Void tipoDeRecursoToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	string tipo = "recurso";
	SGBDRasore::eliminaElemForm ^dialog = gcnew SGBDRasore::eliminaElemForm(*bd, tipo);
	dialog->ShowDialog();
	delete dialog;
}
private: System::Void tipoDeDocumentaci�nToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	string tipo = "documentaci�n";
	SGBDRasore::eliminaElemForm ^dialog = gcnew SGBDRasore::eliminaElemForm(*bd, tipo);
	dialog->ShowDialog();
	delete dialog;
}
private: System::Void BorrarDownButton_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void recargarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->bd->reloadDataBase();
	string m = "Se ha recargado todo el contenido de la base de datos.";
	SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
	inforD->ShowDialog();
	delete inforD;
}
private: System::Void copiaDeSeguridadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->exportFileDialog->ShowDialog();
	if (this->bd->getLocationExport().size() > 0) {
		this->bd->exportDataBase();
		this->bd->setLocationExport("");
		string m = "Se ha exportado correctamente la base de datos.";
		SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
		inforD->ShowDialog();
		delete inforD;
	}
}
private: System::Void exportFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	using namespace Runtime::InteropServices;
	string location = (const char*)(Marshal::StringToHGlobalAnsi(this->exportFileDialog->FileName)).ToPointer();
	if (location.size() > 0)
		this->bd->setLocationExport(location);
}
private: System::Void exportarYVaciarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->exportFileDialog->ShowDialog();
	if (this->bd->getLocationExport().size() > 0) {
		this->bd->exportDataBase();
		this->bd->setLocationExport("");
		this->bd->clearDataBase();
		string m = "Se ha exportado correctamente la base de datos.";
		SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
		inforD->ShowDialog();
		delete inforD;
	}
}
private: System::Void sustituirDatosAlmacenadosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->importDialog->ShowDialog();
	if (this->bd->getLocationImport().size() > 0) {
		bool doIt = false;
		string m = (string) "Se borrar�n todos los datos almacenados en la base de datos y no se podr�n recuperar\n" +
			"a menos que haya importado la base de datos. �Est� seguro de querer continuar?";
		SGBDRasore::warningBooleanDialog ^dWarn = gcnew SGBDRasore::warningBooleanDialog(doIt, m);
		dWarn->ShowDialog();
		delete dWarn;
		if (doIt) {
			this->bd->clearDataBase();
			vector<string> errores;
			vector<unsigned int> numOfErrors;
			this->bd->importDataBase(errores, numOfErrors);
			this->bd->setLocationImport("");
			string m = "Se ha importado correctamente la base de datos.";
			SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
			inforD->ShowDialog();
			delete inforD;
		}
	}
}
private: System::Void importDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	using namespace Runtime::InteropServices;
	string location = (const char*)(Marshal::StringToHGlobalAnsi(this->importDialog->FileName)).ToPointer();
	if (location.size() > 0)
		this->bd->setLocationImport(location);
}
private: System::Void a�adirDatosALosAlmacenadosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void reemplazarActualesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->importDialog->ShowDialog();
	if (this->bd->getLocationImport().size() > 0) {
		vector<string> errores;
		vector<unsigned int> numOfErrors;
		this->bd->importDataBase(errores, numOfErrors);
		this->bd->setLocationImport("");
		this->bd->insertErrorLines(errores, numOfErrors);
		string m = "Se ha importado correctamente la base de datos.";
		SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
		inforD->ShowDialog();
		delete inforD;
	}
}
private: System::Void mantenerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->importDialog->ShowDialog();
	if (this->bd->getLocationImport().size() > 0) {
		vector<string> errores;
		vector<unsigned int> numOfErrors;
		this->bd->importDataBase(errores, numOfErrors);
		this->bd->setLocationImport("");
		string m = "Se ha importado correctamente la base de datos.";
		SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
		inforD->ShowDialog();
		delete inforD;
	}
}
private: System::Void cToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void centrosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void mantenerTablasB�sicasToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->exportFileDialog->ShowDialog();
	if (this->bd->getLocationExport().size() > 0) {
		this->bd->exportDataBase();
		this->bd->setLocationExport("");
		this->bd->dropTableResolution();
		this->bd->dropTableApplications();
		this->bd->dropTableStudents();
		string m = "Se ha exportado correctamente la base de datos.";
		SGBDRasore::InformationDialog ^inforD = gcnew SGBDRasore::InformationDialog(m);
		inforD->ShowDialog();
		delete inforD;
	}
}
private: System::Void GrabResButton_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	auto nSol = this->bd->getAppWithoutRes();
	if (nSol.size() == 0) {
		string mensaje = "No hay solicitudes para tramitar una resoluci�n.";
		SGBDRasore::errorDialog ^dError = gcnew SGBDRasore::errorDialog(mensaje);
		dError->ShowDialog();
		delete dError;
	}
	else {
		SGBDRasore::GrabarResolucion ^d = gcnew SGBDRasore::GrabarResolucion(*bd, nSol);
		d->ShowDialog();
		delete d;
	}
	this->Show();
}
};
}
#endif