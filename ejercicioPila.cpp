#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarPila(Nodo *&, int);

void imprimirPila(Nodo *);

void sacarPila(Nodo *&, int &);

int menu();

int main() {
    int option = 0, dato;
    Nodo *pila = nullptr;

    do {
        option = menu();
        switch (option) {
            case 1:
                cout << "Ingresar dato: ";
                cin >> dato;
                insertarPila(pila, dato);
                break;
            case 2:
                cout << "pila: ";
                imprimirPila(pila);
                break;
            case 3:
                cout << "sacando pila..." << endl;
                sacarPila(pila, dato);
                break;
        }
    } while (option != 4);
}

void insertarPila(Nodo *&pila, int numero) {
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->dato = numero;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "elemento " << numero << " agregado a la pila correctamente" << endl;
}

void sacarPila(Nodo *&pila, int &numero) {
    Nodo *nodo_auxiliar = pila;
    numero = nodo_auxiliar->dato;
    pila = nodo_auxiliar->siguiente;
    delete nodo_auxiliar;
}

void imprimirPila(Nodo *pila) {
    while (pila != nullptr) {
        cout << pila->dato << " ";
        pila = pila->siguiente;
    }
    cout << endl;
}

int menu() {
    int op;
    cout << "[_MENU_]" << endl;
    cout << "1. Insertar a la pila" << endl;
    cout << "2. Imprimir pila" << endl;
    cout << "3. Sacar pila" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> op;
    return op;
}
