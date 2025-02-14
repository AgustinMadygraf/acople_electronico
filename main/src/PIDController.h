#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController {
private:
    float kp;                // Proportional gain
    float ki;                // Integral gain
    float kd;                // Derivative gain
    float setpoint;          // Target value
    float lastError;         // Last error for derivative calculation
    float integral;          // Integral accumulator
    float outputMin;         // Minimum output value
    float outputMax;         // Maximum output value
    unsigned long lastTime;  // Last sample time

public:
    PIDController(float kp, float ki, float kd);
    
    void setTunings(float kp, float ki, float kd);
    void setOutputLimits(float min, float max);
    void setSetpoint(float setpoint);
    void reset();
    
    float compute(float input);
};

#endif
