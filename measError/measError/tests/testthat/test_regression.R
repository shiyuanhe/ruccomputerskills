context("Compute the linear regression")

test_that("correct coef estimation", {
    n = 1e4
    beta0 = 1
    beta1 = 2
    sigmaU = runif(n, 0.2, 0.3)
    sigmaQ = runif(n, 0, 0.1)
    sigmaE = 0.1
    simuData = getData(n, beta0, beta1, sigmaU, sigmaQ, sigmaE)
    betaHat = correctedRegression(simuData$D, simuData$W, sigmaU)
    betaTrue = c(beta0, beta1)
    diff = sum(abs(betaTrue - betaHat))
    expect_lt(diff, 1e-2)
})
