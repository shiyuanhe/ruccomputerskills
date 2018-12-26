

library(microbenchmark)

microbenchmark(mcIntegration_serial_Uniform(),
               mcIntegration_parallel_Uniform(),
               mcIntegration_parallel_trancatedNormal())











