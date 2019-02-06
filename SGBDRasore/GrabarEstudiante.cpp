#include "GrabarEstudiante.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaGrabarEstudiante(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);
	
	Application::Run(gcnew GrabarEstudiante());

	return 0;

}