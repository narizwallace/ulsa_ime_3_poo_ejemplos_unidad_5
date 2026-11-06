// Diapositiva 40: Dependencias en los encabezados
// Que observar: Monitor.h solo necesita saber que Sensor existe.
// Experimento: agrega un #include "Sensor.h" a Monitor.h; compila igual, pero crea mas dependencia.
// Nota: este es el unico ejemplo que usa include/, porque el tema son los encabezados.

#include "Monitor.h"  // Trae la declaracion de Monitor
#include "Sensor.h"   // Aqui si se necesita la definicion completa de Sensor
#include <iostream>   // Permite imprimir con cout

const double LECTURA_FIJA = 9.5;  // Lectura simulada

// Guarda la direccion del sensor recibido.
Monitor::Monitor(const Sensor* sensor) : sensor(sensor) {}

// Usa el sensor; por eso este archivo necesita conocer su definicion.
void Monitor::mostrar() const {
    std::cout << sensor->leer() << "\n";  // Llama al metodo virtual
}

// Sensor concreto para probar Monitor.
class SensorFijo : public Sensor {
public:  // Interfaz publica de la clase
    double leer() const override { return LECTURA_FIJA; }  // Implementa el metodo puro
};

// Punto de inicio del programa.
int main() {
    SensorFijo sensor;  // Objeto concreto
    Monitor monitor(&sensor);  // Recibe la direccion del sensor

    monitor.mostrar();  // Imprime la lectura

    return 0;  // Indica que el programa termino bien
}
