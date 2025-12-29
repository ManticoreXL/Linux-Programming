#include <stdio.h>
#include <math.h>

int main(void) {

    double x, y;

    // Get x and y
    printf("Input x: ");
    scanf("%lf", &x);
    printf("Input y: ");
    scanf("%lf", &y);

    // Print outputs from math functions
    printf("sqrt(x): %lf\n", sqrt(x));
    printf("pow(x, y): %lf\n", pow(x, y));
    printf("sin(x): %lf\n", sin(x));
    printf("cos(x): %lf\n", cos(x));
    printf("tan(x): %lf\n", tan(x));
    printf("fabs(x): %lf\n", fabs(x));

    return 0;
}