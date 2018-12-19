oneReplicate = function(){
    simuData = getData(n, beta0, beta1, sigmaU, sigmaQ, sigmaE)
    betaHat1 = naiveRegression(simuData$D, simuData$W)
    betaHat2 = correctedRegression(simuData$D, simuData$W, sigmaU)
    result = rep(0,2)
    result[1] = evaluateLoss(betaTrue, betaHat1)
    result[2] = evaluateLoss(betaTrue, betaHat2)
    return(result)
}


evaluateLoss = function(beta0, betaHat){
    norm(betaHat - beta0)
}
