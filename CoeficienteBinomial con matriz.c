#include <stdio.h>
#include <time.h>
int coefBin(int n, int k);
int min(int x, int y);

int main() 
{
	//Prueba con (734,702)
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	
	tiempo_inicio = clock();
	int coeficiente;
	coeficiente=coefBin(20,20);
	printf("Coeficiente binomial: %d",coeficiente); 
	tiempo_final = clock();
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
	printf("tiempo de ejecucion: %f",segundos);
}
/*
int coefBin(int n, int k) {
	int i,j;
	int B[n+1][k+1]; 
	
	
	for(i=0; i<=n; i++)
		
		for(j=0; j<= min(i,k); j++)
		
		if(j==0 || j==i)
		B[i][j] = 1;
		else
			B[i][j] = B[i-1][j-1] + B[i-1][j];
		
		return B[n][k];
}
*/

int coefBin(int n, int k) {
	int i,j;
	int B[n+1][k+1]; 
	
	for(i=0; i<=n; i++)
	{
		for(j=0; j<= min(i,k); j++)
		{
			if(j==0 || j==i)
			{
				B[i][j] = 1;
			}else{
				B[i][j] = B[i-1][j-1] + B[i-1][j];
			}
		}
	}
	return B[n][k];
}


int min(int x, int y) 
{ 
	
	
	return (x<y)? x :y; 
}
