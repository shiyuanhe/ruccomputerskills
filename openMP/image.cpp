#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

int mirrorIndex(int fetchI, int length){
    if(fetchI < 0)
        fetchI = -fetchI - 1;
    if(fetchI >= length){
        fetchI = length - (fetchI - length) - 1;
    }
    return fetchI;
}


// [[Rcpp::export]]
mat imageConv_serial(mat img,  mat kernel){
    int m, n;
    m = img.n_rows;
    n = img.n_cols;
    mat img_result(m,n);
    
    int i, j, h, k, imgI, imgJ;
    double fin;
    for(j = 0; j < n; j++)
        for(i = 0; i < m; i++){
            fin = 0;
            for(h = -1; h < 2; h++)
                for(k = -1; k < 2; k++){
                    imgI = i + h;
                    imgJ = j + k;
                    imgI = mirrorIndex(imgI, m);
                    imgJ = mirrorIndex(imgJ, n);
                    fin += img(imgI,imgJ) * kernel(h+1, k+1);
                }
            if(fin < 0) fin =0;
            if(fin > 1) fin = 1;
            img_result(i,j) = fin;
        }
    
    return img_result;
}




// [[Rcpp::export]]
mat imageConv_parallel(mat img,  mat kernel){
    // write your parallel code here
}

