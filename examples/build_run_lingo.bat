@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
cd /d C:\SourceControl\dirapi\examples
cl /nologo /W3 run_lingo.c user32.lib gdi32.lib
