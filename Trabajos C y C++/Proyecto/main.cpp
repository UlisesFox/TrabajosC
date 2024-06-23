#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct nodo{
    char dato;
    struct nodo siguiente;
} tipoNodo;

typedef tipoNodopNodo;
typedef tipoNodo Lista;

void insertar(Listal, char);
void mostrarLista(Lista l);
void menu();

Lista lista = NULL;
pNodo p;

int main(){
    menu();
    return 0;
}

void insertar(Lista lista, char d){
    pNodo nodo;

    nodo = (pNodo)malloc(sizeof(tipoNodo));
    nodo->dato = d;

    if(lista == NULL) 
        lista = nodo;
    else 
        nodo->siguiente = (lista)->siguiente;

    (*lista)->siguiente = nodo;
}

void mostrarLista(Lista lista){
    pNodo nodo = lista;
    do{
        cout << nodo->dato << " -> ";
        nodo = nodo->siguiente;
    }while(nodo != lista);
    printf("\n");
}

void menu(){

    int cantidadIntroducir = 0;

    cout << "Ingresa la cantidad de datos a ingresar: ";
    cin >> cantidadIntroducir;

    for(int i = 0; i < cantidadIntroducir; i++) {
        char dato;
        cout << "Ingresa dato numero [" << i << "]: ";
        cin >> dato;

        insertar(&lista, dato);
    }

    cout<<"La lista: \n";
    mostrarLista(lista);
}
