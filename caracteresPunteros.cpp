#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    char palabras[5] = {'h', 'o', 'l', 'a', char(0)};
    cout << palabras << endl;

    const char *pc = "adios";
    cout << pc << endl << endl;

    int k;
    for (k = 0; k < 6; k++) {
        cout << uintptr_t(pc[k]) << endl;
    }


}