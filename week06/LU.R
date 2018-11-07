Rcpp::sourceCpp("LU.cpp")
options(digits = 3)

# Generate the 7x7 Hilbert matrix
# (known to be poorly conditioned)
set.seed(100)
library(Matrix)
n = 7
(A = as.matrix(Hilbert(n)))
x0 = rnorm(n)
b = A %*% x0

pivotLU(A,b,x0)


