#include <iostream>
#include <Windows.h>

#include "restartprogram.h"

void rProgram(const char* pszFileName)
{
	bool bOpenReVancedAPKBuilder{ false };
	bOpenReVancedAPKBuilder = ShellExecuteA(0, "runas", pszFileName, "c:\\ReVancedAPKBuilder.exe", NULL, SW_SHOW);

	if (!bOpenReVancedAPKBuilder)
	{
		std::cerr << "Unable to locate file 'ReVancedAPKBuilder.exe'. File path is hardcoded to c: drive only. Manual restart instead.";
	}
}