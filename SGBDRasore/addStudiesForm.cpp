#include "addStudiesForm.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaaddStudies(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew addStudiesForm());

	return 0;

}