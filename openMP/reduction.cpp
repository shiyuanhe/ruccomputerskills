#include <RcppArmadillo.h>
#include <omp.h>
using namespace arma;

// [[Rcpp::plugins(openmp)]]
// [[Rcpp::depends(RcppArmadillo)]]


#include <armadillo>
#include <omp.h>

#pragma omp declare reduction( + : arma::mat : omp_out += omp_in ) \
    initializer( omp_priv = omp_orig )

// [[Rcpp::export]]
mat computeCovariance(mat dataX)
{
    int nSample, pCov, i;
    nSample = dataX.n_cols;
    pCov = dataX.n_rows;
    
    arma::mat result = arma::zeros(pCov, 1);

#pragma omp parallel for shared(dataX) reduction(+:result) schedule(static)
    for(i = 0; i < nSample; i++)
    {
        result += dataX.col(i); // Adding the matrices to X here
    }
    
    return result;
}


    
// [[Rcpp::export]]
mat computeCovariance2(mat dataX)
{
    int nSample, pCov, i;
    nSample = dataX.n_cols;
    pCov = dataX.n_rows;
        
    arma::mat result = arma::zeros(pCov, 1);
        
    for(i = 0; i < nSample; i++)
    {
        result += dataX.col(i); // Adding the matrices to X here
    }
        
    return result;
}
    
// [[Rcpp::export]]
mat computeCovariance3(mat dataX){
    return sum(dataX,1);
}
    


