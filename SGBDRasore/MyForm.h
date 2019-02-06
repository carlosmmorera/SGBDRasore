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
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeResoluciónToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeRecursoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  titulaciónToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;




	private: System::Windows::Forms::ToolStripDropDownButton^  ModificarDownButton;
	private: System::Windows::Forms::ToolStripMenuItem^  copiaDeSeguridadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportarYVaciarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sustituirDatosAlmacenadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  añadirDatosALosAlmacenadosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  titulaciónToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  centroToolStripMenuItem1;



	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeDocumentaciónToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^  EliminarDownButton;
	private: System::Windows::Forms::ToolStripMenuItem^  titulaciónToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  centroToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeSolicitudToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeResoluciónToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeRecursoToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tipoDeDocumentaciónToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  universidadesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  recargarToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  exportFileDialog;
	private: System::Windows::Forms::OpenFileDialog^  importDialog;
	private: System::Windows::Forms::ToolStripMenuItem^  reemplazarActualesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mantenerToolStripMenuItem;










	private: System::Windows::Forms::ToolStripMenuItem^  mantenerTablasBásicasToolStripMenuItem;
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
			this->mantenerTablasBásicasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importarMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sustituirDatosAlmacenadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->añadirDatosALosAlmacenadosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reemplazarActualesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->EditarButton = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->titulaciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->centroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeSolicitudToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeResoluciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeRecursoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeDocumentaciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->universidadesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ModificarDownButton = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->titulaciónToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->centroToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->EliminarDownButton = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->titulaciónToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->centroToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeSolicitudToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeResoluciónToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeRecursoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tipoDeDocumentaciónToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
					this->exportarYVaciarToolStripMenuItem, this->mantenerTablasBásicasToolStripMenuItem
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
			// mantenerTablasBásicasToolStripMenuItem
			// 
			this->mantenerTablasBásicasToolStripMenuItem->Name = L"mantenerTablasBásicasToolStripMenuItem";
			resources->ApplyResources(this->mantenerTablasBásicasToolStripMenuItem, L"mantenerTablasBásicasToolStripMenuItem");
			this->mantenerTablasBásicasToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::mantenerTablasBásicasToolStripMenuItem_Click);
			// 
			// importarMenuItem
			// 
			this->importarMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->sustituirDatosAlmacenadosToolStripMenuItem,
					this->añadirDatosALosAlmacenadosToolStripMenuItem
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
			// añadirDatosALosAlmacenadosToolStripMenuItem
			// 
			this->añadirDatosALosAlmacenadosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->reemplazarActualesToolStripMenuItem,
					this->mantenerToolStripMenuItem
			});
			this->añadirDatosALosAlmacenadosToolStripMenuItem->Name = L"añadirDatosALosAlmacenadosToolStripMenuItem";
			resources->ApplyResources(this->añadirDatosALosAlmacenadosToolStripMenuItem, L"añadirDatosALosAlmacenadosToolStripMenuItem");
			this->añadirDatosALosAlmacenadosToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::añadirDatosALosAlmacenadosToolStripMenuItem_Click);
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
				this->titulaciónToolStripMenuItem,
					this->centroToolStripMenuItem, this->tipoDeSolicitudToolStripMenuItem, this->tipoDeResoluciónToolStripMenuItem, this->tipoDeRecursoToolStripMenuItem,
					this->tipoDeDocumentaciónToolStripMenuItem, this->universidadesToolStripMenuItem
			});
			resources->ApplyResources(this->EditarButton, L"EditarButton");
			this->EditarButton->Name = L"EditarButton";
			// 
			// titulaciónToolStripMenuItem
			// 
			this->titulaciónToolStripMenuItem->Name = L"titulaciónToolStripMenuItem";
			resources->ApplyResources(this->titulaciónToolStripMenuItem, L"titulaciónToolStripMenuItem");
			this->titulaciónToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::titulaciónToolStripMenuItem_Click);
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
			// tipoDeResoluciónToolStripMenuItem
			// 
			this->tipoDeResoluciónToolStripMenuItem->Name = L"tipoDeResoluciónToolStripMenuItem";
			resources->ApplyResources(this->tipoDeResoluciónToolStripMenuItem, L"tipoDeResoluciónToolStripMenuItem");
			this->tipoDeResoluciónToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tipoDeResoluciónToolStripMenuItem_Click);
			// 
			// tipoDeRecursoToolStripMenuItem
			// 
			this->tipoDeRecursoToolStripMenuItem->Name = L"tipoDeRecursoToolStripMenuItem";
			resources->ApplyResources(this->tipoDeRecursoToolStripMenuItem, L"tipoDeRecursoToolStripMenuItem");
			this->tipoDeRecursoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tipoDeRecursoToolStripMenuItem_Click);
			// 
			// tipoDeDocumentaciónToolStripMenuItem
			// 
			this->tipoDeDocumentaciónToolStripMenuItem->Name = L"tipoDeDocumentaciónToolStripMenuItem";
			resources->ApplyResources(this->tipoDeDocumentaciónToolStripMenuItem, L"tipoDeDocumentaciónToolStripMenuItem");
			this->tipoDeDocumentaciónToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tipoDeDocumentaciónToolStripMenuItem_Click);
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
				this->titulaciónToolStripMenuItem1,
					this->centroToolStripMenuItem1
			});
			resources->ApplyResources(this->ModificarDownButton, L"ModificarDownButton");
			this->ModificarDownButton->Name = L"ModificarDownButton";
			// 
			// titulaciónToolStripMenuItem1
			// 
			this->titulaciónToolStripMenuItem1->Name = L"titulaciónToolStripMenuItem1";
			resources->ApplyResources(this->titulaciónToolStripMenuItem1, L"titulaciónToolStripMenuItem1");
			this->titulaciónToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::titulaciónToolStripMenuItem1_Click);
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
				this->titulaciónToolStripMenuItem2,
					this->centroToolStripMenuItem2, this->tipoDeSolicitudToolStripMenuItem1, this->tipoDeResoluciónToolStripMenuItem1, this->tipoDeRecursoToolStripMenuItem1,
					this->tipoDeDocumentaciónToolStripMenuItem1
			});
			resources->ApplyResources(this->EliminarDownButton, L"EliminarDownButton");
			this->EliminarDownButton->Name = L"EliminarDownButton";
			// 
			// titulaciónToolStripMenuItem2
			// 
			this->titulaciónToolStripMenuItem2->Name = L"titulaciónToolStripMenuItem2";
			resources->ApplyResources(this->titulaciónToolStripMenuItem2, L"titulaciónToolStripMenuItem2");
			this->titulaciónToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::titulaciónToolStripMenuItem2_Click);
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
			// tipoDeResoluciónToolStripMenuItem1
			// 
			resources->ApplyResources(this->tipoDeResoluciónToolStripMenuItem1, L"tipoDeResoluciónToolStripMenuItem1");
			this->tipoDeResoluciónToolStripMenuItem1->Name = L"tipoDeResoluciónToolStripMenuItem1";
			this->tipoDeResoluciónToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::tipoDeResoluciónToolStripMenuItem1_Click);
			// 
			// tipoDeRecursoToolStripMenuItem1
			// 
			resources->ApplyResources(this->tipoDeRecursoToolStripMenuItem1, L"tipoDeRecursoToolStripMenuItem1");
			this->tipoDeRecursoToolStripMenuItem1->Name = L"tipoDeRecursoToolStripMenuItem1";
			this->tipoDeRecursoToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::tipoDeRecursoToolStripMenuItem1_Click);
			// 
			// tipoDeDocumentaciónToolStripMenuItem1
			// 
			this->tipoDeDocumentaciónToolStripMenuItem1->Name = L"tipoDeDocumentaciónToolStripMenuItem1";
			resources->ApplyResources(this->tipoDeDocumentaciónToolStripMenuItem1, L"tipoDeDocumentaciónToolStripMenuItem1");
			this->tipoDeDocumentaciónToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::tipoDeDocumentaciónToolStripMenuItem1_Click);
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
			// ìab'l1
		)/¯0
	RAwources->Qp0dyResources(this->label1, L"laâEló2);
			this­>l#bel1->Name = L"laben1ª:H			thiS-þtacal1->Click += gcnew System::EventJafeler(tlic. &MyFoRmº*label1_Click_2);
			// 
			// Consultarw4tnn
			// 
		bgsources->Aqpè{Òmr-urces(thas:Consultabuttoî, "Consultab}tTkn");
			phyq-<Cgosultabutton->Name = L"Consu|t!jqtdmn";
			this-:Clsultabutton->UseVisualSty|eickColor =$tbwe;
			thir-ºÁfp}ltabutton->Click += gcnew SySvåu;:EventHandler(this, &MyForm::Cons5lt@bu4toO_Click);
			// 
			/' Eü`ortFileDialog
			// 
			this->exp/rtgileDialog->@evcultExt = L"rasr";
		RasOuòses->ApplyResources(tlic/>expgrTBileDianoo- L"%ppnvtFmluFialog");	…	Tlis->exportFéleialog->FileOk += gcnew System::ComponåntoleL>:CancelEventHaodèer(vhar, &MyForm::exportFileDiele_FileOk);
)	// 
	)+/ imporTDéqlog
			// 	this->importFiimkg-<mfauLuÅìt = L"rasr";
			this->importDialo'->gileName = L"openFileDiaLoç2;
			resourãeso>ApplyResourCeó8this->importDialog, L"importDialog")?		this->imporpD9clNg->DIlä_o ;= gcnew System::ComponendM/lel::CancelEventHandler(this, &MyForm::impostÀialog_fiìuOk);
			// 
			// EricSeÿBUpton
		/'!
