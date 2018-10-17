#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
mat matrixTimesTwo(mat x){
    mat y;
    y = 2*x;
    return y;
}

