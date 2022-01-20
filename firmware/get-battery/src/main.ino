#include "Arduino.h"

void setup() {
    pinMode(Vext,OUTPUT);
	digitalWrite(Vext,LOW);
    Serial.begin(115200);
}

void loop() {
	float voltage = getBatteryVoltage() / 1000.0;
    Serial.print("voltage: ");
    Serial.println(voltage);
    delay(2000);
}
