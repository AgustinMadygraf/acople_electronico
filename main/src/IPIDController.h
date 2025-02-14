#ifndef IPID_CONTROLLER_H
#define IPID_CONTROLLER_H

class IPIDController {
public:
    virtual ~IPIDController() {}

    // Configura los parámetros del PID
    virtual void setTunings(float kp, float ki, float kd) = 0;
    
    // Configura los límites de la salida
    virtual void setOutputLimits(float min, float max) = 0;
    
    // Establece el valor objetivo (setpoint)
    virtual void setSetpoint(float setpoint) = 0;
    
    // Reinicia el estado interno del PID
    virtual void reset() = 0;
    
    // Calcula la salida del PID basado en la entrada
    virtual float compute(float input) = 0;
};

#endif // IPID_CONTROLLER_H
