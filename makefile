StringToDouble: main.o
	g++ -std=c++23 -g  -Wall main.o -o StringToDouble
main.o: main.cpp
	g++ -std=c++23 -g -Wall -c main.cpp
	
clean:
	rm *.o StringToDouble
