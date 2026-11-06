// Diapositiva 5: Un derivado contiene a su baseYou ha
// Que observar: Termometro mide mas que Instrumento, y la parte base esta dentro del objeto.
// Experimento: agrega un atributo double a Termopar y mira como crece sizeof(Termometro).
// Nota: las direcciones cambian en cada ejecucion y los tamanos dependen del compilador.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

// Pieza que forma parte del termometro.
class Termopar {
private:  // Solo la propia clase puede tocar lo siguiente
    double milivolts{0};  // Ocupa espacio dentro de cada objeto; inicia en 0
public:  // Lo siguiente se puede usar desde fuera
    // const indica que este metodo no modifica el objeto.
    double getMilivolts() const { return milivolts; }
};

// Clase base con una identificacion.
class Instrumento {
private:  // Solo Instrumento puede tocar el id directamente
    string id;  // Cada instrumento guarda su propia identificacion
public:  // Interfaz publica de la clase
    // explicit evita que un string se convierta solo en Instrumento sin pedirlo.
    explicit Instrumento(const string& id) : id(id) {}
    virtual ~Instrumento() = default;  // Destructor virtual: la clase se usa como base
    const string& getId() const { return id; }  // Permite leer el id sin copiarlo
};

// Clase derivada: un Termometro ES UN Instrumento y TIENE UN Termopar.
class Termometro : public Instrumento {
private:  // El termopar solo lo maneja Termometro
    Termopar termopar;  // Parte propia del objeto derivado
public:  // Interfaz publica de la clase
    // explicit evita conversiones automaticas; primero se construye la parte base.
    explicit Termometro(const string& id) : Instrumento(id) {}
    // Devuelve la direccion del termopar para poder imprimirla.
    const Termopar* getTermopar() const { return &termopar; }
};

// Punto de inicio del programa.
int main() {
    Termometro termometro("T1");  // Crea un objeto derivado
    const Instrumento* parteBase = &termometro;  // Apunta a la parte heredada del objeto

    cout << "sizeof(Instrumento): " << sizeof(Instrumento) << " bytes\n";  // Tamano de la base
    cout << "sizeof(Termometro):  " << sizeof(Termometro) << " bytes\n";  // Base mas parte propia
    cout << "Direccion del objeto:   " << &termometro << "\n";  // Donde inicia el objeto
    cout << "Direccion parte base:   " << parteBase << "\n";  // Normalmente coincide con el inicio
    cout << "Direccion del termopar: " << termometro.getTermopar() << "\n";  // Esta despues de la base
    cout << "Id guardado en la base: " << parteBase->getId() << "\n";  // El dato heredado existe aqui
    cout << "Milivolts del termopar: " << termometro.getTermopar()->getMilivolts() << "\n";  // Dato propio

    return 0;  // Indica que el programa termino bien
}
