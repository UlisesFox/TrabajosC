#include <iostream>
using namespace std;
 
class nodo {
   public:
    nodo(int v, nodo *sig = NULL){
       valor = v;
       siguiente = sig;
    }
    
    private:
    int valor;
    nodo *siguiente;
    friend class cola;
};
 
typedef nodo *pnodo;
 
class cola {
   public:
	    cola() : primero(NULL), ultimo(NULL) {}
	    ~cola();  
	    void intro(int v);
	    int mostra();
    private:
    	pnodo primero, ultimo;
};
 
cola::~cola(){
   while(primero) mostra();
}

int cola::mostra(){
   pnodo nodo; 
   int v;      
   
	nodo = primero;
		if(!nodo) return 0; 
	   primero = nodo->siguiente;
	   v = nodo->valor; 
	   delete nodo;
	   if(!primero) ultimo = NULL;
   return v;
}

void cola::intro(int v){
   pnodo nuevo;
   nuevo = new nodo(v);
	   if(ultimo) ultimo->siguiente = nuevo;
	   ultimo = nuevo;
	   if(!primero) primero = nuevo;
}

int main(){
    cola Cola;
    Cola.intro(20);
	Cola.intro(10);
	Cola.intro(40);
	Cola.intro(30);
	Cola.intro(90);
		cout << "Introducido: 20" << endl;
		cout << "Introducido: 10" << endl;
		cout << "Introducido: 40" << endl;
		cout << "Introducido: 30" << endl;
		cout << "Introducido: 90" << endl;
		cout << "Numero: " << Cola.mostra() << endl;
		cout << "Numero: " << Cola.mostra() << endl;
		cout << "Numero: " << Cola.mostra() << endl;
		cout << "Numero: " << Cola.mostra() << endl;
		cout << "Numero: " << Cola.mostra() << endl;	
   cin.get();
   return 0;
}
