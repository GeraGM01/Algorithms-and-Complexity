
#include<stdio.h>
#define N 5
void imprimeMatrizP(int P[N][N]);
//int w[N][N] = {  {0,1,'0',1 , 5}, {9,0,3,2,'0'}, {'0','0',0,4,'0'}, {'0','0',2,0,3}, {3,'0','0','0',0}  };
//int P[N][N]; //Matriz de predecesores, utilizada para trazar las rutas
//int D[N][N]; //Matriz de distancias, guarda la distancia mas corta entre todos los pares de vertices
int w[N][N] ={
	{0,8,13,18,20},
{3,0,7,8,10},
	{4,11,0,10,7},
{6,6,7,0,11},
	{10,6,2,1,0}};
int P[N][N];
int D[N][N];


void floyd2(int w[N][N], int D[N][N], int P[N][N], int n ){
	int i,j,k;
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
	imprimeMatrizP(P);
}
	
void imprimeMatrizP(int P[N][N])
{
	int i,j;
	for (i=0;i<N;i++) {
		printf("\n");
		for (j=0;j<N;j++) {
			printf("%d ",P[i][j]);
		}
	}
	printf("\n");
}
	
int main(){
	floyd2(w,D,P,N);
	imprimeMatrizP(P);
}
		
