#include <Arduino.h>

#include "stationMeteoVar.h"
#include "commandManager.h"

void setup()
{
  initialize();
}

void loop()
{

  commandsFromSerial();
  commandsFromBT();

  int counter = myTouch.touchCount();

  readDate();

  readData();

  myTFT.affiche(
      currentDate,
      currentTemperature,
      currentHumidity,
      currentPressure,
      (String)rtc.dayOfTheWeek(),
      counter);
}