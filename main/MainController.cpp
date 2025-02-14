#include "MainController.h"

MainController::MainController()
    : sensorMaestro(SENSOR_MAESTRO_PIN, PULSES_PER_REVOLUTION, SAMPLE_TIME),
      sensorEsclavo(SENSOR_ESCLAVO_PIN, PULSES_PER_REVOLUTION, SAMPLE_TIME),
      pid(2.0, 0.5, 0.1, SAMPLE_TIME),
      previousTime(0) {
    // ...existing code...
}

void MainController::begin() {
    logger.begin(LOG_DEBUG);
    sensorMaestro.begin();
    sensorEsclavo.begin();
    pinMode(PWM_ESCLAVO_PIN, OUTPUT);
    ledcSetup(0, 1000, 8);
    ledcAttachPin(PWM_ESCLAVO_PIN, 0);
    // ...existing code...
}

void MainController::update() {
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= SAMPLE_TIME) {
        previousTime = currentTime;
        float rpmMaestro = sensorMaestro.getRPM();
        float rpmEsclavo = sensorEsclavo.getRPM();
        int pwmOutput = pid.compute(rpmMaestro, rpmEsclavo);
        ledcWrite(0, pwmOutput);

        char logMsg[128];
        sprintf(logMsg, "RPM Maestro: %.2f, RPM Esclavo: %.2f, PWM: %d", rpmMaestro, rpmEsclavo, pwmOutput);
        logger.log(LOG_INFO, logMsg);
    }
}
