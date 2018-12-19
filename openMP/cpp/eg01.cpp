#include <stdio.h>
#include <omp.h>
 
int main() {
    int total = omp_get_max_threads();
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Greetings from process %d out of %d.\n", id, total);
    }

    int prod = 1;
    int i;
#prgma omp parallel for reduction(*: prod) private(i) schedule(static)
    for(i = 1; i <= n; i++)
	prod *= i;
    
    printf("Parallel ends.\n");
  return 0;
}
y
