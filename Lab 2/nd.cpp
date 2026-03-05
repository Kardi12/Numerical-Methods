#include <stdio.h>

int main() {
    int n, i, j;
    float x[10], y[10], diff[10][10], xp, p, term;

    printf("Enter number of observations: ");
    scanf("%d", &n);

    printf("\nEnter the data:\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("f(x[%d]) = ", i);
        scanf("%f", &y[i]);
        diff[i][0] = y[i];   // a0 = F[x0]
    }

    // Divided difference table
    for(j = 1; j < n; j++) {
        for(i = 0; i < n - j; i++) {
            diff[i][j] = (diff[i+1][j-1] - diff[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    printf("\nEnter the value of x to interpolate: ");
    scanf("%f", &xp);

    // Newton polynomial evaluation
    p = diff[0][0];   // a0
    term = 1;

    for(i = 1; i < n; i++) {
        term = term * (xp - x[i-1]);
        p = p + diff[0][i] * term;
    }

    printf("\nInterpolated value at x = %.3f is %.3f\n", xp, p);

    return 0;
}

