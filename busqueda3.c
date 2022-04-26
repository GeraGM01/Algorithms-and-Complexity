#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// Declaraciones adelantadas de las funciones
int busquedabinrec(int arr[], int low, int high, int x);
void llenararreglo(int arr[], int tam);
void mostrararreglo(int arr[], int tam);
void seleccion(int array[], int m);


int busquedabinrec(int arr[], int low, int high, int x) 
{
	//p1 es el ultimo nunmero del primer arreglo
	// p2 representa el ultimo numero del segundo arreglo
	int p1,p2;
	if(low>high)
	{
		return -1;
	}else{
		p1 = floor((high + low) /3); //partimos el arreglo en 3
		p2 = (p1+1+high)/2;
		if(arr[p1]==x)
			return p1;
		else
			if(x<arr[p1])
			
				return busquedabinrec(arr,low,p1-1,x);
			else
				if(x==arr[p2])
				
					return p2;
				else
					if(x<arr[p2])
					
						return busquedabinrec(arr,p1,p2,x);
					else
						return busquedabinrec(arr,p2+1,high,x);
		}
}


void llenararreglo(int arr[], int tam) {
	int elemento;
	int i;
	for (i=0;i<tam;i++) {
		arr[i] = rand() % 100;
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
	tam =9;
	llenararreglo(arr,tam);
	//mostrararreglo(arr,tam);
	seleccion(arr,tam);
	//printf("\n");
	mostrararreglo(arr,tam);
	key = busquedabinrec(arr,0,tam,90);
	printf("\n");
	printf("\n");
	printf("Se encontro en la posicion: %d\n",key);
	return 0;
}

