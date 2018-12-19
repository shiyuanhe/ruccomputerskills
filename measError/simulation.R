library(measError)
library(doSNOW)
library(doRNG)
source("./utilities.R")
source("./setting02.R")

cl<-makeCluster(4)
registerDoSNOW(cl)
set.seed(123)
result = foreach(i=1:1000, 
                 .combine = "rbind",
                 .packages = "measError") %dorng%
    oneReplicate()
stopCluster(cl)

colnames(result) = c("Naive", "Correted")
boxplot(result)
