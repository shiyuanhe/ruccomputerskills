library(microbenchmark)
Rcpp::sourceCpp('Untitled.cpp', verbose = TRUE)
p = 3
n = 1e4
dataX = matrix(rnorm(p*n), nrow = p, ncol = n)


microbenchmark(res1 = computeCov_simd(dataX),
               res2 = computeCov_parallel(dataX),
               times = 1
)
