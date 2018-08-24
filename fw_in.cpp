#include <cstdio>
#include <cstdlib>
#include <omp.h>

using namespace std;

#define MAX 10000
#define NOT_CONNECTED -1

int distance[MAX][MAX];
int nodesCount;
int numthreads = 1;

void initialize() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            distance[i][j] = NOT_CONNECTED;

        }
        distance[i][i] = 0;
    }
}


int main(int argc, char** argv){

    if (argc < 2) {
        printf("The path to the input file is not specified as a parameter.\n");
        return -1;
    }
    //if (argc == 3) {
    //    numthreads = atoi(argv[2]);
    //    if (numthreads < 1) {
    //        printf("Very cheeky!\n");
    //        numthreads = 1;
    //    }
    //}

    FILE *in_file  = fopen(argv[1], "r");
    if (in_file == NULL)
    {
        printf("Can't open file for reading.\n");
        return -1;
    }

    initialize();

    fscanf(in_file,"%d", &nodesCount);

    int a, b, c;
    while (fscanf(in_file, "%d %d %d", &a, &b, &c) != EOF) {
        if (a > nodesCount || b > nodesCount) {
            printf("Vertex index out of boundary.");
            return -1;
        }
        distance[a][b] = c;
    }

    //Floyd-Warshall
    int i, j, k;


    double startTime = omp_get_wtime();
    if (i >= 100) {
		numthreads = 8;
	} else if (i >= 50) {
		numthreads = 4;
	}
    for (k = 1; k <= nodesCount; ++k) {
        #pragma omp parallel for schedule(dynamic) private(i, j) num_threads(numthreads)
        for (i = 1; i <= nodesCount; ++i) {
			if (distance[i][k])
            for (j = 1; j <= nodesCount; ++j) {
                    if (distance [i][k] != NOT_CONNECTED && distance[k][j] != NOT_CONNECTED && (distance[i][j] == NOT_CONNECTED || distance[i][k] + distance[k][j] < distance[i][j])) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
            }
        }
    }

    int diameter = -1;

    //look for the most distant pair
    for (int i=1; i <= nodesCount; ++i) {
        for (int j = 1; j <= nodesCount; ++j) {
            if (diameter < distance[i][j]) {
                diameter = distance[i][j];
                //printf("%d-%d-%d\n", i, diameter, j);
            }
        }
    }
    double now = omp_get_wtime();
    //printf("%d,%d,%f,%d\n", numthreads, nodesCount, (now - startTime) * 1000, diameter);
	printf("%d %.16g\n", diameter, (now - startTime));

    return 0;

}
