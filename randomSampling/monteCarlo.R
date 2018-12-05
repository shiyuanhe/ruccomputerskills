Sys.setenv("PKG_LIBS"="-ltrng4")
Rcpp::sourceCpp("./monteCarlo.cpp")
mcIntegration_serial_Uniform()
mcIntegration_Uniform()
mcIntegration_trancatedNormal()

