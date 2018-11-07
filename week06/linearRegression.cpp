#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;


// [[Rcpp::export]]
Rcpp::List fastLM(vec y, mat X) {
    vec betaHat, betaSigma, XtY, residuals;
    mat XtX;
    double sigmaHat;
    
    int nSample = X.n_rows;
    int pCov = X.n_cols;
    
    // equivalent to betaHat = solve(X,y);
    XtX = X.t() * X;
    XtY = X.t() * y;
    betaHat = solve(XtX, XtY);

    residuals = y - X * betaHat;
    // % pointwise product
    sigmaHat = sum(residuals % residuals) / (nSample - pCov);
    sigmaHat = sqrt(sigmaHat);
    
    // Inverse: XtX.i()  or use solve(XtX)
    betaSigma = sigmaHat * sqrt(diagvec(XtX.i()));
        
    return Rcpp::List::create(Rcpp::Named("betaHat") = betaHat,
                              Rcpp::Named("betaSigma") = betaSigma,
                              Rcpp::Named("sigmaHat") = sigmaHat);
}

