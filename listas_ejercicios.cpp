#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo* siguiente;
};

class Lista{
  private:
  Nodo* head;
  public:
  Lista(){
    head = nullptr;
  }
  
  bool estaVacia(){
     return head == nullptr;
  }
  
  void insertar(int valor){
      Nodo* nuevo = new Nodo();
      nuevo->dato = valor;
      nuevo->siguiente = nullptr;
      
      if(estaVacia()){
        head = nuevo;
        return;
      } 
      
      Nodo* actual = head;
      while(actual->siguiente != nullptr){
        actual = actual->siguiente;
      }
      actual->siguiente = nuevo;
  }
  
  void recorrerLista(){
    if(estaVacia()) return;
  
    Nodo* actual = head;
    while(actual != nullptr){
      cout << actual->dato << " -> ";
      actual = actual->siguiente;
    }
    cout << "nullptr" << endl;
  }
  
  //eliminar la primera aparición de un valor dado por el usuario
  void eliminar(int valor){
      if(estaVacia()) return;
      
      Nodo* actual = head;
      Nodo* anterior = nullptr;
      
      while(actual != nullptr){
          if(actual->dato == valor){
            if(anterior == nullptr){
              Nodo* temp = head;
              head = head->siguiente;
              actual = head;
              delete temp;
            }else{
              Nodo* temp = actual;
              anterior->siguiente = actual->siguiente;
              actual = actual->siguiente;
              delete temp;
            }
          }else{
              anterior = actual;
              actual = actual->siguiente;
          }
      }
  }
  
  void moverPrimeroySegundo(){
      if(head == nullptr || head->siguiente == nullptr) return;
      
      Nodo* primero = head;
      Nodo* segundo = primero->siguiente;
      primero->siguiente = segundo->siguiente;
      segundo->siguiente = primero;
      head = segundo;
  }
  
  void eliminarUltimo(){
      if(head == nullptr) return;
      if(head->siguiente == nullptr){
          Nodo* actual = head;
          head = nullptr;
          delete actual;
          return;
      }
      
      Nodo* actual = head;
      Nodo* anterior = nullptr;
      
      while(actual->siguiente != nullptr){
          anterior = actual;
          actual = actual->siguiente;
      }
      anterior->siguiente = actual->siguiente;
      delete actual;
  }
  
  void moverUltimoAlInicio(){
      if(head == nullptr || head->siguiente == nullptr) return;
      
      Nodo* actual = head;
      Nodo* anterior = nullptr;
      
      while(actual->siguiente != nullptr){
          anterior = actual;
          actual = actual->siguiente;
      }
      anterior->siguiente = nullptr;
      actual->siguiente = head;
      head = actual;
  }
  
  void moverPrimeroAlFinal(){
      if(head == nullptr || head->siguiente == nullptr) return;
      
      Nodo* primero = head;
      head = head->siguiente;
      
      Nodo* actual = head;
      while(actual->siguiente != nullptr){
          actual = actual->siguiente;
      }
      actual->siguiente = primero;
      primero->siguiente = nullptr;
      
  }
  
  void moverSegundoNodo(){
      if(head == nullptr || head->siguiente == nullptr || head->siguiente->siguiente == nullptr) return;
      
      Nodo* primero = head;
      Nodo* segundo = primero->siguiente;
      primero->siguiente = segundo->siguiente;
      Nodo* actual = head;
      while(actual->siguiente != nullptr){
          actual = actual->siguiente;
      }
      actual->siguiente = segundo;
      segundo->siguiente = nullptr;
  }
  
  void eliminarMenoresA(int valor){
      if(head == nullptr);
      
      Nodo* actual = head;
      Nodo* anterior = nullptr;
      while(actual != nullptr){
          if(actual->dato < valor){
              if(anterior == nullptr){
                Nodo* temp = head;
                head = head->siguiente;
                actual = head;
                delete temp;
              }else{
                Nodo* temp = actual;
                anterior->siguiente = actual->siguiente;
                actual = actual->siguiente;
                delete temp;
              }
          }else{
              anterior = actual;
              actual = actual->siguiente;
          }
      }
  }
};

void menu(){
    cout << "OPERACIONES CON LISTAS ENLAZADAS" << endl;
    cout << "1. Agregar elementos" << endl;
    cout << "2. Eliminar valor" << endl;
    cout << "3. Mostrar lista" << endl;
    cout << "4. Intercambiar el primer y segundo valor" << endl;
    cout << "5. Eliminar el ultimo valor" << endl;
    cout << "6. Mover ultimo al inicio" << endl;
    cout << "7. Mover inicio al final" << endl;
    cout << "8. Mover segundo nodo al final" << endl;
    cout << "Seleccione una opcion: ";
}

int main(){
    Lista lista;
    int opcion, valor;
    do{
        menu();
        cin >> opcion;
        if(opcion == 1){
            cout << "Ingrese un valor: ";
            cin >> valor;
            lista.insertar(valor);
        }else if(opcion == 2){
            cout << "Ingrese el valor que quiere eliminar: ";
            cin >> valor;
            lista.eliminar(valor);
        }else if(opcion == 3){
            cout << "Lista final" << endl;
            lista.recorrerLista();
        }else if(opcion == 4){
            cout << "Elementos intercambiados correctamente" << endl;
            lista.moverPrimeroySegundo();
        }else if(opcion == 5){
            cout << "Ultimo valor eliminado" << endl;
            lista.eliminarUltimo();
        }else if(opcion == 6){
            cout << "Valor reubicado exitosamente" << endl;
            lista.moverUltimoAlInicio();
        }else if(opcion == 7){
            cout << "Vallor reubicado correctamente" << endl;
            lista.moverPrimeroAlFinal();
        }else if(opcion == 8){
            cout << "Valor reubicado al final con exito" << endl;
            lista.moverSegundoNodo();
        }
    }while(opcion != 0);

    return 0;
}