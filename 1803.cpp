#include <iostream>
using namespace std;

void recurrenciaAditiva(int A, int c, int n) {
    for (int i = 1; i <= n; i++) {
        cout << "a" << i << " = " << A + (i - 1) * c << endl;
    }
}

int recurrenciaMultiplicativa(int A, int K, int n) {
    if (n == 1) {
        return A;
    }else {
        return K * recurrenciaMultiplicativa(n-1, A, K);
    }
}
int main() {
    int opcion;
    do {
        cout << endl;
        cout << "Matematicas discretas" << endl;
        cout << "===========================" << endl;
        cout << "Recurrencias: " << endl;
        cout << "===========================" << endl;
        cout << "1. Recurrencia aditiva" << endl;
        cout << "2. Recurrencia multiplicado" << endl;
        cout << "3. Recurrencia no homogenea" << endl;
        cout << "4. Fibonacci" << endl;
        cout << "5. Modelo lineal" << endl;
        cout << "6. Modelo exponencial" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Recurrencia aditiva" << endl;
            cout << "a1 = A, an = an-1 + c" << endl;
            cout << "**************************" << endl;
            int A, c, n;
            cout << "Ingrese A, C, N: ";
            cin >> A >> c >> n;
            cout << "Aplicando formula..." << endl;
            recurrenciaAditiva(A, c, n);

        }else if (opcion == 2) {
            cout << "Recurrencia multiplicada" << endl;
            cout << "a1 = A, an = Kan-1" << endl;
            cout << "**************************" << endl;
            int A, K, n;
            cout << "Ingrese A, K, N: ";
            cin >> A >> K >> n;
            cout << "Aplicando formula..." << endl;
            int res = recurrenciaMultiplicativa(A, K, n);
            cout << res << endl;
        }
    }while(opcion != 0);








    return 0;
}