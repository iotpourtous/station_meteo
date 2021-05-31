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
long tempsDate = millis();
long tempsSensor = millis();

//TFT
MyTFT myTFT;

//TOUCH
MyTouch myTouch(MAX_COUNT, TOUCH_TRESHOLD, TOUCH_DELAY, TOUCH_PIN);
int counter = 0;
boolean currentTouch = LOW;

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
  } while ((count < 4) && (millis() < startTime + TOUCH_DELAY));
  return pressed;
}

void initialisation()
{

  //Initialisation du Serial
  Serial.begin(SERIAL_BAUD);

  Serial.println("Début initialisation");

  Serial.println("------------------------");
  Serial.println("Début initialisation");
  Serial.println("------------------------");

  //Initialisation du bluetooth
  Serial.println("Début Initialisation bluetooth");
  delay(125);
  SerialBT.begin(BT_ACCESS_POINT);
  Serial.println("Initialisation bluetooth OK");
  Serial.println("------------------------");

  delay(125);
  //Initialisation du DHT22
  Serial.println("Début Initialisation DHT22");
  delay(125);
  dht.begin();
  Serial.println("Initialisation DHT22 OK");
  Serial.println("------------------------");

  //Initialisation du BPM280
  Serial.println("Début Initialisation BPM280");
  delay(125);
  bmp.begin();
  Serial.println("Initialisation BPM280 OK");
  Serial.println("------------------------");

  //Initialisation du DS3231
  Serial.println("Début Initialisation DS3231");
  delay(125);
  rtc.begin();
  Serial.println("Initialisation DS3231 OK");
  Serial.println("------------------------");

  //Initialisation du ILI9341
  Serial.println("Début Initialisation ILI9341");
  delay(125);
  myTFT.init();
  Serial.println("Initialisation ILI9341 OK");
  Serial.println("------------------------");

  Serial.println("Fin initialisation");
  Serial.println("------------------------");
}

void manageDate()
{
  if ((millis() - tempsDate) > DELAY_DATE)
  {
    DateTime now = rtc.now();
    if (now.minute() != currentDate.minute())
      currentDate = now;

    tempsDate = millis();
  }
}

void manageSensor()
{
  if ((millis() - tempsSensor) > DELAY_SENSOR)
  {
    float temperature = dht.temperature();
    if (temperature != currentTemperature)
      currentTemperature = temperature;

    float humidity = dht.humidity();
    if (humidity != currentHumidity)
      currentHumidity = humidity;

    int pressure = bmp.pressure();
    if (pressure != currentPressure)
      currentPressure = pressure;

    tempsSensor = millis();
  }
}

#endif