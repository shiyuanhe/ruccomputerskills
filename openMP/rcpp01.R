library(microbenchmark)
n = 1e6
x = runif(n)
y = runif(n)

res = microbenchmark(addTwo_serial(x,y),
               addTwo_parallel(x,y),
               addTwo_direct(x,y),
               times = 20)
print(res)
