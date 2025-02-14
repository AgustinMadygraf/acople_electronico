#include "PIDController.h"
#include <Arduino.h>

PIDController::PIDController(float kp, float ki, float kd, float sampleTime)
    : kp(kp), ki(ki), kd(kd), sampleTime(sampleTime), errorPrev(0.0), errorIntegral(0.0) {
    // ...existing code...
}

int PIDController::compute(float setpoint, float measurement) {
    float error = setpoint - measurement;
    errorIntegral += error * (sampleTime / 1000.0);
    float derivative = (error - errorPrev) / (sampleTime / 1000.0);
    float output = kp * error + ki * errorIntegral + kd * derivative;
    errorPrev = error;
    return constrain((int)output, 0, 255);
}
