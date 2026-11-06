// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositiva 21: Overriding
// Que observar: el compilador advierte y la llamada por la base imprime 0, no 1.
// Experimento: quita el comentario de la linea marcada en FiltroRevisado y lee el error.
// Nota: sin override el programa compila, pero hace algo distinto a lo esperado.
// Nota: g++ 13 o mas reciente y clang muestran la advertencia; g++ anteriores no.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

const double RESULTADO_BASE = 0;  // Valor que devuelve el filtro base
const double RESULTADO_PROMEDIO = 1;  // Valor que devuelve el filtro derivado

// Clase base con un metodo virtual const.
class Filtro {
public:  // Interfaz publica de la clase
    virtual ~Filtro() = default;  // Destructor virtual: se usa como base
    virtual double calcular() const { return RESULTADO_BASE; }  // La firma incluye const
};

// Clase derivada que quiso redefinir, pero olvido const.
class FiltroPromedio : public Filtro {
public:  // Interfaz publica de la clase
    double calcular() { return RESULTADO_PROMEDIO; }  // ERROR A PROPOSITO: firma distinta
};

// Misma equivocacion, pero con override.
class FiltroRevisado : public Filtro {
public:  // Interfaz publica de la clase
    // >>> ERROR A PROPOSITO: override convierte el descuido en error de compilacion.
    // double calcular() override { return RESULTADO_PROMEDIO; }
};

// Punto de inicio del programa.
int main() {
    FiltroPromedio filtro;  // Objeto derivado
    Filtro& referencia = filtro;  // Referencia a la base

    cout << referencia.calcular() << "\n";  // No hubo redefinicion: usa la base
    cout << filtro.calcular() << "\n";  // Llamada directa: usa el metodo nuevo

    return 0;  // Indica que el programa termino bien
}
