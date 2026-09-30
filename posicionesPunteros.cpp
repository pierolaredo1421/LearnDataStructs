#include <iostream>
using namespace std;

int a = 5, b = 8, c;
int spa = a;
int *p = &a;

int main(int argc, char *argv[]) {
    cout << "posicion de memoria a: " << uintptr_t(&a) << endl;

    // usa la referencia de a para estar en esa posicion
    cout << "posicion de memoria *pa asignando a: " << uintptr_t(p) << endl;

    // no tiene como referencia ni apunta a la posicion de memoria de a
    cout << "posicion de memoria spa asignando a: " << uintptr_t(&spa) << endl;

    cout << "=================================" << endl;

    *p = 3;
    cout << "a: " << a << endl;
    p = &b;
    *p = 6;
    cout << "b: " << b << endl;

    cout << "=================================" << endl;

    c = *p;
    *p = 11;
    cout << "c: " << c << endl;
    cout << "b: " << b << endl;
}
