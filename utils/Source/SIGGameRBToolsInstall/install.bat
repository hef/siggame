@echo Installing...
@echo Installing Python2.5...
@echo off
IF NOT EXIST C:\Python25\python.exe START /wait resources\python-2.5.4.msi /passive

@echo on
@echo Compiling RBTools...
@echo off

IF NOT EXIST C:\Python25\Scripts\easy_install.exe START /wait C:\Python25\python.exe resources\RBTools-0.2beta1\ez_setup.py

@echo on
@echo Installing Review Tool...
@echo off

cd resources\RBTools-0.2beta1

IF NOT EXIST C:\Python25\Scripts\post-review START /wait C:\Python25\python.exe setup.py install

cd ..

@echo on
@echo Installing Helper Scripts...
@echo off

XCOPY submitreview.py C:\Python25\Scripts /y
XCOPY easygui.py C:\Python25\Lib\site-packages /y

@echo on
@echo Installing MSYS...
@echo Keep all default options.
@echo During the post install process.  Hit "Y" at the first prompt and "N" at the second prompt.
@echo off

IF NOT EXIST C:\msys\1.0 START /wait MSYS-1.0.10.exe
START /wait C:\Python25\python.exe setenvs.py

@echo on
@echo Integrating Review Tool With P4V...
@echo off
XCOPY customtools.xml "%USERPROFILE%\.p4qt" /y


@echo on
@echo.
@echo.
@echo Installation Complete
@echo Please Restart Any Instances of Perforce
@echo.
@echo.
@pause