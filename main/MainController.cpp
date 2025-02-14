#include "MainController.h"
#include <Arduino.h>

/**
 * @brief Constructs the MainController with provided dependencies.
 */
MainController::MainController(Sensor* sensorMaestro, Sensor* sensorEsclavo, PIDController* pid, ILogger* logger)
    : sensorMaestro(sensorMaestro), sensorEsclavo(sensorEsclavo), pid(pid), logger(logger), previousTime(0) {
    // ...existing code...
}

/**
 * @brief Initializes subsystems: logger, sensors, and PWM.
 */
void MainController::begin() {
    logger->begin(LOG_DEBUG);
    sensorMaestro->begin();
    sensorEsclavo->begin();
    pinMode(PWM_ESCLAVO_PIN, OUTPUT);
    ledcSetup(0, 1000, 8);
    ledcAttachPin(PWM_ESCLAVO_PIN, 0);
    // ...existing code...
}

/**
 * @brief Periodically reads sensor data, computes control signal, and adjusts PWM output.
 */
void MainController::update() {
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= 100) { // using sample time of 100ms
        previousTime = currentTime;
        float rpmMaestro = sensorMaestro->getRPM();
        float rpmEsclavo = sensorEsclavo->getRPM();
        int pwmOutput = pid->compute(rpmMaestro, rpmEsclavo);
        ledcWrite(0, pwmOutput);

        char logMsg[128];
        sprintf(logMsg, "RPM Maestro: %.2f, RPM Esclavo: %.2f, PWM: %d", rpmMaestro, rpmEsclavo, pwmOutput);
        logger->log(LOG_INFO, logMsg);
    }
}
