#include "CoincidenciasForm.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaCoincidenciasForm(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew CoincidenciasForm());

	return 0;

}