#include "GrabarSolicitud.h"

#include <Windows.h>

using namespace SGBDRasore; // This is your project name

int WINAPI creaGrabarSolicitud(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew GrabarSolicitud());

	return 0;

}