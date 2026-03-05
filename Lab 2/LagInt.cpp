#include<stdio.h>

int main(){
	int n,i,j;
	float x[20], y[20], k, pn;
	
	printf("Enter the no.of data points: ");
	scanf("%d",&n);
	
	printf("Enter the data points(x,y): \n");
	for(i=0;i<n;i++){
		scanf("%f %f",&x[i],&y[i]);
	}
 	printf("Enter the value of x for interpolation: ");
 	scanf("%f",&k);
 	
 	for(i=0;i<n;i++){
 		float term=y[i];
 		for(j=0;j<n;j++){
 			if(i!=j){
 				term= term*(k-x[j])/(x[i]-x[j]);
			 }
		 }
		 pn=pn+term;
	 }
	printf("Approximated value at %f = %f",k ,pn);
return 0;
}
