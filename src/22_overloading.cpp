// Diapositiva 22: Overloading
// Que observar: el mismo nombre ejecuta versiones distintas segun el argumento.
// Experimento: agrega la llamada registro.guardar(5.5f) y descubre cual version elige el compilador.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

const int CODIGO = 5;  // Codigo de ejemplo
const double VALOR = 5.0;  // Valor de ejemplo

// Clase con tres versiones de guardar.
class Registro {
public:  // Interfaz publica de la clase
    void guardar(int codigo) { cout << "int " << codigo << "\n"; }  // Version para enteros
    void guardar(double valor) { cout << "double " << valor << "\n"; }  // Version para decimales
    void guardar(const string& texto) { cout << "string " << texto << "\n"; }  // Version para texto
};

// Punto de inicio del programa.
int main() {
    Registro registro;  // Objeto que recibe las tres llamadas

    registro.guardar(CODIGO);  // El compilador elige la version int
    registro.guardar(VALOR);  // El compilador elige la version double
    registro.guardar("texto");  // El texto se convierte a string

    return 0;  // Indica que el programa termino bien
}
