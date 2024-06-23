#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int valor;
	struct nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

void Insertar(Lista *lista, int v);
void Borrar(Lista *lista, int v);
void BorrarLista(Lista *lista);
void MostrarLista(Lista lista);

void Insertar(Lista *lista, int v){
	pNodo nodo;
	//creamos un nodo para el nuevo valor a insertar
	nodo = (pNodo)malloc(sizeof(tipoNodo));
	nodo->valor = v;
	//Si la lista esta vacia, la lista sera el nuevo nodo
	//Si no lo esta, insertamos el nuevo nodo a continuacion
	//del puntero por lista
	if(*lista == NULL) *lista = nodo;
	else nodo->siguiente = (*lista)->siguiente;
	//En cualquier caso, cerramos la lista circular
	(*lista)->siguiente = nodo;
}

void Borrar(Lista *lista, int v){
	pNodo nodo;
	nodo = *lista;
	//hacer que lista apunte al nodo anterior al de valor v
	do{
		if((*lista)->siguiente->valor != v) *lista = (*lista)->siguiente;
	} while((*lista)->siguiente->valor != v && *lista != nodo);
	//Si existe un nodo con el valor v:
	if((*lista)->siguiente->valor == v){
		//y si lista solo tiene un nodo
		if(*lista == (*lista)->siguiente){
			//borrar toda la lista
			free(*lista);
			*lista = NULL;
		}else{
			//si la lista tiene mas de un nodo, borrar el nodo de valor v
			nodo = (*lista)->siguiente;
			(*lista)->siguiente = nodo->siguiente;
			free(nodo);
		}
	}
}

void BorrarLista(Lista *lista){
	pNodo nodo;
	//mientras la lista tenga mas de un nodo
	while((*lista)->siguiente != *lista){
		//Borrar el nodo siguiente al apuntado por lista
		nodo = (*lista)->siguiente;
		(*lista)->siguiente = nodo->siguiente;
		free(nodo);
	}
	//y borrar el ultimo nodo
	free(*lista);
	*lista = NULL;
}

void MostrarLista(Lista lista){
	pNodo nodo = lista;
	if (lista == NULL){
		printf("Lista Vacia");
	}else
	do{
		printf("%d\n", nodo->valor);
		nodo = nodo->siguiente;
	} while(nodo != lista);
	printf("\n");
}


int main() {
	
	Lista lista = NULL;
	
	int opc,n,v;
	do{
	printf("Menu de Lista Circular\n\n");
	printf("1. Instertar Elementos\n");
	printf("2. Eliminar Elementos\n");
	printf("3. Mostrar Lista\n");
	printf("4. Eliminar Lista\n");
	printf("5. Salir\n");
	printf("\nSelecciona una opccion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("\nElemntos a insertar 10, 20, 30, 40, 50");
				printf("\nInsertando Elementos...");
					Insertar(&lista, 10);
					Insertar(&lista, 20);
					Insertar(&lista, 30);
					Insertar(&lista, 40);
					Insertar(&lista, 50);
				printf("\nElementos agregados\n\n");	
			break;
			
			case 2:
				printf("\nElementos a borrar 30, 50");								
				printf("\nBorrando Elementos...\n");
					Borrar(&lista, 30);
					Borrar(&lista, 50);
				printf("\nElementos borrardos\n\n");
			break;
			
			case 3:
				printf("\nMostrando Lista...\n");
					MostrarLista(lista);
				printf("\n");
			break;
			
			case 4:
				printf("\nBorrando Lista...\n");
					BorrarLista(&lista);
					MostrarLista(lista);
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
