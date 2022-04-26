#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// Declaraciones adelantadas de las funciones
int busquedabinrec(int arr[], int x, int low, int high);
void llenararreglo(int arr[], int tam);
void mostrararreglo(int arr[], int tam);
void creaSublistas(int arr[], int primero, int centro, int ultimo, int L1[], int L2[]);
void divide(int arr[],int primero, int ultimo,int L1[],int L2[]);

void divide(int arr[],int primero, int ultimo,int L1[], int L2[])
{
	int centro;
	if(primero < ultimo) // significa que yo puedo seguir sacando la mitad
	{
		centro = (primero + ultimo) /2;
		divide(arr,primero,centro,L1,L2); // ordenamos la sublista izq
		divide(arr,centro+1,ultimo,L1,L2); // ordenamos la sublista der
		creaSublistas(arr,primero,centro,ultimo,L1,L2); // hacer las sublistas
	}
	
}

void creaSublistas(int arr[], int primero, int centro, int ultimo,int L1[], int L2[])
{
	int i,k,z,x;
	i=z=primero;
	k=centro+1;
	x=centro-1;
	//metemos a las sublistas
	for(i=primero; i<=centro && k<=ultimo ;)
	{
		if(arr[i]>=arr[k]) 
		{
			L1[z] = arr[i];
			i++;
			z++;
		}else{
			L1[z] = arr[k];
			k++;
			z++;
		}
	}
	x=0;
	for(i=1; i<centro && x<primero ;)
	{
		if(arr[i]<=arr[k]) 
		{
			L2[x] = arr[i];
			i++;
			x++;
		}else{
			L2[z] = arr[k];
			k++;
			z++;
		}
	}
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
	int tam;
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
}

