#include<stdio.h>
#include<math.h>

double f(double x){
	return x*x-log(x)+sin(x);
}

int main(){
	double a,b,h,sum=0.0,res;
	int n,i;
	
	printf("\n---Composite Simpson's 1/3 Rule---\n");	
	printf("Enter the lower limit (a):");
	scanf("%lf",&a);
	
	printf("Enter the upper limit (b):");
	scanf("%lf",&b);
	
	printf("Enter the no.of subintervals (n):");
	scanf("%d",&n);
	if(n%2!=0){
		printf("Error! n must be even for Simpson's 1/3 Rule.\n");
		return 0;
	}
	
	h=(b-a)/n;
	
	//first term
	sum=f(a);
	//Middle term
	for(i=1;i<n;i++){
		if(i%2==0)
			sum+=2*f(a+i*h);
		else
			sum+=4*f(a+i*h);
	}
	//last term
	sum+=f(b);
	res=(h/3)*sum;
	printf("Approximation value of integral = %.5lf\n",res);
return 0;
}
