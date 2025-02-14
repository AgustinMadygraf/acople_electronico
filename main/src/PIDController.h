#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

/**
 * @class PIDController
 * @brief Implementa un controlador PID.
 */
class PIDController {
private:
    /// Ganancia proporcional.
    float kp;
    /// Ganancia integral.
    float ki;
    /// Ganancia derivativa.
    float kd;
    /// Valor objetivo.
    float setpoint;
    /// Error previo para el cálculo derivativo.
    float lastError;
    /// Acumulador del término integral.
    float integral;
    /// Límite inferior de la salida.
    float outputMin;
    /// Límite superior de la salida.
    float outputMax;
    /// Tiempo de la última muestra.
    unsigned long lastTime;

public:
    /**
     * @brief Constructor del controlador PID.
     * @param kp Ganancia proporcional.
     * @param ki Ganancia integral.
     * @param kd Ganancia derivativa.
     */
    PIDController(float kp, float ki, float kd);
    
    /**
     * @brief Actualiza los parámetros de sintonización.
     * @param kp Nueva ganancia proporcional.
     * @param ki Nueva ganancia integral.
     * @param kd Nueva ganancia derivativa.
     */
    void setTunings(float kp, float ki, float kd);
    /**
     * @brief Configura los límites de la salida.
     * @param min Valor mínimo.
     * @param max Valor máximo.
     */
    void setOutputLimits(float min, float max);
    /**
     * @brief Establece el valor objetivo (setpoint).
     * @param setpoint Valor objetivo deseado.
     */
    void setSetpoint(float setpoint);
    /**
     * @brief Reinicia el estado interno del PID.
     */
    void reset();
    /**
     * @brief Calcula la salida del PID basado en la entrada.
     * @param input Valor de entrada (por ejemplo, la diferencia de posición).
     * @return Salida del PID.
     */
    float compute(float input);
};

#endif
