#include <stdio.h>
#include <math.h>
double f(double x) {
    return 1 / (1 + x * x);
}
int main() {
    printf("TRAPEZOIDAL FORMULA\n");
    // printf("Author : Aryan Shrivastav \nIT-B , 06720803123\n");
    printf("Author : Aniket \nIT-B , 06320803123\n");

    double b, a, h, sum, integ;
    unsigned int n;

    printf("\nNumber of sub interval = ");
    scanf("%d", &n);

    b = 6;
    a = 0;
    h = (b - a) / n;
    sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        sum += 2 * (f(a + i * h));
    }

    integ = (h * sum) / 2.0;
    printf("\nRequired Integration = %0.2lf", integ);

    return 0;
}
