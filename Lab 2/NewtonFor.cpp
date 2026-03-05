#include<stdio.h>

int main(){
	int n,i,j;
	float x[10],y[10][10],k,h,s;
	
	printf("Enter the no.of data points: ");
	scanf("%d",&n);
	
	printf("Enter the data points(x,y):\n");
	for(i=0;i<n;i++){
		scanf("%f %f",&x[i],&y[i][0]);
	}
	
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			y[j][i]=y[j+1][i-1]-y[j][i-1];
		}
	}
	
	 
    
	printf("Enter the value of x for interpolation: ");
	scanf("%f",&k);
	
	h=x[1]-x[0];
	s=(k-x[0])/h;
	
	float res=y[0][0];
	float term=1;
	
	for(i=1;i<n;i++){
		term=term*(s-(i-1))/i;
		res=res+term*y[0][i];
	}
	printf("Interpolated value at x=%f is y=%f",k,res);
return 0;
}

