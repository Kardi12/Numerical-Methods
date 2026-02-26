#include<stdio.h>
#include<math.h>

double f(double x){
	return exp(-x/2);
}

int main(){
	double a,b,x1,x2,res;
	printf("---Gaussian Integration---\n");
	printf("Enter the lower limit (a): ");
	scanf("%lf",&a);
	
	printf("Enter the upper limit (b):");
	scanf("%lf",&b);
	
	//transformed Gauss Points
	x1=((b-a)/2.0)*(-1.0/sqrt(3.0))+(a+b)/2.0;
	x2=((b-a)/2.0)*(1.0/sqrt(3.0))+(a+b)/2.0;
	
	res=((b-a)/2.0)*(f(x1)+f(x2));
	
	printf("Approximation value of integral = %.5lf\n",res);
return 0;	
}
