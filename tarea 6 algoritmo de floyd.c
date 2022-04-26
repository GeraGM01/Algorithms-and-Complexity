#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define N 250

void floyd2(int w[N][N], int D[N][N], int P[N][N],int n);
void generaMatriz(int adyacencias[N][N],int n);
void generaMatrizPeso(int adyacencias[N][N],int n, int peso[N][N]);
void imprimeMatriz(int adyacencias[N][N]);

int main()
{
	int adyacencias[N][N];
	int peso[N][N];
	int P[N][N];
	int D[N][N];
	clock_t tiempo_inicio, tiempo_final;
	double segundos;
	tiempo_inicio = clock();
	generaMatriz(adyacencias,250);  //Matriz de adyacencias
	//printf("Matriz de adyacencias\n");
	//imprimeMatriz(adyacencias);
	//printf("\n");
	//printf("Matriz W\n");
	generaMatrizPeso(adyacencias,250,peso);
	//imprimeMatriz(peso);
	floyd2(peso,D,P,N);
	tiempo_final = clock();
	segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
	printf("tiempo de ejecucion: %f",segundos);
	
}

void floyd2(int w[N][N], int D[N][N], int P[N][N],int n)
{
	int i,j,k,c;
	
	for(i=0; i<n; i++)
		for(j=0;j<n;j++)
		P[i][j] = 0;
		
	for(i=0; i<n;i++)
		for(j=0; j<n; j++)
		D[i][j] = w[i][j];
		
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
		        if(D[i][k] + D[k][j] < D[i][j])
	            {
		            D[i][j] = D[i][k] + D[k][j];
		            P[i][j] = k+1;
	            }
	//printf("\n");
	//printf("Matriz D\n");
    //imprimeMatriz(D);
	//printf("\n");
    //printf("Matriz P\n");
	//imprimeMatriz(P);
}

void generaMatriz(int adyacencias[N][N],int n)
{
	int i,j,x;
	srand(time(NULL));
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			adyacencias[i][j] = rand() % 2;
		}
	}
}

void generaMatrizPeso(int adyacencias[N][N],int n, int peso[N][N])
{
	int i,j,x;
	srand(time(NULL));
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(adyacencias[i][j] == 1)
			{
				peso[i][j] = rand() % 25;
			}else if(adyacencias[i][j] == 0){
				peso[i][j] = 0;
			}
		}
	}
}

void imprimeMatriz(int adyacencias[N][N])
{
	int i,j;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d\t",adyacencias[i][j]);
		}
		printf("\n");
	}
}
