#ifndef stationMeteoDef_h
#define stationMeteoDef_h

//Commons
#define SERIAL_BAUD 115200
#define DEBUG 0

//Identification des capteurs
#define DHT22_SENSOR_ID 1
#define BMP280_SENSOR_ID 2
#define DS3231_SENSOR_ID 3

//DHT22
#define DHTPIN 14
#define DHTTYPE DHT22

//BMP280
#define BMP280_ADDR 0x76

//DS3231
#define DATETIME_FORMAT "DD/MM/YYYY hh:mm:ss"

//ILI9341_DRIVER
#define ILI9341_DRIVER
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4

//Bluetooth
#define BT_ACCESS_POINT "station_meteo"

//Gestion des delays
#define DELAY_DATE 1000
#define DELAY_SENSOR 5000

//TOUCH
#define MAX_COUNT 4
#define TOUCH_TRESHOLD 40
#define TOUCH_DELAY 50
#define TOUCH_PIN T9

#endif