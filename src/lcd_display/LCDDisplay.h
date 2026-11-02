#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H

#include <LiquidCrystal_I2C.h>

class LCDDisplay {
private:
    LiquidCrystal_I2C lcd;

public:
    LCDDisplay(uint8_t addr, uint8_t cols, uint8_t rows);

    void begin();
    void clear();
    void printLine(uint8_t row, const String &text);
};

#endif