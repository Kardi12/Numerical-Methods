#include<stdio.h>
#include<math.h>

double f(double x){
	return exp(-x*x);
}

int main(){
	double a,b,h,sum=0.0,res;
	
	printf("\n---Simpson's 3/8 Rule---\n");
	printf("Enter the lower limit (a):");
	scanf("%lf",&a);
	
	printf("Enter the upper limit (b): ");
	scanf("%lf",&b);
	

	h=(b-a)/3.0;
	res=(3*h/8)*(f(a)+3*f(a+h)+3*f(a+2*h)+f(b));
	printf("Approximation value of integral = %.5lf\n",res);
return 0;
}
