#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

    struct Alumno {
        int matricula;
        string nombre;
        double promedio;
    };

//funcion de tipo int que recibe el vector del struct y una matrícula, recorre el vector con un bucle y si encuentra una coincidencia
//en las matriculas retorna el indice o posicion de esta o de no encontrar nada retorna -1
    int buscarPorMatricula(vector<Alumno> &grupo, int matricula) {
        for (int i = 0; i < grupo.size(); i++) {
            if (grupo[i].matricula == matricula) {
                return i; // Si existe
            }
        }
        return -1;
    }

//funcion booleana que recibe el vector de la struct y un valor de alumno, si la funcion buscarPorMatricula no es igual a -1 retorna false
//porque ya existe, y si es diferente dé agrega a ese alumno
    bool agregarAlumno(vector<Alumno> &grupo, const Alumno &alumno) {
        //Verifica si existe
        if (buscarPorMatricula(grupo, alumno.matricula) != -1) {
            return false; // en caso de que estemos agregando a un alumno que ya existe
        }
        grupo.push_back(alumno);
        return true;
    }

//funcion void que recibe el vector de la struct, la recorre e imprime cada parametro de la struct almacenada
    void mostrarAlumnos (vector<Alumno> &grupo) {
        cout << "=== Listado de alumnos ===\n";
        //si aún no hay alumnos agregados
        if (grupo.empty()) {
            cout << "No hay alumnos registrados\n";
            return;
        }
        //decoracion
        cout << left << setw(20) << "Nombre" << setw(12) << "Matricula" << setw(12) << "Promedio" << endl;
        //recorre el vector
        for (Alumno x: grupo) {
            cout << left << setw(20) << x.nombre << setw(12) << x.matricula << setw(12) << x.promedio << endl;
        }
    }

//funcion booleana que recibe el vector de la struct, una matricula, una cadena y un promedio, se llama a otra funcion previamente usada
//si la funcion es igual a -1 quiere decir que no existe (retorna false)
    bool actualizarAlumno (vector<Alumno>& grupo, int matricula, string nuevoNombre, double nuevoPromedio) {
        int resultadoIndice = buscarPorMatricula(grupo, matricula);

        if (resultadoIndice == -1) {
            return false;
        }
        //Actualizar datos
        grupo[resultadoIndice].nombre = nuevoNombre;
        grupo[resultadoIndice].promedio = nuevoPromedio;

        return true;
    }

//funcion booleana que recibe el vector de la struct y una matricula, mas abajo se manda a llamar a otra funcion ya previamente hecha, y si esa funcion no es igual a -1
//quiere decir que esa matricula no existe, de lo contrario se eliminará la posicion segun esté ubicado el alumno
//y retorna verdad porque ya fue eliminado
    bool eliminarAlumno(vector<Alumno>& grupo, int matricula) {
        int resultado = buscarPorMatricula(grupo, matricula);
        if (resultado == -1){
            return false;
        }

        grupo.erase(grupo.begin() + resultado);
        return true;
    }

//se suman todos los promedios y se dividen entre el numero de alumnos segun haya registrados
    double calcularPromedio(vector<Alumno>& grupo) {
        float suma = 0, promedio;
        for (int i = 0; i < grupo.size(); i++) {
            suma += grupo[i].promedio;
        }
        promedio = suma / grupo.size();
        return promedio;
    }

