#include <iostream>
#include <Windows.h>

#include "files.h"
#include "errorInputHandling.h"
#include "lastVersionPort.h"
#include "consoleColor.h"
#include "patches.h"
#include "restartprogram.h"
#include "javapython.h"

void conColor(uintptr_t menuColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), menuColor);
}

void lvMain()
{
	bool bBuild{ false };
	int selector{};

	std::cout << "\nReVanced APK Builder uses (lastversion 2.4.5) to automatically download latest ReVanced files.\n";
	std::cout << "In order for lastversion to be compatible with your system, you must have Python installed.\n";
	
	do
	{
		std::cout << "\n\tInstall Java and Python? (y/n): ";
		std::cin >> input;
		ignoreLine();

	} while (input != 'y' && input != 'n');

	if (input == 'y' || input == 'Y')
		jpInstall();

	std::cout << '\n' << '\n';

	if (input == 'n' || input == 'N')
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

		do
		{
			std::cout << "\n(1) - YouTube | (2) - YouTube Music: ";
			std::cin >> selector;
			std::cin.clear();
			ignoreLine();

		} while (selector != 1 && selector != 2 );

		if (selector == 2)
		{
			switchFile(5);
			ytmPatchesExclude();
		}
		
		else
		// youtube.apk
		switchFile(4);

		if (input == 'n' || input == 'N')
		{
			std::cout << "\n\n\tStarting revanced.apk compilation process\n";

			do
			{
				conColor(14);
				std::cout << "\nExclude certain patches?(y/n): ";
				std::cin >> input;
				ignoreLine();

			} while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');

			std::cout << '\n';

			// call patch exclude function
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
				std::system("java -jar revancedCLI.jar -a youtube.apk -c -o revanced.apk -b revancedPatches.jar -m revancedIntegrations.apk -e background-play -e exclusive-audio-playback -e codecs-unlock -e upgrade-button-remover -e tasteBuilder-remover -e minimized-playback-music -e hide-get-premium -e music-video-ads -e timeline-ads -e general-reddit-ads -e music-microg-support --experimental");
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