libmymath.a: complex.o cvector.o
	ar rcs libmymath.a complex.o cvector.o

complex.o: complex.hpp complex.cpp
	g++ -c complex.cpp

cvector.o: cvector.hpp cvector.cpp
	g++ -c cvector.cpp


clean:
	rm -f libmymath.a complex.o cvector.o



