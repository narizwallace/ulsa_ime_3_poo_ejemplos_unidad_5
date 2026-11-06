// Diapositiva 31: Herencia multiple
// Que observar: un mismo Servo se usa como Actuador y como Medidor.
// Experimento: crea una funcion que reciba Actuador& y enviale un Servo.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

const double GRADOS = 90;  // Posicion de ejemplo

// Capacidad de moverse.
class Actuador {
public:  // Interfaz publica de la clase
    virtual ~Actuador() = default;  // Destructor virtual: se usa como base
    virtual void mover(double grados) = 0;  // Cada actuador define como moverse
};

// Capacidad de medir.
class Medidor {
public:  // Interfaz publica de la clase
    virtual ~Medidor() = default;  // Destructor virtual: se usa como base
    virtual double medir() const = 0;  // Cada medidor define como medir
};

// Servo hereda de ambas capacidades.
class Servo : public Actuador, public Medidor {
private:  // El angulo solo lo maneja Servo
    double angulo{0};  // Posicion actual
public:  // Interfaz publica de la clase
    void mover(double grados) override { angulo = grados; }  // Cumple con Actuador
    double medir() const override { return angulo; }  // Cumple con Medidor
};

// Punto de inicio del programa.
int main() {
    Servo servo;  // Objeto con las dos capacidades
    Actuador& comoActuador = servo;  // Lo ve solo como Actuador
    Medidor& comoMedidor = servo;  // Lo ve solo como Medidor

    comoActuador.mover(GRADOS);  // Usa la capacidad de moverse
    cout << comoMedidor.medir() << "\n";  // Usa la capacidad de medir

    return 0;  // Indica que el programa termino bien
}
