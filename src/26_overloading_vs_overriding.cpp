// Diapositiva 26: Overloading vs. overriding
// Que observar: activar se elige por sus argumentos; describir, por el objeto real.
// Experimento: quita virtual de describir y override de la derivada; compara la ultima linea.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

const int NIVEL = 2;  // Nivel de alarma de ejemplo

// Clase base con overloading y con un metodo virtual.
class Alarma {
public:  // Interfaz publica de la clase
    virtual ~Alarma() = default;  // Destructor virtual: se usa como base
    void activar(int nivel) { cout << "Activar nivel " << nivel << "\n"; }  // Sobrecarga para int
    void activar(const string& mensaje) { cout << "Activar: " << mensaje << "\n"; }  // Sobrecarga para texto
    virtual string describir() const { return "Alarma general"; }  // Se puede redefinir
};

// Clase derivada con overriding.
class AlarmaSonora : public Alarma {
public:  // Interfaz publica de la clase
    string describir() const override { return "Alarma sonora"; }  // Misma firma, nuevo comportamiento
};

// Punto de inicio del programa.
int main() {
    AlarmaSonora sonora;  // Objeto derivado
    Alarma& alarma = sonora;  // Referencia a la base

    alarma.activar(NIVEL);  // Overloading: decide el argumento al compilar
    alarma.activar("paro de linea");  // Overloading: el texto elige la otra version
    cout << alarma.describir() << "\n";  // Overriding: decide el objeto al ejecutar

    return 0;  // Indica que el programa termino bien
}
