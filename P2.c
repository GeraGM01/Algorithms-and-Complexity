#include<stdio.h>
#define N 5
void imprimeMatrizP(int P[N][N]);
//int w[N][N] = {  {0,1,'0',1 , 5}, {9,0,3,2,'0'}, {'0','0',0,4,'0'}, {'0','0',2,0,3}, {3,'0','0','0',0}  };
//int P[N][N]; //Matriz de predecesores, utilizada para trazar las rutas
//int D[N][N]; //Matriz de distancias, guarda la distancia mas corta entre todos los pares de vertices

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
		//int w[N][N] = {  {0,4,'0','0','0' ,10,'0'}, {3,0,'0',18,'0','0','0'}, {'0',6,0,'0','0','0','0'}, {'0',5,15,0,2,19,5}, {'0','0',12,1,0,'0','0'},{'0','0','0','0','0',0,10},{'0','0','0',8,'0','0',0}    };
		int P[N][N];
		int D[N][N];
		int i,j;
		
		printf("Matriz P de caminos mas cortos \n");
		floyd2(w,D,P,N);
	}
		
		
		
		
		
		

		
