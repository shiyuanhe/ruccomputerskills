#include "complex.hpp"
#include "cvector.hpp"
#include <iostream>
using namespace std;


int main(){
    complex c1(1,2), c2(3.3, -2.1), c3;
    c3 = c1 + c2;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;
    
    cout << endl << endl;
    
    CVector foo (3,1);
    CVector bar (1,2);
    CVector result;
    result = foo + bar;
    cout << result.x << ',' << result.y << '\n';
    
    return 0;
}
