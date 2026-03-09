#include<stdio.h>
#include<math.h>

#define N 4
#define EPS 0.001

int main()
{
    float u[N][N];
    int i,j;
    float error;

	printf("CODE BY : KHUSHIMA NEMBANG\n");
    // Initialize grid
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            u[i][j] = 0;
        }
    }

   // bottom and top
	for(i=0;i<N;i++)
	{
    u[i][0] = 100;
    u[i][N-1] = 200;
		}

	// left and right (excluding corners)
	for(j=1;j<N-1;j++)
	{
    u[0][j] = 200;
    u[N-1][j] = 100;
	}

    // Gauss-Seidel iteration
    do
    {
        error = 0;

        for(i=1;i<N-1;i++)
        {
            for(j=1;j<N-1;j++)
            {
                float old = u[i][j];

                u[i][j] = 0.25 * (u[i+1][j] + u[i-1][j] +
                                  u[i][j+1] + u[i][j-1]);

                if(fabs(u[i][j] - old) > error)
                    error = fabs(u[i][j] - old);
            }
        }

    } while(error > EPS);

    printf("\nSolution grid:\n");

    for(j=N-1;j>=0;j--)
    {
        for(i=0;i<N;i++)
        {
            printf("%8.2f ", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}
