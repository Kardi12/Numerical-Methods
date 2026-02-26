#include<stdio.h>
#include<math.h>

double f(double x){
	return exp(x);
}

int main(){
	double a,b,h,sum=0.0,res;
	int n,i;
	
	printf("---Composite Trapezoidal Rule---\n");
	printf("Enter lower limit (a): ");
	scanf("%lf",&a);
	
	printf("Enter upper limit (b): ");
	scanf("%lf",&b);
	
	printf("Enter number of subintervals(n): ");
	scanf("%d",&n);
	
	h=(b-a)/n;
	//first and last terms
	sum=f(a)+f(b);
	
	//Middle terms
	for(i=1;i<n;i++){
		sum+=2*f(a+i*h);
	}
	
	res=(h/2)*sum;
	printf("Approximate value of integral=%.5lf\n",res);
return 0;
}
