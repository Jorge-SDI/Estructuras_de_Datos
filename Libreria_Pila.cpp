#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> pila;
	int opcion, valor;
	
	do{
		cout << endl;
		cout << "Pila" << endl;
		cout << "1. Agregar valor" << endl;
		cout << "2. Eliminar valor" << endl;
		cout << "3. Ver primer valor" << endl;
		cout << "4. Imprimir pila" << endl;
		cout << "5. Contar elementos" << endl;
		cout << "6. Vaciar pila" << endl;
		cout << "0. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		if(opcion == 1){
			cout << endl;
			cout << "Ingrese su valor: ";
			cin >> valor;
			pila.push(valor);
			cout << "Se agrego correctamente" << endl;
		}else if(opcion == 2){
			cout << endl;
			if(pila.empty()){
				cout << "No se puede eliminar puesto que esta vacia" << endl;
				continue;
			}
			cout << "Valor eliminado correctamente" << endl;
			pila.pop();
		}else if(opcion == 3){
			cout << endl;
			if(pila.empty()){
				cout << "No se puede visualizar el valor puesto que esta vacia" << endl;
				continue;
			}
			cout << "La cima es: " << pila.top() << endl;
		}else if(opcion == 4){
			cout << endl;
			if(pila.empty()){
				cout << "No se puede desplegar puesto que esta vacia" << endl;
				continue;
			}
			stack<int> copia = pila;
			cout << "Pila desplegada" << endl;
			while(!copia.empty()){
				cout << copia.top() << endl;
				copia.pop();
			}
		}else if(opcion == 5){
			cout << endl;
			if(pila.empty()){
				cout << "No se puede contar puesto que esta vacia" << endl;
				continue;
			}
			cout << "La pila tiene: " << pila.size() << " elementos" << endl;
		}else if(opcion == 6){
			cout << endl;
			if(pila.empty()){
				cout << "No se puede vaciar puesto que esta vacia" << endl;
				continue;
			}
			cout << "Pila vaciada correctamente" << endl;
			while(!pila.empty()){
				pila.pop();
			}
		}else if(opcion == 0){
			cout << endl;
			cout << "Saliendo..." << endl;
		}
	} while(opcion != 0);
	
	
	return 0;
}

