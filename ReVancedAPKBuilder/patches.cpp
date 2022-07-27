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
    char p[28];
    char pMusic[11];
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
    alwaysAutorepeat,
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
    sponsorblock,
    forceVP9Codec,
    rememberVideoQuality,
    experimental
};

enum ytmPatches
{
    minimizedPlaybackMusic,
    tasteBuilderRemover,
    hideGetPremium,
    compactHeader,
    upgradeButtonRemover,
    backgroundPlay,
    musicMicroGSupport,
    musicVideoAds,
    codecsUnlock,
    exclusiveAudioPlayback
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
        case alwaysAutorepeat: return "Auto Repeat By Default: ";
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
        case sponsorblock: return "Sponsorblock: ";
        case forceVP9Codec: return "Force VP9 Codec: ";
        case rememberVideoQuality: return "Remember Video Quality: ";
        case experimental: return "Experimental: ";
    }
}

std::string_view getYTMPatchNames(ytmPatches ytmPatches)
{
    switch (ytmPatches)
    {
    case minimizedPlaybackMusic: return "Minimized Playback Music: ";
    case tasteBuilderRemover: return "Tastebuiler Remover: ";
    case hideGetPremium: return "Hide Get Premium: ";
    case compactHeader: return "Compact Header: ";
    case upgradeButtonRemover: return "Upgrade Button Remover: ";
    case backgroundPlay: return "Background Play: ";
    case musicMicroGSupport: return "YTM MicroG Support: ";
    case musicVideoAds: return "YTM Video Ads: ";
    case codecsUnlock: return "Codecs Unlock: ";
    case exclusiveAudioPlayback: return "Exclusive Audio Playback: ";
    }
}

