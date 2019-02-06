#include "warningBooleanDialog.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaWarning(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew warningBooleanDialog());

	return 0;

}