#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarPila(Nodo *&, int);
void sacarPila(Nodo *&, int &);
void imprimirPila(Nodo *);

int main(int argc, char *argv[]) {
    Nodo *pila = nullptr;
    int dato;

    cout << "[_ingresar dato 1_]";
    cin >> dato;
    insertarPila(pila, dato);

    cout << "[_ingresar dato 2_]";
    cin >> dato;
    insertarPila(pila, dato);

    cout << "\nImprimir pila: " << endl;
    imprimirPila(pila);

    cout << "\nSacando los elementos de pila: " << endl;
    while (pila != nullptr) {
        sacarPila(pila, dato);
        if (pila != nullptr) {
            cout << dato << " , ";
        }
        else {
            cout << dato << " . ";
        }
    }

    cout << "\nImprimir pila despues de sacar la pila: " << endl;
    imprimirPila(pila);
}

void insertarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "\tElemento " << n << " ha sido agregado a PILA correctamente" << endl;
}

void sacarPila(Nodo *&pila, int &n) {
    Nodo *nodo_aux = pila;
    n = nodo_aux->dato;
    pila = nodo_aux->siguiente;
    delete nodo_aux;
}

void imprimirPila(Nodo *pila) {
    while (pila != nullptr) {
        cout << pila->dato << " ";
        pila = pila->siguiente;
    }
}
