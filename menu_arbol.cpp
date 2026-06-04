#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* derecho;
	Nodo* izquierdo;
	
	Nodo(){
		izquierdo = nullptr;
		derecho = nullptr;
	}
		
		Nodo(int valor){
			dato = valor;
			izquierdo = nullptr;
			derecho = nullptr;
		}
			
};

Nodo* insertarNodo(Nodo* &raiz, int valor){
	if(raiz == nullptr){
		return new Nodo(valor);
	}
	if(valor < raiz->dato){
		raiz->izquierdo = insertarNodo(raiz->izquierdo, valor);
	}
	else if(valor > raiz->dato){
		raiz->derecho = insertarNodo(raiz->derecho, valor);
	}else{
		cout << "El valor esta duplicado" <<  endl;
	}
	
	return raiz;
}
	
	bool buscarNodo(Nodo* raiz, int valor) {
		if (raiz == nullptr) {
			return false;
		}
		if (raiz->dato == valor) {
			return true;
		}
		if (valor < raiz->dato) {
			return buscarNodo(raiz->izquierdo, valor);
		}else{
			return buscarNodo(raiz->derecho, valor);
		}
	}
	
	void InOrder(Nodo* raiz) {
		if (raiz != nullptr) {
			InOrder(raiz->izquierdo);
			cout << raiz->dato << " ";
			InOrder(raiz->derecho);
		}
	}
	
	void PostOrder(Nodo* raiz) {
		if (raiz != nullptr) {
			PostOrder(raiz->izquierdo);
			PostOrder(raiz->derecho);
			cout << raiz->dato << " ";
		}
	}
	
	void PreOrder(Nodo* raiz) {
		if (raiz != nullptr) {
			cout << raiz->dato << " ";
			PreOrder(raiz->izquierdo);
			PreOrder(raiz->derecho);
		}
	}
	
	Nodo* mostrarMinimo(Nodo* raiz){
		while (raiz != NULL && raiz->izquierdo != NULL) {
			raiz = raiz->izquierdo;
		}
		return raiz;
	}
		
	Nodo* mostrarMaximo(Nodo* raiz){
		while (raiz != NULL && raiz->derecho != NULL) {
			raiz = raiz->derecho;
		}
		return raiz;
	}
			
	Nodo* eliminarValor(Nodo *raiz, int valor) {
		if (raiz == nullptr) {
			return raiz;
		}
		if (valor < raiz->dato) {
			raiz->izquierdo = eliminarValor(raiz->izquierdo, valor);
		}else if (valor > raiz->dato){
			raiz->derecho = eliminarValor(raiz->derecho, valor);
		}else {
			//caso 1: nodo hoja
			if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) {
				delete raiz;
				return nullptr;
			}
				
			//caso 2.1: tiene un hijo y es del lado izquierdo
			if (raiz->derecho == nullptr) {
				Nodo* temp = raiz->izquierdo;
				delete raiz;
				return temp;
			}
					
			//caso 2.2: tiene un hijo y es del lado derecho
			if (raiz->izquierdo == nullptr) {
				Nodo* temp = raiz->derecho;
				delete raiz;
				return temp;
			}
					
			//caso 3: nodo con 2 hijos
			Nodo* sucesor = mostrarMinimo(raiz->derecho);
			raiz->dato = sucesor->dato;
			raiz->derecho = eliminarValor(raiz->derecho, sucesor->dato);
		}
		return raiz;
	}
			
	void mostrarMenu(){
		cout << endl;
		cout << "Arbol binario de busqueda" << endl;
		cout << "1. Insertar valor" << endl;
		cout << "2. Buscar valor" << endl;
		cout << "3. Recorrido InOrder" << endl;
		cout << "4. Recorrido PostOrder" << endl;
		cout << "5. Recorrido PreOrder" << endl;
		cout << "6. Mostrar minimo" << endl;
		cout << "7. Mostrar maximo" << endl;
		cout << "8. Eliminar valor" << endl;
		cout << "9. Contar nodos" << endl;
		cout << "10. Contar hojas" << endl;
		cout << "11. Mostrar altura" << endl;
		cout << "12. Contar nodos con un solo hijo: " << endl;
		cout << "13. Sumar todo el arbol" << endl;
		cout << "14. Mostrar nodos pares" << endl;
		cout << "15. Contar nodos pares" << endl;
		cout << "16. Invertir el arbol" << endl;
		cout << "17. Mostrar nodos impares" << endl;
		cout << "18. Mostrar nodos mayores a X" << endl;
		cout << "19. Eliminar valores mayores a X" << endl;
		cout << "0. Salir" << endl;
		cout << "Seleccione una opcion: ";
	}
				
	int contarNodosR(Nodo* raiz) {
		if (raiz == nullptr) return 0;
		return 1 + contarNodosR(raiz->izquierdo) + contarNodosR(raiz->derecho);
	}
				
	int contarHojas(Nodo* raiz) {
		if (raiz == nullptr) return 0;
		if (raiz->izquierdo == nullptr && raiz->derecho == nullptr) return 1;
					
		return contarHojas(raiz->izquierdo) + contarHojas(raiz->derecho);
	}
				
	int contarAltura(Nodo* raiz) {
		if (raiz == nullptr) return 0;
		int izquierda = contarAltura(raiz->izquierdo);
		int derecha = contarAltura(raiz->derecho);
					
		if (izquierda > derecha) {
			return  1 + izquierda;
		}
		return 1 + derecha;
	}
				
	int contarNodosConUnHijo(Nodo* raiz) {
		if (raiz == nullptr) return 0;
		if(raiz->izquierdo != nullptr && raiz->derecho == nullptr) return 0; 
		if(raiz->izquierdo == nullptr && raiz->derecho != nullptr) return 0;
		
		return 1 + contarNodosConUnHijo(raiz->izquierdo) + contarNodosConUnHijo(raiz->derecho);
	}
	
	int sumaTotalArbol(Nodo* raiz){
		if(raiz == nullptr){
			return 0;
		}
		
		int sumaIzquierda = sumaTotalArbol(raiz->izquierdo);
		int sumaDerecha = sumaTotalArbol(raiz->derecho);
		
		return raiz->dato + sumaIzquierda + sumaDerecha;
	}
		
	void nodosPares(Nodo* raiz){
		if(raiz == nullptr) return;
		
		if(raiz->dato % 2 == 0){
			cout << raiz->dato << " ";
		}
		nodosPares(raiz->izquierdo);
		nodosPares(raiz->derecho);
	}
				
	int contarPares(Nodo* raiz){
		if(raiz == nullptr){
			return 0;
		}
		
		int contador=0;
		
		if(raiz->dato % 2 == 0)contador = 1; 
		return contador + contarPares(raiz->izquierdo) + contarPares(raiz->derecho);
	}
		
	void invertirArbol(Nodo* raiz){
		if(raiz == nullptr) return;
		
		Nodo* temp = raiz->izquierdo;
		raiz->izquierdo = raiz->derecho;
		raiz->derecho = temp;
		
		invertirArbol(raiz->izquierdo);
		invertirArbol(raiz->derecho);
	}
		
	void nodosImpares(Nodo* raiz){
		if(raiz == nullptr) return;
		
		if(raiz->dato % 2 != 0){
			cout << raiz->dato << " ";
		}
		
		nodosImpares(raiz->izquierdo);
		nodosImpares(raiz->derecho);
	}
		
	void mayoresAX(Nodo* raiz, int n){
		if(raiz == nullptr) return;
		
		if(raiz->dato > n){
			cout << raiz->dato << " ";
		}
		
		mayoresAX(raiz->izquierdo, n);
		mayoresAX(raiz->derecho, n);
	}
		
	Nodo* eliminarMayoresA(Nodo* raiz, int n){
		if(raiz == nullptr) return raiz;
		
		raiz->izquierdo = eliminarMayoresA(raiz->izquierdo, n);
		raiz->derecho = eliminarMayoresA(raiz->derecho, n);
		
		if(raiz->dato > n){
			Nodo* temp = eliminarValor(raiz, raiz->dato);
			return temp;
		}
		
		return raiz;
	}
		
