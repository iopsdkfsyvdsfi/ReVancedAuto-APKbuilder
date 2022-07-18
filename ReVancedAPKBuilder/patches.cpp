#include <iostream>
#include <string_view>
#include <vector>
#include <Windows.h>

#include "files.h"
#include "lastVersionPort.h"
#include "consoleColor.h"
#include "patches.h"

struct pInput
{
    char p1;
    char p2;
    char p3;
    char p4;
    char p5;
    char p6;
    char p7;
    char p8;
    char p9;
    char p10;
    char p11;
    char p12;
    char p13;
    char p14;
    char p15;
    char p16;
    char p17;
    char p18;
    char p19;
    char p20;
    char p21;
    char p22;
    char p23;
    char p24;
};

enum Patches
{
    hideInfoCardSuggestions,
    videoAds,
    generalAds,
    seekbarTapping,
    swipeControls,
    microgSupport,
    hdrAutoBrightness,
    autoRepeatByDefault,
    customPlaybackSpeed,
    enableDebugging,
    oldQualityLayout,
    hideCastButton,
    amoled,
    hideAutoplayButton,
    minimizedPlayback,
    premiumHeading,
    customBranding,
    enableWideSearchbar,
    returnYoutubeDislikes,
    disableFullscreenPanels,
    hideShortsButton,
    disableCreateButton,
    hideWatermark,
    sponsorblock
};

std::string_view getPatchName(Patches patches)
{
    switch (patches)
    {
        case hideInfoCardSuggestions: return "Hide Infocard Suggestions: ";
        case videoAds: return "Video Ads: ";
        case generalAds: return "General Ads: ";
        case seekbarTapping: return "Seekbar Tapping: ";
        case swipeControls: return "Swipe Controls: ";
        case microgSupport: return "MicroG Support: ";
        case hdrAutoBrightness: return "HDR Auto Brightness: ";
        case autoRepeatByDefault: return "Auto Repeat By Default: ";
        case customPlaybackSpeed: return "Custom Playback Speed: ";
        case enableDebugging: return "Enable Debugging: ";
        case oldQualityLayout: return "Old Quality Layout: ";
        case hideCastButton: return "Hide Cast Button: ";
        case amoled: return "AMOLED: ";
        case hideAutoplayButton: return "Hide Autoplay Button: ";
        case minimizedPlayback: return "Minimized Playback: ";
        case premiumHeading: return "Premium Heading: ";
        case customBranding: return "Custom Branding: ";
        case enableWideSearchbar: return "Enable Wide Searchbar: ";
        case returnYoutubeDislikes: return "Return YouTube Dislikes: ";
        case disableFullscreenPanels: return "Disable Fullscreen Panels: ";
        case hideShortsButton: return "Hide Shorts Button: ";
        case disableCreateButton: return "Disable Create Button: ";
        case hideWatermark: return "Hide Watermark: ";
        case sponsorblock: return "Sponsorblock ";
    }
}

