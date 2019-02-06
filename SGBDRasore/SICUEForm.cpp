#include "SICUEForm.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaSICUE(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew SICUEForm());

	return 0;

}