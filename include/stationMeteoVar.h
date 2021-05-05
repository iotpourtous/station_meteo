#ifndef stationMeteoVar_h
#define stationMeteoVar_h

#include <MyDHT.h>
#include <MyBMP280.h>
#include <MyDS3231.h>
#include <MyTFT.h>
#include "BluetoothSerial.h"
#include "stationMeteoDef.h"

BluetoothSerial SerialBT;

//DHT22
temperature_type_t temperatureType = TCELCIUS;
float temperatureOffset = 0;
float humidityOffset = 0;

MyDHT *dht = new MyDHT(DHTPIN, DHTTYPE, temperatureType, temperatureOffset, humidityOffset);

//BMP280
int pressureOffset = 0;

MyBMP280 *bmp = new MyBMP280(BMP280_ADDR);

//DS3231
MyDS3231 rtc;

//TFT
MyTFT myTFT; 

//TOUCH
int counter = 0;
int maxCount = 4;
#define Threshold 40
int delayTouch = 50;
boolean currentTouch = LOW;

DateTime currentDate;
float currentTemperature;
float currentHumidity;
int currentPressure;

int delayDate = 1000;
int delaySensor = 5000;

long tempsDate;
long tempsSensor;

boolean checkTouchKey(int touchPin, int threshold)
{
  unsigned long startTime;
  int count;
  boolean pressed;

  pressed = false;
  startTime = millis();
  count = 0;
  do
  {
    if (touchRead(touchPin) < threshold)
      count++;
    else
      count = 0;
    if (count == 3)
      pressed = true;
  } while ((count < 4) && (millis() < startTime + delayTouch));
  return pressed;
}

#endif