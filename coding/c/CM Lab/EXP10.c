#include <stdio.h>

double f(double x, double y) {
    return x + y;
}

int main() {
    // printf("Aryan Shrivasatav , 67 , IT-B\n");
    // printf("Shivam Singh , 59 , IT-B\n");
    printf("Author : Aniket \nIT-B , 06320803123\n");
    printf("RUNGE KUTTA METHOD\n");
    printf("\ndy/dx = x + y\n");

    double x0, y0, xn, h;

    printf("Enter the initial condition:\n");
    printf("x0 = ");
    scanf("%lf", &x0);
    printf("y0 = ");
    scanf("%lf", &y0);

    printf("Enter the calculation point xn = ");
    scanf("%lf", &xn);

    printf("Enter the step size h = ");
    scanf("%lf", &h);

    double x = x0;
    double y = y0;

    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x = x + h;
    }

    printf("The value of y at x = %lf is %lf\n", xn, y);

    return 0;
}
