#ifndef stationMeteoVar_h
#define stationMeteoVar_h

#include <MyDHT.h>
#include <MyBMP280.h>
#include <MyDS3231.h>
#include <MyTFT.h>
#include <Mytouch.h>
#include "BluetoothSerial.h"
#include "stationMeteoDef.h"

//bluetooth
BluetoothSerial SerialBT;

//DHT22
MyDHT dht(DHTPIN, DHTTYPE, DHT22_SENSOR_ID);
float currentTemperature;
float currentHumidity;

//BMP280
MyBMP280 bmp(BMP280_ADDR, BMP280_SENSOR_ID);
int currentPressure;

//DS3231
MyDS3231 rtc(DS3231_SENSOR_ID, DATETIME_FORMAT);
DateTime currentDate;

//Gestion des delays
long tempsDate;
long tempsSensor;

//TFT
MyTFT myTFT;

//TOUCH
MyTouch myTouch(MAX_COUNT, TOUCH_TRESHOLD, TOUCH_DELAY, TOUCH_PIN);

#endif