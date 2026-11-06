// Diapositiva 8: El costo de virtual
// Que observar: con el mismo atributo, la clase con virtual mide mas.
// Experimento: agrega otro atributo double a ambas clases y compara los dos tamanos.
// Nota: 8 y 16 bytes se esperan en un sistema de 64 bits.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Clase sin metodos virtuales.
class SinVirtual {
private:  // El valor solo lo maneja la clase
    double valor{0};  // Atributo con valor inicial 0
public:  // Interfaz publica de la clase
    double getValor() const { return valor; }  // Metodo normal: no agrega datos al objeto
};

// Misma informacion, pero con metodos virtuales.
class ConVirtual {
private:  // El valor solo lo maneja la clase
    double valor{0};  // Atributo con valor inicial 0
public:  // Interfaz publica de la clase
    virtual ~ConVirtual() = default;  // = default pide el destructor normal del compilador
    virtual double getValor() const { return valor; }  // virtual agrega un vptr oculto al objeto
};

// Punto de inicio del programa.
int main() {
    SinVirtual sinVirtual;  // Crea un objeto sin vptr
    ConVirtual conVirtual;  // Crea un objeto con vptr

    cout << "sizeof(SinVirtual): " << sizeof(SinVirtual) << " bytes\n";  // Solo el double
    cout << "sizeof(ConVirtual): " << sizeof(ConVirtual) << " bytes\n";  // El double mas el vptr
    cout << "Valores: " << sinVirtual.getValor() << " y " << conVirtual.getValor() << "\n";  // Ambos inician en 0

    return 0;  // Indica que el programa termino bien
}
