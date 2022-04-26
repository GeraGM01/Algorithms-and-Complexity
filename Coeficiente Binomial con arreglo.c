#include <stdio.h>
int coefBin(int n, int k);
int min(int x, int y);

int main() 
{
	int coeficiente;
	coeficiente=coefBin(4,2);
	printf("valor de n = 4, Valor de k = 2 \n");
	printf("Coeficiente binomial: %d",coeficiente);
}

int coefBin(int n, int k) {
	int i,j;
	int B[k+1]; 
	
	for(i=0; i<=k; i++)
	{
		B[i]=0;
	}
		B[0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=min(i,k);j>0;j--)
				B[j]=B[j]+B[j-1];
		}
		
		for(i=0; i<=k; i++)
		{
			printf("%d \n",B[i]);
		}
		return B[k];
		
}


int min(int x, int y) 
{ 
	return (x<y)? x :y; 
}
