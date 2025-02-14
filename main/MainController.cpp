#include "MainController.h"
#include <Arduino.h>

/**
 * @brief Constructs the MainController with provided dependencies.
 */
MainController::MainController(Sensor* sensorMaestro, Sensor* sensorEsclavo, PIDController* pid, ILogger* logger)
    : sensorMaestro(sensorMaestro), sensorEsclavo(sensorEsclavo), pid(pid), logger(logger), previousTime(0) {
    // Constructor: inicializa las dependencias necesarias para el control del sistema.

}

/**
 * @brief Initializes subsystems: logger, sensors, and PWM.
 */
void MainController::begin() {
    logger->begin(LOG_DEBUG);
    // Inicializa el logger con nivel DEBUG para capturar información detallada.
    sensorMaestro->begin();
    sensorEsclavo->begin();
    // Configura ambos sensores para empezar a contar pulsos.
    
    pinMode(PWM_ESCLAVO_PIN, OUTPUT);
    // Configura el pin para salida PWM.
    ledcSetup(0, 1000, 8);
    // Configura el canal 0 para un PWM de 1 kHz y resolución de 8 bits.
    ledcAttachPin(PWM_ESCLAVO_PIN, 0);
    // Asocia el canal PWM al pin configurado.

}

/**
 * @brief Periodically reads sensor data, computes control signal, and adjusts PWM output.
 */
void MainController::update() {
    unsigned long currentTime = millis();
    // Obtiene el tiempo actual para calcular intervalos de actualización.
    if (currentTime - previousTime >= 100) { // Usa un tiempo de muestreo de 100ms.
        previousTime = currentTime;
        float rpmMaestro = sensorMaestro->getRPM();
        float rpmEsclavo = sensorEsclavo->getRPM();
        // Se obtienen las RPM de ambos sensores, reiniciando los contadores.
        
        int pwmOutput = pid->compute(rpmMaestro, rpmEsclavo);
        // Calcula la señal de control a partir del error entre ambos sensores.
        ledcWrite(0, pwmOutput);
        // Actualiza la salida PWM según el cálculo del PID.

        char logMsg[128];
        sprintf(logMsg, "RPM Maestro: %.2f, RPM Esclavo: %.2f, PWM: %d", rpmMaestro, rpmEsclavo, pwmOutput);
        logger->log(LOG_INFO, logMsg);
        // Registra la información del estado actual para debugging y monitoreo.
    }

}
