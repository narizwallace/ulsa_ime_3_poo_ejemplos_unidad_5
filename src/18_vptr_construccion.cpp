// Diapositiva 18: El vptr durante la construccion
// Que observar: el constructor y el destructor de la base imprimen ControladorBase.
// Experimento: agrega saludar() en un constructor de ControladorServo y compara la salida.
// Nota: se hace solo para demostrarlo; en codigo real no llames virtuales desde aqui.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Clase base que llama a un metodo virtual al nacer y al destruirse.
class ControladorBase {
public:  // Interfaz publica de la clase
    ControladorBase() { saludar(); }  // El vptr todavia apunta a la vtable de la base
    virtual ~ControladorBase() { saludar(); }  // La parte derivada ya no existe
    virtual void saludar() const { cout << "ControladorBase\n"; }  // Version de la base
};

// Clase derivada que redefine el saludo.
class ControladorServo : public ControladorBase {
public:  // Interfaz publica de la clase
    void saludar() const override { cout << "ControladorServo\n"; }  // Version derivada
};

// Punto de inicio del programa.
int main() {
    ControladorServo controlador;  // Durante la construccion se imprime la version base
    controlador.saludar();  // El objeto ya esta completo: imprime la version derivada

    return 0;  // Al salir, el objeto se destruye e imprime la version base
}
