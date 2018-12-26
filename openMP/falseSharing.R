
x = runif(1e6)
find_parallel(x)
find_serial(x)

library(microbenchmark)

microbenchmark(find_parallel(x),
               find_parallel_2(x),
               find_serial(x),times = 100)
