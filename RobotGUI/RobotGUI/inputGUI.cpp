#include "inputGUI.h"
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
namespace RobotGUI {
	using namespace System;
	using namespace System::Windows::Forms;

	[STAThread]
	int main(array<System::String ^> ^args)
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew inputGUI());
		return 0;
	}
}