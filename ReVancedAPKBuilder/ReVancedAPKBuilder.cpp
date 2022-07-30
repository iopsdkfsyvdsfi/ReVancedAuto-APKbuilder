#include <iostream>
#include <Windows.h>
#include <limits>

#include "files.h"
#include "errorInputHandling.h"
#include "lastVersionPort.h"

#pragma comment(lib, "Urlmon.lib")

int main()
{
	SetConsoleTitleA("revanced.apk Builder");

	HWND rvHWND{ GetConsoleWindow() };
	SetWindowPos(rvHWND, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	ShowWindow(rvHWND, SW_NORMAL);

	lvMain();
}
