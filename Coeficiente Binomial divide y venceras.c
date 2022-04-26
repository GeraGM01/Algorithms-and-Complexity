#include <stdio.h>
#include <time.h>
int bin(int n, int k);

int main() 
{
	//MAX (55,47)
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	
	int coeficiente;
	tiempo_inicio = clock();
	coeficiente=bin(35,20);
	tiempo_final = clock();
	printf("Coeficiente binomial: %d",coeficiente); 
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
	printf("tiempo de ejecucion: %f",segundos);
}

int bin(int n, int k) 
{
	if(k==0 || n==k)
		return 1;
	else
		return bin(n-1,k-1) + bin(n-1,k);
}
