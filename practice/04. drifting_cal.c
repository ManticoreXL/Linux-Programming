/* 
This program estimates straight line deviation in AMR due to wheel radius error.

- Input:
    * Radius of the wheel (m)               -> double radius;
    * Track width of the wheel (m)          -> double width;
    * Error rate of both wheels (error %)   -> double e_left, e_right;
    * Target driving distance (m)           -> double L;

- Output:
    * Effective radius of both wheels (m)
    * Radius of curvature R_c (m)
    * Drift angle Delta (degree)
    * Total drifting distance d_dritf (m)
*/


#include <stdio.h>
#include <math.h>


int main(void) {

    double radius, width, e_left, e_right, L;

    const double pi = 3.14;

    // Get specification
    printf("Radius of the wheel (m): ");
    scanf("%lf", &radius);
    printf("Track width of the wheel (m): ");
    scanf("%lf", &width);
    printf("Error rate of the left wheel (error %%): ");
    scanf("%lf", &e_left);
    printf("Error rate of the right wheel (error %%): ");
    scanf("%lf", &e_right);
    printf("Target driving distance (m): ");
    scanf("%lf", &L);

    // Calculate effective radius of both wheels
    double r_left = radius * (1 + e_left / 100);
    double r_right = radius * (1 + e_right / 100);
    
    // Calcualte radius of curvature 
    double R_c = ((width * (r_left + r_right)) / (2 * fabs(r_right - r_left)));

    // Calculate drift angle delta
    double delta = L / R_c;
    double delta_degree = delta * 180 / pi;

    // Approximate drift disance d_drift
    double d_drift = R_c * (1 - cos(delta));

    // Print the calculated results
    printf("The effective radius of both wheels - left: %.4lf m / right: %.4lf m\n", r_left, r_right);
    printf("Calculated radius of curvature: %.2lf m\n", R_c);
    printf("Driving angle delta: %.2lf deg\n", delta_degree);
    printf("Approximated drifting distance: %.2lf m\n", d_drift);

   return 0;
}