#include <stdio.h>

int main(void) {

    double mass, wheels, sf, margin;
    double torque, gear, radius;
    int wheels;

    const double g = 9.81;  // gravitational acceleration
    const double c = 0.018; // rolling resistance coefficient

    // Get AMR's specification
    printf("Total payload weight (kg): ");
    scanf("%lf", &mass);
    printf("Total number of the wheel: ");
    scanf("%d", &wheels);
    printf("Safety factor: ");
    scanf("%lf", &sf);
    printf("Design Margin (1.2 recommeded): ");
    scanf("%lf", &margin);

    // Get specifications of motors and wheels
    printf("Rated torque of the motor: ");
    scanf("%lf", &torque);
    printf("Rated gear ratio (N*m): ");
    scanf("%lf", &gear);
    printf("Total radius of the wheel (m): ");
    scanf("%lf", &radius);

    // Calculate towing power
    double w = mass * g;
    double f_min = c * w * sf * margin;
    double f_motor = (torque * gear / radius) * wheels;

    // Print minimum required towing power and calculated motor power
    printf("Required towing power at least: %.2lf\n", f_min);
    printf("The maximum towing power of the motor: %.2lf\n", f_motor);

    // print the validation result
    if (f_motor >= f_min) {
        printf("Satisfied. (The motor is enough for the payload.)\n");
    }
    else {
        printf("Unsuitable. (The more powerful motor or the less reduction ratio is required.)\n");
    }

    return 0;
}