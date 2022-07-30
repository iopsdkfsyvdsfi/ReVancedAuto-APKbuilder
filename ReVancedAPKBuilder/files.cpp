#include <iostream>
#include <Windows.h>
#include "consoleColor.h"
#include "files.h"

void switchFile(int fileList)
{
	// Youtube APK
	Files::srcYoutubeAPK = L"https://github.com/iopsdkfsyvdsfi/youtube-apk2/raw/main/youtube.apk";
	Files::destYoutubeAPK = L"youtube.apk";

	// MicroG APK
	Files::srcMicroGAPK = L"https://github.com/TeamVanced/VancedMicroG/releases/latest/download/microg.apk";
	Files::destMicroGAPK = L"microg.apk";

	// Azul Zulu JDK
	Files::srcAzulJDK = L"https://cdn.azul.com/zulu/bin/zulu17.34.19-ca-jdk17.0.3-win_x64.msi";
	Files::destAzulJDK = L"zulu17.34.19-ca-jdk17.0.3-win_x64.msi";

	// Python Install
	Files::srcPythonInstall = L"https://www.python.org/ftp/python/3.10.5/python-3.10.5-amd64.exe";
	Files::destPythonInstall = L"python-3.10.5-amd64";

	// Youtube Music
	Files::srcYoutubeMusicAPK = L"https://github.com/iopsdkfsyvdsfi/youtube-apk2/raw/main/youtubemusic.apk";
	Files::destYoutubeMusicAPK = L"youtubemusic.apk";

	switch (fileList)
	{
	case 1:
		std::cout << "\t\n- Downloading YouTube 17.29.34.apk";
		URLDownloadToFile(NULL, Files::srcYoutubeAPK, Files::destYoutubeAPK, 0, NULL);

		std::cout << "\t\n- Downloading Vanced MicroG (0.2.24.220220)";
		URLDownloadToFile(NULL, Files::srcMicroGAPK, Files::destMicroGAPK, 0, NULL);

		std::cout << "\t\nFiles saved in destination target folder.\n";
		break;

	case 2:
		conColor(8);
		std::cout << "\t\n- Downloading Azul Zulu JDK (17.34.19)";

		URLDownloadToFile(NULL, Files::srcAzulJDK, Files::destAzulJDK, 0, NULL);
		std::system("start zulu17.34.19-ca-jdk17.0.3-win_x64.msi");
		break;

	case 3:
		std::cout << "\t\n- Downloading 'Python 3.10.5'\n";

		URLDownloadToFile(NULL, Files::srcPythonInstall, Files::destPythonInstall, 0, NULL);
		std::system("start python-3.10.5-amd64");
		break;

	case 4:
		conColor(8);
		std::cout << "\t\n- Downloading YouTube 17.29.34.apk";
		URLDownloadToFile(NULL, Files::srcYoutubeAPK , Files::srcYoutubeAPK, 0, NULL);

		conColor(8);
		std::cout << "\t\n- Downloading Vanced MicroG (0.2.24.220220)";
		URLDownloadToFile(NULL, Files::srcMicroGAPK, Files::destMicroGAPK, 0, NULL);
		break;

	case 5:
		conColor(8);
		std::cout << "\t\n- Download YouTube Music 5.16.61";
		URLDownloadToFile(NULL, Files::srcYoutubeMusicAPK, Files::destYoutubeMusicAPK, 0, NULL);

		conColor(8);
		std::cout << "\t\n- Downloading Vanced MicroG (0.2.24.220220)";
		URLDownloadToFile(NULL, Files::srcMicroGAPK, Files::destMicroGAPK, 0, NULL);
		break;

	default:
		break;
	}
}