void patchesExclude()
{
    std::string patchCmds{ "java -jar revancedCLI.jar -a youtube.apk -c -o revanced.apk -b revancedPatches.jar -m revancedIntegrations.apk -e background-play -e exclusive-audio-playback -e codecs-unlock -e upgrade-button-remover -e tasteBuilder-remover -e minimized-playback-music -e hide-get-premium -e music-video-ads -e timeline-ads -e general-reddit-ads" };

    pInput patchInput[26]{};

        conColor(10);
        std::cout << "\t\t|------------------------------------------------------------------|\n";
        std::cout << "\t\t| patch list - use 'e' to exclude patch | use 'i' to include patch |\n";
        std::cout << "\t\t|------------------------------------------------------------------|\n";

        std::cout << "\nExclude [1] | ";
        std::cout << getPatchName(hideInfoCardSuggestions);
        std::cin >> patchInput->p;

        if (patchInput->p[0] == 'e' || patchInput->p[0] == 'E')
            patchCmds += " -e hide-infocard-suggestions";

        std::cout << "Exclude [2] | ";
        std::cout << getPatchName(videoAds);
        std::cin >> patchInput->p[2];

        if (patchInput->p[2] == 'e' || patchInput->p[2] == 'E')
            patchCmds += " -e video-ads";

        std::cout << "Exclude [3] | ";
        std::cout << getPatchName(generalAds);
        std::cin >> patchInput->p[3];

        if (patchInput->p[3] == 'e' || patchInput->p[3] == 'E')
            patchCmds += " -e general-ads";

        std::cout << "Exclude [4] | ";
        std::cout << getPatchName(seekbarTapping);
        std::cin >> patchInput->p[4];

        if (patchInput->p[4] == 'e' || patchInput->p[4] == 'E')
            patchCmds += " -e seekbar-tapping";

        std::cout << "Exclude [5] | ";
        std::cout << getPatchName(swipeControls);
        std::cin >> patchInput->p[5];

        if (patchInput->p[5] == 'e' || patchInput->p[5] == 'E')
            patchCmds += " -e swipe-controls";

        std::cout << "Exclude [6] | ";
        std::cout << getPatchName(microgSupport);
        std::cin >> patchInput->p[6];

        if (patchInput->p[6] == 'e' || patchInput->p[6] == 'E')
            patchCmds += " -e microg-support";

        std::cout << "Exclude [7] | ";
        std::cout << getPatchName(hdrAutoBrightness);
        std::cin >> patchInput->p[7];

        if (patchInput->p[7] == 'e' || patchInput->p[7] == 'E')
            patchCmds += " -e hdr-auto-brightness";

        if (patchInput->p[7] == 'i' || patchInput->p[7] == 'I')
            patchCmds += " -i hdr-auto-brightness";

        std::cout << "Exclude [8] | ";
        std::cout << getPatchName(alwaysAutorepeat);
        std::cin >> patchInput->p[8];

        if (patchInput->p[8] == 'e' || patchInput->p[8] == 'E')
            patchCmds += " -e always-autorepeat";

        std::cout << "Exclude [9] | ";
        std::cout << getPatchName(customPlaybackSpeed);
        std::cin >> patchInput->p[9];

        if (patchInput->p[9] == 'e' || patchInput->p[9] == 'E')
            patchCmds += " -e custom-playback-speed";

        std::cout << "Exclude [10] | ";
        std::cout << getPatchName(enableDebugging);
        std::cin >> patchInput->p[10];
   
        if (patchInput->p[10] == 'e' || patchInput->p[10] == 'E')
            patchCmds += " -e enable-debugging";

        std::cout << "Exclude [11] | ";
        std::cout << getPatchName(oldQualityLayout);
        std::cin >> patchInput->p[11];

        if (patchInput->p[11] == 'y' || patchInput->p[11] == 'Y')
            patchCmds += " -e old-quality-layout";

        std::cout << "Exclude [12] | ";
        std::cout << getPatchName(hideCastButton);
        std::cin >> patchInput->p[12];

        if (patchInput->p[12] == 'e' || patchInput->p[12] == 'E')
            patchCmds += " -e hide-cast-button";

        std::cout << "Exclude [13] | ";
        std::cout << getPatchName(amoled);
        std::cin >> patchInput->p[13];

        if (patchInput->p[13] == 'e' || patchInput->p[13] == 'E')
            patchCmds += " -e amoled";

        std::cout << "Exclude [14] | ";
        std::cout << getPatchName(hideAutoplayButton);
        std::cin >> patchInput->p[14];

        if (patchInput->p[14] == 'e' || patchInput->p[14] == 'E')
            patchCmds += " -e hide-autoplay-button";

        std::cout << "Exclude [15] | ";
        std::cout << getPatchName(minimizedPlayback);
        std::cin >> patchInput->p[15];

        if (patchInput->p[15] == 'e' || patchInput->p[15] == 'E')
            patchCmds += " -e minimized-playback";

        std::cout << "Exclude [16] | ";
        std::cout << getPatchName(premiumHeading);
        std::cin >> patchInput->p[16];

        if (patchInput->p[16] == 'e' || patchInput->p[16] == 'E')
            patchCmds += " -e premium-heading";

        std::cout << "Exclude [17] | ";
        std::cout << getPatchName(customBranding);
        std::cin >> patchInput->p[17];

        if (patchInput->p[17] == 'e' || patchInput->p[17] == 'E')
            patchCmds += " -e custom-branding";

        std::cout << "Exclude [18] | ";
        std::cout << getPatchName(enableWideSearchbar);
        std::cin >> patchInput->p[18];

        if (patchInput->p[18] == 'e' || patchInput->p[18] == 'E')
            patchCmds += " -e enable-wide-searchbar";

        std::cout << "Exclude [19] | ";
        std::cout << getPatchName(returnYoutubeDislikes);
        std::cin >> patchInput->p[19];

        if (patchInput->p[19] == 'e' || patchInput->p[19] == 'E')
            patchCmds += " -e return-youtube-dislike";

        std::cout << "Exclude [20] | ";
        std::cout << getPatchName(disableFullscreenPanels);
        std::cin >> patchInput->p[20];

        if (patchInput->p[20] == 'e' || patchInput->p[20] == 'E')
            patchCmds += " -e disable-fullscreen-panels";

        std::cout << "Exclude [21] | ";
        std::cout << getPatchName(hideShortsButton);
        std::cin >> patchInput->p[21];

        if (patchInput->p[21] == 'e' || patchInput->p[21] == 'E')
            patchCmds += " -e hide-shorts-button";

        std::cout << "Exclude [22] | ";
        std::cout << getPatchName(disableCreateButton);
        std::cin >> patchInput->p[22];

        if (patchInput->p[22] == 'e' || patchInput->p[22] == 'E')
            patchCmds += " -e disable-create-button";

        std::cout << "Exclude [23] | ";
        std::cout << getPatchName(hideWatermark);
        std::cin >> patchInput->p[23];

        if (patchInput->p[23] == 'e' || patchInput->p[23] == 'E')
            patchCmds += " -e hide-watermark";

        std::cout << "Exclude [24] | ";
        std::cout << getPatchName(sponsorblock);
        std::cin >> patchInput->p[24];

        if (patchInput->p[24] == 'e' || patchInput->p[24] == 'E')
            patchCmds += " -e sponsorblock";

        std::cout << "Exclude [25] | ";
        std::cout << getPatchName(forceVP9Codec);
        std::cin >> patchInput->p[25];

        if (patchInput->p[25] == 'e' || patchInput->p[25] == 'E')
            patchCmds += " -e force-vp9-codec";

        if (patchInput->p[25] == 'i' || patchInput->p[25] == 'I')
            patchCmds += " -i force-vp9-codec";

        std::cout << "Exclude [26] | ";
        std::cout << getPatchName(rememberVideoQuality);
        std::cin >> patchInput->p[26];

        if (patchInput->p[26] == 'e' || patchInput->p[26] == 'E')
            patchCmds += " -e remember-video-quality";

        std::cout << "Exclude [27] | ";
        std::cout << getPatchName(experimental);
        std::cin >> patchInput->p[27];

        if (patchInput->p[27] == 'i' || patchInput->p[27] == 'I')
            patchCmds += " --experimental";

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

void ytmPatchesExclude()
{
    conColor(3);
    std::cout << "\n\nExclude YTM Patches?(y/n): ";
    std::cin >> input;

    pInput ytmPatches[10]{};

    if (input == 'y' || input == 'Y')
    {
       // std::string patchCmds{ "java -jar revancedCLI.jar -a youtubemusic.apk -c -o revanced.apk -b revancedPatches.jar -m revancedIntegrations.apk" };
        std::string patchCmds{ "java -jar revancedCLI.jar -a youtubemusic.apk -c -o revancedmusic.apk -b revancedPatches.jar -m revancedIntegrations.apk -e swipe-controls -e seekbar-tapping -e minimized-playback -e amoled -e disable-create-button -e hide-cast-button -e return-youtube-dislike -e hide-autoplay-button -e premium-heading -e custom-branding -e disable-fullscreen-panels -e old-quality-layout -e hide-shorts-button -e hide-watermark -e sponsorblock -e enable-wide-searchbar -e force-vp9-codec -e always-autorepeat -e microg-support -e enable-debugging -e custom-playback-speed -e hdr-auto-brightness -e remember-video-quality -e video-ads -e general-ads -e hide-infocard-suggestions -e timeline-ads -e general-reddit-ads" };
        std::cout << '\n';

        conColor(10);
        std::cout << "\t\t|------------------------------------------------------------------|\n";
        std::cout << "\t\t| patch list - use 'e' to exclude patch | use 'i' to include patch |\n";
        std::cout << "\t\t|------------------------------------------------------------------|\n";

        std::cout << "Exclude [1] | ";
        std::cout << getYTMPatchNames(minimizedPlaybackMusic);
        std::cin >> ytmPatches->pMusic[0];

        if (ytmPatches->pMusic[0] == 'e' || ytmPatches->pMusic[0] == 'E')
            patchCmds += " -e minimized-playback-music";
        else
            patchCmds += " -i minimized-playback-music";

        std::cout << "Exclude [2] | ";
        std::cout << getYTMPatchNames(tasteBuilderRemover);
        std::cin >> ytmPatches->pMusic[1];

        if (ytmPatches->pMusic[1] == 'e' || ytmPatches->pMusic[2] == 'E')
            patchCmds += " -e tasteBuilder-remover";
        else
            patchCmds += " -i tasteBuilder-remover";

        std::cout << "Exclude [3] | ";
        std::cout << getYTMPatchNames(hideGetPremium);
        std::cin >> ytmPatches->pMusic[3];

        if (ytmPatches->pMusic[3] == 'e' || ytmPatches->pMusic[3] == 'E')
            patchCmds += " -e hide-get-premium";
        else
            patchCmds += " -i hide-get-premium";


        std::cout << "Exclude [4] | ";
        std::cout << getYTMPatchNames(compactHeader);
        std::cin >> ytmPatches->pMusic[4];

        if (ytmPatches->pMusic[4] == 'e' || ytmPatches->pMusic[4] == 'E')
            patchCmds += " -e compact-header";
        else
            patchCmds += " -i compact-header";

        std::cout << "Exclude [5] | ";
        std::cout << getYTMPatchNames(upgradeButtonRemover);
        std::cin >> ytmPatches->pMusic[5];

        if (ytmPatches->pMusic[5] == 'e' || ytmPatches->pMusic[5] == 'E')
            patchCmds += " -e upgrade-button-remover";
        else
            patchCmds += " -i upgrade-button-remover";

        std::cout << "Exclude [6] | ";
        std::cout << getYTMPatchNames(backgroundPlay);
        std::cin >> ytmPatches->pMusic[6];

        if (ytmPatches->pMusic[6] == 'e' || ytmPatches->pMusic[6] == 'E')
            patchCmds += " -e background-play";
        else
            patchCmds += " -i background-play";

        std::cout << "Exclude [7] | ";
        std::cout << getYTMPatchNames(musicMicroGSupport);
        std::cin >> ytmPatches->pMusic[7];

        if (ytmPatches->pMusic[7] == 'e' || ytmPatches->pMusic[7] == 'E')
            patchCmds += " -e music-microg-support";
        else
            patchCmds += " -i music-microg-support";

        std::cout << "Exclude [8] | ";
        std::cout << getYTMPatchNames(musicVideoAds);
        std::cin >> ytmPatches->pMusic[8];

        if (ytmPatches->pMusic[8] == 'e' || ytmPatches->pMusic[8] == 'E')
            patchCmds += " -e music-video-ads";
        else
            patchCmds += " -i music-video-ads";

        std::cout << "Exclude [9] | ";
        std::cout << getYTMPatchNames(codecsUnlock);
        std::cin >> ytmPatches->pMusic[9];

        if (ytmPatches->pMusic[9] == 'e' || ytmPatches->pMusic[9] == 'E')
            patchCmds += " -e codecs-unlock";
        else
            patchCmds += " -i codecs-unlock";

        std::cout << "Exclude [10] | ";
        std::cout << getYTMPatchNames(exclusiveAudioPlayback);
        std::cin >> ytmPatches->pMusic[10];

        if (ytmPatches->pMusic[10] == 'e' || ytmPatches->pMusic[10] == 'E')
            patchCmds += " -e exclusive-audio-playback";
        else
            patchCmds += " -i exclusive-audio-playback";

        conColor(12);
        std::cout << "\t\t\t\nThe following argument will be used\n";
        std::cout << "\t\t-------------------------------------\n";
        std::cout << patchCmds << ' ' << '\n';

        conColor(4);
        std::cout << "\t\t\n[!] Do not click inside the command console during this process.\n";
        std::cout << "\t\t  [!] Do not exit the command console while the APK is compiling.\n\n";
        std::cout << "This will take approximately a few minutes to build.\n";

        std::cout << '\n' << '\n';

        conColor(8);
        system(patchCmds.c_str());

        std::remove("python - 3.10.5 - amd64");
        std::remove("revancedIntegrations.apk");
        std::remove("revancedCLI.jar");
        std::remove("revancedPatches.jar");
        std::remove("zulu17.34.19-ca.jdk17.0.3=win_x64.msi");
        std::remove("youtubemusic.apk");

        exit(1);
    }
   
    // default 
    std::string patchCmds{ "java -jar revancedCLI.jar -a youtubemusic.apk -c -o revancedmusic.apk -b revancedPatches.jar -m revancedIntegrations.apk -e swipe-controls -e seekbar-tapping -e minimized-playback -e amoled -e disable-create-button -e hide-cast-button -e return-youtube-dislike -e hide-autoplay-button -e premium-heading -e custom-branding -e disable-fullscreen-panels -e old-quality-layout -e hide-shorts-button -e hide-watermark -e sponsorblock -e enable-wide-searchbar -e force-vp9-codec -e always-autorepeat -e microg-support -e enable-debugging -e custom-playback-speed -e hdr-auto-brightness -e remember-video-quality -e video-ads -e general-ads -e hide-infocard-suggestions -e timeline-ads -e general-reddit-ads -i background-play -i exclusive-audio-playback -i codecs-unlock -i upgrade-button-remover -i tasteBuilder-remover -i minimized-playback-music -i hide-get-premium -i music-video-ads -i music-microg-support -i compact-header" };

    conColor(12);
    std::cout << "\t\t\t\nThe following argument will be used\n";
    std::cout << "\t\t-------------------------------------\n";
    std::cout << patchCmds << ' ' << '\n';

    conColor(4);
    std::cout << "\t\t\n[!] Do not click inside the command console during this process.\n";
    std::cout << "\t\t  [!] Do not exit the command console while the APK is compiling.\n\n";
    std::cout << "This will take approximately a few minutes to build.\n";

    std::cout << '\n' << '\n';

    conColor(8);
    system(patchCmds.c_str());

    std::remove("python - 3.10.5 - amd64");
    std::remove("revancedIntegrations.apk");
    std::remove("revancedCLI.jar");
    std::remove("revancedPatches.jar");
    std::remove("zulu17.34.19-ca.jdk17.0.3=win_x64.msi");
    std::remove("youtubemusic.apk");

    exit(1);
}