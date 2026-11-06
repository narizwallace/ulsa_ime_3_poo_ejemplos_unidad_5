// Diapositiva 17: Metodo virtual no redefinido
// Que observar: Conteo no redefine unidad, por eso responde con la version de Sensor.
// Experimento: agrega unidad a Conteo con override y mira como cambia la salida.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

const double LECTURA_DISTANCIA = 12.5;  // Lectura simulada en centimetros
const double LECTURA_CONTEO = 3;  // Conteo simulado de piezas

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

// Sensor concreto que no redefine unidad.
class Conteo : public Sensor {
public:  // Interfaz publica de la clase
    double leer() const override { return LECTURA_CONTEO; }  // Solo implementa lo obligatorio
};

// Punto de inicio del programa.
int main() {
    Distancia distancia;  // Su vtable apunta a Distancia::unidad
    Conteo conteo;  // Su vtable apunta a Sensor::unidad
    const Sensor& sensorDistancia = distancia;  // Referencia a la base
    const Sensor& sensorConteo = conteo;  // Referencia a la base

    cout << sensorDistancia.unidad() << "\n";  // Usa la version redefinida
    cout << sensorConteo.unidad() << "\n";  // Usa la version heredada

    return 0;  // Indica que el programa termino bien
}
