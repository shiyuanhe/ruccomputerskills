#include <Rcpp.h>
#include <omp.h>
#include <trng/yarn2.hpp>
#include <trng/uniform_dist.hpp>
#include <trng/truncated_normal_dist.hpp>

// [[Rcpp::plugins(openmp)]]

// [[Rcpp::export]]
double mcIntegration_serial_Uniform(){
  double x;
  long double integral = 0;
  int i;
  int N = 1e6;
  for(i = 0; i < N; i++){
    x = R::runif(0,3);
    integral += x * x;
  }  
  integral = 3.0 * integral / N;
  
  return integral;
}


// [[Rcpp::export]]
double mcIntegration_serial_error(){
  double x;
  long double integral = 0;
  int i;
  int N = 1e6;
  omp_set_num_threads(16);
  
#pragma omp parallel for reduction(+:integral) private(x)
  for(i = 0; i < N; i++){
    x = R::runif(0,3);
    integral += x * x;
  }  
  integral = 3.0 * integral / N;
  
  return integral;
}


// [[Rcpp::export]]
double mcIntegration_parallel_Uniform(){
  double integral;
  int i;
  int N = 1e6;
  omp_set_num_threads(16);
  
#pragma omp parallel shared(N) private(i)
{
  trng::yarn2 rx;
  double x;
  rx.seed(10);
  int size=omp_get_num_threads();     // get total number of processes
  int rank=omp_get_thread_num();      // get rank of current process
  rx.split(size, rank);               // choose sub-stream no. rank out of size streams
  trng::uniform_dist<> u(0,3);  // random number distribution
  
#pragma omp for reduction(+:integral)
  for(i = 0; i < N; i++){
    x = u(rx);
    integral += x * x;
  }  
  
}

integral = 3.0 * integral / N;


return integral;
}


// [[Rcpp::export]]
double mcIntegration_parallel_trancatedNormal(){
  double integral;
  int i;
  int N = 1e6;
#pragma omp parallel shared(N) private(i)
{
  trng::yarn2 rx;
  double x;
  rx.seed(10);
  int size=omp_get_num_threads(); 
  int rank=omp_get_thread_num();  
  rx.split(size, rank);   
  trng::truncated_normal_dist<> u(3,2,0,3);
#pragma omp for reduction(+:integral)
  for(i = 0; i < N; i++){
    x = u(rx);
    integral += x * x / u.pdf(x);
  }
  
}

integral = integral / N;

return integral;
}


