// Diapositivas 34 y 35: Herencia virtual
// Que observar: por ambos caminos se llega a la misma parte Dispositivo.
// Experimento: quita Dispositivo(id) del constructor de Servo y lee el error del compilador.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

const int ID_SERVO = 7;  // Identificacion de ejemplo
const double GRADOS = 90;  // Posicion de ejemplo

// Base comun: con herencia virtual solo existe una parte.
class Dispositivo {
private:  // El id solo lo maneja la clase
    int id;  // Identificacion unica del dispositivo
public:  // Interfaz publica de la clase
    // explicit evita que un int se convierta solo en Dispositivo.
    explicit Dispositivo(int id) : id(id) {}
    virtual ~Dispositivo() = default;  // Destructor virtual: se usa como base
    int getId() const { return id; }  // Permite leer el id
};

// virtual indica que esta parte Dispositivo se comparte.
class Actuador : public virtual Dispositivo {
public:  // Interfaz publica de la clase
    explicit Actuador(int id) : Dispositivo(id) {}  // Solo aplica si Actuador es la clase final
    virtual void mover(double grados) = 0;  // Cada actuador define como moverse
};

// virtual indica que esta parte Dispositivo se comparte.
class Medidor : public virtual Dispositivo {
public:  // Interfaz publica de la clase
    explicit Medidor(int id) : Dispositivo(id) {}  // Solo aplica si Medidor es la clase final
    virtual double medir() const = 0;  // Cada medidor define como medir
};

// Clase final del diamante.
class Servo : public Actuador, public Medidor {
private:  // El angulo solo lo maneja Servo
    double angulo{0};  // Posicion actual
public:  // Interfaz publica de la clase
    // La clase mas derivada inicializa directamente a la base virtual.
    explicit Servo(int id) : Dispositivo(id), Actuador(id), Medidor(id) {}
    void mover(double grados) override { angulo = grados; }  // Cumple con Actuador
    double medir() const override { return angulo; }  // Cumple con Medidor
};

// Punto de inicio del programa.
int main() {
    Servo servo(ID_SERVO);  // Crea el objeto con una sola parte Dispositivo
    servo.mover(GRADOS);  // Cambia la posicion

    cout << servo.getId() << " " << servo.medir() << "\n";  // Ya no es ambiguo

    Actuador& comoActuador = servo;  // Primer camino hacia la base
    Medidor& comoMedidor = servo;  // Segundo camino hacia la base
    const Dispositivo* porActuador = &comoActuador;  // Direccion de la base por el primer camino
    const Dispositivo* porMedidor = &comoMedidor;  // Direccion de la base por el segundo camino
    cout << "Misma parte Dispositivo: " << (porActuador == porMedidor) << "\n";  // 1 significa verdadero

    return 0;  // Indica que el programa termino bien
}
