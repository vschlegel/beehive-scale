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

void clear_screen(){
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
}

void menu(){
    clear_screen();
    Serial.println("menu");
    Serial.println("------------------------");
    Serial.println("1 - info");
    Serial.println("2 - settings");
    Serial.println("3 - calibration");
    Serial.println("4 - quit");
    while(!Serial.available());
    String selection = Serial.readStringUntil('\n');
    if(selection == "1"){
        info();
    } else if(selection == "2"){
        settings();
    } else if(selection == "3"){
        calibration();
    } else if(selection != "4"){
        menu(); 
    }
}

void info(){
    clear_screen();
    Serial.println("info");
    Serial.println("------------------------");
    EEPROM.begin(512);
    EEPROM.get(0,my_settings);
    Serial.println("hx711 calibration:");
    Serial.print("- scale:  ");
    Serial.println(my_settings.scale, 5);
    Serial.print("- offset: ");
    Serial.println(my_settings.offset);
    Serial.println("lorawan:");
    Serial.println("- app eui: ----");
    Serial.println("- app key: ----");
    Serial.println("- dev eui: ----");
    Serial.println();
    Serial.println("press enter to continue");
    while(!Serial.available());
    Serial.readStringUntil('\n');
    menu();
}

void settings(){
    clear_screen();
    Serial.println("settings");
    Serial.println("------------------------");
    Serial.println();
    Serial.println("XXX");
    Serial.println("XXX  SETTINGS ARE NOT IMPLEMENTED YET");
    Serial.println("XXX");
    Serial.println();
    Serial.println("press enter to continue");
    while(!Serial.available());
    Serial.readStringUntil('\n');
    menu();
}

void calibration(){
    clear_screen();
    Serial.println("calibration");
    Serial.println("------------------------");

    delay(500);
    pinMode(Vext,OUTPUT);
	digitalWrite(Vext,LOW);
    Serial.println();

    Serial.println("empty platform and press enter");
    while(!Serial.available());
    Serial.readStringUntil('\n');
    delay(1000);
    scale.tare();
    Serial.println();
    Serial.println("put 100kg on the platform and press enter");
    while(!Serial.available());
    Serial.readStringUntil('\n');
    delay(1000);
    scale.calibrate_scale( 1000, 10);
    Serial.println();
    my_settings.scale = scale.get_scale();
    my_settings.offset = scale.get_offset();
    Serial.print("saving");
    EEPROM.put(0, my_settings);
    EEPROM.commit();
    delay(2000);
    menu();
}




void setup() {
    
    Serial.begin(115200);
    scale.begin(HX711_dout, HX711_sck);
    EEPROM.begin(512);
    
    menu();
    
    pinMode(Vext,OUTPUT);
	digitalWrite(Vext,LOW);
    
    EEPROM.get(0, my_settings);
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
    Serial.println(scale.get_units(10));
}
