#include <omp.h>
#include <stdio.h>

void functionA(){
    int id;
    id = omp_get_thread_num();
    printf("Thread %d is doing something else.\n",
        id);
}


int main(){
#pragma omp parallel
    {
#pragma omp single
	functionA();
	int id = omp_get_thread_num();
	printf("Hi from thread %d.\n",
	       id);
    }
    return 0;
}

