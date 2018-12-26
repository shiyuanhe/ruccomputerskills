n = 1e7
x = runif(n)
sum_serial(x)
sum_parallel(x)
sum_devideC(x)

library(microbenchmark)
microbenchmark(sum_serial(x),
               sum_parallel(x),
               sum_devideC(x))

