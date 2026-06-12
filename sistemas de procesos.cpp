#include <iostream>
#include <string>
using namespace std;

struct Pacientes{
    int expediente;
    string nombre;
};

//lista
struct NodoLista{
  Pacientes dato;
  NodoLista* siguiente;
};

class Lista{
  private:
  NodoLista* head;
  public:
  Lista(){
      head = nullptr;
  }
  
  void insertar(Pacientes p){
      NodoLista* nuevo = new NodoLista;
      nuevo->dato = p;
      nuevo->siguiente = nullptr;
      
      if(head == nullptr){
          head = nuevo;
          return;
      }
      
      NodoLista* actual = head;
      while(actual->siguiente != nullptr){
          actual = actual->siguiente;
      }
      actual->siguiente = nuevo;
  }
  
  void mostrar(){
      if(head == nullptr) return;
      
      NodoLista* actual = head;
      while(actual != nullptr){
        cout << actual->dato.expediente << " - " << actual->dato.nombre << endl;
        actual = actual->siguiente;
      }
  }
};

//cola
struct NodoCola{
    Pacientes dato;
    NodoCola* siguiente;
};

class Cola{
  private:
  NodoCola* frente;
  NodoCola* fin;
  public:
  Cola(){
      frente = nullptr;
      fin = nullptr;
  }
  
  void encolar(Pacientes p){
      NodoCola* nuevo = new NodoCola;
      nuevo->dato = p;
      nuevo->siguiente = nullptr;
      
      if(frente == nullptr){
          frente = fin = nuevo;
          return;
      }
      
      fin->siguiente = nuevo;
      fin = nuevo;
  }
  
  void desencolar(){
      if(frente == nullptr){
          cout << "No hay pacientes formados aún" << endl;
          return;
      }
      
      NodoCola* temp = frente;
      cout << "Atendiendo a: " << frente->dato.nombre << endl;
      
      frente = frente->siguiente;
      
      if(frente == nullptr){
          fin = nullptr;
      }
      
      delete temp;
  }
  
  void mostrar(){
        NodoCola* actual = frente;
        while(actual != nullptr){
            cout << actual->dato.nombre
                 << endl;
            actual = actual->siguiente;
        }
    }
};

//abb
struct NodoArbol{
  Pacientes dato;
  NodoArbol* izquierda;
  NodoArbol* derecha;
  
  NodoArbol(Pacientes p){
      dato = p;
      izquierda = nullptr;
      derecha = nullptr;
  }
};

 class Arbol{
   private:
   NodoArbol* raiz;
   
   NodoArbol* insertar(NodoArbol* raiz, Pacientes p){
       if(raiz == nullptr){
           return new NodoArbol(p);
       }
       
       if(p.expediente < raiz->dato.expediente){
            raiz->izquierda = insertar(raiz->izquierda,p);
        }
        else if(p.expediente > raiz->dato.expediente){
            raiz->derecha = insertar(raiz->derecha,p);
        }else{
            cout << "El expediente ya existe" << endl;
        }

        return raiz;
   }
   
   bool buscarRec(NodoArbol* raiz,int exp){
        if(raiz == nullptr)
            return false;
            
        if(raiz->dato.expediente == exp)
            return true;
            
        if(exp < raiz->dato.expediente)
            return buscarRec(raiz->izquierda,exp);

        return buscarRec(raiz->derecha,exp);
    }
   
    void inOrdenRec(NodoArbol* raiz){
        if(raiz == nullptr)
            return;
        inOrdenRec(raiz->izquierda);
        cout << raiz->dato.expediente
             << " - "
             << raiz->dato.nombre
             << endl;
        inOrdenRec(raiz->derecha);
    }   
   
   public:
   Arbol(){
       raiz = nullptr;
   }
   
   void insertar(Pacientes p){
        raiz = insertar(raiz,p);
    }

    bool buscar(int exp){
        return buscarRec(raiz,exp);
    }

    void mostrar(){
        inOrdenRec(raiz);
    }
 };



int main(){
    Lista lista;
    Cola cola;
    Arbol arbol;

    int opcion;

    do{

        cout << "\n1. Registrar paciente";
        cout << "\n2. Enviar a consulta";
        cout << "\n3. Atender paciente";
        cout << "\n4. Buscar paciente";
        cout << "\n5. Mostrar registrados";
        cout << "\n6. Mostrar cola";
        cout << "\n7. Mostrar ABB";
        cout << "\n0. Salir";
        cout << "\nOpcion: ";

        cin >> opcion;

        if(opcion == 1){
            Pacientes p;
            cout << "Expediente: ";
            cin >> p.expediente;
            cout << "Nombre: ";
            cin >> p.nombre;
            
            lista.insertar(p);
            arbol.insertar(p);
            cout << "Paciente registrado\n";
        }else if(opcion == 2){
            Pacientes p;
            cout << "Expediente: ";
            cin >> p.expediente;
            cout << "Nombre: ";
            cin >> p.nombre;

            cola.encolar(p);
        }else if(opcion == 3){
            cola.desencolar();
        }else if(opcion == 4){
            int exp;

            cout << "Expediente a buscar: ";
            cin >> exp;

            if(arbol.buscar(exp))
                cout << "Encontrado\n";
            else
                cout << "No encontrado\n";
        }else if(opcion == 5){
            lista.mostrar();
        }else if(opcion == 6){
            cola.mostrar();
        }else if(opcion == 7){
            arbol.mostrar();
        }

    }while(opcion != 0);
    return 0;
}