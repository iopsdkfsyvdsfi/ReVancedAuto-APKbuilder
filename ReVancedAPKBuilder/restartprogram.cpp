#include <iostream>
#include <Windows.h>

#include "restartprogram.h"

void rProgram(const char* jFileName)
{
	bool bOpenReVancedAPKBuilder{ false };
	bOpenReVancedAPKBuilder = ShellExecuteA(0, "runas", jFileName, "c:\\ReVancedAPKBuilder.exe", NULL, SW_SHOW);

	if (!bOpenReVancedAPKBuilder)
	{
		std::cerr << "Unable to locate file 'ReVancedAPKBuilder.exe'. File path is hardcoded to c: drive only. Manual restart instead.";
	}
}

void pythonRestart(const char* pszFileName)
{
	bool bPythonOpenReVancedAPKBuilder{ false };
	bPythonOpenReVancedAPKBuilder = ShellExecuteA(0, "runas", pszFileName, "c:\\ReVancedAPKBuilder.exe", NULL, SW_SHOW);

	if (!bPythonOpenReVancedAPKBuilder)
	{
		std::cerr << "Unable to locate file 'ReVancedAPKBuilder.exe'. File path is hardcoded to c: drive only. Manual restart instead.";
	}
}