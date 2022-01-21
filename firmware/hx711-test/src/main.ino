#include "Arduino.h"
#include "EEPROM.h"
#include "HX711.h"

//pins:
const int HX711_dout = GPIO5;
const int HX711_sck = GPIO0;

struct settings {
    float scale;
    long offset;
};

HX711 scale;

struct settings my_settings;

void setup() {
    
    Serial.begin(115200);

    pinMode(Vext,OUTPUT);
	digitalWrite(Vext,LOW);

    scale.begin(HX711_dout, HX711_sck);
    
    EEPROM.begin(512);
    EEPROM.get(0, my_settings);

    Serial.println(my_settings.scale);
    Serial.println(my_settings.offset);

    scale.set_scale(my_settings.scale);
    scale.set_offset(my_settings.offset);

/*
    Serial.begin(115200);
    EEPROM.begin(512);

    pinMode(Vext,OUTPUT);
	digitalWrite(Vext,LOW);

    scale.begin(HX711_dout, HX711_sck);

    Serial.println("Starting calibration.");
    Serial.println("Empty scale and press a key");
    
    while(!Serial.available());
    while(Serial.available()) Serial.read();

    scale.tare();

    Serial.println("Put 1 kg on the scale and press a key");

    while(!Serial.available());
    while(Serial.available()) Serial.read();

    scale.calibrate_scale( 1000, 10);
    
    my_settings.scale = scale.get_scale();
    my_settings.offset = scale.get_offset();
    
    Serial.print("Scale:");
    Serial.println(my_settings.scale);
    Serial.print("Offset:");
    Serial.println(my_settings.offset);

    EEPROM.put(0, my_settings);
    EEPROM.commit();
*/

}

void loop() {
    Serial.println(scale.get_units(20));
}
