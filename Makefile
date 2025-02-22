run: main.o BST.h
	g++ -g main.o BST.h -o run

main.o: main.cpp
	g++ -c -g -Wall -std=c++11 main.cpp

clean: 
	-rm *.o

run:
	@./run