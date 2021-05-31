#include <Arduino.h>

#include "stationMeteoVar.h"
#include "commandManager.h"

void setup()
{

  initialisation();

  //Lecture des données
  currentDate = rtc.now();
  currentTemperature = dht.temperature();
  currentHumidity = dht.humidity();
  currentPressure = bmp.pressure();
}

void loop()
{

  commandsFromSerial();
  commandsFromBT();

  if (checkTouchKey(TOUCH_PIN, TOUCH_TRESHOLD))
  {
    if (currentTouch == LOW)
    {
      if (++counter > MAX_COUNT)
        counter = 0;
    }
    currentTouch = HIGH;
  }
  else
    currentTouch = LOW;

  manageDate();

  manageSensor();

  myTFT.affiche(
      currentDate,
      currentTemperature,
      currentHumidity,
      currentPressure,
      (String)rtc.dayOfTheWeek(),
      counter);
}