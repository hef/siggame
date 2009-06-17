; example2.nsi
;
; This script is based on example1.nsi, but it remember the directory, 
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install example2.nsi into a directory that the user selects,
;--------------------------------

; The name of the installer
Name "Siggame"

; The file to write
OutFile "siggame-installer.exe"

; The default installation directory
InstallDir $PROGRAMFILES\Siggame

; Registry key to check for directory (so if you install again, it will 
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\Siggame" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel admin

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "Siggame"

  SectionIn RO
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Put file there
  File "../Release\Siggame.exe"
  File "SDL.dll"
  
  ; Write the installation path into the registry
  WriteRegStr HKLM SOFTWARE\Siggame "Install_Dir" "$INSTDIR"
  
  ; Write the uninstall keys for Windows
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Siggame" "DisplayName" "Siggame"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Siggame" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Siggame" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Siggame" "NoRepair" 1
  WriteUninstaller "uninstall.exe"
  
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\Siggame"
  CreateShortCut "$SMPROGRAMS\Siggame\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\Siggame\Siggame.lnk" "$INSTDIR\Siggame.exe" "" "$INSTDIR\Siggame.exe" 0
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Siggame"
  DeleteRegKey HKLM SOFTWARE\Siggame

  ; Remove files and uninstaller
  Delete $INSTDIR\Siggame.exe
  Delete $INSTDIR\SDL.dll
  Delete $INSTDIR\uninstall.exe

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\Siggame\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\Siggame"
  RMDir "$INSTDIR"

SectionEnd
