#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// Declaraciones adelantadas de las funciones
int busquedabinrec(int arr[], int x, int low, int high);
void llenararreglo(int arr[], int tam);
void mostrararreglo(int arr[], int tam);
void divide(int arr[],int primero, int ultimo,int L1[],int L2[]);

void divide(int arr[],int primero, int ultimo,int L1[], int L2[])
{
	int centro;
	int i,k,z,x;
	if(primero < ultimo) // significa que yo puedo seguir sacando la mitad
	{
		centro = (primero + ultimo) /2;
		divide(arr,primero,centro,L1,L2); // dividimos la sublista izq en arreglos mas pequeños
		divide(arr,centro+1,ultimo,L1,L2); // dividimos la sublista der en arreglos mas pequeños
		
		i=z=primero;
		k=centro+1;
		x=centro-1;
		//metemos a las sublistas comparando cada elemento y metemos los mayores 
		
		
		while(i<=centro && k<=ultimo)
		{
			if(arr[i]>=arr[k]) 
				L1[z++] = arr[i++];
			else
				L1[z++] = arr[k++];
		}
		
		
		i=0;
		x=0;
		//los datos faltantes los agregamos a la sublista 2
		
		while(i<centro && x<primero)
		{
			if(arr[i]<arr[k]) 
				L2[x++] = arr[i++];
			else
				L2[i++] = arr[k++];
		}
	}
}


int maximiza1(int L1[], int L2[],int tamL1, int tamL2)
{
	int i,j,suma1=0,suma2=0,maximo=0;
	for (i=0;i<tamL1;i++) {
		printf("[%d],",L1[i]);
		suma1=suma1+L1[i];
	}
	maximo = suma1-suma2;
	return maximo;
}



/*
void llenararreglo(int arr[], int tam) {
int elemento;
int i;
for (i=0;i<tam;i++) {
arr[i] = rand() % 100;
}
}
*/
void mostrararreglo(int arr[], int tam) {
	int i;
	for (i=0;i<tam;i++) {
		printf("[%d],",arr[i]);
	}
}


int main() {
	int arr[] ={8,4,3,7,10,9};
	int L1[100], L2[100];
	int tam,max=0;
	tam =6;
	//llenararreglo(arr,tam);
	//mostrararreglo(arr,tam);
	printf("Lista Original\n");
	mostrararreglo(arr,tam);
	divide(arr,0, tam,L1,L2);
	printf("\n");
	printf("\nSublista L1: \n");
	mostrararreglo(L1,3);
	printf("\n");
	printf("\nSublista L2: \n");
	mostrararreglo(L2,3);
	//max=maximiza1(L1,L2,3,3);
	//printf("Max = %d ", max);
}

