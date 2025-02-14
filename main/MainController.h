#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <Arduino.h>
#include "Sensor.h"
#include "PIDController.h"
#include "Logger.h"

class MainController {
public:
    MainController();
    void begin();
    void update();
private:
    Sensor sensorMaestro;
    Sensor sensorEsclavo;
    PIDController pid;
    Logger logger;
    unsigned long previousTime;
    static const int SENSOR_MAESTRO_PIN = 34;
    static const int SENSOR_ESCLAVO_PIN = 35;
    static const int PWM_ESCLAVO_PIN = 25;
    static const int PULSES_PER_REVOLUTION = 10;
    static constexpr float SAMPLE_TIME = 100.0;
};

#endif // MAINCONTROLLER_H
