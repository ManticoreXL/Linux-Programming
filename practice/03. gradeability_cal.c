/* 
This program calcuates the maximum traction and gradeability.

- Input:
    * Total mass (kg)                       -> double   mass;
    * Rated torque of the motor (Tm)        -> double   torque;
    * Total number of the driving motors    -> int      wheels;
    * Gear reduction ratio                  -> double   gear;
    * Motor driving efficienty (0-1)        -> double   eta;
    * Radius of the wheel (m)               -> double   radius;
    * Rolling resistance coefficient        -> double   c;
    * Safety factor (0-1)                   -> double   sf;

- Output:
    * Total avaliable traction (N)
    * Maximum climbing angle (degree)
    * Maximum gradeability (%)
*/


#include <stdio.h>
#include <math.h>


/**
 * @brief Clamps the input value within a specified minimum and maximum range.
 *
 * @param x      The input value to be checked.
 * @param lower  The lower bound of the allowed range.
 * @param upper  The upper bound of the allowed range.
 * @return double Returns x if it is within range, lower if x < lower, and upper if x > upper.
 */
double clip_val(double x, double lower, double upper) {
    if (x < lower) {
        return lower;
    } else if (x > upper) {
        return upper;
    } else {
        return x;
    }
}


int main(void) {

    double mass, torque, gear, eta, radius, c, sf;
    int wheels;

    const double g = 9.81;
    const double pi = 3.141592;

    // Get the specification
    printf("Total mass (kg): ");
    scanf("%lf", &mass);
    printf("Rated torque of the motor (Tm): ");
    scanf("%lf", &torque);
    printf("Total number of the driving motors: ");
    scanf("%d", &wheels);
    printf("Gear reduction ration: ");
    scanf("%lf", &gear);
    printf("Motor driving efficiency (0-1): ");
    scanf("%lf", &eta);
    printf("Radius of the wheel (m): ");
    scanf("%lf", &radius);
    printf("Rolling resistance coefficient: ");
    scanf("%lf", &c);
    printf("Safety margin: ");
    scanf("%lf", &sf);

    // Calculate total avaliable traction maximum climbing angle
    double t_tot = wheels * torque * gear * eta;

    // Calculate maximum climbing angle
    double f_avail = t_tot / radius;
    double sin_theta_max = clip_val(((f_avail / (sf * mass * g)) - c), 0, 1);
    double theta_max = asin(sin_theta_max);
    double max_degree = theta_max * 180 / pi;
    
    // Calculate maximum gradeability
    double grade = tan(theta_max) * 100;

    // Print the calculated results
    printf("Total avaliable traction (N): %.2lf\n", f_avail);
    printf("Maximum climbing angle (degrees): %.2lf\n", max_degree);
    printf("Maximum gradeability (grade %%): %.2lf\n", grade);

    return 0;
}