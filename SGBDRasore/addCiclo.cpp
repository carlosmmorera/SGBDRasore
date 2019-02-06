#include "addCiclo.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaAddCiclo(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew addCiclo());

	return 0;

}