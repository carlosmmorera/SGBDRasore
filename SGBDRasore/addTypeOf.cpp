#include "addTypeOf.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaTypeOf(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew addTypeOf());

	return 0;

}