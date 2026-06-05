#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* izquierda;
	Nodo* derecha;
	
	Nodo(int valor){
		dato = valor;
		izquierda = nullptr;
		derecha = nullptr;
	}
};

Nodo* insertarNodo(Nodo* raiz, int valor){
	if(raiz == nullptr){
		return new Nodo(valor);
	}
	
	if(valor < raiz->dato){
		raiz->izquierda = insertarNodo(raiz->izquierda, valor);
	}else if(valor > raiz->dato){
		raiz->derecha = insertarNodo(raiz->derecha, valor);
	}else{
		cout << "El valor está duplicado" << endl;
	}
	
	return raiz;
}

bool buscarNodo(Nodo* raiz, int valor){
	if(raiz == nullptr) return false;
	
	if(raiz->dato == valor){
		return true;
	}
	
	if(valor < raiz->dato){
		return buscarNodo(raiz->izquierda, valor);
	}else{
		return buscarNodo(raiz->derecha, valor);
	}
}
	
void inOrder(Nodo* raiz){
	if(raiz != nullptr){
		inOrder(raiz->izquierda);
		cout << raiz->dato << " ";
		inOrder(raiz->derecha);
	}
}
	
void postOrder(Nodo* raiz){
	if(raiz != nullptr){
		postOrder(raiz->izquierda);
		postOrder(raiz->derecha);
		cout << raiz->dato << " ";
	}
}
	
void preOrder(Nodo* raiz){
	if(raiz != nullptr){
		cout << raiz->dato;
		preOrder(raiz->izquierda);
		preOrder(raiz->derecha);
	}
}
	
void minimo(Nodo* raiz){
	while(raiz != nullptr && raiz->izquierda != nullptr){
		raiz = raiz->izquierda;
	}
	
	cout << raiz->dato;
}
	
int contarAltura(Nodo* raiz){
	if(raiz == nullptr) return 0;
	
	int izq = contarAltura(raiz->izquierda);
	int der = contarAltura(raiz->derecha);
	
	if(izq > der){
		return 1 + izq;
	}
	
	return 1 + der;
}
	
int contarNodos(Nodo* raiz){
	if(raiz == nullptr) return 0;
	
	return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}
	
int contarHojas(Nodo* raiz){
	if(raiz == nullptr) return 0;
	
	if(raiz->izquierda == nullptr && raiz->derecha == nullptr){
		return 1;
	}
	
	return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
}
	
Nodo* eliminar(Nodo* raiz, int valor){
	if(raiz == nullptr) return raiz;
	
	if(valor < raiz->dato){
		raiz->izquierda = eliminar(raiz->izquierda, valor);
	}else if(valor > raiz->dato){
		raiz->derecha = eliminar(raiz->derecha, valor);
	}else{
		//hoja
		if(raiz->izquierda == nullptr && raiz->derecha == nullptr){
			delete raiz;
			return nullptr;
		}
		
		//nodo izquierdo
		if(raiz->derecha == nullptr){
			Nodo* temp = raiz->izquierda;
			delete raiz;
			return temp;
		}
		
		//nodo derecho
		if (raiz->izquierdo == nullptr) {
			Nodo* temp = raiz->derecho;
			delete raiz;
			return temp;
		}
		
		//dos hijos
		Nodo* sucesor = mostrarMinimo(raiz->derecho);
		raiz->dato = sucesor->dato;
		raiz->derecho = eliminarValor(raiz->derecho, sucesor->dato);
	}
	return raiz;
}
	
int main() {
	Nodo* raiz = nullptr;
	int opcion, valor;
	do{
		cout << "1. Insertar" << endl;
		cout << "2. Contar hojas" << endl;
		cin >> opcion;
		
		if(opcion == 1){
			cout << "Valor para el nodo: ";
			cin >> valor;
			raiz = insertarNodo(raiz, valor);
		}else if(opcion == 2){
			int hojas = contarHojas(raiz);
			cout << "Hojas del arbol " << hojas << endl;
		}
	} while(opcion != 0);
	return 0;
}

