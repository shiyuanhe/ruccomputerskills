#include <omp.h>
#include <stdio.h>


int main(){
    int a = 10;
#pragma omp parallel private(a)
{
    int id = omp_get_thread_num();
    printf("a = %d in thread %d.\n",
           a, id);
    a = 3;
}

printf("a = %d after parallel.\n", a);
return 0;
}

