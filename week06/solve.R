Rcpp::sourceCpp("solve.cpp")
options(digits = 3)

# Generate the 7x7 Hilbert matrix
# (known to be poorly conditioned)
set.seed(100)
library(Matrix)
n = 7
(A = as.matrix(Hilbert(n)))
eigen(A)$value
x0 = rnorm(n)
b = A %*% x0

computeInverse(A,b,x0)
computeInverse2(A,b,x0)
solveLS(A,b,x0)


