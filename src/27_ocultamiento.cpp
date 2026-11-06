// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositiva 27: Ocultamiento de nombres
// Que observar: con using se pueden llamar las versiones de la base y la derivada.
// Experimento: quita el comentario de la linea marcada y lee el error del compilador.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

const int VALOR_ENTERO = 1;  // Valor de ejemplo
const double VALOR_DECIMAL = 2.5;  // Valor de ejemplo

// Clase base con dos sobrecargas.
class ConfigBase {
public:  // Interfaz publica de la clase
    virtual ~ConfigBase() = default;  // Destructor virtual: se usa como base
    void configurar(int) { cout << "ConfigBase int\n"; }  // Sin nombre: no usa el parametro
    void configurar(double) { cout << "ConfigBase double\n"; }  // Sin nombre: no usa el parametro
};

// Clase derivada que agrega otra version.
class ConfigBanda : public ConfigBase {
public:  // Interfaz publica de la clase
    using ConfigBase::configurar;  // using trae las versiones que el nombre nuevo ocultaria
    void configurar(const string&) { cout << "ConfigBanda string\n"; }  // Version de la derivada
};

// Clase derivada sin using: oculta las versiones de la base.
class ConfigOculta : public ConfigBase {
public:  // Interfaz publica de la clase
    void configurar(const string&) { cout << "ConfigOculta string\n"; }  // Oculta a la base
};

// Punto de inicio del programa.
int main() {
    ConfigBanda banda;  // Objeto con using
    ConfigOculta oculta;  // Objeto sin using

    banda.configurar(VALOR_ENTERO);  // Usa la version int de la base
    banda.configurar(VALOR_DECIMAL);  // Usa la version double de la base
    banda.configurar(string("modo"));  // Usa la version de la derivada
    oculta.configurar(string("modo"));  // Sin using, solo se ve esta version

    // >>> ERROR A PROPOSITO: sin using no se encuentra la version int.
    // oculta.configurar(VALOR_ENTERO);

    return 0;  // Indica que el programa termino bien
}
