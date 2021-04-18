#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <Preferences.h>
#include "espdeck_moduleparent.hpp"
#include "espdeck_moduleimport.hpp"

LiquidCrystal_I2C lcd(0x27,16,2);
Preferences prefs;
SpotifyAPI spot;
ESPDeckModule *modules[1] = {&spot};

void setup() {
    for (ESPDeckModule *module : modules) {
        module->initialize();
    }
    prefs.begin("espdeck");
}

void loop() {
    
}