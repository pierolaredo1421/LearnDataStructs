#include <iostream>
using namespace std;

struct Nodo {
    char dato;
    Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo *&, char);
void suprimirCola(Nodo *&, Nodo *&, char &);
void imprimirCola(Nodo *);
bool cola_vacia(Nodo *);

int main(int argc, char *argv[]) {
    Nodo *frente = nullptr;
    Nodo *fin = nullptr;
    char dato;

    cout << "digite un caracter: ";
    cin >> dato;
    insertarCola(frente, fin, dato);

    cout << "digite un caracter: ";
    cin >> dato;
    insertarCola(frente, fin, dato);

    cout << "digite un caracter: ";
    cin >> dato;
    insertarCola(frente, fin, dato);

    cout << "digite un caracter: ";
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

void insertarCola(Nodo *&frente, Nodo *&fin, char dato) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = nullptr;

    if (cola_vacia(frente)) {
        frente = nuevo_nodo;
    }
    else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\tdato insertado correctamente" << endl;
}

void suprimirCola(Nodo *&frente, Nodo *&fin, char &dato) {
    dato = frente->dato;
    Nodo *aux = frente;

    if (frente == fin) {
        frente = nullptr;
        fin = nullptr;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
}

void imprimirCola(Nodo *frente) {
    while (!cola_vacia(frente)) {
        cout << frente->dato << " ";
        frente = frente->siguiente;
    }
    cout << endl;
}

bool cola_vacia(Nodo *frente) {
    return (frente == nullptr);
}
