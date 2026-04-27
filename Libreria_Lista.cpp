#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void menu(){
	cout << endl;
	cout << "Lista enlazada" << endl;
	cout << "***********************************" <<endl;
	cout << "1. Insertar al inicio" << endl;
	cout << "2. Insertar al final" << endl;
	cout << "3. Remover primer valor" << endl;
	cout << "4. Remover ultimo valor" << endl;
	cout << "5. Remover valor especifico" << endl;
	cout << "6. Buscar" << endl;
	cout << "7. Desplegar lista" << endl;
	cout << "8. Contar nodos" << endl;
	cout << "9. Nodo mayor y menor" << endl;
	cout << "0. Salir" << endl;
	cout << "Selecciona una opcion: ";
}

int main() {
	list<int> lista;
	int opcion, valor;
	do{
		menu();
		cin >> opcion;
		
		if(opcion == 1){
			cout << "Ingrese un valor: ";
			cin >> valor;
			lista.push_front(valor);
		}else if(opcion == 2){
			cout << "Ingrese un valor: ";
			cin >> valor;
			lista.push_back(valor);
		}else if(opcion == 3){
			if(lista.empty()){
				cout << "Lista vacia, nada puede ser eliminado" << endl;
				continue;
			}
			cout << endl;
			cout << "Primer elemento eliminado correctamente" << endl;
			lista.pop_front();
		}else if(opcion == 4){
			if(lista.empty()){
				cout << "Lista vacia, nada puede ser eliminado" << endl;
				continue;
			}
			cout << endl;
			cout << "Ultimo elemento eliminado correctamente" << endl;
			lista.pop_back();
		}else if(opcion == 5){
			if(lista.empty()){
				cout << "Lista vacia, nada puede ser eliminado" << endl;
				continue;
			}
			cout << endl;
			cout << "Ingrese el valor a eliminar: ";
			cin >> valor;
			lista.remove(valor);
		}else if(opcion == 6){
			if(lista.empty()){
				cout << "Lista vacia, nada puede ser buscado" << endl;
				continue;
			}
			cout << endl;
			cout << "Ingrese el valor a buscar: ";
			cin >> valor;
			
			bool encontrado = false;
			for(int x : lista){
				if(x == 10){
					encontrado = true;
					break;
				}
			}
			
			if(encontrado){
				cout << "El valor fue encontrado exitosamente" << endl;
			}else{
				cout << "El valor no pudo ser encontrado" << endl;
			}
		}else if(opcion == 7){
			if(lista.empty()){
				cout << "Lista vacia, no se puede mostrar" << endl;
				continue;
			}
			cout << endl;
			cout << "Lista" << endl;
			for(int x : lista){
				cout << x << " -> ";
			}
			cout << "FIN" << endl;
		}else if(opcion == 8){
			if(lista.empty()){
				cout << "Lista vacia, no se puede mostrar" << endl;
				continue;
			}
			cout << endl;
			int nodos = 0;
			for(int x : lista){
				nodos++;
			}
			cout << "La cantidad de nodos existentes es: " << nodos << endl;
		}else if(opcion == 9){
			if(lista.empty()){
				cout << "Lista vacia, nada puede ser mostrado" << endl;
				continue;
			}
			cout << endl;
			auto min_it = min_element(lista.begin(), lista.end());
			auto max_it = max_element(lista.begin(), lista.end());
			
			cout << "El nodo mas pequeño es: " << *min_it << endl;
			cout << "El nodo mas grande es: " << *max_it << endl;
		}else if(opcion == 0){
			cout << endl;
			cout << "Saliendo..." << endl;
		}
		
	} while(opcion != 0);
	return 0;
}

