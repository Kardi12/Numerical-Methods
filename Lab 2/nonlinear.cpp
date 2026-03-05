#include <stdio.h>
#include <math.h>
int n;
float x[50], y[50];

float f(float b) {
    float num = 0, den = 0, sum1 = 0, sum2 = 0;
    int i;

    for(i = 0; i < n; i++) {
        num += y[i] * exp(b * x[i]);
        den += exp(2 * b * x[i]);
    }

    float a = num / den;

    for(i = 0; i < n; i++) {
        sum1 += x[i] * y[i] * exp(b * x[i]);
        sum2 += x[i] * exp(2 * b * x[i]);
    }

    return sum1 - a * sum2;
}

int main() {
    int i;
    float b1, b2, bm, err = 0.0001;
    
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points(x,y):\n");
    for(i = 0; i < n; i++){
    	 scanf("%f %f", &x[i],&y[i]);
	}
       

    printf("Enter initial guesses b1 and b2: ");
    scanf("%f %f", &b1, &b2);

    if (f(b1) * f(b2) > 0) {
        printf("Invalid initial guesses. f(b1) and f(b2) should have opposite signs.\n");
        return 0;
    }

    do {
        bm = (b1 + b2) / 2;
        if (f(b1) * f(bm) < 0)
            b2 = bm;
        else
            b1 = bm;
    } while (fabs(b2 - b1) > err);

    float num = 0, den = 0, a;
    for(i = 0; i < n; i++) {
        num += y[i] * exp(bm * x[i]);
        den += exp(2 * bm * x[i]);
    }
    a = num / den;

    printf("\nValue of b = %.6f\n", bm);
    printf("Value of a = %.6f\n", a);
    printf("Regression equation: y = %.6f * e^(%.6f * x)\n", a, bm);

    return 0;
}
