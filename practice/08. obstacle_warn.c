/* 
This program detects the length between the obstacle and the robot in real-time.


- Inputs:
    * Total number of sensor inputs.
    * Sensor input at each time step.

- Outputs:
    * Obstacle warning.
    * Current velocity of the robot.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


int main(void) {

    int n;
    int *d;

    double v = 100.0f;

    printf("Insert total number of input: ");
    scanf("%d", &n);

    d = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        printf("Insert distance at %d: ", i);
        scanf("%d", &d[i]);
    }

    printf("--- Result ---\n");

    for (int i = 0; i < n; i++) {
        printf("- Time step [%d] : ", i);

        if (d[i] <= 10) {
            printf("WARNING: Obstacle detected. Vehicle stopped.\n");
            v = 0;
        }
        else if (d[i] <= 30) {
            printf("Warning. Obstacle detected. Recommend stopping the vehicle.\n");
            v *= 0.80;
        }
        else if (d[i] <= 50) {
            printf("Warning. Obstacle detected. Recomment stopping the vehicle.\n");
            v *= 0.50;
        }
        else {
            printf("No obstacle detected.\n");
            v += (v < 100) ? 10 : 0;
        }

        printf("-- Current velocity = %.2lf\n", v);
    }

    free(d);

    return 0;
}