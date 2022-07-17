#include <iostream>
#include <Windows.h>
#include "consoleColor.h"
#include "files.h"

void switchFile(int fileList)
{
	static const wchar_t* srcFiles[7]
	{
		Files::srcRevancedCLI, Files::srcRevancedPatches, Files::srcRevancedIntegrations,
		Files::srcYoutubeAPK, Files::srcMicroGAPK, Files::srcAzulJDK, Files::srcPythonInstall
	};

	static const wchar_t* destFiles[7]
	{
		Files::destRevancedCLI, Files::srcRevancedPatches, Files::srcRevancedIntegrations,
		Files::srcYoutubeAPK, Files::srcMicroGAPK, Files::destAzulJDK, Files::destPythonInstall
	};

	// Youtube APK
	srcFiles[3] = L"https://github.com/iopsdkfsyvdsfi/ReVancedAuto-APK/raw/main/youtube.apk";
	destFiles[3] = L"youtube.apk";

	// MicroG APK
	srcFiles[4] = L"https://github.com/TeamVanced/VancedMicroG/releases/latest/download/microg.apk";
	destFiles[4] = L"microg.apk";

	// Azul Zulu JDK
	srcFiles[5] = L"https://cdn.azul.com/zulu/bin/zulu17.34.19-ca-jdk17.0.3-win_x64.msi";
	destFiles[5] = L"zulu17.34.19-ca-jdk17.0.3-win_x64.msi";

	// Python Install
	srcFiles[6] = L"https://www.python.org/ftp/python/3.10.5/python-3.10.5-amd64.exe";
	destFiles[6] = L"python-3.10.5-amd64";

	switch (fileList)
	{
	case 1:
		std::cout << "\t\n- Downloading YouTube 17.26.35.apk";
		URLDownloadToFile(NULL, srcFiles[3], destFiles[3], 0, NULL);

		std::cout << "\t\n- Downloading Vanced MicroG (0.2.24.220220)";
		URLDownloadToFile(NULL, srcFiles[4], destFiles[4], 0, NULL);

		std::cout << "\t\nFiles saved in destination target folder.\n";
		break;

	case 2:
		conColor(8);
		std::cout << "\t\n- Downloading Azul Zulu JDK (17.0.3+7)";

		URLDownloadToFile(NULL, srcFiles[5], destFiles[5], 0, NULL);
		std::system("start zulu17.34.19-ca-jdk17.0.3-win_x64.msi");
		break;

	case 3:
		std::cout << "\t\n- Downloading 'Python 3.10.5'\n";

		URLDownloadToFile(NULL, srcFiles[6], destFiles[6], 0, NULL);
		std::system("start python-3.10.5-amd64");
		break;

	case 4:
		conColor(8);
		std::cout << "\t\n- Downloading YouTube 17.26.35.apk";
		URLDownloadToFile(NULL, srcFiles[3], destFiles[3], 0, NULL);

		conColor(8);
		std::cout << "\t\n- Downloading Vanced MicroG (0.2.24.220220)";
		URLDownloadToFile(NULL, srcFiles[4], destFiles[4], 0, NULL);

		break;

	default:
		break;
	}
}