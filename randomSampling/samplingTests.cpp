#include <RcppArmadillo.h>
#include <trng/yarn2.hpp>
#include <trng/discrete_dist.hpp>

using namespace arma;
// [[Rcpp::depends(RcppArmadillo)]]

// Examples of samplng from discrete distribution

// [[Rcpp::export]]
vec discreteSampling() {
    vec result;
    
    vec prob;
    prob << 0.1 << 0.8 << 0.1;

    trng::yarn2 rx;
    rx.seed(10);
    trng::discrete_dist distSampling(prob.begin(), prob.end());
    Rcpp::Rcout << distSampling(rx) << std::endl;
    
    prob(1) = 0.1;
    prob(2) = 0.8;
    
    // Method One to update sampling probabilities
    trng::discrete_dist::param_type newParam(prob.begin(), prob.end());
    distSampling.param(newParam);
    Rcpp::Rcout << distSampling(rx) << std::endl;

    // Method Two to update sampling probabilities
    distSampling = trng::discrete_dist(prob.begin(), prob.end() );
    Rcpp::Rcout << distSampling(rx) << std::endl;
    
    return result;
}


