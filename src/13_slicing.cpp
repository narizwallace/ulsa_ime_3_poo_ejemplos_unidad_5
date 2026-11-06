// Diapositivas 12 y 13: Slicing
// Que observar: la copia responde como Indicador; la referencia, como IndicadorTemperatura.
// Experimento: cambia Indicador copia por Indicador& copia y compara la primera linea.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

// Clase base concreta: el ejemplo necesita crear un objeto Indicador.
class Indicador {
private:  // El id solo lo maneja esta clase
    string id;  // Identificacion del indicador
public:  // Interfaz publica de la clase
    // explicit evita que un string se convierta solo en Indicador.
    explicit Indicador(const string& id) : id(id) {}
    virtual ~Indicador() = default;  // Destructor virtual: la clase se usa como base
    const string& getId() const { return id; }  // Permite leer el id
    virtual string describir() const { return "Indicador " + id; }  // La derivada lo redefine
};

// Clase derivada que cambia la descripcion.
class IndicadorTemperatura : public Indicador {
public:  // Interfaz publica de la clase
    // Pasa el id a la parte base.
    explicit IndicadorTemperatura(const string& id) : Indicador(id) {}
    // override pide al compilador confirmar que redefine a la base.
    string describir() const override { return "Temperatura " + getId(); }
};

// Punto de inicio del programa.
int main() {
    IndicadorTemperatura temperatura("T1");  // Objeto real derivado

    Indicador copia = temperatura;  // Copia solo la parte base: esto es slicing
    Indicador& referencia = temperatura;  // Otro nombre para el mismo objeto real

    cout << copia.describir() << "\n";  // Responde la version base
    cout << referencia.describir() << "\n";  // Responde la version derivada

    return 0;  // Indica que el programa termino bien
}
