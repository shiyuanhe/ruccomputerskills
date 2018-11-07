#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

//' Kalman filtering for object tracking
//' 
//' @param A transition matrix on latent state
//' @param C observation matrix on latent state
//' @param z0 initial latent state
//' @param Yobs observations
//' @param sigmaQ transition uncertainty
//' @param sigmaR observation uncertainty
//' @return a matrix, each column of which is the estimated latent state
// [[Rcpp::export]]
mat kalmanFiltering(mat A, mat C, vec z0, mat Yobs, 
                    double sigmaQ, double sigmaR) {
    
}

