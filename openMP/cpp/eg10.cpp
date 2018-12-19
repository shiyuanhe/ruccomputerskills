#include <stdio.h>
#include <omp.h>

int main(){
    int i,n,id;
    n = 13;
#pragma omp parallel for shared(n) private(i, id) schedule(dynamic,2)
    for(i=0; i<n; i++){
        id = omp_get_thread_num();
        printf("Thread %d executes loop iteration %d\n",
               id, i);
    }
    
    return 0;
}
