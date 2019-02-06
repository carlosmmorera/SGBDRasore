#include "ConsultaForm.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaConsultaForm(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew ConsultaForm());

	return 0;

}