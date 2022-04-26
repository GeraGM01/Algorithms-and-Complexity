/************************************
COURSE: Algorithms and Complexity
Homework 3 - Sorting Algorithms
*************************************/

// Libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Total size of the array
// You should change N for the experiments according to the description (see PDF)
#define N 100000

// Function declaration
// Array functions
void createArray (int array[N]);
void printArray (int array[N], int m);
void Burbuja(int array[N], int m);
void seleccion(int array[N], int m);
void quicksort(int A[],int inf, int sup);
void heapSort(int array[N], int m);
void heapify(int arr[N], int n, int i);

// Declaration of your sorting functions
// For example: void bubbleSort (int array[N]);


// Main function where the sorting algorithm is called
int main ()
{
	int m;
	// Array is static so that the compiler can store it beforehand in memory
	static int arr[N];
	// Variables to measure time
	clock_t t_ini, t_end;
	double t_elapsed;
	
	
	printf("Ingrese el tamaño de m \n");
	scanf("%d",&m);
	// Create the array with random elements
	createArray (arr);
	// WARNING: Only print the array for testing purposes and if N is small
	// printf ("\n\nUNSORTED ARRAY:\n");
	// printArray (arr,m);

	// Check the initial time
	t_ini = clock();
	printf ("\n\nInitial time: %f", ((double)t_ini));
	
	// Start the sorting algorithm
	// For example: bubbleSort (arr);
	//  Burbuja(arr,m);
	// seleccion(arr,m);
	//  quicksort(arr,0,m-1);
	 heapSort(arr,m);
	
	// Check the final time and calculate the elapsed time
	t_end = clock() - t_ini;
	printf ("\nFinal time: %f", ((double)t_end));
	t_elapsed = ((double)t_end)/CLOCKS_PER_SEC;
	printf ("\nTotal time: %f segs", t_elapsed);
	
	// WARNING: Only print the array for testing purposes and if N is small
	 //printf ("\n\nSORTED ARRAY:\n");
	 //printArray (arr,m);
	
	return 0;
}

// ADD HERE YOUR SORTING METHODS

void Burbuja(int array[N],int m) // Metodo de complejidad cuadratica
{
	
	int i,j,aux=0;
	for(j=0; j<m; j++)
		for(i=0; i<m; i++)
		if(array[i]>array[i+1])
	{
		aux = array[i];
		array[i] = array[i+1];
		array[i+1] = aux;
	}
}

void seleccion(int array[N], int m)
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

void quicksort(int A[N],int inf, int m)
{
	int i,j,aux,x;
	i=inf;
	j=m;
	x=A[(i+j)/2]; //obteniendo el pivote
	while(i<=j)
	{	
		while(A[i]<x) //obteniendo elemento mayor de lado izquierdo del  pivote para intercambiar
			i++;
		while(A[j]>x) // obteniendo elemento menor de lado derecho del pivote a intercambiar
			j--;
		if(i<=j)  //intercambiando cuando se sigan presentando valores menores ala derecha y mayores a la izquierda
		{
			aux=A[i];
			A[i]=A[j];
			A[j]=aux;
			i++;
			j--;
		}
	}
	if(inf<j)
		  quicksort(A,inf,j);
	if(i<m)
		quicksort(A,i,m);
}

void heapSort(int array[N], int m)
{
	int temp;
	// Build heap (rearrange array)
	for (int i = m / 2 - 1; i >= 0; i--)
		heapify(array, m, i);
	
	// One by one extract an element from heap
	for (int i = m - 1; i > 0; i--) {
		// Move current root to end
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		
		// call max heapify on the reduced heap
		heapify(array, i, 0);
	}
}

void heapify(int arr[N], int n, int i)
{
	int swap;
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	
	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;
	
	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;
	
	// If largest is not root
	if (largest != i) {
		swap = arr[i];
		arr[i] = arr[largest];
		arr[largest] = swap;
		
		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// Prints an array of size N
void printArray (int array[N],int m)
{
	int i;
	
	printf ("\n\n");
	for (i = 0; i < m; i++)
	{
		printf ("%d, ", array[i]);
	}
}

// Fills an existing array with random values
void createArray (int array[N])
{
	int i;
	time_t t;
	
	srand((unsigned) time(&t));
	
	for (i = 0; i < N; i++)
	{
		// NOTE: If N is large try to have large numbers in the array
		// otherwise the array would contain many repeated elements
		array[i] = rand() % 10000000;
	}
}
