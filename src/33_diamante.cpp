// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositiva 33: El problema del diamante
// Que observar: un Servo guarda dos id distintos porque tiene dos partes Dispositivo.
// Experimento: quita el comentario de la linea marcada y lee el error del compilador.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

const int ID_ACTUADOR = 7;  // Id que recibe la primera copia
const int ID_MEDIDOR = 8;  // Id que recibe la segunda copia

// Base comun de la parte superior del diamante.
class Dispositivo {
private:  // El id solo lo maneja la clase
    int id;  // Cada parte Dispositivo tiene su propio id
public:  // Interfaz publica de la clase
    // explicit evita que un int se convierta solo en Dispositivo.
    explicit Dispositivo(int id) : id(id) {}
    virtual ~Dispositivo() = default;  // Destructor virtual: se usa como base
    int getId() const { return id; }  // Permite leer el id
};

// Primer camino del diamante: herencia normal.
class Actuador : public Dispositivo {
public:  // Interfaz publica de la clase
    explicit Actuador(int id) : Dispositivo(id) {}  // Construye su propia parte Dispositivo
};

// Segundo camino del diamante: herencia normal.
class Medidor : public Dispositivo {
public:  // Interfaz publica de la clase
    explicit Medidor(int id) : Dispositivo(id) {}  // Construye otra parte Dispositivo
};

// Clase inferior del diamante.
class Servo : public Actuador, public Medidor {
public:  // Interfaz publica de la clase
    // Cada base recibe un id distinto para ver las dos copias.
    Servo(int idActuador, int idMedidor) : Actuador(idActuador), Medidor(idMedidor) {}
};

// Punto de inicio del programa.
int main() {
    Servo servo(ID_ACTUADOR, ID_MEDIDOR);  // Crea un objeto con dos partes Dispositivo

    cout << servo.Actuador::getId() << "\n";  // Lee la copia del camino Actuador
    cout << servo.Medidor::getId() << "\n";  // Lee la copia del camino Medidor

    // >>> ERROR A PROPOSITO: hay dos getId y el compilador no sabe cual usar.
    // cout << servo.getId() << "\n";

    return 0;  // Indica que el programa termino bien
}
