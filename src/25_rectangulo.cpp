// Diapositivas 24 y 25: Sobrecarga de constructores y de metodos, Rectangulo
// Que observar: hay dos formas de crear y de desplazar; la superficie no cambia al mover.
// Experimento: agrega un metodo perimetro y calcula su resultado en main.
// Nota: superficie supone un rectangulo alineado con los ejes.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout y ostream

const int NUM_VERTICES = 4;  // Todo rectangulo tiene cuatro vertices
const int INFERIOR_IZQUIERDO = 0;  // Posicion del vertice en el arreglo
const int INFERIOR_DERECHO = 1;  // Posicion del vertice en el arreglo
const int SUPERIOR_DERECHO = 2;  // Posicion del vertice en el arreglo
const int SUPERIOR_IZQUIERDO = 3;  // Posicion del vertice en el arreglo

// Clase que representa un punto en el plano.
class Punto {
private:  // Las coordenadas solo las maneja la clase
    double x;  // Coordenada horizontal
    double y;  // Coordenada vertical
public:  // Interfaz publica de la clase
    // Argumentos por defecto: permiten crear Punto() sin datos, como pide el arreglo.
    Punto(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }  // Permite leer x
    double getY() const { return y; }  // Permite leer y
    // Define que significa a + b.
    Punto operator+(const Punto& o) const { return Punto(x + o.x, y + o.y); }
};

// Define como se imprime un Punto.
ostream& operator<<(ostream& os, const Punto& p) {
    return os << "(" << p.getX() << ", " << p.getY() << ")";  // Escribe las coordenadas
}

// Clase con constructores y metodos sobrecargados.
class Rectangulo {
private:  // Los vertices solo los maneja la clase
    Punto v[NUM_VERTICES];  // Arreglo de cuatro puntos dentro del objeto
public:  // Interfaz publica de la clase
    // Primer constructor: recibe los cuatro vertices.
    Rectangulo(const Punto& a, const Punto& b, const Punto& c, const Punto& d)
        : v{a, b, c, d} {}  // Las llaves inicializan el arreglo en orden

    // Segundo constructor: recibe base y altura, e inicia en (0, 0).
    Rectangulo(double base, double altura)
        : v{Punto(0, 0), Punto(base, 0), Punto(base, altura), Punto(0, altura)} {}

    // Calcula base por altura a partir de los vertices.
    double superficie() const {
        double base = v[INFERIOR_DERECHO].getX() - v[INFERIOR_IZQUIERDO].getX();  // Ancho
        double altura = v[SUPERIOR_IZQUIERDO].getY() - v[INFERIOR_IZQUIERDO].getY();  // Alto
        return base * altura;  // Resultado de la superficie
    }

    // Primera version: mueve con dos numeros.
    void desplazar(double dx, double dy) {
        // La referencia permite modificar cada vertice del arreglo.
        for (Punto& p : v) {
            p = p + Punto(dx, dy);  // Suma el desplazamiento al vertice
        }
    }

    // Segunda version: delega en la primera para no duplicar logica.
    void desplazar(const Punto& d) {
        desplazar(d.getX(), d.getY());  // Reutiliza el metodo anterior
    }

    // Devuelve un vertice para ver el efecto de desplazar.
    Punto verticeSuperiorDerecho() const { return v[SUPERIOR_DERECHO]; }
};

// Punto de inicio del programa.
int main() {
    const double BASE = 4;  // Base del primer rectangulo
    const double ALTURA = 3;  // Altura del primer rectangulo
    const double PASO_NUMEROS = 1;  // Desplazamiento con dos numeros
    const double PASO_PUNTO = 2;  // Desplazamiento con un Punto
    const double LADO_CORTO = 2;  // Ancho del segundo rectangulo
    const double LADO_LARGO = 5;  // Alto del segundo rectangulo

    Rectangulo rectangulo(BASE, ALTURA);  // Usa el constructor de base y altura
    cout << "Superficie: " << rectangulo.superficie() << "\n";  // Muestra la superficie
    cout << "Vertice: " << rectangulo.verticeSuperiorDerecho() << "\n";  // Posicion inicial

    rectangulo.desplazar(PASO_NUMEROS, PASO_NUMEROS);  // Usa la version de dos numeros
    rectangulo.desplazar(Punto(PASO_PUNTO, PASO_PUNTO));  // Usa la version de Punto
    cout << "Superficie: " << rectangulo.superficie() << "\n";  // No cambia al mover
    cout << "Vertice: " << rectangulo.verticeSuperiorDerecho() << "\n";  // Si cambio de lugar

    // Usa el constructor de cuatro vertices.
    Rectangulo porVertices(Punto(0, 0), Punto(LADO_CORTO, 0),
                           Punto(LADO_CORTO, LADO_LARGO), Punto(0, LADO_LARGO));
    cout << "Superficie: " << porVertices.superficie() << "\n";  // Muestra la superficie

    return 0;  // Indica que el programa termino bien
}
