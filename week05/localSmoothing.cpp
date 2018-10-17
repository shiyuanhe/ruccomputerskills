#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;


// [[Rcpp::export]]
vec localSmoothing(vec y, vec weights){
    int i, j, ySize = y.n_elem;
    vec smoothedY(ySize);
    double s;
    for(i = 0; i < ySize; i++){
        s = 0;
        for(j = -4; j < 5; j++){
            s += weights(j+4) * y(i+j);
        }
        smoothedY(i) = s;
    }
    
    return smoothedY;
}

