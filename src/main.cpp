#include <Arduino.h>

#include "stationMeteoVar.h"
#include "commandManager.h"

void setup()
{
  init();
}

void loop()
{

  commandsFromSerial();
  commandsFromBT();

  int counter = myTouch.touchCount();

  readDate();

  ReadDataFromSensor();

  myTFT.affiche(
      currentDate,
      currentTemperature,
      currentHumidity,
      currentPressure,
      (String)rtc.dayOfTheWeek(),
      counter);
}