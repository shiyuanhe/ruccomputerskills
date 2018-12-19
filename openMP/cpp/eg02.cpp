#include <stdio.h>
#include <omp.h>

int main(){
    int i,n;
    n = 10;
    #pragma omp parallel shared(n) private(i)
    {
        #pragma omp for
        for(i=0; i<n; i++){
            int id;
            id = omp_get_thread_num();
            printf("Thread %d executes loop iteration %d\n",
                id, i);
        }
    }
    return 0;
}
