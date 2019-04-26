Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp
	
Logic.o: Logic.cpp Logic.h
	g++ -c Logic.cpp
	
Function.o: Function.cpp Function.h
	g++ -c Function.cpp

main: main.cpp Menu.o Logic.o Function.o
	g++ main.cpp Menu.o Logic.o Function.o -o main
