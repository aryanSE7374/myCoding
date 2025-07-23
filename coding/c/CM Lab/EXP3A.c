#include <stdio.h>
#include <math.h>

double func(double x) {
    return 3 * x - cos(x) - 1;
}

double derivFunc(double x) {
    return 3 + sin(x);
}

int main() {
    printf("Aniket , 63 , IT-B\n");
    double x0, x1;
    double epsilon = 0.0000001;
    int maxitr, i = 1;

    printf("Newton-Raphson Method\n");

    printf("Enter x0: ");
    scanf("%lf", &x0);

    printf("Enter maximum number of iterations: ");
    scanf("%d", &maxitr);

    while (i <= maxitr) {
        x1 = x0 - (func(x0) / derivFunc(x0));
        if (fabs(x1 - x0) < epsilon) {
            printf("Root found at x = %lf\n", x1);
            break;
        }
        x0 = x1;
        printf("Iteration %d: x = %lf, f(x) = %lf\n", i, x0, func(x0));
        i++;
    }

    if (i > maxitr) {
        printf("Root not found within %d iterations\n", maxitr);
    }

    return 0;
}