// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// naiveRegression
arma::vec naiveRegression(arma::vec D, arma::vec W);
RcppExport SEXP _measError_naiveRegression(SEXP DSEXP, SEXP WSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type D(DSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type W(WSEXP);
    rcpp_result_gen = Rcpp::wrap(naiveRegression(D, W));
    return rcpp_result_gen;
END_RCPP
}
// correctedRegression
arma::vec correctedRegression(arma::vec D, arma::vec W, arma::vec sigmaU);
RcppExport SEXP _measError_correctedRegression(SEXP DSEXP, SEXP WSEXP, SEXP sigmaUSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type D(DSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type W(WSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sigmaU(sigmaUSEXP);
    rcpp_result_gen = Rcpp::wrap(correctedRegression(D, W, sigmaU));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_measError_naiveRegression", (DL_FUNC) &_measError_naiveRegression, 2},
    {"_measError_correctedRegression", (DL_FUNC) &_measError_correctedRegression, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_measError(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
