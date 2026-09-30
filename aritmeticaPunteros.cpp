#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    double T[5] = {3.0, 8.0, 10.0, 5.0, 2.0};
    double *p;
    p = &T[0];

    cout << "T[0]: " << uintptr_t(&T[0]) << endl;
    cout << "p: " << uintptr_t(p) << endl;

    // cambia el valor de p haciendo que pase de T[0] a T[1]
    p = p + 1; 
    cout << "p: " << *p << endl;

    // lee el valor de p mas adelnate (+1) sin necesidad de cambiar el valor de p
    cout << "p: " << *(p + 1) << endl;

    cout << "=================================" << endl;

    double T2[5] = {5.0, 10.0, 2.0, 6.0, 9.0};
    double *p2;
    p2 = T2; // &T2[0] = T2
    *p2 = 3;
    *(T2 + 1) = -2; // T2[1] = -2
    T2[2] = 15; // *(p2 + 2) = 15

    int k;
    for (k = 0; k < 5; k++) cout << T2[k] << endl;
    cout << endl;
}