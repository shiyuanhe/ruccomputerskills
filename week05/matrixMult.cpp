#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;


// [[Rcpp::export]]
mat matrixMult_v1(mat A, mat B) {
    size_t pSize, rSize, qSize;
    size_t i, j, k;
    pSize = A.n_rows;
    rSize = A.n_cols;
    qSize = B.n_cols;
    
    mat C = zeros<mat>(pSize, qSize);
    
    double s;
    for(i = 0; i < pSize; i++)
        for(j = 0; j < qSize; j++){
            s = 0;
            for(k = 0; k < rSize; k++){
                s += A(i, k) * B(k, j);
            }
            C(i,j) = s;
        }
        
    return C;
}

