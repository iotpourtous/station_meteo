#ifndef commandManager_h
#define commandManager_h

#include "stationMeteoVar.h"

String commands(String command)
{
  if (command.startsWith((String)DHT22_SENSOR_ID))
  {
    return dht.executeCommand(command.substring(1));
  }
  else if (command.startsWith((String)BMP280_SENSOR_ID))
  {
    return bmp.executeCommand(command.substring(1));
  }
  else if (command.startsWith((String)DS3231_SENSOR_ID))
  {
    return rtc.executeCommand(command.substring(1));
  }

  String retour = "------------------------------------\n";
  retour += (String)DHT22_SENSOR_ID + " : capteur température\n";
  retour += (String)BMP280_SENSOR_ID + " : capteur humidité\n";
  retour += (String)DS3231_SENSOR_ID + " : capteur pression\n";
  retour += "------------------------------------";
  return retour;
}

void commandsFromSerial(void)
{
  if (Serial.available())
  {
    String command = Serial.readStringUntil('\n');
    Serial.println(commands(command));
  }
}

void commandsFromBT(void)
{
  if (SerialBT.available() > 0)
  {
    String command = SerialBT.readStringUntil('\n');
    SerialBT.println(commands(command));
  }
}

void commandManager()
{
  commandsFromSerial();
  commandsFromBT();
}

#endif