#include "addCentre.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaAddCentre(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew addCentre());

	return 0;

}