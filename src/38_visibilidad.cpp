// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositiva 38: Visibilidad en la herencia
// Que observar: las tres derivadas leen los miembros public y protected de la base.
// Experimento: quita el comentario de cualquier linea marcada y lee el error del compilador.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Clase base con los tres niveles de acceso.
class Tablero {
private:  // Ni las derivadas pueden tocarlo directamente
    int secreto{3};  // Solo Tablero lo usa
protected:  // Las derivadas si pueden usarlo
    int interno{2};  // Dato disponible para derivadas
public:  // Se puede usar desde fuera, segun el tipo de herencia
    int a{1};  // Miembro publico de la base
    int getSecreto() const { return secreto; }  // Unica forma de leer el dato privado
};

// public mantiene los niveles de acceso: expresa IS-A.
class TableroPublico : public Tablero {
public:  // Interfaz publica de la clase
    int getInterno() const { return interno; }  // protected es visible aqui

    // >>> ERROR A PROPOSITO: private de la base no es accesible en la derivada.
    // int leerSecreto() const { return secreto; }
};

// protected convierte lo public de la base en protected.
class TableroProtegido : protected Tablero {
public:  // Interfaz publica de la clase
    int getA() const { return a; }  // Dentro de la derivada a sigue visible
    int getInterno() const { return interno; }  // protected sigue visible
};

// private convierte lo public y protected de la base en private.
class TableroPrivado : private Tablero {
public:  // Interfaz publica de la clase
    int getA() const { return a; }  // Dentro de la derivada a sigue visible
    int getInterno() const { return interno; }  // Aqui tambien es visible
};

// Punto de inicio del programa.
int main() {
    TableroPublico publico;  // Herencia public
    TableroProtegido protegido;  // Herencia protected
    TableroPrivado privado;  // Herencia private

    cout << publico.a << " " << publico.getInterno() << " " << publico.getSecreto() << "\n";  // a sigue public
    cout << protegido.getA() << " " << protegido.getInterno() << "\n";  // Acceso por metodos
    cout << privado.getA() << " " << privado.getInterno() << "\n";  // Acceso por metodos

    // >>> ERROR A PROPOSITO: en TableroProtegido, a ya no es public.
    // cout << protegido.a << "\n";

    return 0;  // Indica que el programa termino bien
}
