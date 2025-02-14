#include "MainController.h"
#include <Arduino.h>
#include "DebugManager.h"

/**
 * @brief Constructs the MainController with provided dependencies.
 */
MainController::MainController(Sensor* sensorMaestro, Sensor* sensorEsclavo, PIDController* pid, ILogger* logger, HardwareManager* hardwareManager)
    : sensorMaestro(sensorMaestro), sensorEsclavo(sensorEsclavo), pid(pid), logger(logger),
      hardwareManager(hardwareManager), previousTime(0) {
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
    
    configureHardware(); // call new method
    // Delegate PWM configuration to HardwareManager.

}

/**
 * @brief Configures the hardware components.
 */
void MainController::configureHardware() {
    hardwareManager->beginPWM();
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
        // Delegate PWM write to HardwareManager.
        hardwareManager->writePWM(pwmOutput);
        // Actualiza la salida PWM según el cálculo del PID.

        char logMsg[128];
        sprintf(logMsg, "RPM Maestro: %.2f, RPM Esclavo: %.2f, PWM: %d", rpmMaestro, rpmEsclavo, pwmOutput);
        // Reemplaza logger->log por DebugManager->log
        // Ejemplo: debugManager.log(LOG_INFO, logMsg);
        // ...existing code...
    }

}
