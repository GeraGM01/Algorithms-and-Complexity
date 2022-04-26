#include <stdio.h>
#define N 7
int determinaCaminoMasCorto(int P[N][N], int vertice_ini, int vertice_des);
// int w[N][N] = {  {0,1,'0',1 , 5}, {9,0,3,2,'0'}, {'0','0',0,4,'0'},
// {'0','0',2,0,3}, {3,'0','0','0',0}  };
// int P[N][N]; //Matriz de predecesores, utilizada para trazar las rutas
// int D[N][N]; //Matriz de distancias, guarda la distancia mas corta entre
// todos los pares de vertices

int floyd2(int w[N][N], int D[N][N], int P[N][N], int n, int vertice_ini,int vertice_des) 
{
	int i, j, k, c = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			P[i][j] = 0;
			
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			D[i][j] = w[i][j];
					
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
						P[i][j] = k + 1;
				}
	c = determinaCaminoMasCorto(P, vertice_ini, vertice_des);
	return c;
}
	
int determinaCaminoMasCorto(int P[N][N], int vertice_ini, int vertice_des) {
	int i, j, camino = 0;
	for (i = vertice_ini; i < vertice_ini + 1; i++) {
		for (j = 0; j < vertice_des + 1; j++) {
			camino = P[i][j];
		}
	}
	return camino;
}
	
int main() {
	int w[N][N] = {
			{0, 4, '0', '0', '0', 10, '0'},  {3, 0, '0', 18, '0', '0', '0'},
			{'0', 6, 0, '0', '0', '0', '0'}, {'0', 5, 15, 0, 2, 19, 5},
			{'0', '0', 12, 1, 0, '0', '0'},  {'0', '0', '0', '0', '0', 0, 10},
			{'0', '0', '0', 8, '0', '0', 0}};
		int P[N][N];
		int D[N][N];
		int i,j,x;
		x=floyd2(w, D, P, N, 5, 3);
		printf("Matriz P: ");
		for(i=0; i<N; i++)
		{
			printf("\n");
			for(j=0; j<N; j++)
			{
				printf("%d ",P[i][j]);
			}
			
		}
		printf("\n");
		printf("Camino mas corto entre el vertice 5 y el vertice 3 es: %d\n",x);
	}
