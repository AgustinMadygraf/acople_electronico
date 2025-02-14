# Control de Velocidad Maestro-Esclavo con ESP32

Este proyecto implementa un sistema de control de velocidad basado en un algoritmo PID utilizando un ESP32. Se controla la velocidad de un motor esclavo para que siga la velocidad de un motor maestro utilizando sensores inductivos.

## 📜 Descripción

El sistema mide la velocidad de dos motores utilizando sensores inductivos y ajusta el PWM del motor esclavo mediante un controlador PID. Esto permite sincronizar la velocidad del motor esclavo con la del maestro, asegurando un funcionamiento coordinado.

## 🛠️ Hardware Requerido

- **ESP32**
- **Sensores inductivos** (x2)
- **Motor maestro** (sin control directo en este código)
- **Motor esclavo** con control de velocidad por PWM
- **Fuente de alimentación adecuada**
- **Cables y conexiones**

## 🔧 Configuración de Pines

| Componente         | Pin ESP32 |
|--------------------|----------|
| Sensor Maestro    | GPIO 34  |
| Sensor Esclavo    | GPIO 35  |
| PWM Motor Esclavo | GPIO 25  |

## ⚙️ Parámetros del Sistema

- **Pulsos por vuelta**: 10 (ajustable según sensor inductivo)
- **Tiempo de muestreo**: 100 ms
- **Frecuencia PWM**: 1 kHz
- **Resolución PWM**: 8 bits (valores de 0 a 255)

## 📌 Código Explicado

1. **Interrupciones**: Se usan interrupciones para contar los pulsos de los sensores.
2. **Cálculo de RPM**: Se determina la velocidad de cada motor a partir del conteo de pulsos.
3. **Control PID**: Se usa un algoritmo PID para ajustar el PWM del motor esclavo en función de la diferencia de velocidad con el maestro.
4. **Salida PWM**: Se configura la salida PWM usando `ledcWrite()`.

## 🖥️ Ejecución

1. **Compilar y cargar el código en el ESP32**.
2. **Abrir el Monitor Serie** con una velocidad de `115200 baudios`.
3. **Observar la sincronización de velocidades entre el motor maestro y el motor esclavo**.

## 📊 Salida Esperada en Monitor Serie

```plaintext
RPM Maestro: 1200.00 | RPM Esclavo: 1180.00 | PWM Esclavo: 180
RPM Maestro: 1250.00 | RPM Esclavo: 1230.00 | PWM Esclavo: 190
...
```

## 📌 Posibles Mejoras

- **Ajuste fino de los coeficientes PID** (`Kp`, `Ki`, `Kd`) para una mejor respuesta.
- **Filtro digital** para reducir ruido en las mediciones de los sensores.
- **Interfaz gráfica** para visualización en tiempo real.

---

📌 **Autor:** Agustín  
📆 **Última actualización:** Febrero 2025  
📄 **Licencia:** MIT

## 4. Selección entre ESP-WROOM-32 y Arduino Uno

- **Implementación Actual:**  
  • El sistema determina la plataforma a través de la función fábrica definida en [`HAL.h`](main/HAL.h), y sus implementaciones están divididas en [`HAL_Arduino.cpp`](main/HAL_Arduino.cpp) y [`HAL_ESP32.cpp`](main/HAL_ESP32.cpp).

- **Momento de Selección:**  
  • Se recomienda la selección en **tiempo de compilación** utilizando macros (por ejemplo: `ESP32_PLATFORM`). Esto garantiza que el código generado sea específico para la plataforma destino, eliminando verificaciones en tiempo de ejecución que puedan añadir overhead.
  
- **Ventajas de la Compilación Condicional:**  
  • Minimiza el consumo de recursos en sistemas embebidos.  
  • Facilita la integración y el mantenimiento, ya que se elimina la complejidad del manejo dinámico de plataformas.  

- **Sugerencia Adicional:**  
  • Incluir en la documentación ejemplos de cómo configurar y definir la macro (`ESP32_PLATFORM`) en el entorno de desarrollo para compilar correctamente para cada plataforma.

## 📌 Configuración del Preprocesador

Para compilar para ESP32 defina la macro <code>ESP32_PLATFORM</code>. Por ejemplo, en el entorno de desarrollo (como el Arduino IDE) agregue la bandera:
```bash
-DESP32_PLATFORM
```
Para Arduino Uno, asegúrese de no definir esta macro.

## ⚙️ Diseño y Modularidad

El proyecto utiliza el patrón Factory en la abstracción de hardware (ver HAL.h, HAL_ESP32.cpp y HAL_Arduino.cpp) y la inyección de dependencias en MainController para facilitar la escalabilidad y el mantenimiento. Además, la gestión de interrupciones (InterruptManager.cpp) y el sistema de logs (Logger.cpp y MQTTLogger.cpp) se implementan de forma modular para optimizar el rendimiento y la flexibilidad.