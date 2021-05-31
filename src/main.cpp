#include <Arduino.h>

#include "stationMeteoVar.h"
#include "commandManager.h"

void setup()
{

  initialisation();
}

void loop()
{

  commandsFromSerial();
  commandsFromBT();

  int counter = myTouch.manageCheck();

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