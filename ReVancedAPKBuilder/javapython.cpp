#include <iostream>
#include <Windows.h>

#include "javapython.h"
#include "files.h"
#include "consoleColor.h"
#include "restartprogram.h"



void jpInstall()
{
	bool bJavaContinue{ false };

	conColor(8);
	switchFile(3);

	std::cout << "\nSetup and install (Python 3.10.5)\n";

	conColor(4);
	std::cout << "\n\n[!] Make sure to check 'Add Python 3.10 to PATH' in Python Installer\n";
	std::cout << "\n** Do not continue unless Python is installed. The program will not work otherwise.\n";

	conColor(14);
	std::cout << "\n\nPress Enter to proceed with JDK installation.\n";

	(void)getchar();

	switchFile(2);

	std::cout << "\n\nComplete the setup for 'zulu17.34.19-ca-jdk17.0.3-win_x64' (JDK 17)\n";

	conColor(4);
	std::cout << "\n[!] Do not continue until JDK is successfully installed; the compilation will fail otherwise.\n";

	Sleep(100);
	conColor(4);
	std::cout << "\n** Continue after JDK has been installed. Check taskbar for JDK installer popup. ( Minimize Console )";

	conColor(14);
	Sleep(2000);
	std::cout << "\n\nPress Enter to automatically restart if both Python and JDK 17 have been successfully installed.\n";

	while (bJavaContinue == false)
	{
		if (GetAsyncKeyState(VK_RETURN) & 1)
			bJavaContinue = !bJavaContinue;
	}

	conColor(8);
	std::cout << "\tRestarting ReVancedAPKBuilder";
	Sleep(1000);
	rProgram("ReVancedAPKBuilder.exe");
	exit(0);
}