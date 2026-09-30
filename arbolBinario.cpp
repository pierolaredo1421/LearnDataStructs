#include <iostream>
using namespace std;

struct Nodo {
    int data;
    Nodo *left;
    Nodo *right;
};

Nodo *createNodo(int);

void insertNodo(Nodo *&, int);

void menu();

Nodo *tree = nullptr;

int main(int argc, char *argv[]) {
    menu();
}

Nodo *createNodo(int data) {
    Nodo *new_nodo = new Nodo;

    new_nodo->data = data;
    new_nodo->left = nullptr;
    new_nodo->right = nullptr;

    return new_nodo;
}

void insertNodo(Nodo *&tree, int data) {
    if (tree == nullptr) {
        Nodo *new_nodo = createNodo(data);
        tree = new_nodo;
    } else {
        int rootValue = tree->data;
        if (data < rootValue) {
            insertNodo(tree->left, data);
        } else {
            {
                insertNodo(tree->right, data);
            }
        }
    }
}

void menu () {
    int option, data;

    do {
        cout << "\t[_MENU_]" << endl;
        cout << "1. insert nodo" << endl;
        cout << "2. leave" << endl;
        cout << "[_option_]";
        cin >> option;

        switch (option) {
            case 1:
                cout << "enter a number: ";
                cin >> data;
                insertNodo(tree, data);
                cout << endl;
                break;
        }
    } while (option != 2);
}
