#include "matrix.hpp"
#include <iostream>


int main(){
    matrix A(2,2);
    matrix B, C;

    A(0,0) = 1.5;
    A(1,0) = 2.2;
    A(0,1) = 3.3;
    A(1,1) = 1.5;

    B.resize(2,2);
    B(0,0) = 1.1;
    B(1,0) = 2.3;
    B(0,1) = 2.3;
    B(1,1) = 1.2;

    C = A + B;
    std::cout << C << std::endl;
    C = A * B;
    std::cout << C << std::endl;

    return 0;
 }




