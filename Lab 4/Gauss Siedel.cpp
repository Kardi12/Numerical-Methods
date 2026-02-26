#include<stdio.h>
#include<math.h>

#define MAX 10
#define EPS 0.0001     // tolerance
#define MAX_ITER 100

int main()
{
    int n,i,j,iter;
    float a[MAX][MAX], b[MAX], x[MAX]={0}, old[MAX], sum, error;

    printf("Gauss-Seidel Method\n");

    printf("Enter number of variables: ");
    scanf("%d",&n);

    // Input coefficients
    printf("Enter coefficient matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
        	printf("a[%d][%d]:",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }

    // Input constants
    printf("Enter constant terms:\n");
    for(i=0;i<n;i++)
        scanf("%f",&b[i]);

    // Iteration
    for(iter=1; iter<=MAX_ITER; iter++)
    {
        for(i=0;i<n;i++)
            old[i]=x[i];

        for(i=0;i<n;i++)
        {
            sum=b[i];
            for(j=0;j<n;j++)
            {
                if(i!=j)
                    sum=sum-a[i][j]*x[j];
            }
            x[i]=sum/a[i][i];
        }

        // Calculate error
        error=0;
        for(i=0;i<n;i++)
            error=fmax(error,fabs(x[i]-old[i]));

        if(error<EPS)
            break;
    }

    printf("\nSolution after %d iterations:\n",iter);
    for(i=0;i<n;i++)
        printf("x%d = %.4f\n",i+1,x[i]);

    return 0;
}

