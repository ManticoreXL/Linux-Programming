/* 
This program determines the suitability of a Autonomous Mobile Rotot's motor.

- Input:
    * Total weight (kg)                 -> double   mass;
    * Total number of the wheel         -> int      wheels;
    * Safety factor                     -> double   sf;
    * Design margin                     -> double   margin;
    * Rated torque of the motor (N*m)   -> double   torque;
    * Gear reduction ratio              -> double   gear;
    * Radius of the wheel (m)           -> double   radius; 

- Output:
    * Minimum required traction (N)
    * Calcualated power of the motor (N)
    * Suitability of the given motor
*/


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
    printf("Gear reduction ratio (N*m): ");
    scanf("%lf", &gear);
    printf("Radius of the wheel (m): ");
    scanf("%lf", &radius);

    // Calculate towing power
    double w = mass * g;
    double f_min = c * w * sf * margin;
    double f_motor = (torque * gear / radius) * wheels;

    // Print minimum required towing power and calculated motor power
    printf("Minimum required towing power (N): %.2lf\n", f_min);
    printf("Calcualated power of the motor (N): %.2lf\n", f_motor);

    // print the validated results
    if (f_motor >= f_min) {
        printf("Satisfied. (The motor is enough for the payload.)\n");
    }
    else {
        printf("Unsuitable. (The more powerful motor or the less reduction ratio is required.)\n");
    }

    return 0;
}