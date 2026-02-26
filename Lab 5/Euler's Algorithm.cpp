#include<stdio.h>

// function dy/dx = f(x,y)
float f(float x, float y)
{
    return x + y;
}

int main()
{
    float x0=0, y0=1, xn=0.4, h;
    int steps,i;

    printf("Euler Method\n");
    printf("Enter step size h: ");
    scanf("%f",&h);

    steps=(xn-x0)/h;

    printf("\nStep\tx\ty\n");
    printf("0\t%.2f\t%.4f\n",x0,y0);

    for(i=1;i<=steps;i++)
    {
        y0 = y0 + h*f(x0,y0);
        x0 = x0 + h;

        printf("%d\t%.2f\t%.4f\n",i,x0,y0);
    }

    printf("\nApproximate value at x=%.2f is y=%.4f\n",xn,y0);

    return 0;
}

