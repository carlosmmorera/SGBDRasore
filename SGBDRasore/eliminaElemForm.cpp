#include "eliminaElemForm.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaEliminaEleme(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew eliminaElemForm());

	return 0;

}