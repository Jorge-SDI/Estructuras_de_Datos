#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* siguiente;
};

class Cola{
	private:
		Nodo* primero;
		Nodo* cima;
	
	public:
		Cola(){
			primero = NULL;
		}
	
		bool estaVacia(){
			return primero == NULL;
		}
			
		void insertar(int dato){
			Nodo* nuevo = new Nodo();
			
			nuevo->dato = dato;
			nuevo->siguiente = NULL;
			
			if(estaVacia()){
				primero = nuevo;
			} else{
				cima->siguiente = nuevo;
			}
			cima = nuevo;
			cout << "Valor insertado correctamente" << endl;
		}
			
		//dequeue	
		void eliminar(){
			if(estaVacia()){
				cout << "La cola esta vacia" << endl;
				return;
			}
			
			Nodo* actual = primero;
			primero = primero->siguiente;
			delete actual;
			
			if(primero == NULL){
				cima = NULL;
			}
		}
			
		void verCima(){
			if(!estaVacia()){
				cout << primero->dato << endl;
			}else{
				cout << "Cola vacia" << endl;
			}
			
		}
			
		void imprimir(){
			Nodo* actual = primero;
			while(actual != NULL){
				cout << actual->dato << " -> ";
				actual =  actual->siguiente;
			}
			cout << "NULL" << endl;
		}
			
		void vaciarCola(){
			Nodo* actual = primero;
			
			while(actual !=	NULL){
				actual = actual->siguiente;
				delete actual;
			}
		}
	
};

void menu(){
	cout << endl;
	cout << "********* Cola *********" << endl;
	cout << "1. Insertar valor (ENQUEUE)" << endl;
	cout << "2. Eliminar valor (DEQUEUE)" << endl;
	cout << "3. Ver cima (PEEK)" << endl;
	cout << "4. Verificar si esta vacia" << endl;
	cout << "5. Imprimir cola" << endl;
	cout << "6. Vaciar / eliminar cola" << endl;
	cout << "0. Salir" << endl;
	
}

int main() {
	Cola cola;
	int opcion, dato;
	
	do{
		menu();
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		if(opcion == 1){
			cout << "Ingrese un valor: ";
			cin >> dato;
			cola.insertar(dato);
			
		} else if(opcion == 2){
			cout << "Eliminar" << endl;
			cola.eliminar();
			
		} else if(opcion == 3){
			cout << "Imprimiendo cima..." << endl;
			cola.verCima();
			
		} else if(opcion == 4){
			if(cola.estaVacia()){
				cout << "La lista esta vacia" << endl;
			} else{
				cout << "La lista no esta vacia" << endl;
			}
			
		} else if(opcion == 5){
			cout << endl;
			cout << "Cola" << endl;
			cola.imprimir();
			
		} else if(opcion == 6){
			cola.vaciarCola();
			
		} else if(opcion == 0){
			cout << "Saliendo" << endl;
		}
	} while(opcion != 0);
	
	return 0;
}

