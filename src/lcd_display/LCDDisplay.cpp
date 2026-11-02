#include "LCDDisplay.h"

LCDDisplay::LCDDisplay(uint8_t addr, uint8_t cols, uint8_t rows)
    : lcd(addr, cols, rows) {}

void LCDDisplay::begin() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void LCDDisplay::clear() {
    lcd.clear();
}

void LCDDisplay::printLine(uint8_t row, const String &text) {
    lcd.setCursor(0, row);
    lcd.print(text);
}