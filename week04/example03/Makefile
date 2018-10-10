eg03: main.o
	g++ main.o -o eg03 -L./math/ -lmymath

main.o: main.cpp
	g++ -c main.cpp -I./math/

clean:
	rm -f main.o eg02
