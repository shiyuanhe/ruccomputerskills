eg02: complex.o main.o
	g++ complex.o main.o -o eg02

complex.o: complex.hpp complex.cpp
	g++ -c complex.cpp

main.o: complex.hpp main.cpp
	g++ -c main.cpp

clean:
	rm -f complex.o main.o eg02
