/* 
This program detect all directions and print the most closet dist and degree.

- Inputs:
    * Random input.

- Outputs:
    * The most 3 closest distance and its degree.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <float.h>

#define COUNT 3

int main(void) {
    srand(time(NULL));

    double *dist;
    int *min_i;;
    double *min_v;

    while (1) {
        dist = (double*)malloc(sizeof(double) * 360);
        min_i = (int*)malloc(sizeof(int) * COUNT);
        min_v = (double*)malloc(sizeof(int) * COUNT);

        for (int i = 0; i < COUNT; i++) {
            min_i[i] = -1;
            min_v[i] = DBL_MAX;
        }

        for (int i = 0; i < 360; i++) {
            dist[i] = (rand() % 399 + 100) + ((double)rand() / RAND_MAX);
        }

        for (int i = 0; i < 360; i++) {
            for (int j = 0; j < COUNT; j++) {
                if (dist[i] < min_v[j]) {
                    for (int k = COUNT - 2; k > j; k--) {
                        min_v[k] = min_v[k - 1];
                        min_i[k] = min_i[k - 1];
                    }
                    min_v[j] = dist[i];
                    min_i[j] = i;
                    break;
                }
            }
        }

        printf("--- Result ---\n");
        printf("The most closest distance (TOP %d): ", COUNT);
        for (int i = 0; i < COUNT; i++) {
            printf("%.2lf ", min_v[i]);
        }
        printf("\n");

        printf("The direction to the obstacle (TOP %d): ", COUNT);
        for (int i = 0; i < COUNT; i++) {
            printf("%d ", min_i[i]);
        }
        printf("\n");

        free(dist);
        free(min_i);
        free(min_v);

        sleep(1);
    }

    return 0;
}