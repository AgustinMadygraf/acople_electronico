#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <Arduino.h>
#include "Sensor.h"
#include "PIDController.h"
#include "ILogger.h"

/**
 * @class MainController
 * @brief Coordina la lectura de sensores, cálculo PID y salida a actuadores.
 *
 * La clase MainController utiliza:
 * - Inyección de dependencias para los sensores, controlador PID y logger.
 * - Métodos para inicializar y actualizar el sistema de control.
 */
class MainController {
public:
    /**
     * @brief Constructor que inyecta las dependencias necesarias.
     *
     * @param sensorMaestro Puntero al sensor maestro.
     * @param sensorEsclavo Puntero al sensor esclavo.
     * @param pid Puntero al controlador PID.
     * @param logger Puntero al logger para el registro de eventos.
     *
     * Se guardan las referencias para uso en la inicialización y actualización.
     */
    MainController(Sensor* sensorMaestro, Sensor* sensorEsclavo, PIDController* pid, ILogger* logger);
    
    /**
     * @brief Inicializa todos los subsistemas.
     *
     * Configura el logger, inicializa ambos sensores y ajusta la salida PWM.
     */
    void begin();
    
    /**
     * @brief Actualiza de forma periódica:
     * - Lee las RPM de los sensores.
     * - Calcula la salida PID.
     * - Aplica la señal a través del PWM.
     */
    void update();
    
private:
    Sensor* sensorMaestro;
    Sensor* sensorEsclavo;
    PIDController* pid;
    ILogger* logger;
    unsigned long previousTime;
    static const int PWM_ESCLAVO_PIN = 25; // Pin dedicado a la salida PWM del sensor esclavo.
    // Constants used for PWM setup and other hardware parameters.
};

#endif // MAINCONTROLLER_H
