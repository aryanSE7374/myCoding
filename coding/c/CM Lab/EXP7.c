#include <stdio.h>

double f(double x) {
    return 1 / (1 + x * x);
}

int main() {
    // printf("Aryan Shrivasatav , 67 , IT-B\n");
    // printf("Shivam Singh , 59 , IT-B\n");
    // printf("Author : Aniket \nIT-B , 06320803123\n");
    printf("SIMPSONS 1/3 METHOD\n");

    int a, b, n;

    printf("Enter the lower limit = ");
    scanf("%d", &a);

    printf("Enter the upper limit = ");
    scanf("%d", &b);

    printf("Enter the sub interval (it should be even) = ");
    scanf("%d", &n);

    double h = (b - a) / (double)n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }

    double integ = sum * h / 3.0;
    printf("The result is = %0.2lf", integ);

    return 0;
}
