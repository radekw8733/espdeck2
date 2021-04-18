#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <Preferences.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Preferences prefs;

void setup() {
    prefs.begin("espdeck");
}

void loop() {

}