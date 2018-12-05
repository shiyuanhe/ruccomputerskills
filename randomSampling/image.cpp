#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
mat fixedRankApprox(mat A, int K) {
    mat U,V,result;
    vec s;
    svd_econ(U,s,V,A);
    
    s.rows(K+1,s.n_elem - 1).zeros();
    result = (U.each_row() % s.t()) * V.t();
    result(find(result < 0)).zeros();
    result(find(result > 1)).ones();
    return result;
}

