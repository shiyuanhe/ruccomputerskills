#include <iostream>
using namespace std;

class complex{
public:
    complex();
    complex(double r_, double i_);
    complex operator+(const complex& z2);
    friend ostream& operator<<(ostream& os, const complex& c);
private:
    double real, imaginary;
};

