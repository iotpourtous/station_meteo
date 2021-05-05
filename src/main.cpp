#include <Arduino.h>

#include "stationMeteoVar.h"
#include "commandManager.h"

void setup()
{
  Serial.begin(SERIAL_BAUD);
  delay(1000);
  //Initialisation du bluetooth
  SerialBT.begin("STATION_METEO");

  //Initialisation du DHT22
  dht->begin();

  //Initialisation du BPM280
  if (!bmp->begin())
  {
    Serial.println("Le capteur BMP280 est introuvable. Vérifier votre câblage");
    while (1)
      yield();
  }

  //Initialisation du DS3231
  if (!rtc.begin())
  {
    Serial.println("Le RTC est introuvable. Vérifier votre câblage");
  }

  if (rtc.lostPower())
  {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  //Initialisation du SPIFFS
  if (!SPIFFS.begin())
  {
    Serial.println("SPIFFS initialisation failed!");
    while (1)
      yield(); // Stay here twiddling thumbs waiting
  }

  //Initialisation du ILI9341
  myTFT.init();

  Serial.println("Initialisation done.");

  currentDate = rtc.now();
  currentTemperature = dht->temperature();
  currentHumidity = dht->humidity();
  currentPressure = bmp->pressure();

  tempsDate = millis();
  tempsSensor = millis();


  myTFT.afficheEcranAccueil(
      currentDate,
      currentTemperature,
      currentHumidity,
      currentPressure);
}

void loop()
{

  commandsFromSerial();
  commandsFromBT();

  if (checkTouchKey(T3, Threshold))
  {
    if (currentTouch == LOW)
    {
      if (++counter > maxCount)
        counter = 0;

      if (counter == 0)
      {
        myTFT.afficheEcranAccueil(rtc.now(),
                            dht->temperature(),
                            dht->humidity(),
                            bmp->pressure());
      }
      else if (counter == 1)
        myTFT.afficheTemperature((String)(dht->temperature()), true);
      else if (counter == 2)
        myTFT.afficheHumidite((String)(dht->humidity()), true);
      else if (counter == 3)
        myTFT.affichePression((String)(bmp->pressure()), true);
      else if (counter == 4)
        myTFT.afficheHeure(rtc.now(),String(rtc.dayOfTheWeek()), true);
    }
    currentTouch = HIGH;
  }
  else
  {
    currentTouch = LOW;
  }

  if ((millis() - tempsDate) > delayDate)
  {

    DateTime now = rtc.now();
    if (now.minute() != currentDate.minute())
    {
      currentDate = now;

      if (counter == 4)
      {
        myTFT.afficheHeure(currentDate, String(rtc.dayOfTheWeek()),true);
      }
      else
        myTFT.afficheHeure(currentDate, String(rtc.dayOfTheWeek()));
    }

    tempsDate = millis();
  }

  if ((millis() - tempsSensor) > delaySensor)
  {

    float temperature = dht->temperature();
    if (temperature != currentTemperature)
    {
      currentTemperature = temperature;
      if (counter == 0)
      {
        myTFT.afficheTemperature((String)(currentTemperature));
      }
      else if (counter == 1)
        myTFT.afficheTemperature((String)(currentTemperature), true);
    }

    float humidity = dht->humidity();
    if (humidity != currentHumidity)
    {
      currentHumidity = humidity;
      if (counter == 0)
        myTFT.afficheHumidite((String)(currentHumidity));
      else if (counter == 2)
        myTFT.afficheHumidite((String)(currentHumidity), true);
    }

    int pressure = bmp->pressure();
    if (pressure != currentPressure)
    {
      currentPressure = pressure;
      if (counter == 0)
        myTFT.affichePression((String)(currentPressure));
      else if (counter == 3)
        myTFT.affichePression((String)(currentPressure), true);
    }

    tempsSensor = millis();
  }
}