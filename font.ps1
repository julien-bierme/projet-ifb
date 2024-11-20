$wallpaperPath = "$HOME\h.jpg"

Invoke-WebRequest -Uri 'https://github.com/julien-bierme/projet-ifb/blob/main/h.jpg?raw=true' -OutFile $wallpaperPath

# Définir le fond d'écran
Add-Type -TypeDefinition @"
using System;
using System.Runtime.InteropServices;
public class Wallpaper {
    [DllImport("user32.dll", CharSet=CharSet.Auto)]
    public static extern int SystemParametersInfo(int uAction, int uParam, string lpvParam, int fuWinIni);
}
"@
[Wallpaper]::SystemParametersInfo(20, 0, $wallpaperPath, 1)
