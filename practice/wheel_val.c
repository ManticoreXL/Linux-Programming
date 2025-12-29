#include <stdio.h>
#include <math.h>

int main(void) {

    double mass, radius, height, p_m;
    int wheels;

    // Get AMR's specification
    printf("Total weight (kgf): ");
    scanf("%lf", &mass);
    printf("Radius of the caster (cm): ");
    scanf("%lf", &radius);
    printf("Height of the bump (cm): ");
    scanf("%lf", &height);
    printf("Rated torque of the motor (kgf-cm): ");
    scanf("%lf", &p_m);
    printf("Total number of the wheel: ");
    scanf("%d", &wheels);

    // Calculate moments
    double w = mass / wheels;
    double p = (w * pow(pow(radius, 2) - pow(height, 2), 0.5) / (radius - height));
    double m_w = (w * pow(pow(radius, 2) - pow(height, 2), 0.5));
    double m_p = p * (radius - height);

    // Print the calculated moments
    printf("Required minimal torque: %.2lf\n", p);
    printf("Moment by its weight: %.2lf\n", m_w);
    printf("Required moment to overcome the bump: %.2lf\n", m_p);

    // Print the validated result 
    if ((p_m >= p) && (m_p >= m_w))
        printf("Satisfied. The vehicle is enough to overcome the bump.\n");
    else
        printf("Unsuitable. The more powerful motor is required.\n");

    return 0;
}