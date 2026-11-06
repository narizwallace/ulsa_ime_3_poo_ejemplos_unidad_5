// Diapositivas 6 y 7: Orden de construccion y destruccion
// Que observar: se construyen base, miembro y derivado; se destruyen en orden inverso.
// Experimento: agrega un segundo Termopar a Termometro y mira cuantas lineas nuevas aparecen.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

// Miembro de Termometro; avisa cuando nace y cuando se destruye.
class Termopar {
public:  // Se puede crear desde otras clases
    Termopar() { cout << "Termopar()\n"; }  // Se ejecuta al crear el objeto
    ~Termopar() { cout << "~Termopar()\n"; }  // Se ejecuta al destruir el objeto
};

// Clase base; tambien avisa cuando nace y cuando se destruye.
class Instrumento {
private:  // El id solo lo maneja esta clase
    string id;  // Identificacion del instrumento
public:  // Interfaz publica de la clase
    // explicit evita que un string se convierta solo en Instrumento.
    explicit Instrumento(const string& id) : id(id) {
        cout << "Instrumento()\n";  // Muestra que la parte base ya esta lista
    }
    virtual ~Instrumento() { cout << "~Instrumento()\n"; }  // Virtual porque es clase base
    const string& getId() const { return id; }  // Permite leer el id
};

// Clase derivada que hereda de Instrumento y contiene un Termopar.
class Termometro : public Instrumento {
private:  // El termopar es parte interna del termometro
    Termopar termopar;  // Se construye despues de la base y antes del cuerpo
public:  // Interfaz publica de la clase
    // La lista de inicializacion construye primero la parte Instrumento.
    explicit Termometro(const string& id) : Instrumento(id) {
        cout << "Termometro()\n";  // El cuerpo corre al final de la construccion
    }
    // override confirma que redefine el destructor virtual de la base.
    ~Termometro() override {
        cout << "~Termometro()\n";  // El cuerpo corre al inicio de la destruccion
    }
};

// Punto de inicio del programa.
int main() {
    // Las llaves crean un bloque: el objeto se destruye al salir de el.
    {
        Termometro termometro("T1");  // Aqui se ejecuta toda la construccion
        cout << "--- objeto listo: " << termometro.getId() << " ---\n";  // Marca el punto medio
    }

    return 0;  // Indica que el programa termino bien
}
