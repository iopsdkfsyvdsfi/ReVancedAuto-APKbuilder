Extremely basic program to compile a ReVanced .apk file for non root devices

This downloads all default patches along with the --experimental argument unless you manually exclude patches
	
	YouTube
	> java -jar revancedCLI.jar -a youtube.apk -c -o revanced.apk -b revancedPatches.jar -m revancedIntegrations.apk -e background-play -e exclusive-audio-playback -e codecs-unlock -e upgrade-button-remover -e tasteBuilder-remover --experimental
	
	YouTube Music
	> java -jar revancedCLI.jar -a youtubemusic.apk -c -o revanced.apk -b revancedPatches.jar -m revancedIntegrations.apk -e swipe-controls -e seekbar-tapping -e minimized-playback -e amoled -e disable-create-button -e hide-cast-button -e return-youtube-dislike -e hide-autoplay-button -e premium-heading -e custom-branding -e disable-fullscreen-panels -e old-quality-layout -e hide-shorts-button -e hide-watermark -e sponsorblock -e enable-wide-searchbar -e force-vp9-codec -e always-autorepeat -e microg-support -e enable-debugging -e custom-playback-speed -e hdr-auto-brightness -e remember-video-quality -e video-ads -e general-ads -e hide-infocard-suggestions -i background-play -i exclusive-audio-playback -i codecs-unlock -i upgrade-button-remover -i tasteBuilder-remover -i minimized-playback-music -i hide-get-premium -i music-video-ads -i music-microg-support -i compact-header


BTC: 3PQV5bxZvZnFVcfjU8yw2VCFykXyjvzYb3

ETH: 0xF1EF0e449CFd8Cf051338Cabe1424c67a4754D3d


REQUIREMENTS: 
- Python https://www.python.org/ftp/python/3.10.5/python-3.10.5-amd64.exe
- JDK 17 https://cdn.azul.com/zulu/bin/zulu17.34.19-ca-jdk17.0.3-win_x64.msi

Make sure when installing Python that you check 'ADD TO PATH' in the installer
![Python Installer](https://github.com/iopsdkfsyvdsfi/ReVancedAuto-APKbuilder/blob/main/image.png)


https://user-images.githubusercontent.com/109194157/179404135-f8d10260-f021-4e48-a6a1-5e85ee9c9470.mp4

