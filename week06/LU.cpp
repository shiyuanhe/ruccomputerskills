#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// Solve Ax=b, the true x0 is provided
// [[Rcpp::export]]
vec pivotLU(mat A, vec b, vec x0){
    vec xhat, error(2);
    mat L,U,P;
    lu(L,U,P,A);
    xhat = solve(trimatl(L), P*b);
    xhat = solve(trimatu(U), xhat);
    
    error(0) = norm(xhat - x0);
    error(1) = norm(A*xhat - b);
    return error;
}

