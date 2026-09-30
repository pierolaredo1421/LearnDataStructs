#include <iostream>
using namespace std;

// new: reserva de memoria heap (zona de memoria dinamica)
// 1. para un solo dato de tipo basico (char, int, double, ...)
// 2. para una tabla de tipo basico
// 3. para un struct
struct Punto {
    double x, y;
};
// 4. para una clase
class Circulo {
    double _radio, _cx, _cy;
    public:
    Circulo(double r, double x, double y) // constructor
    : _radio(r), _cx(x), _cy(y) {}

    double radio() const { // funcion que devuelve radio
        return _radio;
    }
};

int main(int argc, char *argv[]) {
    int T[10]; // reservada en la pila

    //1.
    int *p_entero = new int;
    *p_entero = 5;
    cout << "*p_entero: " << *p_entero << endl;

    //2.
    int *p_tabla = new int[10];
    *p_tabla = 1;
    *(p_tabla + 3) = 4; // 1era manera de acceder a una tabla
    p_tabla[3] = 4; // 2da manera de acceder a una tabla

    //3.
    Punto *p_punto = new Punto;
    p_punto->x = 4; // 1era manera de acceder a un struct
    (*p_punto).y = 5; // 2da manera de acceder a un struct

    //4.
    Circulo *p_circulo = new Circulo(10.0, 0.0, 0.0);
    cout << p_circulo->radio() << endl; // 1era manera de acceder a una clase
    cout << (*p_circulo).radio() << endl; // 2da manera de acceder a una clase
}
