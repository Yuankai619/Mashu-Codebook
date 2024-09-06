@echo off
g++ ac.cpp -o ac.exe
g++ wa.cpp -o wa.exe
g++ gen1.cpp -o gen.exe

:loop
   echo %%x
   gen.exe > input
   ac.exe < input > ac
   wa.exe < input > wa
   fc ac wa 
if not errorlevel 1 goto loop