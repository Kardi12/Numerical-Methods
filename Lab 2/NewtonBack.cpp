#include<stdio.h>

int main(){
	int n,i,j;
	float x[20],y[20][20],k,h,s;
	
	printf("Enter the no.of data points: ");
	scanf("%d",&n);
	
	printf("\nEnter the data points(x,y): \n");
	for(i=0;i<n;i++){
		scanf("%f %f",&x[i],&y[i][0]);
	}
	
	for(i=1;i<n;i++){
		for(j=n-1;j>=i;j--){
			y[j][i]=y[j][i-1]-y[j-1][i-1];
		}
	}
	printf("Enter the value of x for interpolation: ");
	scanf("%f",&k);
	
	h=x[1]-x[0];
	s=(k-x[n-1])/h;
	
	float res=y[n-1][0];
	float term=1;
	
	for(i=1;i<n;i++){
		term=term*(s+(i-1))/i;
		res=res+term*y[n-1][i];
	}
	
	printf("Interpolated value at x=%f is y=%f",k, res);
return 0;
	
	
}
