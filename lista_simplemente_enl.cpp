#include <iostream>
using namespace std;

struct Nodo {
	int dato;
	Nodo *siguiente;
};

class Lista {
private:
	Nodo *primero;
public:
	
	Lista() {
		primero = NULL;
	}
	
		bool estaVacia() {
			return primero == NULL;
		}
	
		void insertarInicio(int dato){
			Nodo *nuevo = new Nodo();
			nuevo->dato = dato;
			nuevo->siguiente = primero;
			primero = nuevo;
			cout << "Valor agregado correctamente" << endl;
		}
			
		void insertarFinal(int dato) {
			Nodo *nuevo = new Nodo();
			nuevo->dato = dato;
			nuevo->siguiente = NULL;
			
			if (estaVacia()) {
				primero = nuevo;
				return;
			}
			
			Nodo *actual = primero;
			while (actual->siguiente != NULL){
				actual = actual->siguiente;
			}
			actual->siguiente = nuevo;
		}
		
		void antesDe(int referencia, int dato) {
			if (estaVacia()) {
				cout << "La lista esta vacia" << endl;
				return;
			}
			
			Nodo *nuevo = new Nodo();
			nuevo->dato = dato;
			
			Nodo *actual = primero;
			Nodo *anterior = NULL;
			
			while (actual != NULL && actual->dato != referencia) {
				anterior = actual;
				actual = actual->siguiente;
			}
			
			if (actual == NULL) {
				cout << "Referencia no encontrada" << endl;
				return;
			}
			
			if (anterior == NULL) {
				nuevo->siguiente = primero;
				primero = nuevo;
			} else {
				anterior->siguiente = nuevo;
				nuevo->siguiente = actual;
			}
		}
		
		void Despuesde(int referencia, int dato) {
			if(estaVacia()) {
				cout << "La lista esta vacia" << endl;
				return;
			}
			
			Nodo *nuevo = new Nodo();
			nuevo->dato = dato;
			
			Nodo *actual = primero;
			
			while (actual != NULL && actual->dato != referencia) {
				actual = actual->siguiente;
			}
			
			if (actual == NULL) {
				cout << "Referencia no encontrada" << endl;
				return;
			}
			
			nuevo->siguiente = actual->siguiente;
			actual->siguiente = nuevo;
		}
		
		void imprimirLista() {
			cout << endl;
			cout << "Valores en lista" << endl;
			Nodo *actual = primero;
			while (actual != NULL) {
				cout << actual->dato << " -> ";
				actual = actual->siguiente;
			}
			cout << "NULL" << endl;
		}
		
		void removerPrimero() {
			cout << endl;
			cout << "Primer valor eliminado correctamente" << endl;
			if(estaVacia()){
				cout << "La lista esta vacia" << endl;
				return;
			}
			
			Nodo* actual = primero;
			primero = primero->siguiente;
			delete actual;
		}
		
		void removerUltimo(){
			if(estaVacia()){
				cout << "La lista esta vacia" << endl;
				return;
			}
			cout << "Ultimo valor eliminado correctamente" << endl;
			Nodo* actual = primero;
			Nodo* anterior = NULL;
			
			if(primero->siguiente == NULL){
				delete primero;
				primero = NULL;
				return;
			}
			
			while(actual->siguiente != NULL){
				anterior = actual;
				actual = actual->siguiente;
			}
			
			delete actual;
			anterior->siguiente = NULL;
		}
			
		void removerEspecifico(int dato){
			if(estaVacia()){
				cout << "La lista esta vacia" << endl;
				return;
			}
			
			Nodo* actual = primero;
			Nodo* anterior = NULL;
			
			while(actual != NULL && actual->dato != dato){
				anterior = actual;
				actual = actual->siguiente;
			}
			
			if(actual == NULL){
				cout << "Referencia no encontrada" << endl;
				return;
			}
			
			if(anterior == NULL){
				primero = primero->siguiente;
			}else{
				anterior->siguiente = actual->siguiente;
			}
			
			delete actual;
			
		}
			
		void buscarNodo(int dato){
			if(estaVacia()){
				cout << "La lista esta vacia" << endl;
				return;
			}
			
			Nodo* actual = primero;
			while(actual != NULL){
				if(actual->dato == dato){
					cout << "Nodo con valor (" << dato << ") encontrado!" << endl;
					return;
				}
				actual = actual->siguiente;
			}
			cout << "Nodo no encontrado" << endl;
		}
			
		void mostrarLista(Nodo* nodo){
			if(nodo == NULL) return;
				
			cout << nodo->dato << " -> ";
			mostrarLista(nodo->siguiente);
		}
			
