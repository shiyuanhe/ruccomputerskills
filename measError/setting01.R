set.seed(100)
n = 400
beta0 = 1
beta1 = 2
betaTrue = c(beta0, beta1)
sigmaU = runif(n, 0.4, 0.6)
sigmaQ = runif(n, 0.1, 0.2)
sigmaE = 0.2
