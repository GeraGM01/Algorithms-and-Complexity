#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define INF 243
#define N 5
int determinaCaminoMasCorto( int P[N][N],int n);
int w[N][N];
//int P[N][N]; //Matriz de predecesores, utilizada para trazar las rutas
//int D[N][N]; //Matriz de distancias, guarda la distancia mas corta entre todos los pares de vertices

void floyd2(int w[N][N], int D[N][N], int P[N][N],int n){
	int i,j,k,c=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		P[i][j] = 0;
		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			D[i][j] = w[i][j];	
			
			
			for(k=0;k<n;k++)
				for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				if(D[i][k] + D[k][j] < D[i][j]){
				D[i][j] = D[i][k] + D[k][j];
				P[i][j] = k+1;
			}

}
	
void generaMatriz(int adyacencias[N][N],int n)
{
	int i,j,x;
	srand(time(NULL));
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			
			adyacencias[i][j] = rand() % 2;
		}
	}
	
	for(x=0; x<n; x++)
	{
		adyacencias[x][x] = 0;
	}
}

void generaMatrizPeso(int adyacencias[N][N],int n, int peso[N][N])
{
	int i,j,x;
	srand(time(NULL));
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if(adyacencias[i][j] == 1)
			{
				peso[i][j] = rand() % 25;
			}else if(adyacencias[i][j] == 0){
				peso[i][j] = -1;
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

void imprimeMatrizW(int peso[N][N], int adyacencias[N][N])
{
	int i,j,x;
	for(x=0; x<N; x++)
	{
		peso[x][x] = 0;
	}
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(adyacencias[i][j] ==1)
			{
				printf("%d\t",peso[i][j]);
			}if(peso[i][j] == -1){
				printf("%s\t","INF");
			}
		}
		printf("\n");
	}
}	
	
	
	int main(){
		int adyacencias[N][N];
		int peso[N][N];
		int P[N][N];
		int D[N][N];
		int i;
		//generaMatriz(adyacencias,4);  //Matriz de adyacencias
		//printf("Matriz de adyacencias\n");
		//imprimeMatriz(adyacencias);
		printf("Matriz W\n");
		//generaMatrizPeso(adyacencias,4,peso);
		imprimeMatrizW(peso,adyacencias);
		floyd2(w,D,P,N);
	}
