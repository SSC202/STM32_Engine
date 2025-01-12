
set MATLAB=D:\Program Files\MATLAB\R2022b


call  "\\DESKTOP-LLS7BM2\D$\Program Files\MATLAB\R2022b\bin\win64\checkMATLABRootForDriveMap.exe" "\\DESKTOP-LLS7BM2\D$\Program Files\MATLAB\R2022b"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n
cd .

if "%1"=="" ("D:\Program Files\MATLAB\R2022b\bin\win64\gmake" MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f IF_Mode0.mk all) else ("D:\Program Files\MATLAB\R2022b\bin\win64\gmake" MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f IF_Mode0.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1