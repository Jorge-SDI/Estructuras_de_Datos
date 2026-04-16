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
        cout << "Inserte al inicio" << endl;
        Nodo *nuevo = new Nodo();
        nuevo->dato = dato;
        nuevo->siguiente = primero;
        primero = nuevo;
        cout << "Valor agregado correctamente" << endl;
    }
    void insertarFinal(int dato) {
        cout << "Inserte al final" << endl;
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
        Nodo *nuevo = new Nodo();
        nuevo->dato = dato;

        Nodo *actual = primero;

        while (actual != NULL && actual->dato != referencia) {
            actual = actual->siguiente;
        }

        if (actual == NULL) {
            cout << "Referencia no encontrada" << endl;
        }

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }

    void imprimirLista() {
        cout << "Valores en lista" << endl;
        Nodo *actual = primero;
        while (actual != NULL) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
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
    cout << "0. Salir" << endl;
    cout << "Selecciona una opcion: ";
    cout << endl;
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

        } else if (opcion == 6) {

        } else if (opcion == 7) {

        } else if (opcion == 8) {

        } else if (opcion == 9) {
            lista.imprimirLista();

        }






















    }while (opcion != 0);

    return 0;
}