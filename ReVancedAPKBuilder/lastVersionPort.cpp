#include <iostream>
#include <Windows.h>

#include "files.h"
#include "errorInputHandling.h"
#include "lastVersionPort.h"
#include "consoleColor.h"
#include "patches.h"

void conColor(uintptr_t menuColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), menuColor);
}

void lvMain()
{
	bool bBuild{ false };
	bool bJavaContinue{ false };
	int selector{};

	std::cout << "\nReVanced APK Builder uses (lastversion 2.4.5) to automatically download latest ReVanced files.\n";
	std::cout << "In order for lastversion to be compatible with your system, you must have Python installed.\n";
	
	do
	{
		std::cout << "\n\tIs Python already installed on your system? (y/n): ";
		std::cin >> input;
		ignoreLine();

	} while (input != 'y' && input != 'n');

	if (input == 'n' || input == 'N')
	{
		conColor(8);
		switchFile(3);

		std::cout << "\n\nSetup and install (Python 3.10.5)\n";

		conColor(4);
		std::cout << "\n\n[!] Make sure to check 'Add Python 3.10 to PATH' in Python Installer\n";
		std::cout << "Restart ReVancedAPKBuilder.exe after installing Python on your system.\n";

		conColor(8);
		std::cout << "\tPress enter to exit program";
		(void)getchar();

		std::exit(1);
	}

	do
	{
		std::cout << "\n\tis JDK 17+ installed on your system? (y/n): ";
		std::cin >> input;
		ignoreLine();

	} while (input != 'y' && input != 'n');

	if (input == 'n' || input == 'N')
	{
		switchFile(2);

		std::cout << "\n\n[!] Complete the setup for 'zulu17.34.19-ca-jdk17.0.3-win_x64' (JDK 17)\n";

		conColor(4);
		std::cout << "\t\t[!] Do not continue until JDK is successfully installed. The compilation will fail otherwise\n";

		Sleep(3000);
		conColor(3);
		std::cout << "\n\nPress enter to continue";
	}

	while (bJavaContinue == false)
	{
		if (GetAsyncKeyState(VK_RETURN) & 1)
			bJavaContinue = !bJavaContinue;
	}

	std::cout << '\n' << '\n';

	if (input == 'y' || input == 'Y' || bJavaContinue == true)
	{
		conColor(8);
		std::system("python -m ensurepip --default-pip");

		conColor(8);
		std::cout << ("\t\t\npip install lastversion\n");

		std::system("pip install lastversion");

		conColor(3);
		std::cout << "\n- Installing latest ReVanced files into target directory";

		std::system("lastversion --assets download https://github.com/iopsdkfsyvdsfi/revanced-patches/releases -o revancedPatches.jar"); // use my repo temporaily for lastversion
		std::system("lastversion --assets download https://github.com/revanced/revanced-cli/releases -o revancedCLI.jar");
		std::system("lastversion --assets download https://github.com/revanced/revanced-integrations/releases -o revancedIntegrations.apk");
		
		std::cout << "\n(1) YouTube (2) YouTube Music: ";
		std::cin >> selector;

		if (selector == 2)
		{
			switchFile(5);
			ytmPatchesExclude();
		}

		else
		// youtube.apk
		switchFile(4);

		if (bJavaContinue == true || input == 'y' || input == 'Y')
		{
			std::cout << "\n\n\tStarting revanced.apk compilation process\n";

			conColor(14);
			std::cout << "\nExclude certain patches?(y/n): ";
			std::cin >> input;

			std::cout << '\n';
			if (input == 'y')
			{
				patchesExclude();
			}

			conColor(4);
			std::cout << "\t\t\n[!] Do not click inside the command console during this process.\n";
			std::cout << "\t\t  [!] Do not exit the command console while the APK is compiling.\n\n";
			std::cout << "This will take approximately 3-5 minutes to build.\n";

			std::cout << '\n' << '\n';

			conColor(8);
			while (bBuild == false)
			{
				bBuild = !bBuild;
				std::system("java -jar revancedCLI.jar -a youtube.apk -c -o revanced.apk -b revancedPatches.jar -m revancedIntegrations.apk -e background-play -e exclusive-audio-playback -e codecs-unlock -e upgrade-button-remover -e tasteBuilder-remover -e minimized-playback-music -e hide-get-premium -e music-video-ads -e timeline-ads -e general-reddit-ads --experimental");
			}
		}

		conColor(7);
		std::cout << "\n\n\t Move 'revanced.apk' and 'microg.apk' to your phone and then install both.";

		Sleep(1000);

		conColor(8);
		std::cout << "\nPress enter to exit the console";
		(void)getchar();

		std::remove("python - 3.10.5 - amd64");
		std::remove("revancedIntegrations.apk");
		std::remove("revancedCLI.jar");
		std::remove("revancedPatches.jar");
		std::remove("zulu17.34.19-ca.jdk17.0.3=win_x64.msi");
		std::remove("youtube.apk");

		std::exit(0);
	}
}