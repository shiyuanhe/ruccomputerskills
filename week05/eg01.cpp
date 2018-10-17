#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
vec timesTwo(vec x){
    vec y;
    y = 2*x;
    return y;
}

