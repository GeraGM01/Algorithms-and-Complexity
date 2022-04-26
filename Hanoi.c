#include <stdio.h>
void hanoi(int disco, char varilla_inicial, char varilla_central, char varilla_final);

int main() {
	hanoi (5,'A','B','C');
}


void hanoi(int disco,char varilla_inicial, char varilla_central, char varilla_final)
{
	if(disco==1)
	{
		printf("\nMover el disco %d desde la varilla %c a la varilla %c ",disco, varilla_inicial, varilla_final);
	}else{
		hanoi(disco-1,varilla_inicial,varilla_final,varilla_central);
		printf("\nMover el disco %d desde la varilla %c a la varilla %c ",disco, varilla_inicial, varilla_final);
		hanoi(disco-1,varilla_central,varilla_inicial,varilla_final);
	}
}
