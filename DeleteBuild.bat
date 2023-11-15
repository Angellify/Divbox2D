@echo off
Rem Remove all build outputs

set folder="C:\Projects\Divbox2D\bin"
cd /d %folder%
for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)

set folder="C:\Projects\Divbox2D\bin-int"
cd /d %folder%
for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)

set folder="C:\Projects\Divbox2D\vendor\Glad\bin"
cd /d %folder%
for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)

set folder="C:\Projects\Divbox2D\vendor\Glad\bin-int"
cd /d %folder%
for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)

set folder="C:\Projects\Divbox2D\vendor\GLFW\bin"
cd /d %folder%
for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)

set folder="C:\Projects\Divbox2D\vendor\GLFW\bin-int"
cd /d %folder%
for /F "delims=" %%i in ('dir /b') do (rmdir "%%i" /s/q || del "%%i" /s/q)

set folder="C:\Projects\Divbox2D"
cd /d %folder%
del "Divbox2D.sln"
del "Divbox2D.vcxproj"
del "Divbox2D.vcxproj.filters"
del "Divbox2D.vcxproj.user"
rmdir /s /q "C:\Projects\Divbox2D\.vs"


