#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define A 4
#define B 1
#define C 100

double angle_between_slopes(double slope1, double slope2);
double find_new_slope(double x, double y, double slope);
double new_x(double init_x, double init_y, double slope);

int main(void) {
    int hits = 1;
    double x = 1.4;
    double y = -9.6;
    double slope = (10.1 + 9.6) / -1.4;
    bool done = false;
    
    while(!done)  {
        double new_slope = find_new_slope(x, y, slope);
        double x1 = new_x(x, y, new_slope);
        double y1 = new_slope * (x1 - x) + y;
        if (x1 <= 0.01 && x1 >= -0.01 && y1 > 0)
            done = true;
        else {
            x = x1;
            y = y1;
            slope = new_slope;
            hits++;
        }
    }
    printf("%d\n", hits);
}


 double angle_between_slopes(double slope1, double slope2) {
    float theta = atan((slope1 - slope2) / (1 + slope1 * slope2));
    return fabs(theta);
}

 double find_new_slope(double x, double y, double slope) {
    double tangent_slope = (-1 * A * x) / (B * y);
    double diff_angle = angle_between_slopes(tangent_slope, slope);
    double tangent_angle = atanl(tangent_slope);
    double slope_angle = atanl(slope);
    if (fabs((tangent_angle - diff_angle) - slope_angle) > 0.001)
        return tan(tangent_angle - diff_angle);
    else
        return tan(tangent_angle + diff_angle);
}

double new_x(double init_x, double init_y, double slope) {
    double k = -1 * slope * init_x + init_y;
    double v1 = A + B * slope * slope;
    double v2 = 2 * B * k * slope;
    double v3 = B * k * k - C;
    
    double discriminant = sqrtl(v2 * v2 - 4 * v1 * v3);
    double x1 = (-1 * v2 + discriminant) / (2 * v1);
    double y1 = slope * (x1 - init_x) + init_y;
    if (fabs(init_x - x1) > 0.1 || fabs(init_y - y1) > 0.1)
        return x1;
    else
        return (-1 * v2 - discriminant) / (2 * v1);
}
