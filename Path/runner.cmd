@echo off

rem This is not optimal btw
rem echo %~dpn1 

com %1 && echo. && echo Running... && %~dpn1.exe %2 %3 %4