void patchesExclude()
{
    std::string patchCmds{ "java -jar revancedCLI.jar -a youtube.apk -c -o revanced.apk -b revancedPatches.jar -m revancedIntegrations.apk -e background-play -e exclusive-audio-playback -e codecs-unlock -e upgrade-button-remover -e tasteBuilder-remover" };

        pInput patchInput{};

        conColor(10);
        std::cout << "\t\t|------------------------------------------------------------------|\n";
        std::cout << "\t\t| patch list - use 'e' to exclude patch | use 'i' to include patch |\n";
        std::cout << "\t\t|------------------------------------------------------------------|\n";

        std::cout << "\nExclude [1] | ";
        std::cout << getPatchName(hideInfoCardSuggestions);
        std::cin >> patchInput.p1;

        if (patchInput.p1 == 'e' || patchInput.p1 == 'E')
            patchCmds += " -e hide-infocard-suggestions";

        std::cout << "Exclude [2] | ";
        std::cout << getPatchName(videoAds);
        std::cin >> patchInput.p2;

        if (patchInput.p2 == 'e' || patchInput.p2 == 'E')
            patchCmds += " -e video-ads";

        std::cout << "Exclude [3] | ";
        std::cout << getPatchName(generalAds);
        std::cin >> patchInput.p3;

        if (patchInput.p3 == 'e' || patchInput.p3 == 'E')
            patchCmds += " -e general-ads";

        std::cout << "Exclude [4] | ";
        std::cout << getPatchName(seekbarTapping);
        std::cin >> patchInput.p4;

        if (patchInput.p4 == 'e' || patchInput.p4 == 'E')
            patchCmds += " -e seekbar-tapping";

        std::cout << "Exclude [5] | ";
        std::cout << getPatchName(swipeControls);
        std::cin >> patchInput.p5;

        if (patchInput.p5 == 'e' || patchInput.p5 == 'E')
            patchCmds += " -e swipe-controls";

        std::cout << "Exclude [6] | ";
        std::cout << getPatchName(microgSupport);
        std::cin >> patchInput.p6;

        if (patchInput.p6 == 'e' || patchInput.p6 == 'E')
            patchCmds += " -e microg-support";

        std::cout << "Exclude [7] | ";
        std::cout << getPatchName(hdrAutoBrightness);
        std::cin >> patchInput.p7;

        if (patchInput.p7 == 'e' || patchInput.p7 == 'E')
            patchCmds += " -e hdr-auto-brightness";

        std::cout << "Exclude [8] | ";
        std::cout << getPatchName(autoRepeatByDefault);
        std::cin >> patchInput.p8;

        if (patchInput.p8 == 'e' || patchInput.p8 == 'E')
            patchCmds += " -e autorepeat-by-default";

        std::cout << "Exclude [9] | ";
        std::cout << getPatchName(customPlaybackSpeed);
        std::cin >> patchInput.p9;

        if (patchInput.p9 == 'e' || patchInput.p9 == 'E')
            patchCmds += " -e custom-playback-speed";

        std::cout << "Exclude [10] | ";
        std::cout << getPatchName(enableDebugging);
        std::cin >> patchInput.p10;

        if (patchInput.p10 == 'e' || patchInput.p10 == 'E')
            patchCmds += " -e enable-debugging";

        std::cout << "Exclude [11] | ";
        std::cout << getPatchName(oldQualityLayout);
        std::cin >> patchInput.p11;

        if (patchInput.p11 == 'y' || patchInput.p11 == 'Y')
            patchCmds += " -e old-quality-layout";

        std::cout << "Exclude [12] | ";
        std::cout << getPatchName(hideCastButton);
        std::cin >> patchInput.p12;

        if (patchInput.p12 == 'e' || patchInput.p12 == 'E')
            patchCmds += " -e hide-cast-button";

        std::cout << "Exclude [13] | ";
        std::cout << getPatchName(amoled);
        std::cin >> patchInput.p13;

        if (patchInput.p13 == 'e' || patchInput.p13 == 'E')
            patchCmds += " -e amoled";

        std::cout << "Exclude [14] | ";
        std::cout << getPatchName(hideAutoplayButton);
        std::cin >> patchInput.p14;

        if (patchInput.p14 == 'e' || patchInput.p14 == 'E')
            patchCmds += " -e hide-autoplay-button";

        std::cout << "Exclude [15] | ";
        std::cout << getPatchName(minimizedPlayback);
        std::cin >> patchInput.p15;

        if (patchInput.p15 == 'e' || patchInput.p15 == 'E')
            patchCmds += " -e minimized-playback";

        std::cout << "Exclude [16] | ";
        std::cout << getPatchName(premiumHeading);
        std::cin >> patchInput.p16;

        if (patchInput.p16 == 'e' || patchInput.p16 == 'E')
            patchCmds += " -e premium-heading";

        std::cout << "Exclude [17] | ";
        std::cout << getPatchName(customBranding);
        std::cin >> patchInput.p17;

        if (patchInput.p17 == 'e' || patchInput.p17 == 'E')
            patchCmds += " -e custom-branding";

        std::cout << "Exclude [18] | ";
        std::cout << getPatchName(enableWideSearchbar);
        std::cin >> patchInput.p18;

        if (patchInput.p18 == 'e' || patchInput.p18 == 'E')
            patchCmds += " -e enable-wide-searchbar";

        std::cout << "Exclude [19] | ";
        std::cout << getPatchName(returnYoutubeDislikes);
        std::cin >> patchInput.p19;

        if (patchInput.p19 == 'e' || patchInput.p19 == 'E')
            patchCmds += " -e return-youtube-dislikes";

        std::cout << "Exclude [20] | ";
        std::cout << getPatchName(disableFullscreenPanels);
        std::cin >> patchInput.p20;

        if (patchInput.p20 == 'e' || patchInput.p20 == 'E')
            patchCmds += " -e disable-fullscreen-panels";

        std::cout << "Exclude [21] | ";
        std::cout << getPatchName(hideShortsButton);
        std::cin >> patchInput.p21;

        if (patchInput.p21 == 'e' || patchInput.p21 == 'E')
            patchCmds += " -e hide-shorts-button";

        std::cout << "Exclude [22] | ";
        std::cout << getPatchName(disableCreateButton);
        std::cin >> patchInput.p22;

        if (patchInput.p22 == 'e' || patchInput.p22 == 'E')
            patchCmds += " -e disable-create-button";

        std::cout << "Exclude [23] | ";
        std::cout << getPatchName(hideWatermark);
        std::cin >> patchInput.p23;

        if (patchInput.p23 == 'e' || patchInput.p23 == 'E')
            patchCmds += " -e hide-watermark";

        std::cout << "Exclude [24] | ";
        std::cout << getPatchName(sponsorblock);
        std::cin >> patchInput.p24;

        if (patchInput.p24 == 'e' || patchInput.p24 == 'E')
            patchCmds += " -e sponsorblock";

    conColor(12);
    std::cout << "\t\t\t\nThe following argument will be used\n";
    std::cout << "\t\t-------------------------------------\n";
    std::cout << patchCmds << ' ' << '\n';

    conColor(4);
    std::cout << "\t\t\n[!] Do not click inside the command console during this process.\n";
    std::cout << "\t\t  [!] Do not exit the command console while the APK is compiling.\n\n";
    std::cout << "This will take approximately 3-5 minutes to build.\n";

    std::cout << '\n' << '\n';

    conColor(8);
    system(patchCmds.c_str());

    std::remove("python - 3.10.5 - amd64");
    std::remove("revancedIntegrations.apk");
    std::remove("revancedCLI.jar");
    std::remove("revancedPatches.jar");
    std::remove("zulu17.34.19-ca.jdk17.0.3=win_x64.msi");
    std::remove("youtube.apk");

    exit(1);
}