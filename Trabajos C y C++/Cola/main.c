#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
	int valor;
	struct _nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;

/*funcion con colas*/
void Poner(pNodo *primero, pNodo *ultimo, int v);
int Leer(pNodo *primero, pNodo *ultimo);

/*Predefinido*/
/*int main() {
	pNodo primero = NULL, ultimo = NULL;
	
	Poner(&primero, &ultimo, 20);
	Poner(&primero, &ultimo, 10);
	printf("Poner (10)\n");
	printf("Leer: %d\n", Leer(&primero, &ultimo));
	Poner(&primero, &ultimo, 40);
	printf("Poner (40)\n");
	Poner(&primero, &ultimo, 30);
	printf("Poner(30)\n");
				
	return 0;
}*/

/*introducido por el usuario*/
int main(){
	pNodo primero = NULL, ultimo = NULL;
	int n = 5, valor, i;
	
	for(i=0; i<n; i++){
		printf("Valor %d: ", i);
		scanf("%d",&valor);
		Poner(&primero, &ultimo, valor);
	}
	for(i=0; i<n; i++){
		printf("Leer: %d\n", Leer(&primero, &ultimo));
	}
	return 0;
}

void Poner(pNodo *primero, pNodo *ultimo, int v){
	pNodo nuevo;
	
	/*Crear un nodo nuevo*/
	nuevo = (pNodo)malloc(sizeof(tipoNodo));
	nuevo->valor = v;
	/*Este sera el ultimo nodo, no debe tener siguiente*/
	nuevo->siguiente = NULL;
	/*Si la cola no estaba vacia, añadimos el valor a continuacion de ultimo*/
	if(*ultimo) (*ultimo)->siguiente = nuevo;
	/*Ahora, el ultimo elemento de la cola es el nuevo nodo*/
	*ultimo = nuevo;
	/*Si primero es NULL, la cola estaba vacia ahora ptimero apuntara tambien al nuevo nodo*/
	if(!*primero) *primero = nuevo;
}

int Leer(pNodo * primero, pNodo *ultimo){
	pNodo nodo; 	/*variable auxiliar para manipular nodo*/
	int v; 			/*variable auxilar para retornar*/
	
	/*Nodo apunta al primer elemnto de la pila*/
	nodo = *primero;
	if(!nodo) return 0; /*Si no hay nodos en la pila retornamos 0*/
	/*Asignamos a primero la direccion del siguiente nodo*/
	*primero = nodo->siguiente;
	/*Guardamos el valor de retorno*/
	v = nodo->valor;
	/*Borrar el nodo*/
	free(nodo);
	/*Si la cola quedo vacia, ultimo de ser NULL tambien*/
	if(!*primero) *ultimo = NULL;
	return v;
}
