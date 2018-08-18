#include <cstdio>
#include <omp.h>

using namespace std;

#define MAX 10000
#define NOT_CONNECTED -1

int distance[MAX][MAX];

int nodesCount;

void initialize() {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            distance[i][j] = NOT_CONNECTED;

        }
        distance[i][i] = 0;
    }
}


int main(int argc, char** argv){

    if (argc != 2) {
        printf("The path to the input file is not specified as a parameter.\n");
        return -1;
    }
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
	double startTime = omp_get_wtime();
	int numthreads = 16;
	int i, j, k;
	bool printed = false;
    #pragma omp parallel for default(none) shared(distance, nodesCount) private(i, j, k, printed) num_threads(numthreads)
    for (k = 1; k <= nodesCount; ++k) {
		if (!printed) {
			printf("%d", omp_get_thread_num());
			printed = true;
		}
        for (i = 1; i <= nodesCount; ++i) {
            if (distance[i][k] != NOT_CONNECTED) {
                for (j = 1; j <= nodesCount; ++j) {
                    if (distance[k][j] != NOT_CONNECTED && (distance[i][j] == NOT_CONNECTED || distance[i][k] + distance[k][j] < distance[i][j])) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
    }

	double now = omp_get_wtime();
	printf("Took %fms to calculate distances\n", (now - startTime) * 1000);

    int diameter=-1;

    //look for the most distant pair
    for (int i=1;i<=nodesCount;++i){
        for (int j=1;j<=nodesCount;++j){
            if (diameter<distance[i][j]){
                diameter=distance[i][j];
                //printf("%d-%d-%d\n", i, diameter, j);
            }
        }
    }

	now = omp_get_wtime();
	printf("Took %fms to find the most distant\n", (now - startTime) * 1000);

    printf("%d\n", diameter);

    return 0;

}
