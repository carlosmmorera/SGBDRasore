#include "TablaEstud.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaTablaEstud(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew TablaEstud());

	return 0;

}