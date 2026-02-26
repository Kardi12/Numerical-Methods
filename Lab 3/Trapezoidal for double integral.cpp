#include <stdio.h>
#include <math.h>

// Define the function to integrate
double f(double x, double y){
    return x*x + y*y;  // Example: f(x,y) = x^2 + y^2
}

int main(){
    double a, b, c, d;   // limits for x and y
    int n, m;            // number of subintervals in x and y
    double h, k;         // step sizes
    double x, y, sum = 0.0, res;
    int i, j;

    // Input limits
    printf("Enter lower limit for x (a): ");
    scanf("%lf", &a);
    printf("Enter upper limit for x (b): ");
    scanf("%lf", &b);
    printf("Enter lower limit for y (c): ");
    scanf("%lf", &c);
    printf("Enter upper limit for y (d): ");
    scanf("%lf", &d);

    // Input number of subintervals
    printf("Enter number of subintervals in x (n): ");
    scanf("%d", &n);
    printf("Enter number of subintervals in y (m): ");
    scanf("%d", &m);

    h = (b - a) / n;
    k = (d - c) / m;

    // Double loop for trapezoidal rule
    for(i = 0; i <= n; i++){
        x = a + i*h;
        for(j = 0; j <= m; j++){
            y = c + j*k;

            // Determine weight for corners, edges, and interior
            double weight = 1.0;
            if((i == 0 || i == n) && (j == 0 || j == m))        // corners
                weight = 1.0;
            else if(i == 0 || i == n || j == 0 || j == m)       // edges
                weight = 2.0;
            else                                                 // interior
                weight = 4.0;

            sum += weight * f(x, y);
        }
    }

    // Multiply by (h*k)/4 for 2D trapezoidal rule
    res = (h * k / 4.0) * sum;

    printf("Approximate value of double integral = %.6lf\n", res);
    return 0;
}

