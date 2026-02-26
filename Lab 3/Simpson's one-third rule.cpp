#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x);   // change function if needed
}

int main() {
    double a, b, h, result;

	printf("---Simpson's 1/3 Rule---\n");
    printf("Enter lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter upper limit (b): ");
    scanf("%lf", &b);

    // For simple Simpson rule:
    h = (b - a) / 2.0;

    result = (h / 3.0) * ( f(a) + 4 * f(a + h) + f(b) );

    printf("Approximate value of integral = %.5lf\n", result);

    return 0;
}

