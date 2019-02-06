#include "errorDialog.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaErrorD(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew errorDialog());

	return 0;

}