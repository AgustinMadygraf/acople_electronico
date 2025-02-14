#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <Arduino.h>
#include "Sensor.h"
#include "PIDController.h"
#include "ILogger.h"

/**
 * @class MainController
 * @brief Manages sensor readings, PID computation, and actuator output.
 *
 * Uses dependency injection to receive Sensor, PIDController, and ILogger instances.
 */
class MainController {
public:
    /**
     * @brief Constructs MainController with injected dependencies.
     *
     * @param sensorMaestro Pointer to the master sensor.
     * @param sensorEsclavo Pointer to the slave sensor.
     * @param pid Pointer to the PID controller.
     * @param logger Pointer to the logger instance.
     */
    MainController(Sensor* sensorMaestro, Sensor* sensorEsclavo, PIDController* pid, ILogger* logger);
    
    /**
     * @brief Initializes all subsystems.
     */
    void begin();
    
    /**
     * @brief Performs a periodic update: reads sensors, computes PID, and updates PWM output.
     */
    void update();
    
private:
    Sensor* sensorMaestro;
    Sensor* sensorEsclavo;
    PIDController* pid;
    ILogger* logger;
    unsigned long previousTime;
    static const int PWM_ESCLAVO_PIN = 25;
    // Constants used for PWM setup and other hardware parameters.
};

#endif // MAINCONTROLLER_H
