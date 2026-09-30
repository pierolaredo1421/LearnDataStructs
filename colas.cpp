#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo *&, int);

void suprimirCola(Nodo *&, Nodo *&, int &);

bool cola_vacia(Nodo *);

void imprimirCola(Nodo *);

int main(int argc, char *argv[]) {
    Nodo *frente = nullptr;
    Nodo *fin = nullptr;

    int dato;

    cout << "digite un numero: ";
    cin >> dato;
    insertarCola(frente, fin, dato);

    cout << "digite un numero: ";
    cin >> dato;
    insertarCola(frente, fin, dato);

    cout << "digite un numero: ";
    cin >> dato;
    insertarCola(frente, fin, dato);

    cout << "digite un numero: ";
    cin >> dato;
    insertarCola(frente, fin, dato);
    imprimirCola(frente);
    // eliminar los elementos de la cola
    cout << "\neliminando los elementos de la cola " << endl;
        while (frente != nullptr) {
            suprimirCola(frente, fin, dato);
            if (frente != nullptr) {
                cout << dato << " ";
            } else {
                cout << dato << "." << endl;
            }
            imprimirCola(frente);
        }
}

void insertarCola(Nodo *&frente, Nodo *&fin, int numero) {
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->dato = numero;
    nuevo_nodo->siguiente = nullptr;

    if (cola_vacia(frente)) {
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo; // apunta al siguiente nodo creado
    }
    fin = nuevo_nodo; // actualiza el nodo fin para que se pueda seguir creando nodos apartir del ultimo nodo

    cout << "\telemento " << numero << " agregado a la pila correctamente" << endl;
}

void suprimirCola(Nodo *&frente, Nodo *&fin, int &numero) {
    numero = frente->dato;
    Nodo *aux = frente;

    if (frente == fin) {
        frente = nullptr;
        fin = nullptr;
    } else {
        frente = frente->siguiente; // apunta al siguiente nodo para cuando elimine el nodo anterior
    }
    delete aux;
}

bool cola_vacia(Nodo *frente) {
    return (frente == nullptr);
}

void imprimirCola(Nodo *frente) {
    while (!cola_vacia(frente)) {
        cout << frente->dato << " ";
        frente = frente->siguiente;
    }
    cout << endl;
}
