// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositiva 9: Nota de C++, double valor{0}
// Que observar: el atributo inicia en 0 sin escribir un constructor, y con = se pierde el .5.
// Experimento: quita el comentario de la linea marcada y lee el error del compilador.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Clase sin constructor escrito por nosotros.
class SinVirtual {
private:  // El valor solo lo maneja la clase
    double valor{0};  // Inicializador de miembro: cada objeto nace con 0.0
public:  // Interfaz publica de la clase
    double getValor() const { return valor; }  // Permite leer el valor
};

// Clase que muestra que un constructor tiene prioridad sobre {0}.
class ConConstructor {
private:  // El valor solo lo maneja la clase
    double valor{0};  // Se ignora si el constructor da otro valor
public:  // Interfaz publica de la clase
    // explicit evita convertir un double en objeto sin pedirlo.
    explicit ConConstructor(double valorInicial) : valor(valorInicial) {}
    double getValor() const { return valor; }  // Permite leer el valor
};

// Punto de inicio del programa.
int main() {
    const double VALOR_INICIAL = 5.5;  // Constante con nombre en lugar de un numero suelto
    const double DECIMAL = 3.5;  // Valor que se usara para mostrar la perdida

    SinVirtual sinConstructor;  // Usa el valor inicial {0}
    ConConstructor conConstructor(VALOR_INICIAL);  // Usa el valor del constructor

    cout << sinConstructor.getValor() << "\n";  // Imprime 0
    cout << conConstructor.getValor() << "\n";  // Imprime 5.5

    int entero = DECIMAL;  // Con = el compilador acepta perder la parte decimal
    cout << entero << "\n";  // Imprime 3: se perdio la parte decimal

    // >>> ERROR A PROPOSITO: las llaves no aceptan perder la parte decimal.
    // int enteroConLlaves{3.5}; cout << enteroConLlaves << "\n";

    return 0;  // Indica que el programa termino bien
}
