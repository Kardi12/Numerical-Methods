#include <stdio.h>
#include <math.h>

double f(double x) {
    return exp(x);   // Change the function if needed
}

int main() {
    double a, b,h, res;

	printf("---Trapezoidal Rule---\n");
    printf("Enter lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter upper limit (b): ");
    scanf("%lf", &b);

  	h=(b-a)/2;
    // Trapezoidal rule formula: (b - a)/2 * [f(a) + f(b)]
    res = h * (f(a) + f(b)) / 2.0;

    printf("Approximate value of integral = %.5lf\n", res);

    return 0;
}

