//Conjuntos con estructuras

# include <stdio.h>
# include <stdlib.h>

#define N 20

typedef struct
{
	int Conjunto[N];
	int tam;
	int pos;  //permite controlar los datos que se almacenan en el arreglo
}TConjunto;

int InsertarConjunto(TConjunto *C, int d);
void ImprimeConjunto(TConjunto C);
void InicializarConjunto(TConjunto *C, int tam);
int ConjuntoLleno(TConjunto C);
void determinaSubConjuntos(TConjunto C, char sub[N]);
int main()
{
	TConjunto C1, C2, CR;
	char sub[N];
	int tam,d;
	
	InicializarConjunto(&C1,4);
	
	InsertarConjunto(&C1,5);
	InsertarConjunto(&C1,8);
	InsertarConjunto(&C1,10);
	InsertarConjunto(&C1,1);
	printf("CONJUNTO 1: \n ");
	printf("\n");
	ImprimeConjunto(C1);
	printf("\n");
	determinaSubConjuntos(C1,sub);
}


void ImprimeConjunto(TConjunto C)
{
	int i;
	printf("\n");
	for (i=0;i<C.pos;i++)
	{
		printf(" %d ",C.Conjunto[i]);
	}
}

void InicializarConjunto(TConjunto *C, int tam) //recibe el conjunto y el tamaño del conjunto, se inicializa el campo tam y pone la posicion en cero
{
	C->tam= tam<=N?tam:N;
	
	C->pos=0;  //siguiente poscicion vacia en nuestro arreglo
}

/*1 -- Si Inserta
0 -- NO Inserta -- Está lleno
-1 - NO Inserta -- Está repetido - Ya existe*/
int InsertarConjunto(TConjunto *C, int d)   //1 si insertar, 0 no inserta por que ya esta lleno, -1 no inserta por que esta repetido y ya existe
{
	int cont;
	
	if(ConjuntoLleno(*C)==1)   //si ya se lleno, ya no cabe, regresara un cero
	{
		return(0);
	}
	for(cont=0;cont<C->pos && C->Conjunto[cont]!=d; cont++);  //busca para ver si existe, si recorre todo quiere decir que no existe el numero         recorre el arreglo, el ciclo se termina si llego al final o fue diferente de d, si el contador llego hasta el ultimo significa qyue no lo encontro y pasa al if 	
	if(cont==C->pos)  //si se cumple lo de arriba entra a esta condicion
	{
		C->Conjunto[C->pos]=d;  //agrega el dato si no estaba en el arreglo
		C->pos++;
		return(1);
	}
	return(-1);   //recorre el arreglo y si encontro el dato, regresara un -1
}

int ConjuntoLleno(TConjunto C)
{
	if(C.pos==C.tam)
	{
		return(1);
	}
	return(0);
}
int potencia(int b,int e){
	int i;  //b es la bse que seria en este caso 2 y e es el exponente que seria el limite
	int pot=1;
	for(i=1;i<=e;i++){
		pot=pot*b;
	}
	return pot;
}

void determinaSubConjuntos(TConjunto C, char sub[N])
{
	int i,j,k;
	for(i=0;i<potencia(2,C.tam);i++){
		for(j=0;j<C.tam;j++){
			if(i & (1<<j))
			sub[i]=C.Conjunto[j];
		}
		printf("\n");
	}
	
	for(k=0; i<N; i++)
	{
		printf("%c\n",sub[i]);
	}
	
}
