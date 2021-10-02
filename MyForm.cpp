#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

//[STAThreadAttribute]
int MyUI(void* data) {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	FlightSimInterface::MyForm form((SharedData*)data);
	Application::Run(% form);

	return 0;
}



