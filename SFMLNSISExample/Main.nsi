Unicode true
SetCompressor /SOLID lzma
OutFile "SFMLNSIS_AnsiSupportSetup.exe"
!addplugindir "F:\NSISInclude\AnsiSupport"
!include "MUI.nsh"
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE "AGPL30.txt"
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_LANGUAGE "English"
Name "SFMLNSIS-AnsiSupEdition"
BrandingText "SFMLNSIS"
ReserveFile "${NSISDIR}\Plugins\x86-unicode\System.dll"
ReserveFile "F:\NSISInclude\UnicodeSupport\SFMLNSIS.dll"
ReserveFile "ReonaGG.mp3"

Function .onInit
    InitPluginsDir
    File /oname=$PLUGINSDIR\ReonaGG.mp3 "ReonaGG.mp3"
    StrCpy $0 "$PLUGINSDIR\ReonaGG.mp3"
    System::Call 'F:\NSISInclude\AnsiSupport\SFMLNSIS.dll::PlayMusicWithLoop(m r0)'
FunctionEnd
Section 01
    File /nonfatal /r "C:\SFMLNSISRel\*.*"
SectionEnd