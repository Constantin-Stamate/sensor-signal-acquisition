#include <Arduino.h>

#include "ntc_sensor/NTCSensor.h"
#include "lcd_display/LCDDisplay.h"

#define NTC_PIN A0
#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

const unsigned long ACQ_PERIOD = 200;    
const unsigned long REPORT_PERIOD = 500; 

NTCSensor ntc(NTC_PIN);
LCDDisplay lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

int latestADC = 0;
float latestTemp = 0.0;

unsigned long lastAcq = 0;
unsigned long lastReport = 0;

void setup() {
    Serial.begin(9600);
    lcd.begin();
}

void loop() {
    unsigned long now = millis();

    if (now - lastAcq >= ACQ_PERIOD) {
        lastAcq = now;

        latestADC = ntc.readADC();
        latestTemp = ntc.readTemperature();
    }

    if (now - lastReport >= REPORT_PERIOD) {
        lastReport = now;

        Serial.print("ADC: ");
        Serial.print(latestADC);
        Serial.print(" | Temp: ");
        Serial.print(latestTemp, 1);
        Serial.println(" C");

        lcd.clear();
        lcd.printLine(0, "ADC:" + String(latestADC));
        lcd.printLine(1, "Temp:" + String(latestTemp, 1) + "C");
    }
}