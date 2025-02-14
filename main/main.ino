/**
 * @file main.ino
 * @brief Main program delegating control and sensor acquisition to MainController.
 */

#include <Arduino.h>
#include "MainController.h"

MainController mainController;

void setup() {
    mainController.begin();
}

void loop() {
    mainController.update();
}
