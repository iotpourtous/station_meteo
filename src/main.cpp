#include <Arduino.h>

#include "stationMeteoVar.h"
#include "commandManager.h"
#include "utils.h"

void setup()
{
  initialize();
}

void loop()
{
  commandManager();

  int counter = myTouch.touchCount();

  readData();

  myTFT.display(
      currentDate,
      currentTemperature,
      currentHumidity,
      currentPressure,
      (String)rtc.dayOfTheWeek(),
      counter);
}