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

int mostrarMinimo(Nodo* raiz){
    if (raiz != nullptr) {
        if (raiz->izquierdo == nullptr){
            return raiz->dato;
        }else {
            return mostrarMinimo(raiz->izquierdo);
        }
    }
}

int mostrarMaximo(Nodo* raiz){
    if (raiz != nullptr) {
        if (raiz->derecho == nullptr){
            return raiz->dato;
        }else {
            return mostrarMaximo(raiz->derecho);
        }
    }
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
}

void mostrarMenu(){
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
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
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
            cout << "El valor minimo del arbol es: ";
            mostrarMinimo(raiz);
            cout << endl;
        }else if (opcion == 7) {
            cout << "El valor maximo del arbol es: ";
            mostrarMaximo(raiz);
            cout << endl;
        }else if (opcion == 8) {
            cout << "Eliminar valor: ";
            cin >> valor;
            raiz = eliminarValor(raiz, valor);
        }
    }while(opcion != 0);

    return 0;
}
