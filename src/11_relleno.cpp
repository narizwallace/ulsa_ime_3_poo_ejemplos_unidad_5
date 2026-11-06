// Diapositiva 11: Reto de curiosidad, el relleno
// Que observar: los atributos suman 5 bytes en Paquete, pero sizeof dice otra cosa.
// Experimento: cambia char extra por double y explica el nuevo tamano de PaqueteExtendido.
// Nota: el relleno lo decide el compilador; por eso se usa sizeof y no una suma.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Clase base con un int y un char.
class Paquete {
private:  // Los datos solo los maneja la clase
    int entero{0};  // Normalmente ocupa 4 bytes
    char letra{'x'};  // Ocupa 1 byte; despues suele quedar relleno
public:  // Interfaz publica de la clase
    int getEntero() const { return entero; }  // Permite leer el entero
    char getLetra() const { return letra; }  // Permite leer la letra
};

// Clase derivada que agrega un char.
class PaqueteExtendido : public Paquete {
private:  // El dato solo lo maneja la clase
    char extra{'y'};  // Puede guardarse en el relleno que dejo la base
public:  // Interfaz publica de la clase
    char getExtra() const { return extra; }  // Permite leer el dato propio
};

// Punto de inicio del programa.
int main() {
    PaqueteExtendido paquete;  // Crea un objeto para usar sus datos

    cout << "sizeof(int):              " << sizeof(int) << " bytes\n";  // Tamano del entero
    cout << "sizeof(char):             " << sizeof(char) << " byte\n";  // Tamano de la letra
    cout << "sizeof(Paquete):          " << sizeof(Paquete) << " bytes\n";  // Incluye relleno
    cout << "sizeof(PaqueteExtendido): " << sizeof(PaqueteExtendido) << " bytes\n";  // No aumento
    // Los tres datos existen aunque no aumento el tamano.
    cout << "Datos: " << paquete.getEntero() << " " << paquete.getLetra()
         << " " << paquete.getExtra() << "\n";

    return 0;  // Indica que el programa termino bien
}
