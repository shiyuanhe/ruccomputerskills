library(microbenchmark)

p = 4
n = 1e4
dataX = matrix(rnorm(p*n), nrow = p, ncol = n)

microbenchmark(res1 = computeCov(dataX),
               res2 = computeCov_parallel(dataX),
               times = 1)

