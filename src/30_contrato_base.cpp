// Diapositiva 30: El contrato vive en la base
// Que observar: siempre se imprime validar antes del resultado.
// Experimento: crea una clase Radar con su propio medir y comprueba que tambien valida.

#include <iostream>  // Permite imprimir con cout
using namespace std;  // Evita escribir std:: antes de cout

const double MEDICION_LIDAR = 3.2;  // Medicion simulada

// Clase base que controla el proceso completo.
class Lector {
private:  // Nadie fuera de la clase llama a estos pasos
    void validar() const { cout << "validar\n"; }  // Paso fijo para todos
    virtual double medir() const = 0;  // Paso variable: lo define la derivada
public:  // Interfaz publica de la clase
    virtual ~Lector() = default;  // Destructor virtual: se usa como base
    // Unico punto de entrada: fija el orden de los pasos.
    double leer() const {
        validar();  // Primero valida
        return medir();  // Despues ejecuta la version de la derivada
    }
};

// Clase derivada que solo aporta el paso variable.
class Lidar : public Lector {
private:  // medir tampoco se llama desde fuera
    double medir() const override { return MEDICION_LIDAR; }  // Implementa el paso variable
};

// Punto de inicio del programa.
int main() {
    Lidar lidar;  // Objeto concreto
    cout << lidar.leer() << "\n";  // Ejecuta validar y luego medir

    return 0;  // Indica que el programa termino bien
}
