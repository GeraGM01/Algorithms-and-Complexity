#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// Declaraciones adelantadas de las funciones
int busquedaBinRec(int arr[], int x, int low, int high);
void llenararreglo(int arr[], int tam);
void mostrararreglo(int arr[], int tam);
void seleccion(int array[], int m);


int busquedaBinRec(int arr[], int x, int low, int high) {
	int mid;                  //N
	
	if (low>high)   
		return -1;   //N
	else{
    mid= low;  // N
		if (x==arr[mid])
			return mid;  // N
		else if(x<arr[mid])
			return busquedaBinRec(arr,x,low,mid-1);  // T(n) = T(n-1) + n
		else
			return busquedaBinRec(arr,x,mid+1,high); //T(n) = T(n+1) + n
		
		// a =2   b = 2
		//lg 2 = 1
		//
	}
}


/*
int busquedaBinRec(int arr[], int x, int low, int high) 
{
	int mid;
	//Aqui asumimos que siempre va a estar el elemento
	mid= floor((low+high) / 2);
	if (x==arr[mid])
		return mid;
	else if(x<arr[mid])
		return busquedaBinRec(arr,x,low,mid-1);
	else
		return busquedaBinRec(arr,x,mid+1,high);
	
}*/

void llenararreglo(int arr[], int tam) {
	int elemento;
	int i;
	for (i=0;i<tam;i++) {
		arr[i] = rand() % 1000;
	}
}

void mostrararreglo(int arr[], int tam) {
	int i;
	for (i=0;i<tam;i++) {
		printf("[%d],",arr[i]);
	}
}

void seleccion(int array[], int m)
{
	int i,j,aux,minimo;
	for(i=0; i<m; i++)
	{
		minimo = i; //suponemos que la primer posicion es el numero minimo
		for(j=i+1; j<m; j++)
		{
			if(array[j]<array[minimo])
			{
				minimo = j;
			}
		}
		aux = array[i];
		array[i] = array[minimo];
		array[minimo] = aux;
	}
}



int main() {
	int arr[5000];
	int key;
	int tam;
	tam =13;
	llenararreglo(arr,tam);
	//mostrararreglo(arr,tam);
	seleccion(arr,tam);
	//printf("\n");
	mostrararreglo(arr,tam);
	key = busquedaBinRec(arr,962,0,tam);
	printf("\n");
	printf("\n");
	printf("Se encontro en la posicion: %d\n",key);
	return 0;
}

