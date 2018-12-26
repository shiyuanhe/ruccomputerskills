#include <RcppArmadillo.h>
#include <omp.h>
using namespace arma;

// [[Rcpp::plugins(openmp)]]
// [[Rcpp::depends("RcppArmadillo")]]

// [[Rcpp::export]]
double sum_parallel(vec x){
  int i;
  double sum;
  omp_set_num_threads(8);
#pragma omp parallel for schedule(static) reduction(+:sum)
    for(i=0; i < x.n_elem; i++)
      sum += x(i) ;
  return sum;
}


// [[Rcpp::export]]
double sum_serial(vec x){
  int i;
  double sum;
  for(i=0; i < x.n_elem; i++)
    sum += x(i) ;

  return sum;
}



#define CUTOFF 20000

double parallel_sum(const vec & , size_t ,size_t);
double serial_sum(const vec & , size_t , size_t);

// [[Rcpp::export]]
double sum_devideC(const vec & data)
{
  double r;
  size_t n = data.n_elem;
#pragma omp parallel
#pragma omp single nowait
  r = parallel_sum(data, 0, n);
  return r;
}

double parallel_sum(const vec & data, size_t b, size_t n)
{
  // base case
  if ((n - b) <= CUTOFF) {
    return serial_sum(data, b,  n);
  }
  
  // recursive case
  double x, y;
  size_t half = b + (n - b) / 2;
  
#pragma omp task shared(x, data)
  x = parallel_sum(data, b, half);
#pragma omp task shared(y, data)
  y = parallel_sum(data, half,  n);
#pragma omp taskwait
  x += y;
  
  return x;
}


double serial_sum(const vec & data, size_t b,  size_t n)
{
  double s = 0;
  int i;
  for(i = b; i < n; i++)
    s += data(i);
  return s;
}

