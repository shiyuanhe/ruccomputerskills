set.seed(10)
n = 1e4
p = 5
sigma_e = 0.1
(beta = rnorm(p, sd = 5))
X = matrix(rnorm(n*p), n, p)
y = X %*% beta + rnorm(n, sd = sigma_e)

betaHat01 = linearRegression01(y, X, 2e3)
betaHat02 = linearRegression02(y, X, 2e3)
sum(abs(betaHat01 - beta))
sum(abs(betaHat02 - beta))

