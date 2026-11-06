// Diapositiva 10: vptr y vtable
// Que observar: agregar mas metodos virtuales no cambia el tamano del objeto.
// Experimento: agrega otro metodo virtual y confirma que el tamano sigue igual.
// Nota: la vtable pertenece a la clase; cada objeto solo guarda un puntero hacia ella.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Clase con un metodo virtual, ademas del destructor.
class ConUnVirtual {
private:  // El valor solo lo maneja la clase
    double valor{0};  // Dato normal del objeto
public:  // Interfaz publica de la clase
    virtual ~ConUnVirtual() = default;  // = default pide el destructor normal
    virtual double primero() const { return valor; }  // Agrega una entrada a la vtable
};

// Clase con tres metodos virtuales, ademas del destructor.
class ConTresVirtuales {
private:  // El valor solo lo maneja la clase
    double valor{0};  // Dato normal del objeto
public:  // Interfaz publica de la clase
    virtual ~ConTresVirtuales() = default;  // = default pide el destructor normal
    virtual double primero() const { return valor; }  // Entrada en la vtable
    virtual double segundo() const { return valor; }  // Otra entrada en la vtable
    virtual double tercero() const { return valor; }  // La tabla crece, el objeto no
};

// Punto de inicio del programa.
int main() {
    cout << "sizeof(ConUnVirtual):     " << sizeof(ConUnVirtual) << " bytes\n";  // double mas vptr
    cout << "sizeof(ConTresVirtuales): " << sizeof(ConTresVirtuales) << " bytes\n";  // Mismo tamano

    return 0;  // Indica que el programa termino bien
}
