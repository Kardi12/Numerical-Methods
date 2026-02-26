#include<stdio.h>
#include<math.h>

double f(double x){
	return x*x;
}

int main(){
	double a,b,h,sum=0.0,res;
	int n,i;
	
	printf("---Composite Simpson's 3/8 Rule---\n");
	printf("Enter the lower limit (a):");
	scanf("%lf",&a);
	
	printf("Enter the upper limit (b):");
	scanf("%lf",&b);
	
	printf("Enter the no.of subintervals (n):");
	scanf("%d",&n);
	if(n%3!=0){
		printf("Error! n must be multiple of 3 for Simpson's 3/8 Rule.\n");
		return 0;
	}
	h=(b-a)/n;
	//first term
	sum=f(a)+f(b);
	//Middle terms
	for(i=1;i<n;i++){
		if(i%3==0)
			sum+=2*f(a+i*h);
		else
			sum+=3*f(a+i*h);
	}
	

	res=(3*h/8)*sum;
	printf("Approximation value of integral = %.5lf\n",res);
return 0;
}