I	resources-?A´plXResources(thaw*ErabResButton, L"GrabVec@utton"©;H			tpi!>GrabResButton->Name < È"GrabResButton";
			this->GrabResBut4on>ÕseisuAlÓdy,eB@c{C/dor = true;
			this->Gòabec@utton->Click!+¹ gãne5 System::E6enUHandler(this, &MyFormº:G0abResButtonOC,ack);
			// 
			// buttïnÅ:t0aer(+/ 
			reco5zces->ApplyResources(this->bwt|nnMxTvaer, L"`u|uonExtraer");
	|hIw->buttonExtraer->Name = L"buttonExtraer";
			this->juTponExtraer->UseVisualStyleacJColor = true+J‰	om`,
(		// M9FoSm
			// 
			resources->ApplyRdsëurgec*this, L"$this")»
K		thkse?aPôoQca,eMNde"=(Rystem::Windows::Forms::AutoSca,eMNde::Font;	
	this-¾Ba!kColor = System::Drawing::SystemColors::Control;
‰		6his->Controls->Add¨ph;q->bttðonExtraer);
			this->Contro|sm6Add(this->GrabResBudt/n);
			this->Conprns->Add(this->Conóul6abutton)»
K		t(iS¾Sontrïlso>Add(this->label1)9‰	t*ms=<Controls->A`d8vhiw-.ErabEstbuutãn	?
			this->CgnTvols->AldHphHs->GrabEstlafe|+;
)	thhs©>Contsoès->Edt*this-láredBUgc!z);
‰		6ii÷->Controls->Add)tìis->labelExportar)+J		this->Controls->Add,txks->labelModif)caS);
			thiw-.Aontrols->Add(txi3%>toolStrip1);
			this->Controls->Add(this->labelGrabar);
			this->Controlc-~Idd,txks->"utUonGrabar);
			thhs©>HelpButton = true»
