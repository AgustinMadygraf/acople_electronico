#ifndef HAL_H
#define HAL_H

/**
 * @class HAL
 * @brief Hardware Abstraction Layer to encapsulate differences between platforms.
 *
 * Provides an abstraction for PWM configuration and control.
 */
class HAL {
public:
    virtual ~HAL() {}
    
    /**
     * @brief Configures PWM on a specified pin.
     * 
     * For ESP32, frequency and resolution are used.
     * For Arduino Uno, these parameters may be ignored.
     *
     * @param pin The pin to configure.
     * @param frequency PWM frequency.
     * @param resolution PWM resolution.
     */
    virtual void setupPWM(int pin, int frequency, int resolution) = 0;
    
    /**
     * @brief Writes a PWM value to the specified pin.
     *
     * @param pin The pin to output PWM.
     * @param value PWM duty cycle value.
     */
    virtual void writePWM(int pin, int value) = 0;
};

/**
 * @enum PlatformType
 * @brief Enum to specify the platform type.
 */
enum PlatformType { PLATFORM_ARDUINO, PLATFORM_ESP32 };

/**
 * @brief Factory function to create a HAL instance.
 *
 * The implementation selected can be based on the platform parameter.
 *
 * @param platform The platform type.
 * @return HAL* Pointer to the HAL instance.
 */
HAL* createHAL(PlatformType platform);

#endif // HAL_H
