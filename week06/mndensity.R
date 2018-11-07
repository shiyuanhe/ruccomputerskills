sigma = matrix(c(3,1,1,1,3,1,1,1,3), nrow = 3)
sigma
#     [,1] [,2] [,3]
#[1,]    3    1    1
#[2,]    1    3    1
#[3,]    1    1    3
mu = rep(0, 3)
xobs = c(0.5, 0.2, 0.3)

## Test with Rcpp
Rcpp::sourceCpp('mndensity.cpp')
mndensity(xobs, mu, sigma)
# -4.299682

## Test with mvtnorm
library(mvtnorm)
dmvnorm(xobs, mu, sigma,log = TRUE)
# -4.299682
