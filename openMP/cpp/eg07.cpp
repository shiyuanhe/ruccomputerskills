#include <omp.h>
#include <stdio.h>


int main(){
    int i,a = 99;
#pragma omp parallel for private(i) lastprivate(a)
for(i=0; i<10; i++)
    a = i;

printf("i = %d after parallel.\n", i);
printf("a = %d after parallel.\n", a);
return 0;
}

