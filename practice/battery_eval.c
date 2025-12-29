#include <stdio.h>

int main(void) {

    double i_load, vel, R;
    double V, C, eta;

    // Get environment information
    printf("Average current load (A): ");
    scanf("%lf", &i_load);
    printf("Average velocity (km/h): ");
    scanf("%lf", &vel);
    printf("Remaining percent (0-1)): ");
    scanf("%lf", &R);

    // exception catch for R
    if((i_load < 0) || (vel < 0) || (R > 1) || (R < 0)) {
        printf("The range of R must be in [0, 1].\n");
        return -1;
    }

    // Get battery information
    printf("Factory voltage(V): ");
    scanf("%lf", &V);
    printf("Total capacity (Ah): ");
    scanf("%lf", &C);
    printf("System efficiency = eta (0-1): ");
    scanf("%lf", &eta);

    // exception catch for eta
    if((V < 0) || (C < 0) || (eta > 1) || (eta < 0)) {
        printf("The range of eta must be in [0, 1].\n");
        return -1;
    }
    
    // Calculate usable energy, power consumption, runtime, distance
    double e_u = V * C * eta * (1 - R);
    double p = (V * i_load) / eta;
    double t = e_u / p;
    double d = vel * t;

    // Print the calculated results
    printf("Total usable energy (Wh): %.2lf\n", e_u);
    printf("Power consumption (W): %.2lf\n", p);
    printf("Total runtime (h): %.2lf\n", t);
    printf("Total range (km): %.2lf\n", d);

    return 0;
}