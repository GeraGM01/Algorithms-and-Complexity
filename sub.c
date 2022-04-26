#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define TAM 256
int potencia(int a,int e);
void imprimeSubconjuntos(int A[TAM],int t);
void llenaConjunto(int A[TAM],int t);

int main() 
{
	int A[TAM];
	llenaConjunto(A,4);
	imprimeSubconjuntos(A,4);
}

int potencia(int a,int e)
{
	int i,pot=1;
	for(i=1; i<=e; i++)
	{
		pot=pot*a;
	}
	return pot;
}

void imprimeSubconjuntos(int A[TAM],int t)
{
	int B[TAM];
	int i,j,k;
	int Comb=pow(t-1,2);
	for(i=1;i<Comb-1;i++){  //enviamos los vertices que estan en V a un arreglo temporal 
		k=0;
		B[k] =0;
		for(j=0; j<t; j++){
			if(i &(1<<j)){
				B[k] = A[j];
				k++;
				B[k] = 0;
			}
		}
		 // A son los subconjuntos del conjunto A que tambien es elemento del conjunto V(Vertices)
	}
	for(i=0; i<t; i++)
	{
		printf("A: %d\n",B[i]);
	}
}

void llenaConjunto(int A[TAM],int t)
{
	int i;
	for(i=0; i<t; i++)
	{
		printf("Ingrese el elemento %d ",i+1);
		scanf("%d",&A[i]);
	}
}
