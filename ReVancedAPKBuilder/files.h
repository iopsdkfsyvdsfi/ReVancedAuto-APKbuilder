#ifndef FILES_H
#define FILES_H

// main input
static char input{};

// function
void switchFile(int x);

namespace Files
{
    static const wchar_t* srcRevancedCLI;
    static const wchar_t* destRevancedCLI;

    static const wchar_t* srcRevancedPatches;
    static const wchar_t* destRevancedPatches;

    static const wchar_t* srcRevancedIntegrations;
    static const wchar_t* destRevancedIntegrations;

    static const wchar_t* srcYoutubeAPK;
    static const wchar_t* destYoutubeAPK;

    static const wchar_t* srcMicroGAPK;
    static const wchar_t* destMicroGAPK;

    static const wchar_t* srcAzulJDK;
    static const wchar_t* destAzulJDK;

    // lv 
    static const wchar_t* srcPythonInstall;
    static const wchar_t* destPythonInstall;
}

#endif