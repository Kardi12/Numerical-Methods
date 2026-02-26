 #include<stdio.h>
#include<math.h>
#define MAX 10

double f(double x){
	return exp(x)-1;
}


int main(){
	double a,b,h,sum;
	int n,i,j,k;
	double R[MAX][MAX];
	
	printf("---Romberg's Formula---\n");
	printf("Enter the lower limit (a): ");
	scanf("%lf",&a);
	
	printf("Enter the upper limit (b): ");
	scanf("%lf",&b);
	
	printf("Enter the number of Romberg iterations: ");
	scanf("%d",&n);
	
	//first trapezoidal approximation
	R[0][0]=(b-a)*(f(a)+f(b))/2.0;
	
	for(i=1;i<n;i++){
		h=(b-a)/pow(2,i);
		sum=0.0;
		//sum of new points
		for(k=1;k<=pow(2,i-1);k++){
			sum+=f(a+(2*k-1)*h);
		}
		R[i][0]=0.5*R[i-1][0]+h*sum;
		
		for(j=1;j<=i;j++){
			R[i][j]=(pow(4,j)*R[i][j-1]-R[i-1][j-1])/(pow(4,j)-1);
		}
	}
	
	printf("\nRomberg Integration Table:\n");
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			printf("%lf\t",R[i][j]);
		}
		printf("\n");
	}
		
	printf("Approximate value of integral = %lf\n",R[n-1][n-1]);
return 0;
}


