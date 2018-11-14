#include <iostream>
using namespace std;

class complex{
public:
    complex(){
	real = 0.0;
	imaginary = 0.0;
    }

    complex(double r_, double i_){
	real = r_;
	imaginary = i_;
    }

    void print(){
	if(imaginary >=0)
	    cout << real << "+" << imaginary << "i" << endl;
	else
    	    cout << real  << imaginary << "i" << endl;
    }

    complex add(const complex & z2){
	complex result;
	result.real = real + z2.real;
	result.imaginary = imaginary + z2.imaginary;
	return result;
    }

    complex multiply(const complex & z2){
	//write your code here
    }

    
private:
    double real, imaginary;
    
};


int main(){
    complex c1(1,2), c2(3.3, -2.1);
    complex c3, c4;
    c3 = c1.add(c2);
    c4 = c1.multiply(c2);

    c1.print();
    c2.print();
    cout << "c1+c2=";
    c3.print();

    cout << "c1*c2=";
    c4.print();
    
    return 0;
}
