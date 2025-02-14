#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

/**
 * @class Sensor
 * @brief Encapsula la lectura de pulsos y el cálculo de RPM de un sensor.
 *
 * Esta clase se encarga de:
 * - Configurar el pin del sensor.
 * - Gestionar las interrupciones para contar pulsos.
 * - Calcular las RPM en base a un tiempo de muestreo.
 */
class Sensor {
public:
    /**
     * @brief Constructor que inicializa la configuración del sensor.
     * @param pin Pin digital al que se conecta el sensor.
     * @param pulsesPerRevolution Número de pulsos generados por revolución.
     * @param sampleTime Tiempo de muestreo en milisegundos.
     *
     * Se almacenan los parámetros iniciales para configurar el sensor.
     */
    Sensor(int pin, int pulsesPerRevolution, float sampleTime);
    
    /**
     * @brief Inicializa el sensor configurando el pin y asociando la interrupción.
     *
     * Se configura el pin en modo INPUT_PULLUP y se asocia el manejador de interrupciones.
     */
    void begin();
    
    /**
     * @brief Incrementa el contador interno de pulsos.
     *
     * Este método es llamado por la rutina de interrupción para contar cada pulso.
     */
    void countPulse();
    
    /**
     * @brief Calcula y retorna las RPM actuales.
     *
     * El método:
     * - Desactiva interrupciones para leer y resetear el contador.
     * - Calcula las RPM basado en el número de pulsos y el tiempo de muestreo.
     *
     * @return float RPM calculadas.
     */
    float getRPM();

    /**
     * @brief Manejador de interrupciones estático.
     *
     * Este método se pasa como parámetro a attachInterruptArg y:
     * - Recibe un puntero al objeto Sensor.
     * - Llama a countPulse() para actualizar el contador de pulsos.
     *
     * @param arg Puntero a la instancia Sensor.
     */
    static void IRAM_ATTR isrHandler(void *arg);

private:
    int pin;
    int pulsesPerRevolution;
    float sampleTime;
    volatile unsigned long pulseCount;
};

#endif // SENSOR_H
