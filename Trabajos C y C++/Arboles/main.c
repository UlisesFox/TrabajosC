#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo *Izq;
	struct Nodo *Der;
};

/*size_t es un tipo de dato sin signo, que es mayor a 0*/
struct Nodo *nuevonodo(int dato){
	//se pide el espacio de memoria para el nuevo Nodo
	size_t TamaNodo=sizeof(struct Nodo);
	struct Nodo *nodo=(struct Nodo *)malloc(TamaNodo);
	//Asigan el dato al iniciar
	nodo->dato=dato;
	nodo->Izq=nodo->Der=NULL;
	return nodo;
};

void Insertar(struct Nodo *nodo, int dato);
void Borrar(struct Nodo *nodo);
void Preorden(struct Nodo *nodo);
void Inorden(struct Nodo *nodo);
void Posorden(struct Nodo *nodo);

void Insertar(struct Nodo *nodo, int dato){
	//si es mayor va a la derecha
	if(dato > nodo->dato){
		if(nodo->Der==NULL){
			nodo->Der=nuevonodo(dato);
		}else{
			Insertar(nodo->Der,dato);
		}
	}else{
		//sino a la izq.
		if(nodo->Izq==NULL){
		   nodo->Izq=nuevonodo(dato);
		}else{
			Insertar(nodo->Izq,dato);
		}
	}
}

void Borrar(struct Nodo *nodo){
	if(nodo == NULL){
		printf("hola");
	}else{
		printf("adios");
	}
}

void Preorden(struct Nodo *nodo){
	if(nodo!=NULL){
		printf("%d ", nodo->dato);
		Preorden(nodo->Izq);
		Preorden(nodo->Der);
	}
}

void Inorden(struct Nodo *nodo){
	if(nodo!=NULL){
		Inorden(nodo->Izq);
		printf("%d ", nodo->dato);
		Inorden(nodo->Der);
	}
}

void Posorden(struct Nodo *nodo){
	if(nodo!=NULL){
		Posorden(nodo->Izq);
		Posorden(nodo->Der);
		printf("%d ", nodo->dato);
	}
}

int main(int argc, char *argv[]) {

	struct Nodo *raiz=nuevonodo(28);

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
				Insertar(raiz,11);
				Insertar(raiz,96);
				Insertar(raiz,21);
				Insertar(raiz,6);
				Insertar(raiz,97);
				Insertar(raiz,1);
				Insertar(raiz,30);
				Insertar(raiz,10);
				Insertar(raiz,2);
				printf("\nElementos agregados\n\n");	
			break;
			
			case 2:
				printf("\nElementos a buscar");	
				printf("\nBuscando...\n");							



				printf("\n");
			break;
			
			case 3:							
				printf("\nBorrando...");
				Borrar;
				printf("\nElementos borrardos\n\n");
			break;
			
			case 4:
				printf("\nMostrando Lista en preorden...\n");
				Preorden(raiz);
				printf("\n");
			break;
			
			case 5:
				printf("\nMostrando Lista en inorden...\n");
				Inorden(raiz);
				printf("\n");
			break;
			
			case 6:
				printf("\nMostrando Lista en posorden...\n");
				Posorden(raiz);
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
