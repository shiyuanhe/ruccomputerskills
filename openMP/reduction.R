library(microbenchmark)

p = 10
n = 1e6
dataX = matrix(rnorm(p*n), nrow = p, ncol = n)


microbenchmark(res1 = computeCovariance(dataX),
               res2 = computeCovariance2(dataX),
               res3 = computeCovariance3(dataX),
               times = 1
               )
