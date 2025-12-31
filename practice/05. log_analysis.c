/* 
This program counts rapid changes in driving velocity log.

- Inputs:
    * Total numbers of driving log -> int n;

- Outputs:
    * Total counts of rapid increase/decrease event
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int n, vel, delta;
    int inc = 0, dec = 0;
    int* log;

    // // 1, 2, 3, 4. Get iterate count
    // printf("Input log counts: ");
    // scanf("%d", &n);

    // // allocate dynamic memory
    // log = (int*)malloc(sizeof(int) * n);

    // // 1. Input driving velocity log manually
    // for(int i = 0; i < n; i++) {
    //     scanf("%d", &vel);
    //     log[i] = vel;
    // }

    // // 2. Generate driving velocity log
    // srand(time(NULL));
    // for(int i = 0; i < n; i++) {
    //     vel = rand() % 100;
        // printf("velocity at %d: %d\n", i, vel);
        // log[i++] = vel;
    // }

    // 3, 4, 5. Generate driving velocity with fixed +/- slope at least 10 in a row
    srand(time(NULL));

    n = __INT_MAX__;
    log = (int*)malloc(sizeof(int) * 1024);

    // first log
    vel = rand() % 100;
    log[0] = vel;
    int mem = vel;
    printf("Velocity at 0: %d\n", vel);

    // second log
    vel = rand() % 100;
    log[1] = vel;
    mem = vel;
    printf("Velocity at 1: %d\n", vel);

    int count = 1;
    while (1) { 
        delta = log[count] - log[count - 1];

        if (delta > 0) { // increase phase
            for (int j = 0; j < rand() % 5 + 10 && count < n; j++) {
                vel = mem + rand() % 20 + 1;
                mem = vel;
                log[count++] = vel;
                printf("Velocity at %d: %d\n", count, vel);
            }
        }
        else if (delta < 0) { // decrease phase
            for (int j = 0; j < rand() % 5 + 10 && count < n; j++) {
                vel = mem - rand() % 20 - 1;
                mem = vel;
                log[count++] = vel;
                printf("Velocity at %d: %d\n", count, (vel < 0) ? 0 : vel);

                if (vel < 0) {
                    printf("Vehicle stopped. Terminate program.\n");
                    exit(0);
                }
            }
        }
        else {
            vel = rand() % 100 + 1;
            log[count++] = vel;
            printf("Velocity at %d: %d\n", count, vel);
        }
    }
    
    // Count rapid increase/decrease events
    for(int i = 0; i < n - 1; i++) {
        delta = log[i + 1] - log[i];
        if (delta >= 10)
            inc++;
        else if (delta<= -10)
            dec++;
    }

    // // Print the measured results
    // printf("Total rapid increase event count: %d\n", inc);
    // printf("Total rapid decrease event count: %d\n", dec);

    // delete dynamic memory
    free(log);
    
    return 0;
}