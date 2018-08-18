#include <omp.h>
#include <stdio.h>

int main (int argc, char** argv) {
    #define MYSIZE 1024
	int arr[MYSIZE];
	int i;
	int numthreads = 8;
    #pragma omp parallel for default(none) shared(arr) num_threads(numthreads) private(i)
    for (i = 0; i < MYSIZE; i++) {
		arr[i] = i * 2;
		int tid = omp_get_thread_num();
		printf("Thread %d\n", tid);
	}
	return 0;
}
