#include <iostream>
#include <omp.h>
using namespace std;

int main() {
int total = omp_get_num_threads();
#pragma omp parallel
{
    int id = omp_get_thread_num();
    cout << "Greetings from process " <<
        id << " out of " << total << endl;
}
return 0;
}
