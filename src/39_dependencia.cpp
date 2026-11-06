// Diapositiva 39: Dependencia entre clases
// Que observar: Banda depende de Motor y Bitacora de formas distintas.
// Experimento: cambia el mensaje de Bitacora::escribir y mira que Banda no necesita cambios.

#include <iostream>  // Permite imprimir con cout
#include <string>    // Permite usar el tipo string
using namespace std;  // Evita escribir std:: antes de cout y string

// Clase que Banda contiene por composicion.
class Motor {
public:  // Interfaz publica de la clase
    void encender() { cout << "motor\n"; }  // Accion del motor
};

// Clase que Banda conoce, pero no contiene.
class Bitacora {
public:  // Interfaz publica de la clase
    void escribir(const string& texto) { cout << texto << "\n"; }  // Registra un mensaje
};

// Clase que muestra tres formas de dependencia.
class Banda {
private:  // Las relaciones solo las maneja Banda
    Motor motor;  // Composicion: el motor nace y muere con la banda
    Bitacora* bitacora;  // Asociacion: la bitacora existe por fuera
public:  // Interfaz publica de la clase
    // explicit evita convertir un puntero en Banda sin pedirlo.
    explicit Banda(Bitacora* b) : bitacora(b) {}
    // Usa sus dos relaciones permanentes.
    void iniciar() {
        motor.encender();  // Llama a la parte que contiene
        bitacora->escribir("Banda iniciada");  // Llama al objeto asociado
    }
    // Uso en parametro: solo depende de Bitacora durante esta llamada.
    void reportar(Bitacora& otra) const {
        otra.escribir("Reporte");  // Usa el objeto recibido
    }
};

// Punto de inicio del programa.
int main() {
    Bitacora bitacora;  // Existe antes que la banda
    Banda banda(&bitacora);  // Recibe la direccion de la bitacora

    banda.iniciar();  // Usa composicion y asociacion
    banda.reportar(bitacora);  // Usa la dependencia por parametro

    return 0;  // Indica que el programa termino bien
}
