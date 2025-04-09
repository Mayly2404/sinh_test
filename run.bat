@echo off
color 0a
g++ -g RUNME.cpp -o RUNME.exe
RUNME.exe
g++ -g generator.cpp -o generator.exe
cls
generator.exe
python process_log.py
timeout /t 60