#include <omp.h>
#include <stdio.h>

void functionA(){
    int id;
    id = omp_get_thread_num();
    printf("Thread %d executes functionA\n",
        id);
}

void functionB(){
    int id;
    id = omp_get_thread_num();
    printf("Thread %d executes functionA\n",
        id);
}

int main(){
    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            functionA();
        
            #pragma omp section
            functionB();
        }
    }
    return 0;
}
