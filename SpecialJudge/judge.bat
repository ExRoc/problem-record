@echo off
g++ -g my.cpp -o my.exe
g++ -g right.cpp -o right.exe
g++ -g data.cpp -o data.exe
:loop
	data.exe > test.txt
	right.exe < test.txt > right_ans.txt
	my.exe < test.txt > my_ans.txt
	fc right_ans.txt my_ans.txt
	if not errorlevel 1 goto loop
pause
goto loop