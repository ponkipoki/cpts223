prog: main.o matchingGame.hpp.gch matchingGame.o
	g++ -g main.o matchingGame.o -o matchingGame

main.o: main.cpp matchingGame.h
	g++ -c -g -Wall -std=c++11  main.cpp 

matchingGame.hpp.gch: matchingGame.cpp matchingGame.h
	g++ -c -g -Wall -std=c++11 matchingGame.h

matchingGame.o: matchingGame.cpp
	g++ -c -g -Wall -std=c++11 matchingGame.cpp 

clean: 
	-rm *.o

run:
	@./matchingGame