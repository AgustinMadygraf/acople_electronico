#include "PIDController.h"
#include <Arduino.h>

PIDController::PIDController(float kp, float ki, float kd) 
    : kp(kp), ki(ki), kd(kd), setpoint(0), lastError(0), integral(0),
      outputMin(0), outputMax(255), lastTime(0) {}

void PIDController::setTunings(float _kp, float _ki, float _kd) {
    kp = _kp;
    ki = _ki;
    kd = _kd;
}

void PIDController::setOutputLimits(float min, float max) {
    outputMin = min;
    outputMax = max;
}

void PIDController::setSetpoint(float _setpoint) {
    setpoint = _setpoint;
}

void PIDController::reset() {
    lastError = 0;
    integral = 0;
    lastTime = 0;
}

float PIDController::compute(float input) {
    unsigned long now = millis();
    float timeChange = (now - lastTime);
    
    // Primera ejecución
    if (lastTime == 0) {
        lastTime = now;
        return 0;
    }
    
    // Cálculo del error
    float error = setpoint - input;
    
    // Término proporcional
    float pTerm = kp * error;
    
    // Término integral
    integral += (ki * error * timeChange);
    if (integral > outputMax) integral = outputMax;
    else if (integral < outputMin) integral = outputMin;
    
    // Término derivativo
    float dTerm = 0;
    if (timeChange > 0) {
        dTerm = (kd * (error - lastError)) / timeChange;
    }
    
    // Cálculo de la salida
    float output = pTerm + integral + dTerm;
    
    // Limitar la salida
    if (output > outputMax) output = outputMax;
    else if (output < outputMin) output = outputMin;
    
    // Almacenar valores para la próxima iteración
    lastError = error;
    lastTime = now;
    
    return output;
}
