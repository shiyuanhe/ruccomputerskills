#include "complex.hpp"

complex::complex(){
    real = 0.0;
    imaginary = 0.0;
}

complex::complex(double r_, double i_){
    real = r_;
    imaginary = i_;
}


complex complex::operator+(const complex& z2){
    complex result;
    result.real = real + z2.real;
    result.imaginary = imaginary + z2.imaginary;
    return result;
}


ostream& operator<<(ostream& os, const complex& c){
    if(c.imaginary >=0)
        os << c.real << "+" << c.imaginary << "i";
    else
        os << c.real  << c.imaginary << "i";
    return os;
}




