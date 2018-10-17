#include <RcppArmadillo.h>
#include <cmath>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;


// [[Rcpp::export]]
vec vectorSquared(vec x){
    int i, vSize = x.n_elem; // length of vector x
    vec xSq(vSize);
    for(i=0; i<vSize; i++){
        xSq(i) = pow(x(i), 2); // Error: x(i)^2
    }
    return xSq;
}
