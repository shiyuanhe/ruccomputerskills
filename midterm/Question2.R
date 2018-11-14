## Data Science Computer Skills
## 2018 Midterm Examination

library(microbenchmark)

# Parameters
n = 2^17 # number of samples
d = 50 # number of variables
m = 500
q = 0.001

# Generate the design matrix
A = matrix(rnorm(n*d), ncol = d)
# Generate the regression coefficients
beta = rnorm(d, sd = 5)
## Generate the response
b = A %*% beta + rnorm(n, sd = 1)
Ab = cbind(A, b)

## Direct least square regression
betaHat = solve(t(A) %*% A, t(A) %*% b)
## Your algorithm 
betaHat2 = efficientRegression(Ab, m, q)
## Two results should be close to each other
cbind(betaHat, betaHat2)








