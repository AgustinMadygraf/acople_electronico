/**
 * @file main.ino
 * @brief Main program delegating control and sensor acquisition to MainController.
 */

#include <Arduino.h>
#include "MainController.h"
#include "Sensor.h"
#include "PIDController.h"
#include "Logger.h"
#include "HardwareManager.h"  // add HardwareManager include

Sensor sensorMaestro(34, 10, 100.0);
Sensor sensorEsclavo(35, 10, 100.0);
PIDController pid(2.0, 0.5, 0.1, 100.0);
Logger logger;
HardwareManager hardwareManager; // new instance for hardware control

// Updated MainController instantiation with HardwareManager dependency.
MainController mainController(&sensorMaestro, &sensorEsclavo, &pid, &logger, &hardwareManager);

void setup() {
    mainController.begin();
}

void loop() {
    mainController.update();
}
