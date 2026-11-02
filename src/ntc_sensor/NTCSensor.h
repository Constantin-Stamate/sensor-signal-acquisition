#ifndef NTC_SENSOR_H
#define NTC_SENSOR_H

#include <Arduino.h>

class NTCSensor {
private:
    uint8_t pin;
    float vref;
    float adcResolution;

public:
    NTCSensor(uint8_t pin, float vref = 5.0, float adcResolution = 1023.0);

    int readADC();
    float readVoltage();
    float readTemperature();
};

#endif