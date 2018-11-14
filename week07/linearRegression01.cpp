#include <RcppArmadillo.h>
#include <RcppArmadilloExtensions/sample.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;


// [[Rcpp::export]]
vec linearRegression01(vec y, mat X, int q){
    vec beta;
    mat XSub;
    vec ySub;
    
    uvec fullvec;
    fullvec = regspace<uvec>(0, y.n_elem - 1) ;
    
    uvec sampleIndex = Rcpp::RcppArmadillo::sample(fullvec, q, true);
    
    XSub = X.rows(sampleIndex);
    ySub = y.rows(sampleIndex);
    beta = solve(XSub.t() * XSub, XSub.t() * ySub);
    
    return beta;
}


// [[Rcpp::export]]
vec linearRegression02(vec y, mat X, int q) {
    vec beta;
    mat XSub, HatMat;
    vec ySub;
    vec infScore;
    
    uvec fullvec;
    fullvec = regspace<uvec>(0, y.n_elem - 1) ;
    
    HatMat = X * solve(X.t()*X , X.t() );
    infScore = diagvec(HatMat);  
    infScore /= sum(infScore);
        
    uvec sampleIndex = Rcpp::RcppArmadillo::sample(fullvec, q, true, infScore);
    XSub = X.rows(sampleIndex);
    ySub = y.rows(sampleIndex);
    beta = solve(X.t() * X, X.t() * y);
    
    return beta;
}



// [[Rcpp::export]]
mat rngCpp(const int N) {
    mat X(N, 4);
    X.col(0) = vec(Rcpp::runif(N, -1, 1));
    X.col(1) = vec(Rcpp::rnorm(N, 0, 10));
    X.col(2) = vec(Rcpp::rt(N, 5));
    X.col(3) = vec(Rcpp::rbeta(N, 1, 1));
    return X;
}

