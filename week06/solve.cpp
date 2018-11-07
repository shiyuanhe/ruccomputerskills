#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// Solve Ax=b, the true x0 is provided

// [[Rcpp::export]]
vec computeInverse(mat A, vec b, vec x0){
    vec error(2);
    
    // the inverse of matrix A:
    // inv(A) or A.i()
    mat tmp = A.i();
    vec xhat = tmp * b;
    error(0) = norm(xhat - x0);
    error(1) = norm(A*xhat - b);
    return error;
}


// [[Rcpp::export]]
vec computeInverse2(mat A, vec b, vec x0){
    vec error(2);
    
    // the inverse of matrix A:
    // inv(A) or A.i()
    vec xhat = (inv(A)) * b;
    error(0) = norm(xhat - x0);
    error(1) = norm(A*xhat - b);
    return error;
}



// [[Rcpp::export]]
vec solveLS(mat A, vec b, vec x0){
    vec error(2);
    
    // directly solve the linear system
    vec xhat = solve(A,b);
    error(0) = norm(xhat - x0);
    error(1) = norm(A*xhat - b);
    return error;
}