		void mostrar2(){
			mostrarLista(primero);
			cout << "NULL";
		}
			
		int contarNodos(){
			int nodosNum = 0;
			if(estaVacia()) cout << "La lista esta vacia" << endl;
			
			Nodo* actual = primero;
			while(actual != NULL){
				nodosNum++;
				actual = actual->siguiente;
			}
			
			return nodosNum;
		}
			
		int nodoMayor(){
			if(estaVacia()){
				cout << "La lista esta vacia" << endl;
				return -1;
			}
			
			Nodo* actual = primero;
			int mayor = actual->dato;
			
			while(actual != NULL){
				if(actual->dato > mayor){
					mayor = actual->dato;
				}
				actual = actual->siguiente;
			}
			return mayor;
		}
			
		int nodMen(){
			if(estaVacia()){
				cout << "La lista esta vacia" << endl;
				return -1;
			}
				
			Nodo* actual = primero;
				int menor = actual->dato;
				
			while(actual != NULL){
				if(actual->dato < menor){
					menor = actual->dato;
				}
				actual = actual->siguiente;
			}
			return menor;
		}
			
		void invertirLista(){
			Nodo* anterior = NULL;
			Nodo* actual = primero;
			Nodo* siguiente = NULL;
			
			while(actual != NULL){
				siguiente = actual->siguiente;
				actual->siguiente = anterior;
				anterior = actual;
				actual = siguiente;
			}
			primero = anterior;
		}
};

void menu() {
	cout << endl;
	cout << "Lista enlazada" << endl;
	cout << "***********************************" <<endl;
	cout << "1. Insertar al inicio" << endl;
	cout << "2. Insertar al final" << endl;
	cout << "3. Insertar antes de..." << endl;
	cout << "4. Insertar despues de..." << endl;
	cout << "5. Remover primer valor" << endl;
	cout << "6. Remover ultimo valor" << endl;
	cout << "7. Remover valor especifico" << endl;
	cout << "8. Buscar" << endl;
	cout << "9. Desplegar lista" << endl;
	cout << "10. Despliegue recursivo" << endl;
	cout << "11. Contar nodos" << endl;
	cout << "12. Nodo mayor" << endl;
	cout << "13. Nodo menor" << endl;
	cout << "0. Salir" << endl;
	cout << "Selecciona una opcion: ";
}

int main() {
	Lista lista;
	
	int opcion, valor, ref;
	
	do {
		menu();
		cin >> opcion;
		
		if (opcion == 1) {
			cout << "Ingrese un valor: ";
			cin >> valor;
			lista.insertarInicio(valor);
		} else if (opcion == 2) {
			cout << "Ingrese un valor: ";
			cin >> valor;
			lista.insertarFinal(valor);
			
		} else if (opcion == 3) {
			cout << "Ingrese un valor: ";
			cin >> valor;
			cout << "Ingrese el valor antes del cual insertar: ";
			cin >> ref;
			lista.antesDe(ref, valor);
		} else if (opcion == 4) {
			cout << "Ingese un valor: ";
			cin >> valor;
			cout << "Ingrese el valor especifico: ";
			cin >> ref;
			lista.Despuesde(ref, valor);
			
		} else if (opcion == 5) {
			lista.removerPrimero();
			
		} else if (opcion == 6) {
			lista.removerUltimo();
			
		} else if (opcion == 7) {
			cout << "Ingrese el valor del nodo a eliminar: ";
			cin >> valor;
			lista.removerEspecifico(valor);
			
		} else if (opcion == 8) {
			cout << "Ingrese el valor del nodo a buscar: ";
			cin >> valor;
			lista.buscarNodo(valor);
			
		} else if (opcion == 9) {
			lista.mostrar2();
			
		} else if (opcion == 10){
			cout << "Lista de forma recursiva" << endl;
			lista.mostrar2();	
			
		} else if(opcion == 11){
			int numNodos = lista.contarNodos();
			cout << "El numero de nodos es: " << numNodos << endl;
			
		}else if (opcion == 12){
			int nodMay = lista.nodoMayor();
			cout << "El nodo con mayor valor es: " << nodMay << endl;
			
		}else if(opcion == 13){ 
			int nodoMenor = lista.nodMen();
			cout << "El nodo menor es: " << nodoMenor << endl;
			
		}else if(opcion == 14){
			cout << "Lista invertida correctamente" << endl;
			cout << "Pulse 9 o 10 para visualizar" << endl;
			lista.invertirLista();
			
		}else if(opcion == 0){
			cout << "Saliendo...." << endl;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}while (opcion != 0);
	
	return 0;
}
