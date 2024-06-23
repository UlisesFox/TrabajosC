#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct _nodo{
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

void Insertar(Arbol *a, int dat);
void Borrar(Arbol *a, int dat);
int Buscar(Arbol a, int dat);
int Vacio(Arbol r);
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));
void Mostrar(int *d);

/* Contar número de nodos: */
int NumeroNodos(Arbol a, int* c);
/* Comprobar si es un nodo hoja: */
int EsHoja(pNodo r);
/* Funciones auxiliares: */
void auxContador(Arbol a, int*);

int main(int argc, char *argv[]) {
    
	Arbol ArbolInt=NULL;
    int nnodos;

	int opc,n,v;
	do{
	printf("Menu de Lista Abierta y/o Enlazada\n\n");
	printf("1. Instertar Elementos\n");
	printf("2. Buscar elemento\n");
	printf("3. Eliminar Elemento\n");
	printf("4. Mostrar Lista preorden\n");
	printf("5. Mostrar Lista inorden\n");
	printf("6. Mostrar Lista posorden\n");
	printf("7. Salir\n");
	printf("\nSelecciona una opccion: ");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("\nInsertando Elementos...");
				Insertar(&ArbolInt,11);
				Insertar(&ArbolInt,96);
				Insertar(&ArbolInt,21);
				Insertar(&ArbolInt,6);
				Insertar(&ArbolInt,97);
				Insertar(&ArbolInt,1);
				Insertar(&ArbolInt,30);
				Insertar(&ArbolInt,10);
				Insertar(&ArbolInt,2);
				printf("\nElementos agregados\n\n");		
			break;
			
			case 2:
				printf("\nBuscando elementos...\n");							
				printf("\nTotal de Nodos en el arbol: %d\n", NumeroNodos(ArbolInt, &nnodos));
				printf("\n");
			break;
			
			case 3:							
				printf("\nElementos a borrar 96, 30, 1, 11");							
				printf("\nBorrando...");
				Borrar(&ArbolInt, 96);
				Borrar(&ArbolInt, 30);
				Borrar(&ArbolInt, 1);
				Borrar(&ArbolInt, 11);
				printf("\nElementos borrardos\n\n");
			break;
			
			case 4:
				printf("\nMostrando Lista en preorden...\n");
				PreOrden(ArbolInt, Mostrar);
				printf("\n");
			break;
			
			case 5:
				printf("\nMostrando Lista en inorden...\n");
				InOrden(ArbolInt, Mostrar);
				printf("\n");
			break;
			
			case 6:
				printf("\nMostrando Lista en posorden...\n");
				PostOrden(ArbolInt, Mostrar);
				printf("\n");
			break;
			
			case 7:
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

/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat){
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->dato){
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;}

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si principal es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)){
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;}
   /* Si el dato es menor que el que contiene el nodo principal, lo insertamos
      en la rama izquierda */
   else if(dat < padre->dato){
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;}
   /* Si el dato es mayor que el que contiene el nodo principal, lo insertamos
      en la rama derecha */
   else if(dat > padre->dato){
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;}
  }

/* Eliminar un elemento de un árbol ABB */
void Borrar(Arbol *a, int dat){
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *a;
   /* Mientras sea posible que el valor esté en el árbol */
   while(!Vacio(actual)) {
      if(dat == actual->dato) { /* Si el valor está en el nodo actual */
         if(EsHoja(actual)) { /* Y si además es un nodo hoja se borramos */
            if(padre) /* Si tiene padre*/
               /* Anulamos el puntero que le hace referencia */
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            free(actual); /* Borrar el nodo */
            actual = NULL;
            return;
         }else{ /* Si el valor está en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo más izquierdo de rama derecha */
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;}
            /* O buscar nodo más derecho de rama izquierda */
            }else{
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;}
            }
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }else{ /*no se a encontrado el valor, seguir buscándolo */
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

void InOrden(Arbol a, void (*func)(int*)){
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);}

void PreOrden(Arbol a, void (*func)(int*)){
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);}

void PostOrden(Arbol a, void (*func)(int*)){
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);}

/* Buscar un valor en el árbol */
int Buscar(Arbol a, int dat){
   pNodo actual = a;
   /* Todavía puede aparecer*/
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; /* dato encontrado */
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;}
   return FALSE;} /* No está en árbol */

/* Contar el número de nodos */
int NumeroNodos(Arbol a, int *contador){
   *contador = 0;
   auxContador(a, contador);
   return *contador;}

void auxContador(Arbol nodo, int *c){
   (*c)++;
   /* Continuar recorrido */
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);}

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r){
   return r==NULL;}

/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r){
   return !r->derecho && !r->izquierdo;}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d){
   printf("%d, ", *d);}