K		this->Name = L"MyForm";MŠ([vhis->Load += gcnew Syrtám::EventHandlmrPhéc, &MyForm::MyVo0eWMoad);
	K	this->toolStrip1->Re{uMoLY~out(false);
			this->toomSðrip-¾@erformLayout();
		dis-¾Re1umeLayout(false);
			this->PerformLayout();
-
‰}
#pragí` £ndrefién)pòyvitE> System::Void MyFormLo@d(Syst%m:Object~  cender, System::EventArgs^  e) {
	}
	private: Sywtuo::Void label1_ClickSùctem::Object^  sender, Sys~eE?:EventArgs^ `e){
	}
	private: System::Voie æutto~G2ibar_Click(System::Object^  sender, Sysueé::EventAsg÷^  e) {
this->Iiàe();
		SGBDRasore::GrabarSolic)tuE ^dialog = gcnew SGBDRaSOòõ:::ab@rSolicitud(.bt+;
		dialog->ShowDialog();
	tìis->Show(!;-		delete"da`log;
	iZpRmvate: Syspe}8:Voil Lebel1_Click_1(System::Object^  sendurl(Syct%e::E~eNpArgs^  e) ;
(}
	private: Sùst'-::Woét Gr!bERôbu¶to,_Click(SysTeí*:Objuc4V  sendep,(Rystem::EventrgZ^ $e+ s
		4hhR©>Hkdm));
		SGBDRasore*:zabarEstudiante ^dialog = gcnew [Gb@Rasore::GrabarGs|tdianre0)bd-;		dialog->ShowDialOg¨9;
		thiS-¾Chow();
		ddláte dialog;
	}
