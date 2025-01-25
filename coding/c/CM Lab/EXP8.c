#include <stdio.h>

double f(double x) {
    return 1 / (1 + x * x);
}

int main() {
    // printf("Aryan Shrivasatav , 67 , IT-B\n");
    // printf("Shivam Singh , 59 , IT-B\n");
    // printf("Author : Aniket \nIT-B , 06320803123\n");
    printf("SIMPSON'S 3/8 METHOD\n");

    double b, a, n;

    printf("Enter the lower limit a = ");
    scanf("%lf", &a);

    printf("Enter the upper limit b = ");
    scanf("%lf", &b);

    printf("Enter the sub interval {multiple of 3} = ");
    scanf("%lf", &n);

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }

    double integ = (3 * sum * h) / 8;
    printf("The result = %lf", integ);

    return 0;
}
