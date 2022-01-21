# beehive-scale
beehive-scale is an open-source project that measures the weight of your beehives and sends it to a monitoring server via LoRaWAN. Basically, it's Internet of Bees (IOB).

## Warning
This project is under develpoment and things might not work yet.

## Overview
- Hardware
  - Mechanics
    - Steel Frame
    - Electronics Enclosure
  - PCB
    - Battery Powered
    - Heltec Cubecell HTCC AB01
    - HX711 load cell amplifier
- Firmware
  - Platformio (Arduino-Compatible)
  - Libraries used:
    - [Heltec: CubeCell Libraries](https://github.com/HelTecAutomation/CubeCell-Arduino)
    - [Rob Tillaart: HX711](https://github.com/RobTillaart/HX711)
    - [ElectronicCats: Cayenne LPP](https://github.com/ElectronicCats/CayenneLPP)
    - [BBlanchon: ArduinoJSON](https://github.com/bblanchon/ArduinoJson)
  - measures load & sends values to the LoRaWAN network
  - calibration and other settings over serial commands and stored in EEPROM
- LoRaWAN
  - OTAA
  - data transfer over MQTT
- Server
  - Telegraf
  - InfluxDB
  - Grafana
