prog: Destination.o ListMyJosephus.o VectorMyJosephus.o TestListMyJosephus.o TestVectorMyJosephus.o main.o 
	g++ -g Destination.o ListMyJosephus.o VectorMyJosephus.o TestListMyJosephus.o TestVectorMyJosephus.o main.o -o ourProg

main.o: main.cpp TestListMyJosephus.h TestVectorMyJosephus.h
	g++ -c -g -Wall -std=c++14  main.cpp 

TestListMyJosephus.o: TestListMyJosephus.cpp TestListMyJosephus.h
	g++ -c -g -Wall -std=c++14 TestListMyJosephus.cpp

TestVectorMyJosephus.o: TestVectorMyJosephus.cpp TestVectorMyJosephus.h
	g++ -c -g -Wall -std=c++14 TestVectorMyJosephus.cpp

ListMyJosephus.o: ListMyJosephus.cpp ListMyJosephus.h
	g++ -c -g -Wall -std=c++14 ListMyJosephus.cpp

VectorMyJosephus.o: VectorMyJosephus.cpp VectorMyJosephus.h
	g++ -c -g -Wall -std=c++14 VectorMyJosephus.cpp

Destination.o: Destination.cpp Destination.h
	g++ -c -g -Wall -std=c++14 Destination.cpp

clean: 
	-rm *.o

run:
	@./ourProg