#include <RcppArmadillo.h>
#include <omp.h>
using namespace arma;

// [[Rcpp::plugins(openmp)]]
// [[Rcpp::depends("RcppArmadillo")]]
// [[Rcpp::export]]
vec addTwo_parallel(vec x, vec y){
    vec z(x.n_elem);
    int i;
#pragma omp parallel for schedule(static) \
    private(i) shared(x,y,z)
    for(i=0; i < x.n_elem; i++)
        z(i) = x(i) + y(i);
    return z;
}


// [[Rcpp::export]]
vec addTwo_serial(vec x, vec y){
    vec z(x.n_elem);
    int i;
    for(i=0; i < x.n_elem; i++)
        z(i) = x(i) + y(i);
    return z;
}


// [[Rcpp::export]]
vec addTwo_direct(vec x, vec y){
    return x + y;
}



