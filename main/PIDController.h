#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

/**
 * @class PIDController
 * @brief Implements a PID (Proportional-Integral-Derivative) controller.
 *
 * This class computes a control signal based on the error between a setpoint and measurement.
 */
class PIDController {
public:
    /**
     * @brief Constructs a PID controller with given gains and sample time.
     *
     * @param kp Proportional gain.
     * @param ki Integral gain.
     * @param kd Derivative gain.
     * @param sampleTime Sampling interval in milliseconds.
     */
    PIDController(float kp, float ki, float kd, float sampleTime);
    
    /**
     * @brief Computes the control output based on setpoint and measurement.
     *
     * @param setpoint The desired target value.
     * @param measurement The current measured value.
     * @return int Control output value bounded between 0 and 255.
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
