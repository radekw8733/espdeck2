#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <Preferences.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include "espdeck_moduleparent.hpp"
#include "espdeck_moduleimport.hpp"
#include "secretCredentials.h"

int currentFrame;
LiquidCrystal_I2C lcd(0x27,16,2);
Preferences prefs;
SpotifyAPI spot;
ESPDeckModule *modules[] = {&spot};
IRrecv ir(15,1024,39,true);
decode_results results;

void setup() {
    Serial.begin(115200);
    lcd.begin();
    ir.setUnknownThreshold(12);
    ir.enableIRIn();
    prefs.begin("espdeck");
    WiFi.begin(SSID,PASSWD);
    Serial.print("Connecting...");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    for (ESPDeckModule *module : modules) {
        module->initialize(&lcd);
    }
    Serial.println("Ready");
    lcd.print("Ready");
}

void loop() {
    modules[currentFrame]->lcdRefresh();
}