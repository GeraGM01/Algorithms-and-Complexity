#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct
{
	int pila[N];
	int tope;
	int tam;
}TPila;

int Capturatam();
int Menu();
void Imprimir(int c);
int Captura();
void inicializaPila(TPila *p, int tam);
int PilaVacia(TPila p);
int PilaLlena(TPila p);
int push(TPila *p, int d);
int pop(TPila *p, int *d);


int main()
{
	TPila p;
	int c;
	
	int op, b, tam, seguir, a=0,col=0;
	
	do
	{
		op=Menu();
		switch(op)
		{
		case 1:
			if(a==0)
			{
				tam=Capturatam();
				inicializaPila(&p,tam);
				printf("---Pila inicializada---\n");
				 a=1;
			}
			else if(a==1)
			{
				printf("*AVISO* --- Ya habia una pila existente. Se eliminaran los datos al inicializar\n");
				printf("Desea continuar? 1.Si  2.No: ");
				scanf("%d",&seguir);
				if(seguir==1)
				{
					tam=Capturatam();
					inicializaPila(&p,tam);
					printf("---Pila inicializada---\n");
				}else if(seguir==2)
				{
					printf("***No se inicializo la pila***\n");
				}
			}
			break;
		case 2:
			if(a==1)
			{
				c=Captura();
				b=push(&p,c);
				if(b==0)
				{
					printf("*****No se pudo insertar*****\n");
					printf("--->Pila Llena\n");
				}else if(b==1)
				{
					printf("-----El dato se inserto exitosamente-----\n");
				}
			}else if(a==0){
				printf("***Debe inicializar la pila primero***\n");
			}
			break;
		case 3:
			if(a==1)
			{
				b=pop(&p,&c);
				if(b==0)
				{
					printf("*****No se pudo eliminar ningun elemento de la pila*****\n");
					printf("--->Pila vacia\n");
				} else{
					Imprimir(c);
				}
			}else if(a==0){
				printf("***Debe inicializar la pila primero***\n");
			}
			
			break;
		}while(op!=7);
	}
}
}


	int Menu()
	{
		int op;
		
		printf("1.Inicializar pila\n");
		printf("2.Insertar en pila\n");
		printf("3.Eliminar de la pila\n");
		printf("4.Inicializar cola\n");
		printf("5.Insertar en cola\n");
		printf("6.Eliminar de la cola\n");
		printf("7.Salir\n");
		printf("Elige una opcion: ");
		scanf("%d",&op);
		return(op);
	}
	
	int Capturatam()
	{
		int tam;
		printf("Ingrese tamano: ");
		scanf("%d",&tam);
		return(tam);
	}
	
	int Captura()
	{
		int c;
		printf("Elemento: ");
		scanf("%d",&c);
		return(c);
	}
	
	void inicializaPila(TPila *p, int tam)
	{
		p->tam= tam <=N? tam:N;//tam es menor o igual a N?
		//Si tam es menor, asigna tam a p, si no, le asigna N
		/*  if(tam<=N)
		{
		p->tam=tam; LA LINEA DE ARRIBA EQUIVALE A ESTO
		}else{
		p->tam=N;
		}*/
		
		p->tope=0;
	}
	
	int PilaVacia(TPila p)//Regresa 1 si está vacía y 0 si NO está vacía
	{
		int reg=1;//Vacía
		
		if(p.tope>0)//No vacía
		{
			reg=0;
		}
		return(reg);
	}
	
	int PilaLlena(TPila p)
	{
		int reg=1;//Asumimos que está llena
		
		if(p.tope<p.tam)
		{
			reg=0;//NO está llena
		}
		return(reg);
	}
	
	int push(TPila *p, int d)//La pila por referencia porque se va a modificar y el dato que se le va a insertar
	{
		int reg=0;
		
		if(!PilaLlena(*p))//=PilaLlena(*p)==0 Se lee si no pila llena
		{//Solo se puede insertar si la pila no está llena
			p->pila[p->tope]=d;//Está poniendo el dato en la pila en la posicion que indica el tope
			p->tope++;
			reg=1;//Indica que sí pudo insertar el dato en la pila
		}
		return(reg);
	}
	
	int pop(TPila *p,int *d)
	{
		int reg=0;
		
		if(!PilaVacia(*p))//Si NO pila vacía
		{
			p->tope--;
			*d=p->pila[p->tope];
			reg=1;
		}
		
		return(reg);
	}
	
	void Imprimir(int c)
	{
		printf("***Elemento eliminado***\n");
		printf("Elemento: %d\n",c);
	}
