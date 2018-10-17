set.seed(100)
n = 400
x = 2*pi*(1:n)/n
y = sin(x) + rnorm(n, sd = 0.1)

weights = c(1,2,3,4,5,4,3,2,1) /25
fHat = localSmoothing(y, weights)

par(mar = c(4,4,1,1))
plot(x,y, pch = 20)
lines(x, sin(x), lwd = 2, lty = 2)
lines(x,fHat, lwd = 2, col = "red")
