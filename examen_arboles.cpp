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

Nodo* insertar(Nodo* raiz, int valor){
	if(raiz == nullptr){
		return new Nodo(valor);
	}
	
	if(valor < raiz->dato){
		raiz->izquierda = insertar(raiz->izquierda, valor);
	}else if(valor > raiz->dato){
		raiz->derecha = insertar(raiz->derecha, valor);
	}else{
		cout << "El valor esta repetido" << endl;
	}
	
	return raiz;
}
	
void recorridoInOrder(Nodo* raiz){
	if(raiz != nullptr){
		recorridoInOrder(raiz->izquierda);
		cout << raiz->dato << " ";
		recorridoInOrder(raiz->derecha);
	}
}

Nodo* valorMinimo(Nodo* raiz){
	while(raiz != nullptr && raiz->izquierda != nullptr){
		raiz = raiz->izquierda;
	}
	return raiz;
}

Nodo* eliminarValor(Nodo *raiz, int valor) {
	if (raiz == nullptr) {
		return raiz;
	}
	if (valor < raiz->dato) {
		raiz->izquierda = eliminarValor(raiz->izquierda, valor);
	}else if (valor > raiz->dato){
		raiz->derecha = eliminarValor(raiz->derecha, valor);
	}else {
		//caso 1: nodo hoja
		if (raiz->izquierda == nullptr && raiz->derecha == nullptr) {
			delete raiz;
			return nullptr;
		}
			
		//caso 2.1: tiene un hijo y es del lado izquierdo
		if (raiz->derecha == nullptr) {
			Nodo* temp = raiz->izquierda;
			delete raiz;
			return temp;
		}
			
		//caso 2.2: tiene un hijo y es del lado derecho
		if (raiz->izquierda == nullptr) {
			Nodo* temp = raiz->derecha;
			delete raiz;
			return temp;
		}
			
		//caso 3: nodo con 2 hijos
		Nodo* sucesor = valorMinimo(raiz->derecha);
		raiz->dato = sucesor->dato;
		raiz->derecha = eliminarValor(raiz->derecha, sucesor->dato);
	}
	return raiz;
}

void invertirArboll(Nodo* raiz){
	if(raiz == nullptr) return;
	
	Nodo* temp = raiz->izquierda;
	raiz->izquierda = raiz->derecha;
	raiz->derecha = temp;
	
	invertirArboll(raiz->izquierda);
	invertirArboll(raiz->derecha);
}

Nodo* eliminarHojas(Nodo* raiz){
	if(raiz == nullptr) return raiz;

	
	if(raiz->izquierda == nullptr && raiz->derecha == nullptr){
		Nodo* temp = eliminarValor(raiz, raiz->dato);
		return temp;
	}
	
	raiz->izquierda = eliminarHojas(raiz->izquierda);
	raiz->derecha = eliminarHojas(raiz->derecha);
	
	return raiz;
}

void mostrarNodosHojas(Nodo* raiz){
	if(raiz == nullptr) return;
	
	if(raiz->izquierda == nullptr && raiz->derecha == nullptr){
		cout << raiz->dato << " ";
	}
	
	mostrarNodosHojas(raiz->izquierda);
	mostrarNodosHojas(raiz->derecha);
}
	
Nodo* eliminarImpares(Nodo* raiz){
	if(raiz == nullptr) return raiz;
	
	raiz->izquierda = eliminarImpares(raiz->izquierda);
	raiz->derecha = eliminarImpares(raiz->derecha);
	
	if(raiz->dato % 2 != 0){
		Nodo* temp = eliminarValor(raiz, raiz->dato);
		return temp;
	}
	
	return raiz;
}
	
Nodo* duplicarHojas(Nodo* raiz){
	if(raiz == nullptr) return raiz;
	
	if(raiz->izquierda == nullptr && raiz->derecha == nullptr){
		raiz->derecha = insertar(raiz->derecha, raiz->dato*2);
		return raiz;
	}
	
	raiz->izquierda = duplicarHojas(raiz->izquierda);
	raiz->derecha = duplicarHojas(raiz->derecha);
	
	return raiz;
}
	
void mostrarNivel(Nodo* raiz, int nivelActual, int nivelBuscado){
	if(raiz == nullptr) return;
	
	if(nivelActual == nivelBuscado){
		cout << raiz->dato << " ";
	}
	
	mostrarNivel(raiz->izquierda, nivelActual+1, nivelBuscado);
	mostrarNivel(raiz->derecha, nivelActual+1, nivelBuscado);
}

void mostrarMenu(){
	cout << endl;
	cout << "1. Ingresar valores" << endl;
	cout << "2. Recorrido InOrder" << endl;
	cout << "3. Eliminar hojas" << endl;
	cout << "4. Mostrar nodos hojas" << endl;
	cout << "5. Eliminar valores impares" << endl;
	cout << "6. Duplicar nodos hojas" << endl;
	cout << "7. Mostrar nodos de un nivel" << endl;
	cout << "Ingrese una opcion: ";
}
int main() {
	Nodo* raiz = nullptr;
	int opcion, valor;
	
	do{
		mostrarMenu();
		cin >> opcion;
		
		if(opcion == 1){
			cout << endl;
			cout << "Valor del nodo: ";
			cin >> valor;
			raiz = insertar(raiz, valor);
			cout << "Insertado correctamente" << endl;
		}else if(opcion == 2){
			cout << endl;
			cout << "Valores del arbol" << endl;
			recorridoInOrder(raiz);
		}else if(opcion == 3){
			cout << endl;
			cout << "Nodos hojas eliminados" << endl;
			raiz = eliminarHojas(raiz);
		}else if(opcion == 4){
			cout << endl;
			cout << "Nodos hojas del arbol" << endl;
			mostrarNodosHojas(raiz);
		}else if(opcion == 5){
			cout << endl;
			cout << "Valores impares borrados del arbol" << endl;
			raiz = eliminarImpares(raiz);
		}else if(opcion == 6){
			cout << endl;
			cout << "Valores hojas duplicados" << endl;
			raiz = duplicarHojas(raiz);
		}else if(opcion == 7){
			cout << endl;
			int nivelBuscado;
			cout << "Nivel  buscado: ";
			cin >> nivelBuscado;
			
			cout << endl;
			cout << "Nodos del nivel " << nivelBuscado << endl;
			mostrarNivel(raiz, 0, nivelBuscado);
		}else if(opcion == 0){
			cout << "Saliendo..." << endl;
		}
	} while(opcion != 0);
	
	return 0;
}