int main(){
	Nodo* raiz = nullptr;
	int opcion, valor;
					
	do {
		mostrarMenu();
		cin >> opcion;
						
		if(opcion == 1){
			cout << "Ingrese el valor: ";
			cin >> valor;
			raiz = insertarNodo(raiz, valor);
		}else if (opcion == 2) {
			cout << "Ingrese el valor: ";
			cin >> valor;
			if (buscarNodo(raiz, valor)) {
			cout << "El valor esta encontrado" << endl;
		}else {
			cout << "El valor no encontrado" << endl;
		}
		}else if (opcion == 3) {
			cout << "Recorrido InOrder" << endl;
			InOrder(raiz);
			cout << endl;
		}else if (opcion == 4) {
			cout << "Recorrid PostOrder" << endl;
			PostOrder(raiz);
			cout << endl;
		}else if (opcion == 5) {
			cout << "Recorrid PreOrder" << endl;
			PreOrder(raiz);
			cout << endl;
		}else if (opcion == 6) {
			Nodo* min = mostrarMinimo(raiz);
			if (min != nullptr) {
				cout << "El valor minimo del arbol es: " << min->dato << endl;
			}else {
				cout << "...." << endl;
			}
		}else if (opcion == 7) {
			Nodo* max = mostrarMaximo(raiz);
			if (max != nullptr) {
				cout << "El valor mas grande del arbol es: " << max->dato << endl;
			}else {
				cout << "...." << endl;
			}
		}else if (opcion == 8) {
			cout << "Eliminar valor: ";
			cin >> valor;
			raiz = eliminarValor(raiz, valor);
		}else if (opcion == 9) {
			int i = contarNodosR(raiz);
			cout << "Cantidad de nodos del arbol: " << i << endl;
			cout << endl;
		}else if (opcion == 10) {
			int i = contarHojas(raiz);
			cout << "Cantidad de hojas del arbol: " << i << endl;
			cout << endl;
		}else if (opcion == 11) {
			int alt = contarAltura(raiz);
			cout << "La altura del arbol es: " << alt << endl;
		}else if (opcion == 12) {
			int unHijo = contarNodosConUnHijo(raiz);
			cout << "El arbol tiene " << unHijo << " nodos con un solo hijo" << endl;
		}else if(opcion == 13){
			int sumTot = sumaTotalArbol(raiz);
			cout << "La suma de todos los elementos del arbol es: " << sumTot << endl;
		}else if(opcion == 14){
			cout << "Nodos pares del arbol: ";
			nodosPares(raiz);
		}else if(opcion == 15){
			int cant = contarPares(raiz);
			cout << "Cantidad de nodos pares: " << cant << endl;
		}else if(opcion == 16){
			cout << "Arbol invertido correctamente" << endl;
			invertirArbol(raiz);
		}else if(opcion == 17){
			cout << "Nodos impares del arbol: ";
			nodosImpares(raiz);
		}else if(opcion == 18){
			int n;
			cout << "Numero: ";
			cin >> n;
			
			cout << endl;
			cout << "Nodos mayores a " << n << endl;
			mayoresAX(raiz, n);
		}else if(opcion == 19){
			int limite;
			cout << "Numero: ";
			cin >> limite;
			
			cout << endl;
			raiz = eliminarMayoresA(raiz, limite);
			cout << "Valores eliminados correctamente" << endl;
		}
	}while(opcion != 0);
	
	return 0;
}
