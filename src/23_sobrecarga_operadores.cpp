// Diapositiva 23: Sobrecarga de operadores
// Que observar: + , == y << funcionan con Punto como si fuera un tipo basico.
// Experimento: agrega operator- a Punto y prueba cout << a - b.
// Nota: 0 significa falso y 1 verdadero al imprimir un bool.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout y ostream

// Clase que representa un punto en el plano.
class Punto {
private:  // Las coordenadas solo las maneja la clase
    double x;  // Coordenada horizontal
    double y;  // Coordenada vertical
public:  // Interfaz publica de la clase
    // Argumentos por defecto: si no se envian, x y y valen 0.
    Punto(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }  // Permite leer x
    double getY() const { return y; }  // Permite leer y
    // Define que significa a == b; aqui solo es una demostracion con double.
    bool operator==(const Punto& o) const { return x == o.x && y == o.y; }
    // Define que significa a + b; devuelve un punto nuevo.
    Punto operator+(const Punto& o) const { return Punto(x + o.x, y + o.y); }
};

// Define que significa cout << punto; regresa el flujo para encadenar otro <<.
ostream& operator<<(ostream& os, const Punto& p) {
    return os << "(" << p.getX() << ", " << p.getY() << ")";  // Escribe las coordenadas
}

// Punto de inicio del programa.
int main() {
    const double AX = 1;  // Coordenada x del primer punto
    const double AY = 2;  // Coordenada y del primer punto
    const double BX = 3;  // Coordenada x del segundo punto
    const double BY = 4;  // Coordenada y del segundo punto

    Punto a(AX, AY);  // Crea el primer punto
    Punto b(BX, BY);  // Crea el segundo punto

    cout << a + b << "\n";  // Usa operator+ y luego operator<<
    cout << (a == b) << "\n";  // Los parentesis hacen que == se evalue primero

    return 0;  // Indica que el programa termino bien
}
