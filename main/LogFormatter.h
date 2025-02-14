#ifndef LOGFORMATTER_H
#define LOGFORMATTER_H

#include <Arduino.h>
#include "LogLevel.h"

class LogFormatter {
public:
    static String format(LogLevel level, const char* message);
};

#endif
