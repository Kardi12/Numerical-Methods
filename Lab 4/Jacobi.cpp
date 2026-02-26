#include<stdio.h>
#include<math.h>
#define MAX 10
#define MAX_ITR 100

int main(){
	int n,i,j,itr=0;
	float a[MAX][MAX],b[MAX],x[MAX],x_new[MAX],eps=0.0001,error;
	printf("\n------JACOBI MEHTOD-----\n");
    printf("Enter the number of variables: ");
    scanf("%d",&n);
    
    printf("Enter the coefficient: \n");
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		printf("a[%d][%d]: ",i+1,j+1);
    		scanf("%f",&a[i][j]);
		}
	}
	printf("Enter the constant terms: \n");
	for(i=0;i<n;i++){
		printf("b[%d]: ",i+1);
		scanf("%f",&b[i]);
	}
	
	for(i=0;i<n;i++){
		x[i]=0;
	}
	
 // Iteration
    do{
         error = 0;

        for(i=0;i<n;i++){
            float sum = 0;
            for(j=0;j<n;j++){
                if(j != i){
                    sum += a[i][j] * x[j];
                }
            }

            x_new[i] = (b[i] - sum) / a[i][i];

            if(fabs(x_new[i] - x[i]) > error){
                error = fabs(x_new[i] - x[i]);
            }
        }

        for(i=0;i<n;i++){
            x[i] = x_new[i];
        }

        itr++;

    }while(error > eps && itr < MAX_ITR);

    printf("\nSolution:\n");
    for(i=0;i<n;i++){
        printf("x%d = %.4f\n", i+1, x[i]);
    }

    printf("Number of iterations: %d\n", itr);

    return 0;
}