private: System8:^nid lAbí|[Click_2(System::Object^  sender, System::EventArgs^" }(`s
}
privctm; Qy{ueM:¸Fghd guardarMenuItem_Click(System::Objeãt^b sender, System::Eve~ôz%{^ de){
	this->bd->saveDataBasg(%:]
	Zuring menSaêu =!"Ðodos los datos se han guardado satisfac4orHaleête.";
	SGBDRasore::InformationDialog ^dialog = gcnew SGBDRasOrå*:InformationDialog(menóaj');
	dialog->ShowDaaLkg();
	de|e4m diAlïw;K}‰+private: Systei:*Toid 4iXNäqSolicitudToolStrypmnuItem_Click(S9stÄm:xObject~  cender, System::Evefteöwq `m) {
	string mensaje = "solicitud.";
	SGBDRasore::addTypeOf ^dialog = gcnew SGBDRasore::addTypeOf(*bd, mensaje-;	dialog->Sho7Di@log();
	delede`lialog;
}
privatå: ys4em:Void tipoDeResolucióoTëolStripMenuItem_Glyak(Sy{tEi::Object^  senddr¨ System::veOtArgs^  e) {
	stRiîw m%ns@je = "resolqcyñn.2;M	SGBDRasore:>atfTypeOf ^dialog =0g!fmv SGB@rqñre2:A`dTypgOn)*bd, mensaje);
	dialog->SHo÷Tialog()3*delete dialoe;}
private: System::Void tipoDeRecursoToolStripMenuItem_Cliãk(ystem:2OBnebtÚ  senderl SXstee:AvejtQpgs^  g)(z
	stréngbmensaJe - "recurso."{(×GBDRasore::atdqpmOF$^dialog = gcnew SGBDÒas-re::addTypeOf(*bd, mmnSaju+;
	dialog->ShowDiahow*)?delete dialog;-
ý
private: Sywtuo::Void titulaciónTnoèStripMenuItem_Click(System::Object^  sender, System::EventArgs~  u) {
	this->HadE,);
	SGBDRcsgse:aätStudiesForm ^dialog ? bîTw SGBDRa{oRa::addStudiesFoRm¨:bd);
	dialog->ShowDialOg¨9;
	thhs©>Show();
	delete diilOc:Š}@v)~ate: Óys6em:;Vëid centroToolStripMenuI4em~Click(Sysde-2:Object^  sdnàer, System::EventArgs^  ek ;
(this->Hide();
	SGBDRasore::adeCántre ^dialog = gcnew SGBDRasore::addCenTrå8*bd)+Jdialog->ShowLiAhgh!;
	this->Show();
	leLate dialog;
}
pbi6ite: System::Void eqt}eiantesToolStripMenuItem_Click(System::Object^  s'nder, Sxsðdm¾:EventArgc^`(e) {
	joOh eoÍt = false;
	string mens`já = "Óu procederá i BkrzaR$todos lïs &áto1 de los est}dIeotás grabados y no se(pO`rñn`zecuperar.\n¿Está seguro de querer cïnt*nñar/"{
	SEBLSasove*8warningBol%inDialog ^dialow }(gcnew SBÄsa1ore::warniogÆoïle#nDialog(doIt, mdn÷aje);
	liAhog->ShowD)alNg();
	if (doIt)	
vhar->bä->&ropTableStudentq(!:
	delete diálo%;
}
privadez(System::Void solici|qDqqTooltrHpMenuMtuo_Sl)kk(System8:Gcject^  sender, System::Evåntrgó^ be) {
	bool doÉt  falsa;	ótr+ng mensaje`= Se prmcmeerá a borrar unàës los datos de las solicitudes grabadas y no qg yN`záN$recupdrår.\n¿Está seguro de qtåöe0 conôin7ar?*;-	SOBDVáCoò}:sarningBooleanDialog ^dialog = gcnew SGBDRasore::warNiêwRmoleaoDíalog(doIt, menqabd);
	dialog->ShowDialoc(99
	i& (EoYti
		thiw-.`d->dropTab|explications();
	delete Diá|og;
}
xsivate: System:>Vkd ReólucionesToolStripMenuItem_Click(System::Object^  sender, SyStå}::Evun4Irgs^  e) {
	bool doIt = false;
	string mensaje = "Se procederá a borrar todos los datos de las resolucionew qnmacenadas y no se podrán recUp¥baS.\n¿Está$s5euSo $e PueReò0continucr7#;
	SGBDRasoòe:xwarNiîwBoglEenDialog ^dialog =(gCjew SGBDRasore::sibLmngBooleanDaaLkg(doI|, iensaje);
	dialOg­.ShowDma|mg();	If (doIt9J	this->bd->dropUcæddResolution();
	delete d9a,Fg;M
},
privitE> Systeo:2Woid Consultabutton_Click(Systumz2Object^  smnDar, System::EventArcsN"!e­ {
	this->Hide();
	SGBDRasore::ConsultaForm ^ti!dog = gcn%w rGBDRasore::ConsultaForm(*bd);
	dialgm6ShowDialog();
	this->Sioó();
	delete(dIelog;
}JprHvate:(SYwtem::Void titulaciónToolStripManeKtem1_Click)Sýstem::Object^  sender, System*:~entArgs^  e) {
)tèys->HiDe¨9;
	string mensaje = "ôytulación";
	SGBDRasore::modificarElem ^dialog = gcnew SGBDRasore::MoäygiåazDlem(*bd, mensaje);
	dialog->ShowTi!dog();
	t(is>Show)»J)`Dlete dialog;
}
privaôe:bSyptél::Toae centroToolStripMenuItem1_Click(System::Object^  sånd'r, System::EvandCrgs^  å9({-	this->Hide();
	string mensaje = `centrg"	SGBDRaqozd::modificarElem$^tkalog = ecfdw S‚Dssore::modificarElem(*bd, mensaje);
	dialog->ShowFiimog();
	this->Show();Š	d'letå d+alog;
}
private: System::Voit 4apoDgDgrõ-m,taciónToolQtzhpMenuItem_Click(System::Object~ ¤culder, System::EventArgs^  e) {
	string mensaêe( &documenda#aón.";
	sGÂTRasore::addTyxeob ^dialog = gcnew SGBDRa3orD::addTypeOf(*bd, menqabd);
	dialog-SèwDialog((;‰
	delete dialog;
}
private: System:*V/ad universidadesToml[Uré`MenuItem_Click(System::ObjectÞ  1ender, Sys4Em›*EventArgs^ 0ei({
)WGBDRasore::addUnivForm$tk@log = gcnew SGBDRasore::addUnivForm(*bd);
	dialog->ShowDialkg8+;
	delete dialog;
}
priva4e:System:2VOmd titulaciónToomSðripMenuItem2_Click(System::Object^  sender, syódem::EventQr'{^  e) {
	string tipo =0"4atulación";
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
private: System::Void tipoDeResoluciónToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	string tipo = "resolución";
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
private: System::Void tipoDeDocumentaciónToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	string tipo = "documentación";
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
		string m = (string) "Se borrarán todos los datos almacenados en la base de datos y no se podrán recuperar\n" +
			"a menos que haya importado la base de datos. ¿Está seguro de querer continuar?";
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
private: System::Void añadirDatosALosAlmacenadosToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
private: System::Void mantenerTablasBásicasToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
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
		string mensaje = "No hay solicitudes para tramitar una resolución.";
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