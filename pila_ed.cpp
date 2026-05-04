#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* siguiente;
};

class Pila{
	private:
		Nodo* cima; // peek, top
		
	public:
		Pila(){
			cima = NULL;
		}
		
		//verificar si la lista  esta vacia o no
		bool estaVacia(){
			return cima == NULL;
		}
			
		//insertar nuevo dato
			void push(int dato){
				Nodo* nuevo = new Nodo();
				nuevo->dato = dato;
				nuevo->siguiente = cima;
				cima = nuevo;
				cout << "Valor agregado correctamente" << endl;
			}
		
		//desplegar la pila
			void imprimir(){
				cout << endl;  
				if(estaVacia()){
					cout << "La pila esta vacia" << endl;
					return;
				}
				cout << "Pila: " << endl;
				Nodo* actual = cima;
				while(actual != NULL){
					cout << actual->dato << " -> ";
					actual = actual->siguiente;
				}
				cout << "NULL" << endl;
			}
				
		//eliminar valor
			void pop(){
				cout << endl;
				if(estaVacia()){
					cout << "La pila esta vacia" << endl;
					return;
				}
				
				Nodo* actual = cima;
				cout << "Nodo eliminado -> " << actual->dato << endl;
				cima = cima->siguiente;
				delete actual;
			}
				
		//ver primer valor
			void consultarCima(){
				cout << endl;
				if(estaVacia()){
					cout << "La pila esta vacia" << endl;
					return;
				}
				
				cout << "Cima: " << cima->dato << endl;
			}
		
		//contar los valores totales
			int contarElementos(){
				cout << endl;

				int num = 0;
				Nodo* actual = cima;
				while(actual != NULL){
					actual = actual->siguiente;
					num++;
				}
				
				return num;
			}
			
		//vaciar la pila (todos los elementos)
			void vaciarPila(){
				while(cima != NULL){
					Nodo* actual = cima;
					cima = cima->siguiente;
					delete actual;
				}
			}
};

void menu(){
	cout << endl;
	cout << "****** PILA ******" << endl;
	cout << "1. Push (Insertar)" << endl;
	cout << "2. Pop (Eliminar)" << endl;
	cout << "3. Ver primer elemento (Cima)" << endl;
	cout << "4. Imprimir pila" << endl; 
	cout << "5. Contar elementos" << endl;
	cout << "6. Vaciar la pila" << endl;
	cout << "0. Salir" << endl;
	cout << "Ingrese su opcion: ";
}


int main() {
	Pila pila;
	int opcion, valor;
	
	do{
		menu();
		cin >> opcion;
		
		if(opcion == 1){
			cout << "Valor: ";
			cin >> valor;
			pila.push(valor);
		} else if(opcion == 2){
			pila.pop();
		} else if(opcion == 3){
			pila.consultarCima();
		} else if(opcion == 4){
			pila.imprimir();
		} else if(opcion == 5){
			int cant = pila.contarElementos();
			cout << "La pila tiene: " << cant << " elementos" << endl;
		} else if(opcion == 6){
			pila.vaciarPila();
		}
		
	} while(opcion != 0);
	
	
	
	
	return 0;
}

