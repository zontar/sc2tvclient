@echo off
set DebugFiles="Qt5MultimediaWidgetsd.dll" "Qt5Networkd.dll" "Qt5OpenGLd.dll" "Qt5Positioningd.dll" "Qt5PrintSupportd.dll" "Qt5Qmld.dll" "Qt5Quickd.dll" "Qt5Sensorsd.dll" "Qt5Sqld.dll" "Qt5WebKitd.dll" "Qt5WebKitWidgetsd.dll" "Qt5Widgetsd.dll" "icudt51.dll" "icuin51.dll" "icuuc51.dll" "libgcc_s_dw2-1.dll" "libstdc++-6.dll" "libwinpthread-1.dll" "Qt5Cored.dll" "Qt5Guid.dll" "Qt5Multimediad.dll"

set ReleaseFiles="Qt5MultimediaWidgets.dll" "Qt5Network.dll" "Qt5OpenGL.dll" "Qt5Positioning.dll" "Qt5PrintSupport.dll" "Qt5Qml.dll" "Qt5Quick.dll" "Qt5Sensors.dll" "Qt5Sql.dll" "Qt5WebKit.dll" "Qt5WebKitWidgets.dll" "Qt5Widgets.dll" "icudt51.dll" "icuin51.dll" "icuuc51.dll" "libgcc_s_dw2-1.dll" "libstdc++-6.dll" "libwinpthread-1.dll" "Qt5Core.dll" "Qt5Gui.dll" "Qt5Multimedia.dll"

set DestDir=%cd%\..\..\distrib
set SrcDir=%1
set OpenSslDir=%cd%\..\..\external\openssl

REM rmdir /s /q %DestDir%
mkdir %DestDir%

if "%2" == "release" goto CopyRelease
if "%2" == "debug" goto CopyDebug
goto end

:CopyRelease
mkdir %DestDir%\Release
mkdir %DestDir%\Release\platforms
mkdir %DestDir%\Release\imageformats
mkdir %DestDir%\Release\QtQuick.2
for %%F in (%ReleaseFiles%) do robocopy %1\bin %DestDir%\Release %%F /MIR
robocopy %SrcDir%\plugins\platforms %DestDir%\Release\platforms qwindows.dll /MIR
robocopy %SrcDir%\imageformats\platforms %DestDir%\Release\imageformats qjpeg.dll /MIR
robocopy %SrcDir%\qml\QtQuick.2 %DestDir%\Release\QtQuick.2 /MIR /xf qtquick2plugind.dll
copy /y %OpenSslDir%\*.dll %DestDir%\Release
goto end

:CopyDebug
mkdir %DestDir%\Debug
mkdir %DestDir%\Debug\platforms
mkdir %DestDir%\Debug\imageformats
mkdir %DestDir%\Debug\QtQuick.2
for %%F in (%DebugFiles%) do robocopy %1\bin %DestDir%\Debug %%F /MIR
robocopy %SrcDir%\plugins\platforms %DestDir%\Debug\platforms qwindowsd.dll /MIR
robocopy %SrcDir%\imageformats\platforms %DestDir%\Debug\imageformats qjpegd.dll /MIR
robocopy %SrcDir%\qml\QtQuick.2 %DestDir%\Debug\QtQuick.2 /MIR /xf qtquick2plugin.dll
copy /y %OpenSslDir%\*.dll %DestDir%\Debug
goto end

:end
