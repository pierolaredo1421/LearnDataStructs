#include <iostream>
using namespace std;

struct Cliente {
    char nombre[50];
};

struct Cajero {
    Cliente cliente;
    Cajero *siguienteCliente;
};

void datoCliente(Cliente &cliente);

void colaCajero(Cajero *&, Cajero *&, Cliente);

void atenderCliente(Cajero *&, Cajero *&, Cliente &);

bool colaVacia(Cajero *);

void menu();

void imprimirClientes(Cajero *);

int main(int argc, char *argv[]) {
    Cajero *inicioCola = nullptr;
    Cajero *finCola = nullptr;
    Cliente cliente;
    int opcion = 0;

    do {
        menu();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                datoCliente(cliente);
                colaCajero(inicioCola, finCola, cliente);
                break;
            case 2:
                atenderCliente(inicioCola, finCola, cliente);
                break;
            case 3:
                imprimirClientes(inicioCola);
                break;
            case 4:
                cout << "hasta luego!" << endl;
                break;
            default:
                cout << "opcion invalida" << endl;
        }
    } while (opcion != 4);
}

void datoCliente(Cliente &cliente) {
    cout << "digite el nombre: ";
    cin.getline(cliente.nombre, 50);
}

void colaCajero(Cajero *&inicioCola, Cajero *&finCola, Cliente cliente) {
    Cajero *nueva_cola = new Cajero();
    nueva_cola->cliente = cliente;
    nueva_cola->siguienteCliente = nullptr;

    if (colaVacia(inicioCola)) {
        inicioCola = nueva_cola;
    } else {
        finCola->siguienteCliente = nueva_cola;
    }
    finCola = nueva_cola;
    cout << "cliente agregado a la cola!" << endl;
}

void atenderCliente(Cajero *&inicioCola, Cajero *&finCola, Cliente &cliente) {
    if (colaVacia(inicioCola)) {
        cout << "no hay clientes para atender!" << endl;
        return;
    }
    cliente = inicioCola->cliente;
    Cajero *aux = inicioCola;

    if (inicioCola == finCola) {
        inicioCola = nullptr;
        finCola = nullptr;
    } else {
        inicioCola = inicioCola->siguienteCliente;
    }
    delete aux;
    cout << "cliente atendido correctamente!" << endl;
}

bool colaVacia(Cajero *inicioCola) {
    return inicioCola == nullptr;
}

void menu() {
    cout << "\n\t[_MENU_]" << endl;
    cout << "[1. INGRESAR CLIENTE]" << endl;
    cout << "[2. ATENDER CLIENTE]" << endl;
    cout << "[3. MOSTRAR FILA DE CLIENTES]" << endl;
    cout << "[4. SALIR]" << endl;
    cout << "\n[INGRESAR OPCION]";
}

void imprimirClientes(Cajero *inicioCola) {
    if (colaVacia(inicioCola)) {
        cout << "La fila esta vacia" << endl;
        return;
    }
    Cajero *actual = inicioCola;
    while (actual != nullptr) {
        cout << actual->cliente.nombre << endl;
        actual = actual->siguienteCliente;
    }
}
