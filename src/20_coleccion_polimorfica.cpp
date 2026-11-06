// Diapositiva 20: Colecciones polimorficas
// Que observar: el mismo ciclo atiende sensores distintos sin preguntar su tipo.
// Experimento: crea una clase Humedad, agregala al vector y deja el ciclo sin cambios.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
#include <vector>    // Permite usar vector
using namespace std;  // Evita escribir std:: antes de cout, string y vector

const double LECTURA_DISTANCIA = 12.5;  // Lectura simulada en centimetros
const double LECTURA_PRESION = 101.3;  // Lectura simulada en kilopascales

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

// Sensor concreto de presion.
class Presion : public Sensor {
public:  // Interfaz publica de la clase
    string unidad() const override { return "kPa"; }  // Redefine la unidad
    double leer() const override { return LECTURA_PRESION; }  // Implementa el metodo puro
};

// Punto de inicio del programa.
int main() {
    Distancia distancia;  // Primer objeto concreto
    Presion presion;  // Segundo objeto concreto

    vector<Sensor*> sensores{&distancia, &presion};  // Guarda direcciones, no copias

    // Cada vuelta llama a la version del objeto real.
    for (const Sensor* sensor : sensores) {
        cout << sensor->leer() << " " << sensor->unidad() << "\n";  // No hay if por tipo
    }

    return 0;  // Indica que el programa termino bien
}
