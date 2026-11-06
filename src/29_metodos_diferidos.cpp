// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositivas 28 y 29: Metodos diferidos, y si la derivada no implementa
// Que observar: SensorCompleto funciona porque implementa leer.
// Experimento: quita el comentario de la linea marcada y lee el error del compilador.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

const double LECTURA = 7.5;  // Lectura simulada

// Clase abstracta: define lo que todo sensor debe poder hacer.
class Sensor {
public:  // Interfaz publica de la clase
    virtual ~Sensor() = default;  // Destructor virtual: se usa como base
    string nombre() const { return "Sensor"; }  // No virtual: decide el tipo del puntero
    virtual string unidad() const { return "sin unidad"; }  // Virtual con version por defecto
    virtual double leer() const = 0;  // = 0: cada derivada debe implementarlo
};

// No implementa leer: hereda el metodo puro y tambien queda abstracta.
class SensorParcial : public Sensor { };

// Implementa leer: ya se pueden crear objetos.
class SensorCompleto : public Sensor {
public:  // Interfaz publica de la clase
    double leer() const override { return LECTURA; }  // Cumple el contrato de la base
};

// Punto de inicio del programa.
int main() {
    SensorCompleto sensor;  // Clase concreta: se puede instanciar
    cout << sensor.leer() << "\n";  // Usa la implementacion de la derivada

    // >>> ERROR A PROPOSITO: una clase abstracta no se puede instanciar.
    // SensorParcial parcial;

    return 0;  // Indica que el programa termino bien
}
