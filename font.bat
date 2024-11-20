@echo off

set "wallpaperPath=%USERPROFILE%.jpg"
curl -o "%wallpaperPath%" "%USERPROFILE%.jpg" --silent
reg add "HKCU\Control Panel\Desktop" /v Wallpaper /t REG_SZ /d "%wallpaperPath%" /f

RUNDLL32.EXE user32.dll,UpdatePerUserSystemParameters
