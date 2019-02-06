#include "modificarElem.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaModificarElem(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew modificarElem());

	return 0;

}