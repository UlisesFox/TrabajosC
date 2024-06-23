#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
	int valor;
	struct nodo *sig;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *lista;
//prototipo de las funciones
//declaracion de las formulas
void insertar(lista *l, int v);
void borrar(lista *l, int v);
int listavacia(lista l);
void borrarlista(lista *);
void mostrarlista(lista l);

void insertar(lista *lista, int v){
	pNodo nuevo, anterior;
nuevo=(pNodo)malloc(sizeof(tipoNodo));
nuevo->valor = v;
/*Caso de la lista vacia*/
if(listavacia(*lista)||(*lista)->valor>v){
	nuevo->sig=*lista;
	*lista=nuevo;
	}else{
	anterior=*lista;
	while(anterior->sig && anterior->sig->valor<=v)
		anterior=anterior->sig;
		nuevo->sig=anterior->sig;
		anterior->sig=nuevo; 
	}
}	

void borrar(lista *l, int v){
	pNodo anterior, nodo;
	nodo=*l;
	anterior=NULL;
	while(nodo&&nodo->valor<v){
		anterior=nodo;
		nodo = nodo->sig;
	}
	if(!nodo||nodo->valor!=v)return;
	else{
		if(!anterior)
		*l=nodo->sig;
		else
			anterior->sig=nodo->sig;
		free(nodo);
		}
	}

	int listavacia(lista l){
		return(l==NULL);
	}


void borrarlista(lista *lista){
	pNodo nodo;
	while(*lista){
	
		nodo=*lista;
		*lista=nodo->sig;
		free(nodo);
	}
}

void mostrarlista(lista lista){
	pNodo nodo=lista;
if(listavacia(lista))printf("lista vacia\n");
else{
	while(nodo){
		printf("%d \n", nodo->valor);
		nodo=nodo->sig;
		}
	}
}


int main(int argc, char *argv[]) {
	
	lista lista=NULL;
	
	int opc,n,v;
	do{
	printf("Menu de Lista Abierta y/o Enlazada\n\n");
	printf("1. Instertar Elementos\n");
	printf("2. Eliminar Elementos\n");
	printf("3. Mostrar Lista\n");
	printf("4. Eliminar Lista\n");
	printf("5. Salir\n");
	printf("\nSelecciona una opccion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("\nElemntos a insertar 20, 10, 40, 30");
				printf("\nInsertando Elementos...");
				insertar(&lista, 20);			
				insertar(&lista, 10);
				insertar(&lista, 40);
				insertar(&lista, 30);
				printf("\nElementos agregados\n\n");	
			break;
			
			case 2:
				printf("\nElementos a borrar 20, 10");								
				printf("\nBorrando Elementos...\n");
				borrar(&lista,20);
				borrar(&lista,10);
				printf("\nElementos borrardos\n\n");
			break;
			
			case 3:
				printf("\nMostrando Lista...\n");
				mostrarlista(lista);
				printf("\n");
			break;
			
			case 4:
				printf("\nBorrando Lista...\n");
				borrarlista(&lista);
				mostrarlista(lista);
				printf("\n");
			break;
			
			case 5:
				printf("Saliendo...");
				return 0;
			break;
			
			default:
				printf("Opcion invalida\n");
			break;
		}
		
	}
	while (opc!=0);
	return 0;
	getch();
}
