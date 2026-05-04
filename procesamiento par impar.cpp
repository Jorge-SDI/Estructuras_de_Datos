#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* siguiente;
};

class Cola{
private:
	Nodo* Frente;
	Nodo* Final;
	
public:
	Cola(){
		Frente = nullptr;
	}
	
	bool vacio(){
		return Frente == nullptr;
	}
	
	void insertar(int dato){
		Nodo* nuevo = new Nodo;
		nuevo->dato = dato;
		nuevo->siguiente = nullptr;
		
		if(Frente == nullptr){
			Frente = Final = nuevo;
		}else{
			Final->siguiente = nuevo;
			Final = nuevo;
		}
	}
		
	void mostrar(){
		cout << endl;
		if(vacio()){
			cout << "Sin valores existentes" << endl;
			return;
		}
		cout << "Valores procesados" << endl;
		Nodo* actual = Frente;
		while(actual != nullptr){
			cout << actual->dato << " ";
			actual = actual->siguiente;
		}
	}
};
int main() {
	Cola proceso;
	int opcion, dato;
	
	do{
		cout << endl;
		cout << "Filtro con propiedad temporal" << endl;
		cout << "1. Entrada de datos." << endl;
		cout << "2. Valores procesados." << endl;
		cout << "0. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		if(opcion == 1){
			int n;
			cout << "Numero de datos que dara entrada: ";
			cin >> n;
			
			cout << endl;
			for(int i = 0; i < n; i++){
				cout << "Dato: "; cin >> dato;
					if(dato < 0){
						cout << dato << " " << "eliminado" << endl;
					}else{
						proceso.insertar(dato);
					}
			}
		}else if(opcion == 2){
			proceso.mostrar();
		}else if(opcion == 0){
			cout << endl;
			cout << "Saliendo" << endl;
		}
	} while(opcion != 0);
	return 0;
}

