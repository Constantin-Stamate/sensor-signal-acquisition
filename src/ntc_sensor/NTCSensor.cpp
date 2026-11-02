#include "NTCSensor.h"

NTCSensor::NTCSensor(uint8_t pin, float vref, float adcResolution) {
    this->pin = pin;
    this->vref = vref;
    this->adcResolution = adcResolution;
}

int NTCSensor::readADC() {
    return analogRead(pin);
}

float NTCSensor::readVoltage() {
    int adcVal = readADC();
    return (adcVal / adcResolution) * vref;
}

float NTCSensor::readTemperature() {
    float voltage = readVoltage();

    // Example: 0-5V -> 0-50°C, adjust according to the sensor
    return (voltage / vref) * 50.0;
}