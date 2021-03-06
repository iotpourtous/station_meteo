#ifndef stationMeteoDef_h
#define stationMeteoDef_h

//Nombre de caractères pour les commandes
#define MAX_COMMAND_SIZE 10

//Commons
#define SERIAL_BAUD 115200
#define DEBUG 0

//Identification des capteurs
#define DHT22_SENSOR_ID 1
#define BMP280_SENSOR_ID 2
#define DS3231_SENSOR_ID 3

//DHT22
#define DHTPIN 13
#define DHTTYPE DHT22

//BMP280
#define BMP280_ADDR 0x76

//ILI9341_DRIVER
#define ILI9341_DRIVER
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15  // Chip select control pin
#define TFT_DC    2  // Data Command control pin
#define TFT_RST   4  // Reset pin (could connect to RST pin)

//DS3231
//rien

#endif