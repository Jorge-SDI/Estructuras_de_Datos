#include <iostream>
#include <queue>
using namespace std;

struct Nodo{
	int dato;
	Nodo* izquierdo;
	Nodo* derecho;
	
	Nodo(int valor){
		dato = valor;
		izquierdo = nullptr;
		derecho = nullptr;
	}
};

Nodo* insertarNodo(Nodo* raiz, int valor){
	
	if(raiz == nullptr){
		return new Nodo(valor);
	}
	
	if(valor < raiz->dato){
		raiz->izquierdo = insertarNodo(raiz->izquierdo, valor);
	}
	else if(valor > raiz->dato){
		raiz->derecho = insertarNodo(raiz->derecho, valor);
	}
	
	return raiz;
}
	
	void recorridoPorNiveles(Nodo* raiz){
		
		if(raiz == nullptr){
			return;
		}
		
		queue<Nodo*> cola;
		
		cola.push(raiz);
		
		while(!cola.empty()){
			
			Nodo* actual = cola.front();
			cola.pop();
			
			cout << actual->dato << " ";
			
			if(actual->izquierdo != nullptr){
				cola.push(actual->izquierdo);
			}
			
			if(actual->derecho != nullptr){
				cola.push(actual->derecho);
			}
		}
	}
		
		int main(){
			
			Nodo* raiz = nullptr;
			
			raiz = insertarNodo(raiz, 9);
			raiz = insertarNodo(raiz, 6);
			raiz = insertarNodo(raiz, 7);
			raiz = insertarNodo(raiz, 17);
			raiz = insertarNodo(raiz, 27);
			raiz = insertarNodo(raiz, 21);
			raiz = insertarNodo(raiz, 22);
			raiz = insertarNodo(raiz, 30);
			
			cout << "Recorrido por niveles: ";
			recorridoPorNiveles(raiz);
			
			return 0;
		}

			
			
			/*
			#include <iostream>
			#include <queue>
			using namespace std;
			
			struct Nodo{
			int dato;
			Nodo* izquierda;
			Nodo* derecha;
			};
			
			void imprimirPorNiveles(Nodo* raiz){
			
			if(raiz == nullptr) return;
			
			queue<Nodo*> cola;
			
			cola.push(raiz);
			
			while(!cola.empty()){
			
			int cantidad = cola.size();
			
			for(int i = 0; i < cantidad; i++){
			
			Nodo* actual = cola.front();
			cola.pop();
			
			cout << actual->dato << " ";
			
			if(actual->izquierda != nullptr){
			cola.push(actual->izquierda);
			}
			
			if(actual->derecha != nullptr){
			cola.push(actual->derecha);
			}
			}
			
			cout << endl;
			}
			}
