// Diapositiva 36: Reto de curiosidad, cuantos vptr
// Que observar: con dos bases polimorficas, el objeto crece 8 bytes.
// Experimento: agrega una tercera interfaz a ServoCompleto y predice el nuevo tamano.
// Nota: 16 y 24 bytes se esperan en un sistema de 64 bits.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

const double GRADOS = 45;  // Posicion de ejemplo

// Interfaz sin atributos.
class Movible {
public:  // Interfaz publica de la clase
    virtual ~Movible() = default;  // Destructor virtual: se usa como base
    virtual void mover(double grados) = 0;  // Cada clase define como moverse
};

// Segunda interfaz sin atributos.
class Legible {
public:  // Interfaz publica de la clase
    virtual ~Legible() = default;  // Destructor virtual: se usa como base
    virtual double medir() const = 0;  // Cada clase define como medir
};

// Hereda de una sola base polimorfica.
class ServoSimple : public Movible {
private:  // El angulo solo lo maneja la clase
    double angulo{0};  // Posicion actual
public:  // Interfaz publica de la clase
    void mover(double grados) override { angulo = grados; }  // Cumple con Movible
    double getAngulo() const { return angulo; }  // Permite leer el angulo
};

// Hereda de dos bases polimorficas.
class ServoCompleto : public Movible, public Legible {
private:  // El angulo solo lo maneja la clase
    double angulo{0};  // Posicion actual
public:  // Interfaz publica de la clase
    void mover(double grados) override { angulo = grados; }  // Cumple con Movible
    double medir() const override { return angulo; }  // Cumple con Legible
};

// Punto de inicio del programa.
int main() {
    ServoSimple simple;  // Objeto con una base polimorfica
    ServoCompleto completo;  // Objeto con dos bases polimorficas
    simple.mover(GRADOS);  // Usa el primer objeto
    completo.mover(GRADOS);  // Usa el segundo objeto

    cout << "sizeof(ServoSimple):   " << sizeof(ServoSimple) << " bytes\n";  // double mas un vptr
    cout << "sizeof(ServoCompleto): " << sizeof(ServoCompleto) << " bytes\n";  // double mas dos vptr
    cout << "Angulos: " << simple.getAngulo() << " y " << completo.medir() << "\n";  // Ambos funcionan

    return 0;  // Indica que el programa termino bien
}
