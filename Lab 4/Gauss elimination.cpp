#include<stdio.h>
#include<math.h>
#define MAX 10

int main() {
    int n, i, j, k;
    float a[MAX][MAX], x[MAX], ratio, sum;

	printf("---Gauss Elimination Method---\n");
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("\nEnter coefficients of augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
        	printf("a[%d][%d]: ",i+1,j+1);
            scanf("%f", &a[i][j]);
        }
    }

    // Forward elimination
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];

            for(k = 0; k <= n; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for(i = n - 2; i >= 0; i--) {
        sum = 0;
        for(j = i + 1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i + 1, x[i]);
    }

    return 0;
}

