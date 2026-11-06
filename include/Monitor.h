// Diapositiva 40: encabezado de Monitor
// Que observar: no incluye Sensor.h; le basta la declaracion adelantada.

#ifndef MONITOR_H  // Evita procesar este archivo dos veces
#define MONITOR_H  // Marca que el archivo ya se proceso

class Sensor;  // Declaracion adelantada: Sensor existe y se define en otro archivo

// Clase que muestra la lectura de un sensor.
class Monitor {
private:  // El puntero solo lo maneja Monitor
    const Sensor* sensor;  // Un puntero no necesita la definicion completa
public:  // Interfaz publica de la clase
    // explicit evita convertir un puntero en Monitor sin pedirlo.
    explicit Monitor(const Sensor* sensor);
    void mostrar() const;  // Se implementa donde se conoce a Sensor
};

#endif  // Fin de la proteccion contra doble inclusion
