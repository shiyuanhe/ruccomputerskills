library(microbenchmark)
n = 1e7
x = runif(n)
(x1 = sqrt(sum(x^2)))
(x2 = vectorNorm_parallel(x))

res = microbenchmark(vectorNorm_parallel(x),
               vectorNorm_serial(x),
               vectorNorm_direct(x), 
               times = 20, unit = "ms")
print(res)
