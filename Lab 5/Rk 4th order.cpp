#include<stdio.h>

// dy/dx = x + y
float f(float x, float y)
{
    return x + y;
}

int main()
{
    float x0=0, y0=1, xn=0.4, h;
    float k1,k2,k3,k4;
    int steps,i;

    printf("Runge Kutta 4th Order Method\n");
    printf("Enter step size h: ");
    scanf("%f",&h);

    steps=(xn-x0)/h;

    printf("\nStep\tx\ty\n");
    printf("0\t%.2f\t%.6f\n",x0,y0);

    for(i=1;i<=steps;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);

        y0=y0+(k1+2*k2+2*k3+k4)/6;
        x0=x0+h;

        printf("%d\t%.2f\t%.6f\n",i,x0,y0);
    }

    printf("\nApproximate value at x=%.2f is y=%.6f\n",xn,y0);

    return 0;
}

