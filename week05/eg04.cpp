#include <RcppArmadillo.h>
#include <cmath>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;


// [[Rcpp::export]]
mat matrixSquared(mat x){
    int i,j, m, n; // length of vector x
    m = x.n_rows;
    n = x.n_cols;
    mat xSq(m, n);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            xSq(i,j) = pow(x(i,j) , 2); // Error: x(i,j)^2
    return xSq;
}
