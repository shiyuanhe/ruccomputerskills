# include <RcppArmadillo.h>
# include <omp.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]

using namespace arma;

#pragma omp declare simd 
inline double squaredExp(const vec & x1, 
                         const vec & x2){
    double val;
    val = norm(x1-x2);
    val = exp(- val * val / 2.0);
    return val;
}


// [[Rcpp::export()]]
mat computeCov(const mat X) {
    const int N = X.n_cols;
    int i,j;
    // containers
    arma::mat covMat(N, N) ;

    // algorithm
    for (i = 0 ; i < N ; i++){
        for(j = i; j < N; j++){
            covMat(i,j) = squaredExp(X.col(i), X.col(j));
            covMat(j,i) = covMat(i,j);
        }
    }
    
    // returns
    return covMat;
}


// [[Rcpp::export()]]
mat computeCov_parallel(const mat X) {
    const int N = X.n_cols;
    int i,j;
    // containers
    arma::mat covMat(N, N) ;
    
#pragma omp parallel for collapse(2)
    for (i = 0 ; i < N ; i++){
        for(j = i; j < N; j++){
            covMat(i,j) = squaredExp(X.col(i), X.col(j));
            covMat(j,i) = covMat(i,j);
        }
    }
    
    // returns
    return covMat;
}



// [[Rcpp::export()]]
mat computeCov_simd(const mat X) {
    const int N = X.n_cols;
    int i,j;
    // containers
    arma::mat covMat(N, N) ;
    
#pragma omp parallel for simd collapse(2)
    for (i = 0 ; i < N ; i++){
        for(j = i; j < N; j++){
            covMat(i,j) = squaredExp(X.col(i), X.col(j));
            covMat(j,i) = covMat(i,j);
        }
    }
    
    // returns
    return covMat;
}
