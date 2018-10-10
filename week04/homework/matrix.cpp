#include "matrix.hpp"


matrix::matrix(unsigned int m_, unsigned int n_){
    m = m_;
    n = n_;
    data.resize(m*n);
}



double& matrix::operator()(unsigned int i, unsigned int j){
    return data.at(j*m+i);
}


double matrix<T>::operator() (unsigned int i, unsigned int j) const{
    return data.at(j*m+i);
}


ostream & operator<<(ostream & os, const matrix & mat)
{
   // your code
}

// more of your code


