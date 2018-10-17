library(microbenchmark)

p = r = q = 1000
A = matrix(rnorm(p*r), nrow = p, ncol = r)
B = matrix(rnorm(r*q), nrow = r, ncol = q)

testMult = microbenchmark(matrixMult_v1(A,B), 
                          matrixMult_v2(A,B), 
                          times = 10)
testMult

