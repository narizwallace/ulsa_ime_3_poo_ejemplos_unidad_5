// Diapositiva 40: encabezado de Sensor
// Que observar: es la definicion completa que necesita quien llama a sus metodos.

#ifndef SENSOR_H  // Evita procesar este archivo dos veces
#define SENSOR_H  // Marca que el archivo ya se proceso

#include <string>  // Permite usar el tipo std::string

// Clase abstracta: define lo que todo sensor debe poder hacer.
class Sensor {
public:  // Interfaz publica de la clase
    virtual ~Sensor() = default;  // Destructor virtual: se usa como base
    std::string nombre() const { return "Sensor"; }  // No virtual: decide el tipo del puntero
    virtual std::string unidad() const { return "sin unidad"; }  // Virtual con version por defecto
    virtual double leer() const = 0;  // = 0: cada derivada debe implementarlo
};

#endif  // Fin de la proteccion contra doble inclusion
