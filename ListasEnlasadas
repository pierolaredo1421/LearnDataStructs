#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&, int);

int main(int argc, char *argv[]) {
    Nodo *lista = nullptr;
}

void insertarLista(Nodo *&lista, int dato) {
    Nodo *nuevo_nodo = new Nodo;
    // 1. 'nuevo_nodo' apunta a un Nodo recien creado con dato=3, el campo 'siguiente' todavia tiene basura
    // 2. 'Nuevo_nodo' apunta a un Nodo recien creado con dato=1, el campo 'siguiente' todavia tiene basura
    // 3. 'Nuevo_nodo' apunta a un Nodo recien creado con dato=2, el campo 'siguiente' todavia tiene basura
    // 4. 'Nuevo_nodo' apunta a un Nodo recien creado con dato=4, el campo 'siguiente' todavia tiene basura
    nuevo_nodo->dato = dato;

    // 1. 'aux1' apunta a donde apunta 'lista', que es nullptr. Ambos son nullptr
    // 2. 'aux1' apunta a donde apunta 'lista', que es el Nodo con dato=3
    // 3. 'aux1' apunta a donde apunta 'lista', que es el Nodo con dato=1 (cabeza de la lista)
    // 4. 'aux1' apunta a donde apunta 'lista', que es el Nodo con dato=1 (cabeza de la lista)
    Nodo *aux1 = lista;

    // 1. declarado, pero sin inicializar, no importa porque el while no va a entrar
    // 2. declarado, pero sin inicializar, no importa porque el while no va a entrar
    // 3. Declarado, pero sin inicializar, puede entrar al while
    // 4. Declarado, pero sin inicializar, puede entrar al while
    Nodo *aux2;

    // 1. 'aux1' es nullptr -> condición falsa -> no entra al while
    // 2. 'aux1' apunta a Nodo(3), y 3 > 1 -> condición falsa (3 < 1 es falso) -> no entra al while
    // 3. 'aux1' apunta a Nodo(1), y 1 < 2 -> condición verdadera -> entra al while
    // 4. 'aux1' apunta a Nodo(1), y 1 < 4 -> condición verdadera -> entra al while
    while (aux1 != nullptr && aux1->dato < dato) {
        // 3. 'aux2' guarda la direccion de 'aux1', que es el Nodo con dato=1
        // 4. iteración 1: 'aux2' guarda la direccion de 'aux1', que es el Nodo con dato=1
        aux2 = aux1;

        // 3. 'aux1' avanza al siguiente de Nodo(1), que es Nodo(3)
        // 4. iteración 1: 'aux1' avanza al siguiente de Nodo(1), que es Nodo(2)
        aux1 = aux1->siguiente;

        // 3. vuelve a evaluar: aux1 apunta a Nodo(3), y 3 > 2 -> condición falsa -> sale del while
        // 4. iteración 1: vuelve a evaluar: aux1 apunta a Nodo(2), y 2 < 4 -> condición verdadera -> sigue en el while
        //    iteración 2: 'aux2' guarda la direccion de 'aux1', que es el Nodo con dato=2
        //                 'aux1' avanza al siguiente de Nodo(2), que es Nodo(3)
        //                 vuelve a evaluar: aux1 apunta a Nodo(3), y 3 < 4 -> condición verdadera -> sigue en el while
        //    iteración 3: 'aux2' guarda la direccion de 'aux1', que es el Nodo con dato=3
        //                 'aux1' avanza al siguiente de Nodo(3), que es nullptr
        //                 vuelve a evaluar: aux1 es nullptr -> condición falsa -> sale del while
    }

    // 1. 'lista' == 'aux1' (ambos nullptr) -> entra al if
    // 2. 'lista' apunta a Nodo(3) y 'aux1' también apunta a Nodo(3) -> son iguales -> entra al if
    // 3. 'lista' apunta a Nodo(1) y 'aux1' apunta a Nodo(3) -> no son iguales -> entra al else
    // 4. 'lista' apunta a Nodo(1) y 'aux1' es nullptr -> no son iguales -> entra al else
    if (lista == aux1) {
        // 1. 'lista' apunta al mismo Nodo que 'nuevo_nodo', que es Nodo(3). Nodo(3) es ahora la cabeza
        // 2. 'Lista' apunta al mismo Nodo que 'nuevo_nodo', que es Nodo(1). Nodo(1) es ahora la cabeza
        lista = nuevo_nodo;
    } else {
        // 3. el campo 'siguiente' de Nodo(1) apunta a 'nuevo_nodo', que es Nodo(2)
        //    la lista queda: Nodo(1) -> Nodo(2) -> ? (aun sin cerrar)
        // 4. El campo 'siguiente' de Nodo(3) apunta a 'nuevo_nodo', que es Nodo(4)
        //    la lista queda: Nodo(1) -> Nodo(2) -> Nodo(3) -> Nodo(4) -> ? (aun sin cerrar)
        aux2->siguiente = nuevo_nodo;
    }

    // 1. 'siguiente' de Nodo(3) apunta a nullptr. Lista: [3] -> nullptr
    // 2. 'siguiente' de Nodo(1) apunta a Nodo(3) (aux1 quedo en Nodo(3)). Lista: [1] -> [3] -> nullptr
    // 3. 'siguiente' de Nodo(2) apunta a Nodo(3) (aux1 quedo en Nodo(3)). Lista: [1] -> [2] -> [3] -> nullptr
    // 4. 'siguiente' de Nodo(4) apunta a nullptr (aux1 quedo en nullptr). Lista: [1] -> [2] -> [3] -> [4] -> nullptr
    nuevo_nodo->siguiente = aux1;
}