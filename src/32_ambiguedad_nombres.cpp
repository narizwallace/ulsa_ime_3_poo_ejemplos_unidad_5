// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositiva 32: Ambiguedad de nombres
// Que observar: Motor:: y Bomba:: indican cual version se ejecuta.
// Experimento: quita el comentario de la linea marcada y lee el error del compilador.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Primera clase base.
class Motor {
public:  // Interfaz publica de la clase
    void encender() { cout << "motor\n"; }  // Mismo nombre que en Bomba
};

// Segunda clase base.
class Bomba {
public:  // Interfaz publica de la clase
    void encender() { cout << "bomba\n"; }  // Mismo nombre que en Motor
};

// Clase con dos bases que tienen un metodo igual.
class MotoBomba : public Motor, public Bomba {
public:  // Interfaz publica de la clase
    // Llama a ambos metodos indicando la clase de cada uno.
    void iniciar() {
        Motor::encender();  // :: elige la version de Motor
        Bomba::encender();  // :: elige la version de Bomba
    }
};

// Punto de inicio del programa.
int main() {
    MotoBomba motoBomba;  // Objeto con ambas bases
    motoBomba.iniciar();  // Ejecuta las dos versiones

    // >>> ERROR A PROPOSITO: el compilador no sabe cual encender usar.
    // motoBomba.encender();

    return 0;  // Indica que el programa termino bien
}
