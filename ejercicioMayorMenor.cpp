#include <iostream>
using namespace std;

struct Nodo {
    int data;
    Nodo *next;
};

void insertDate (Nodo *&, int data);
void findMaxMin (Nodo *);

int main(int argc, char *argv[]) {
    Nodo *list = nullptr;

    insertDate(list, 15);
    insertDate(list, 8);
    insertDate(list, 20);
    insertDate(list, 3);

    findMaxMin(list);
}

void insertDate (Nodo *&list, int data) {
    Nodo *new_nodo = new Nodo;
    new_nodo->data = data;
    Nodo *aux1 = list;
    Nodo *aux2;

    while (aux1 != nullptr && aux1-> data < data) {
        aux2 = aux1;
        aux1 = aux1->next;
    }
    if (list == aux1) {
        list = new_nodo;
    } else {
        aux2->next = new_nodo;
    }
    new_nodo->next = aux1;
    cout << "data inserted correctly" << endl;
}

void findMaxMin (Nodo *list) {
    if (list == nullptr) {
        cout << "La lista está vacía." << endl;
        return;
    }

    int max = list->data;
    int min = list->data;
    Nodo *aux = list->next;

    while (aux != nullptr) {
        if (aux->data > max)
            max = aux->data;
        if (aux->data < min)
            min = aux->data;
        aux = aux->next;
    }

    cout << "El mayor dato es: " << max << endl;
    cout << "El menor dato es: " << min << endl;
}




