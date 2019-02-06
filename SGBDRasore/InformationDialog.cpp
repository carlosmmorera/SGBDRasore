#include "InformationDialog.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaInfDialog(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew InformationDialog());

	return 0;

}