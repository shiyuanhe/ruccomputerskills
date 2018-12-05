lambda_1 = 10
lambda_2 = 18
n = 60
N = 100

x1 = rpois(n, lambda_1)
x2 = rpois(N-n, lambda_2)
dataX = c(x1, x2)
plot(dataX, xlab = "", ylab = "", pch = 20)


