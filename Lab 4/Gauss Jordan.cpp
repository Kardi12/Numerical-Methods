#include<stdio.h>
#define MAX 10

int main(){
    int n,i,j,k;
    float a[MAX][MAX+1], ratio;

    printf("\n--- Gauss Jordan Method ---\n");
    printf("Enter number of variables: ");
    scanf("%d",&n);

    printf("Enter the augmented matrix coefficients:\n");
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            printf("a[%d][%d]: ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for(i=0;i<n;i++){
        
        if(a[i][i] == 0.0){
            printf("Mathematical Error (Zero Pivot).\n");
            return 0;
        }

        
        float pivot = a[i][i];
        for(j=0;j<=n;j++){
            a[i][j] = a[i][j] / pivot;
        }

        for(k=0;k<n;k++){
            if(k != i){
                ratio = a[k][i];
                for(j=0;j<=n;j++){
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    printf("\nSolution:\n");
    for(i=0;i<n;i++){
        printf("x%d = %.3f\n",i+1,a[i][n]);
    }

    return 0;
}