int main () {
    vector<Alumno> grupo;
    int opcion;

    do {
        cout << "Menu - vector<Alumno>" << endl;
        cout << "=======================" << endl;
        cout << "1) Agregar alumno" << endl;
        cout << "2) Mostrar alumno" << endl;
        cout << "3) Buscar alumno por matricula" << endl;
        cout << "4) Actualizar alumno" << endl;
        cout << "5) Eliminar alumno" << endl;
        cout << "6) Ordenar por promedio (descendente)" << endl;
        cout << "7) Ordenar por promedio (ascendente)" << endl;
        cout << "8) Calcular promedio del grupo" << endl;
        cout << "0) Salir" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

    if (opcion == 1){
            Alumno temp_alumno;
            cout << "Agregar alumno" << endl;
            cout << "=================================" << endl;
            cout << "Ingresa matricula: ";
            cin >> temp_alumno.matricula;
            cin.ignore();
            cout << "Ingresa nombre: ";
            getline(cin, temp_alumno.nombre);
            cout << "Ingresa promedio: ";
            cin >> temp_alumno.promedio;

            if (agregarAlumno(grupo, temp_alumno)) {
                cout << "!Alumno agregado correctamente!" << endl;
            } else {
                cout << "!Error: Matricula ya existente!" << endl;
            }
            cout << endl;
    } else if (opcion == 2){
            cout << "Mostrar alumno" << endl;
            mostrarAlumnos(grupo);
            cout << endl;
    } else if (opcion == 3){
            cout << "Buscar alumno" << endl;
            int matricula;
            cout << "Ingresa matricula del alumno a buscar: ";
            cin >> matricula;
            int resultado = buscarPorMatricula(grupo, matricula);

            if (resultado != -1) {
                cout << left << setw(25) << "Nombre" << setw(10) << "Matricula" << setw(10) << "Promedio" << endl;
                cout << left << setw(25) << grupo[resultado].nombre << setw(10) << grupo[resultado].matricula << setw(10) << grupo[resultado].promedio << endl;
                cout << endl;
            } else {
                cout << "Matricula no encontrada!" << endl;
            }
            cout << endl;
    }else if (opcion == 4){
            int matricula;
            string nuevoNombre;
            double nuevoPromedio;

            cout << "Actualizar alumno" << endl;
            cout << "===========================" << endl;
            cout << "Ingresa matricula del alumno a buscar: ";
            cin >> matricula;
            cin.ignore();
            cout << "Ingresa el nuevo nombre: ";
            getline(cin, nuevoNombre);
            cout << "Ingresa nuevo promedio: ";
            cin >> nuevoPromedio;

            if (actualizarAlumno(grupo, matricula, nuevoNombre, nuevoPromedio) == true) {
                cout << "Alumno modificado correctamente" << endl;
            } else {
                cout << "Error: Matricula inexistente" << endl;
            }
            cout << endl;
    }else if (opcion == 5) {
        int matricula;
        cout << "Ingrese la matricula del alumno desea buscar para eliminar: ";
        cin >> matricula;

        if (eliminarAlumno(grupo, matricula) == true) {
            cout << "Alumno modificado correctamente" << endl;
        }else {
            cout << "Error: Matricula inexistente" << endl;
        }
    }else if (opcion == 6){
        cout << "Promedios en forma descendente" << endl;
        for (int i = 0; i < grupo.size(); i++) {
            for (int j = 0; j < grupo.size()-i-1; j++) {
                if (grupo[j].promedio < grupo[j+1].promedio) {
                    swap(grupo[j], grupo[j+1]);
                }
            }
        }

        for (int i = 0; i < grupo.size(); i++) {
            cout << grupo[i].promedio;
            if (i < grupo.size()-1) {
                cout << ", ";
            }
        }
        cout << endl;
    }else if (opcion == 7) {
        cout << "Promedios en forma ascendente" << endl;
        for (int i = 0; i < grupo.size(); i++) {
            for (int j = 0; j < grupo.size()-i-1; j++) {
                if (grupo[j].promedio > grupo[j+1].promedio) {
                    swap(grupo[j], grupo[j+1]);
                }
            }
        }

        for (int i = 0; i < grupo.size(); i++) {
            cout << grupo[i].promedio;
            if (i < grupo.size()-1) {
                cout << ", ";
            }
        }
        cout << endl;
    }else if (opcion == 8) {
        cout << "Promedio grupal" << endl;
        double prom = calcularPromedio(grupo);
        cout << "El promedio es: " << prom << endl;
        cout << endl;
    }

    } while (opcion != 0);

    return 0;
}