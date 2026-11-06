// ESTE PROGRAMA TIENE UN ERROR A PROPOSITO
// Diapositiva 19: Por que el destructor virtual
// Que observar: la primera prueba ejecuta dos destructores; la segunda solo uno.
// Experimento: agrega virtual al destructor de PuertoBase y confirma que desaparece la advertencia.
// Nota: la advertencia es esperada; borrar asi es comportamiento indefinido.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

// Version correcta: el destructor es virtual.
class RecursoBase {
public:  // Interfaz publica de la clase
    virtual ~RecursoBase() { cout << "~RecursoBase\n"; }  // Tiene entrada en la vtable
};

// Clase derivada de la version correcta.
class RecursoPuerto : public RecursoBase {
public:  // Interfaz publica de la clase
    ~RecursoPuerto() override { cout << "~RecursoPuerto\n"; }  // Redefine el destructor
};

// Version incorrecta: tiene un metodo virtual, pero su destructor no lo es.
class PuertoBase {
public:  // Interfaz publica de la clase
    ~PuertoBase() { cout << "~PuertoBase\n"; }  // ERROR A PROPOSITO: falta virtual
    virtual void abrir() { cout << "abrir base\n"; }  // Hace polimorfica a la clase
};

// Clase derivada de la version incorrecta.
class PuertoSerial : public PuertoBase {
public:  // Interfaz publica de la clase
    ~PuertoSerial() { cout << "~PuertoSerial\n"; }  // No se ejecuta en la segunda prueba
    void abrir() override { cout << "abrir serial\n"; }  // Redefine abrir
};

// Punto de inicio del programa.
int main() {
    cout << "Con destructor virtual:\n";  // Titulo de la primera prueba
    // new crea el objeto en memoria dinamica y devuelve su direccion.
    RecursoBase* recurso = new RecursoPuerto;
    delete recurso;  // delete destruye el objeto y libera su memoria

    cout << "Sin destructor virtual:\n";  // Titulo de la segunda prueba
    PuertoBase* puerto = new PuertoSerial;  // Puntero a la base, objeto derivado
    puerto->abrir();  // leer la vtable funciona: abrir es virtual
    delete puerto;  // Aqui aparece la advertencia del compilador

    return 0;  // Indica que el programa termino bien
}
