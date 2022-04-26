#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 1000 
void merge(int A[], int temp[], int inicio, int medio, int f)
{
	int k = inicio, i = inicio, j = medio + 1;
	
	while (i <= medio && j <= f)
	{
		if (A[i] < A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];
		}
	}
	while (i < N && i <= medio) {
		temp[k++] = A[i++];
	}
	for (int i = inicio; i <= f; i++) {
		A[i] = temp[i];
	}
}


void mergesort(int A[], int temp[], int izq, int der)
{
	int f,x,m,mitad;
	for (m = 1; m <= der - izq; m = 2*m)
	{
		for (int i = 0; i < der; i += 2*m)
		{
			f=der;
			mitad = i + m - 1;
			x=(i + 2*m - 1);
			if(x<der)
			f = x;
			merge(A, temp, i, mitad, f);
		}
	}
}


int printArray(int A[])
{
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	
	printf("\n");
}


int main()
{
	int A[N], temp[N];
	srand(time(NULL));
	
	// generate random input of integers
	for (int i = 0; i < N; i++) {
		temp[i] = A[i] = (rand() % 10000);
	}
	
	printf("Original array: ");
	printArray(A);
	
	// sort array `A[0…N-1]` using a temporary array temp
	mergesort(A, temp, 0, N - 1);
	
	printf("Modified array: ");
	printArray(A);
	
	return 0;
}
