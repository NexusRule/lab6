/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/fxxsj/OneDrive/Desktop/lab6/src/lab6.ino"
void setup();
void loop();
#line 1 "c:/Users/fxxsj/OneDrive/Desktop/lab6/src/lab6.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
#define TEMP_SCAN A4
#define GIORNO A0
#include "oled-wing-adafruit.h"
OledWingAdafruit display;

void setup() {
    display.setup();
    display.clearDisplay();
}

void loop() {
    uint64_t reading = analogRead(TEMP_SCAN);

    double voltage = (reading * 3.3) / 4095.0;
    double temperature = (voltage - 0.5) * 100;

    double f2 = (reading * 3.3) / 4095.0;
    double f1 = (f2 - 0.5) * 100;
    double f = (f1 * 1.8) + 32;

    display.clearDisplay();
    display.setCursor(15, 15);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.print(temperature);
    display.print("C  |  ");
    display.print(f);
    display.print("F");
    display.display();
    delay(100);
}