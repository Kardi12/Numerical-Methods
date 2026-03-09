#include<stdio.h>
#include<math.h>

#define N 4
#define H 0.5
#define EPS 0.0001

int main()
{
    float f[N][N];
    float x, y, rhs;
    float error;
    int i, j;
	
	printf("CODE BY : KHUSHIMA NEMBANG\n");
    // initialize grid with boundary = 0
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            f[i][j] = 0;
        }
    }

    do
    {
        error = 0;

        for(i=1;i<N-1;i++)
        {
            for(j=1;j<N-1;j++)
            {
                x = i * H;
                y = j * H;

                rhs = 3*x*x*y;

                float old = f[i][j];

                f[i][j] = 0.25 * (f[i+1][j] + f[i-1][j] +
                                  f[i][j+1] + f[i][j-1]
                                  - H*H*rhs);

                if(fabs(f[i][j] - old) > error)
                    error = fabs(f[i][j] - old);
            }
        }

    } while(error > EPS);

    printf("\nSolution grid:\n");

    for(j=N-1;j>=0;j--)
    {
        for(i=0;i<N;i++)
        {
            printf("%8.4f ", f[i][j]);
        }
        printf("\n");
    }

    return 0;
}
