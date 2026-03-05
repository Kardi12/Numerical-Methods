#include<stdio.h>
#include<math.h>

int main(){
	int n,i ,j ;
	float x[100], y[100], X,Pn=0,li;
	printf("\nEnter the number of data points: ");
	scanf("%d", &n);
	
	printf("\nEnter the data points(x,y): ");
    for(i=0;i<n;i++){
    	scanf("%f %f",&x[i],&y[i]);
	}
	printf("\nThe table is as follows: \n\n");
	for(i=0;i<n;i++){
		printf("%.3f\t\t%.3f",x[i],y[i]);
		printf("\n");
	}
	
	printf("\nEnter the value of x to find y: ");
	scanf("%f", &X);
	
	//Lagrange interpolation
	//Pn(x)= E yi*li(x)
	for(i=0;i<n;i++){
		li=1;
		for(j=0;j<n;j++){
			if(i!=j){
				li=li*(X-x[j]) / (x[i]-x[j]);
			}
		}
		Pn=Pn+li*y[i];
		
	}
	printf("\nInterpolated value at x= %.3f is y=%.3f\n", X, Pn);
return 0;
}
