set MATLAB=D:\appli\Matlab\R2015a

cd .

if "%1"=="" (D:\appli\Matlab\R2015a\bin\win64\gmake -f model3.mk all) else (D:\appli\Matlab\R2015a\bin\win64\gmake -f model3.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
