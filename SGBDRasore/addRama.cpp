#include "addRama.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaAddRama(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew addRama());

	return 0;

}