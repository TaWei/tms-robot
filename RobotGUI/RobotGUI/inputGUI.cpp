#include "inputGUI.h"
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include "extApi.h"


namespace RobotGUI {
	using namespace System;
	using namespace System::Windows::Forms;
	[STAThread]
	int main(array<System::String ^> ^args)
	{
		//Initialize input arguments portNumber and headMesh handle
		/*
		int portNb = 0;
		int headMesh;
		if (argc >= 5)
		{
			portNb = atoi(argv[1]);
			headMesh = atoi(argv[2]);
		}
		else
		{
			printf("Indicate following arguments: 'portNumber headMesh'!\n");
			extApi_sleepMs(5000);
			return 0;
		}
		*/
		//Setup V-REP Client
		//int clientID = simxStart((simxChar*)"127.0.0.1", portNb, true, true, 2000, 5);

		//Create GUI
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew inputGUI());

		//Client Program
		/*
		if (clientID != -1)
		{
			while (simxGetConnectionId(clientID) != -1)
			{
				extApi_sleepMs(5);
			}
			simxFinish(clientID);
		}
		else{
			printf("Client connection failed.");
		}
		return 0;
		*/
		return 0;
	}

}