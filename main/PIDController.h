#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

/**
 * @class PIDController
 * @brief Implements a PID controller.
 * 
 * This class computes the control signal based on proportional, integral,
 * and derivative components.
 */
class PIDController {
public:
    /**
     * @brief Constructs a new PIDController object.
     * 
     * @param kp Proportional gain.
     * @param ki Integral gain.
     * @param kd Derivative gain.
     * @param sampleTime Interval de muestreo en milisegundos.
     */
    PIDController(float kp, float ki, float kd, float sampleTime);
    
    /**
     * @brief Computes the control output.
     * 
     * @param setpoint Target measurement.
     * @param measurement Current measurement.
     * @return int Valor de salida, acotado entre 0 y 255.
     */
    int compute(float setpoint, float measurement);
    
private:
    float kp;
    float ki;
    float kd;
    float sampleTime;
    float errorPrev;
    float errorIntegral;
};

#endif // PIDCONTROLLER_H
