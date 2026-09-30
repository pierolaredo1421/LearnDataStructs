#include <iostream>
using namespace std;

struct Nodo1 {
    int data;
    Nodo1 *next;
};

struct Nodo2 {
    int data;
    Nodo2 *next;
};

void insertList1(Nodo1 *&, int data);

void insertList2(Nodo2 *&, int data);

void compareToList(Nodo1 *, Nodo2 *);

void printList1(Nodo1 *);

void printList2(Nodo2 *);

int main(int argc, char *argv[]) {
    Nodo1 *list1 = nullptr;
    Nodo2 *list2 = nullptr;

    insertList1(list1, 1);
    insertList1(list1, 5);
    insertList1(list1, 2);
    insertList1(list1, 7);
    insertList1(list1, 3);

    insertList2(list2, 1);
    insertList2(list2, 5);
    insertList2(list2, 2);
    insertList2(list2, 7);
    insertList2(list2, 3);

    printList1(list1);
    printList2(list2);

    compareToList(list1, list2);
}

void insertList1(Nodo1 *&list1, int data) {
    Nodo1 *nuevoNodo = new Nodo1;
    nuevoNodo->data = data;
    Nodo1 *aux1 = list1;
    Nodo1 *aux2;

    while (aux1 != nullptr && aux1->data < data) {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (list1 == aux1) {
        list1 = nuevoNodo;
    } else {
        aux2->next = nuevoNodo;
    }
    nuevoNodo->next = aux1;
}

void insertList2(Nodo2 *&list2, int data) {
    Nodo2 *nuevoNodo = new Nodo2;
    nuevoNodo->data = data;
    Nodo2 *aux1 = list2;
    Nodo2 *aux2;

    while (aux1 != nullptr && aux1->data < data) {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (list2 == aux1) {
        list2 = nuevoNodo;
    } else {
        aux2->next = nuevoNodo;
    }
    nuevoNodo->next = aux1;
}

void compareToList(Nodo1 *list1, Nodo2 *list2) {
    Nodo1 *aux1 = list1;
    Nodo2 *aux2 = list2;

    while (aux1 != nullptr && aux2 != nullptr) {
        if (aux1->data == aux2->data) {
            cout << "the same..." << endl;
            aux1 = aux1->next;
            aux2 = aux2->next;
        } else {
            cout << "the different..." << endl;
            return;
        }
    }
}

void printList1(Nodo1 *list1) {
    Nodo1 *aux = list1;
    if (aux == nullptr) {
        cout << "It has no data..." << endl;
    }

    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

void printList2(Nodo2 *list2) {
    Nodo2 *aux = list2;
    if (aux == nullptr) {
        cout << "It has no data..." << endl;
    }

    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}


