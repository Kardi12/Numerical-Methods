#include<stdio.h>
#include<math.h>

#define MAX 10
#define EPS 0.0001
#define MAX_ITER 100

int main()
{
    int n,i,j,iter;
    float A[MAX][MAX], X[MAX], Y[MAX];
    float lambda_old=0, lambda_new=0, error;

    printf("Power Method to find Largest Eigen Value\n");

    printf("Enter order of matrix: ");
    scanf("%d",&n);

    // Input matrix
    printf("Enter matrix elements:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++){
        	printf("A[%d][%d]:",i+1,j+1);
            scanf("%f",&A[i][j]);
		}
        
    }

    // Initial guess vector
    for(i=0;i<n;i++){
    	X[i]=1;
	}
        

    // Iteration
    for(iter=1; iter<=MAX_ITER; iter++)
    {
        // Y = A * X
        for(i=0;i<n;i++)
        {
            Y[i]=0;
            for(j=0;j<n;j++)
                Y[i]+=A[i][j]*X[j];
        }

        // Find largest absolute value (eigen value)
        lambda_new=fabs(Y[0]);
        for(i=1;i<n;i++)
            if(fabs(Y[i])>lambda_new)
                lambda_new=fabs(Y[i]);

        // Normalize vector
        for(i=0;i<n;i++)
            X[i]=Y[i]/lambda_new;

        // Error
        error=fabs(lambda_new-lambda_old);
        if(error<EPS)
            break;

        lambda_old=lambda_new;
    }

    printf("\nLargest Eigen Value = %.4f\n",lambda_new);

    printf("Corresponding Eigen Vector:\n");
    for(i=0;i<n;i++)
        printf("x%d = %.4f\n",i+1,X[i]);

    printf("Iterations = %d\n",iter);

    return 0;
}

