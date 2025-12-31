/* 
This program performs warning system considering hysteresis .

- Inputs:
    * Total numbers of battery level log -> int n;

- Outputs:
    * Print warning message considering hysteresis.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define OFF 0
#define ON 1

int main(void) {

    int n;
    double level, battery[100];
    int warning = OFF;

    // Get n
    printf("Input numbers of log: ");
    scanf("%d", &n);

    // // 1. Get battery level log manually
    // for (int i = 0; i < n; i++) {
    //     scanf("%lf", &battery[i]);
    //     if (warning == OFF & battery[i] <= 30)
    //         warning = ON;
    //     else if (warning == ON & battery[i] >= 35)
    //         warning = OFF;

    //     if (warning)
    //         printf("WARNING: Low battery level (%.2lf%%)\n", battery[i]);
    //     else
    //         printf("Battery level: %.2lf\n", battery[i]);
    // }

    // 2. Generate battery level log randomly
    srand(time(NULL));
    double sign = 1;
    double integer;
    double decimal;

    level = 50.0f;
    for (int i = 0; i < n; i++) {
        sign = (rand() % 2 == 0) ? 1 : -1;
        integer = (double)(rand() & 5);
        decimal = (double)rand() / RAND_MAX;

        level += sign * (integer + decimal);
        battery[i] = (level < 0) ? 0 : level;

        if (level < 0) {
            printf("Run out of battery. Terminate program.\n");
            break;
        }

        if (warning == OFF & level <= 30)
            warning = ON;
        else if (warning == ON & level >= 35)
            warning = OFF;

        if (warning)
            printf("WARNING: Low battery level (%.2lf%%)\n", level);
        else
            printf("Battery level: %.2lf\n", level);

        sleep(1);
    }
    
    return 0;
}