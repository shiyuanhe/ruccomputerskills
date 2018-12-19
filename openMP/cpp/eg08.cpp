#include <stdio.h>
#include <omp.h>

int main(){
    double a;
#pragma omp parallel shared(a) 
{
    int id = omp_get_thread_num();
    a = id;
    for(int i=0; i<100; i++);  //a loop doing nothing
    printf("Thread %d has a =  %f\n",
           id, a);
}
return 0;
}
