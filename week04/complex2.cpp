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


    friend ostream& operator<<(ostream& os, const complex& c);      

private:
    double real, imaginary;
    
};


ostream& operator<<(ostream& os, const complex& c){
	if(c.imaginary >=0)
	    os << c.real << "+" << c.imaginary << "i";
	else
    	    os << c.real  << c.imaginary << "i";
	return os;
}

int main(){
    complex c1(1,2), c2(3.3, -2.1);
    complex c3, c4;
    c3 = c1 + c2;
    c4 = c1 * c2;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;
    cout << "c1 * c2 = " << c4 << endl;
    
    return 0;
}
