
generateData = function(n, A,C, z0, sigmaQ, sigmaR){
    z = z0
    # 4-by-n Actual hidden state
    ZActual = matrix(0, nrow = 4, ncol = n)
    # 2-by-n observation matrix
    Yobs = matrix(0, nrow = 2, ncol = n) 
    # simulate n observations
    for(i in 1:n){
        z = A%*%z + rnorm(4, sd = sigmaQ)
        Yobs[,i] = C %*% z + rnorm(2, sd = sigmaR)
        ZActual[,i] = z
    }
    # return the observation and latent state as a list
    dataList = list(Yobs = Yobs, 
                    ZActual = ZActual)
    
    return(dataList)
}

drawPath = function(Yobs, ZActual, Zhat){
    plot(t(Yobs),pch = 20, col = "grey", xlab = "", ylab = "")
    lines(t(ZActual[1:2,]), col = "red", lwd = 2)
    lines(t(Zhat[1:2,]), col = "blue", lwd = 2)
}

## Parameters
sigmaQ = 0.2 
sigmaR = 0.8
n = 100 # Sample size
delta = 0.5 # step size
A = diag(1, nrow = 4, ncol = 4) # transition matrix
A[1,3] = A[2,4] = delta 
C = diag(1, nrow = 2, ncol = 4) # obs matrix
x0 = c(0,0) # Initial Poisition
v0 = c(1,1) # Initial velocity
z0 = c(x0, v0) # Initial latent state


data = generateData(n, A, C, z0, sigmaQ, sigmaR)
Zhat = kalmanFiltering(data$Yobs, z0, A, C,  sigmaQ, sigmaR)
drawPath(data$Yobs, data$ZActual, Zhat)

