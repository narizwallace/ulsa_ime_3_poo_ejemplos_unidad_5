// Diapositivas 15 y 16: Con y sin virtual, y que ocurre en una llamada virtual
// Que observar: con el mismo puntero, nombre usa Sensor y leer usa Distancia.
// Experimento: agrega virtual a nombre en Sensor y override en Distancia; vuelve a ejecutar.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

const double LECTURA_DISTANCIA = 12.5;  // Lectura simulada en centimetros

// Clase abstracta: define lo que todo sensor debe poder hacer.
class Sensor {
public:  // Interfaz publica de la clase
    virtual ~Sensor() = default;  // Destructor virtual: se usa como base
    string nombre() const { return "Sensor"; }  // No virtual: decide el tipo del puntero
    virtual string unidad() const { return "sin unidad"; }  // Virtual con version por defecto
    virtual double leer() const = 0;  // = 0: cada derivada debe implementarlo
};

// Sensor concreto de distancia.
class Distancia : public Sensor {
public:  // Interfaz publica de la clase
    string nombre() const { return "Distancia"; }  // Oculta a Sensor::nombre; no es virtual
    string unidad() const override { return "cm"; }  // Redefine el metodo virtual
    double leer() const override { return LECTURA_DISTANCIA; }  // Implementa el metodo puro
};

// Punto de inicio del programa.
int main() {
    Distancia distancia;  // Objeto real: su vptr apunta a la vtable de Distancia
    Sensor* sensor = &distancia;  // El puntero es de la base, el objeto es derivado

    cout << sensor->nombre() << "\n";  // Sin virtual: se fija al compilar segun el puntero
    // Con virtual: objeto, vptr, vtable y salto a Distancia::leer.
    cout << sensor->leer() << "\n";

    return 0;  // Indica que el programa termino bien
}
