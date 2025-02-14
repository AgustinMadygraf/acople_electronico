#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <Arduino.h>
#include "Sensor.h"
#include "PIDController.h"
#include "ILogger.h"
#include "HardwareManager.h" // added dependency for hardware control

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
     * @param hardwareManager Puntero al gestor de hardware para el control PWM.
     *
     * Se guardan las referencias para uso en la inicialización y actualización.
     */
    MainController(Sensor* sensorMaestro, Sensor* sensorEsclavo, PIDController* pid, ILogger* logger, HardwareManager* hardwareManager);
    
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
    HardwareManager* hardwareManager; // new dependency for PWM control
    unsigned long previousTime;
    // Removed PWM_ESCLAVO_PIN; PWM control is delegated.
    void configureHardware(); // new private method
};

#endif // MAINCONTROLLER_H
