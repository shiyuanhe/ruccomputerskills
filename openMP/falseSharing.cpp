#include <RcppArmadillo.h>
#include <omp.h>
using namespace arma;

// [[Rcpp::plugins(openmp)]]
// [[Rcpp::depends("RcppArmadillo")]]

// [[Rcpp::export]]
int find_parallel(vec data){
  int i;
  uvec sumVec(16, fill::zeros);
  omp_set_num_threads(16);
#pragma omp parallel shared(data,sumVec)
{
  int p = omp_get_thread_num();
#pragma omp for schedule(static)
  for( int i = 0; i < data.n_elem; ++i )
    if( data(i) > 0.5 )
      ++sumVec(p);
}

return sum(sumVec);
}

// [[Rcpp::export]]
int find_serial(vec data){
  int odds = 0;
  for( int i = 0; i < data.n_elem; ++i )
    if( data(i) > 0.5 )
      ++odds;
  return odds;
}


// [[Rcpp::export]]
int find_parallel_2(vec data){
  int i;
  uvec sumVec(16, fill::zeros);
  omp_set_num_threads(16);
#pragma omp parallel shared(data,sumVec)
{
  int localSum = 0;
  int p = omp_get_thread_num();
#pragma omp for schedule(static)
  for( int i = 0; i < data.n_elem; ++i )
    if( data(i) > 0.5 )
      ++localSum;
  sumVec(p) = localSum;
}

return sum(sumVec);
}
