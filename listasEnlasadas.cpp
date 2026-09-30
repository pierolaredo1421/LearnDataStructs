#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void menu(Nodo *&);

void insertarLista(Nodo *&, int);

Nodo *buscarDato(Nodo *, Nodo *&, int);

void eliminarDato(Nodo *&, int);

void imprimirLista(Nodo *);

void eliminarLista(Nodo *&, int &);

int main(int argc, char *argv[]) {
    Nodo *lista = nullptr;
    menu(lista);
}

void insertarLista(Nodo *&lista, int dato) {
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->dato = dato;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while (aux1 != nullptr && aux1->dato < dato) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1) {
        lista = nuevo_nodo;
    } else {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
    cout << "\tse inserto dato correctamente!" << endl;
}

Nodo *buscarDato(Nodo *lista, Nodo *&anterior, int dato) {
    Nodo *aux = lista;
    anterior = nullptr;
    while (aux != nullptr && aux->dato <= dato) {
        if (aux->dato == dato) {
            return aux;
        }
        anterior = aux;
        aux = aux->siguiente;
    }
    return nullptr;
}

void eliminarDato(Nodo *&lista, int dato) {
    Nodo *anterior = nullptr;
    Nodo *encontrado = buscarDato(lista, anterior, dato);

    if (encontrado == nullptr) {
        cout << "no se encontro el dato..." << endl;
        return;
    }

    if (anterior == nullptr) {
        lista = encontrado->siguiente;
    } else {
        anterior->siguiente = encontrado->siguiente;
    }

    delete encontrado;
    cout << "dato eliminado correctamente!" << endl;
}

void eliminarLista(Nodo *&lista, int &dato) {
    Nodo *aux = lista;
    dato = aux->dato;
    lista = aux->siguiente;
    delete aux;
}

void imprimirLista(Nodo *lista) {
    Nodo *aux = lista;
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    if (lista == nullptr) {
        cout << "no hay datos en la lista..." << endl;
    }
    cout << endl;
}

void menu(Nodo *&lista) {
    int opcion = 0;
    int dato;

    do {
        cout << "\t[_MENU_]" << endl;
        cout << "[_1. INGRESAR DATO_]" << endl;
        cout << "[_2. ELIMINAR DATO_]" << endl;
        cout << "[_3. BUSCAR DATO_]" << endl;
        cout << "[_4. IMPRIMIR LISTA_]" << endl;
        cout << "[_5. ELIMINAR LISTA_]" << endl;
        cout << "[_6. SALIR_]" << endl;
        cout << "\n[_INGRESAR OPCION_]";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese dato: ";
                cin >> dato;
                insertarLista(lista, dato);
                break;
            case 2:
                cout << "Ingrese dato a eliminar: ";
                cin >> dato;
                eliminarDato(lista, dato);
                break;
            case 3: {
                cout << "Ingrese dato a buscar: ";
                cin >> dato;
                Nodo *anterior = nullptr;
                Nodo *encontrado = buscarDato(lista, anterior, dato);
                if (encontrado != nullptr) {
                    cout << "dato encontrado: " << encontrado->dato << endl;
                } else {
                    cout << "dato no encontrado" << endl;
                }
                break;
            }
            case 4:
                cout << "imprimiendo lista..." << endl;
                imprimirLista(lista);
                break;
            case 5:
                cout << "eliminando lista..." << endl;
                while (lista != nullptr) {
                    eliminarLista(lista, dato);
                }
                cout << "lista eliminada correctamente" << endl;
                break;
            case 6:
                cout << "hasta luego!" << endl;
                break;
            default:
                cout << "opcion incorrecta, debe ser en un rango de (1 - 5)" << endl;
                break;
        }
    } while (opcion != 6);
}
