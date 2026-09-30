#include <clocale>
#include <cstring>
#include <iostream>
using namespace std;

struct Carro {
    char placa[50];
    char marca[50];
    char color[50];
};

struct Nodo {
    Carro carro;
    Nodo *siguiente;
};

void menu(Nodo *&, Nodo *&, Nodo *&);
void agregarCarro(Carro &);
void agregarListaOriginal(Nodo *&, Nodo *&, Carro);
void extraerSegunParidad(Nodo *, Nodo *&);
void encontrarGanador(Nodo *);
bool esPar(Nodo *);
void mostrarLista(Nodo *);
bool listaVacia(Nodo *);
void liberarLista(Nodo *&);

int main(int argc, char *argv[]) {
    Nodo *inicioListaOriginal = nullptr;
    Nodo *finalListaOriginal = nullptr;
    Nodo *inicioNuevaLista = nullptr;

    menu(inicioListaOriginal, finalListaOriginal, inicioNuevaLista);
}

void menu(Nodo *&inicioListaOriginal, Nodo *&finalListaOriginal, Nodo *&inicioNuevaLista) {
    int opcion = 0;
    Carro carro;

    do {
        cout << "\n\t[_MENU_]" << endl;
        cout << "[_1. AGREGAR CARRO_]" << endl;
        cout << "[_2. MOSTRAR LISTA ORIGINAL_]" << endl;
        cout << "[_3. EXTRAER SEGUN PARIDAD_]" << endl;
        cout << "[_4. MOSTRAR NUEVA LISTA_]" << endl;
        cout << "[_5. ENCONTRAR GANADOR_]" << endl;
        cout << "[_6. SALIR_]" << endl;
        cout << "\n[_INGRESAR OPCION_]: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarCarro(carro);
                agregarListaOriginal(inicioListaOriginal, finalListaOriginal, carro);
                break;
            case 2:
                cout << "\n--- lista original ---" << endl;
                mostrarLista(inicioListaOriginal);
                break;
            case 3:
                if (listaVacia(inicioListaOriginal)) {
                    cout << "la lista original esta vacia..." << endl;
                } else {
                    liberarLista(inicioNuevaLista);
                    extraerSegunParidad(inicioListaOriginal, inicioNuevaLista);
                    cout << "\tlista extraida correctamente!" << endl;
                }
                break;
            case 4:
                cout << "\n--- nueva lista ---" << endl;
                mostrarLista(inicioNuevaLista);
                break;
            case 5:
                if (listaVacia(inicioNuevaLista)) {
                    cout << "primero debes extraer segun paridad (opcion 3)" << endl;
                } else {
                    encontrarGanador(inicioNuevaLista);
                }
                break;
            case 6:
                liberarLista(inicioListaOriginal);
                liberarLista(inicioNuevaLista);
                cout << "hasta luego!" << endl;
                break;
            default:
                cout << "opcion incorrecta, debe ser en un rango de (1 - 6)" << endl;
                break;
        }
    } while (opcion != 6);
}

void agregarCarro(Carro &carro) {
    cout << "digite placa: ";
    cin.getline(carro.placa, 50);
    cout << "elegir marca del auto: ";
    cin.getline(carro.marca, 50);
    cout << "elegir color: ";
    cin.getline(carro.color, 50);
}

void agregarListaOriginal(Nodo *&inicio, Nodo *&fin, Carro carro) {
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->carro = carro;
    nuevo_nodo->siguiente = nullptr;

    if (listaVacia(inicio)) {
        inicio = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << "\tcarro agregado correctamente!" << endl;
}

void extraerSegunParidad(Nodo *listaOriginal, Nodo *&nuevaLista) {
    Nodo *aux = listaOriginal;
    Nodo *finNuevaLista = nullptr;
    int posicion = 1;
    bool listaEsPar = esPar(listaOriginal);

    while (aux != nullptr) {
        if (listaEsPar == (posicion % 2 == 0)) {
            agregarListaOriginal(nuevaLista, finNuevaLista, aux->carro);
        }
        posicion++;
        aux = aux->siguiente;
    }
}

void encontrarGanador(Nodo *nuevaLista) {
    Nodo *aux = nuevaLista;
    Nodo *ganador = nuevaLista;
    int maxValor = strlen(ganador->carro.placa) + strlen(ganador->carro.color);

    aux = aux->siguiente;

    while (aux != nullptr) {
        int valorActual = strlen(aux->carro.placa) + strlen(aux->carro.color);
        if (valorActual > maxValor) {
            maxValor = valorActual;
            ganador = aux;
        }
        aux = aux->siguiente;
    }

    cout << "\n--- ganador ---" << endl;
    cout << "Placa:   " << ganador->carro.placa << endl;
    cout << "Marca:   " << ganador->carro.marca << endl;
    cout << "Color:   " << ganador->carro.color << endl;
    cout << "Puntaje: " << maxValor << endl;
}

void mostrarLista(Nodo *inicio) {
    Nodo *aux = inicio;

    if (listaVacia(aux)) {
        cout << "no hay ningun carro en la lista..." << endl;
        return;
    }

    while (aux != nullptr) {
        cout << "Placa: " << aux->carro.placa << endl;
        cout << "Marca: " << aux->carro.marca << endl;
        cout << "Color: " << aux->carro.color << endl;
        cout << "---" << endl;
        aux = aux->siguiente;
    }
}

bool esPar(Nodo *listaOriginal) {
    Nodo *aux = listaOriginal;
    while (aux != nullptr && aux->siguiente != nullptr) {
        aux = aux->siguiente->siguiente;
    }
    return aux == nullptr;
}

bool listaVacia(Nodo *lista) {
    return lista == nullptr;
}

void liberarLista(Nodo *&lista) {
    Nodo *aux = lista;
    while (aux != nullptr) {
        Nodo *temp = aux;
        aux = aux->siguiente;
        delete temp;
    }
    lista = nullptr;
}