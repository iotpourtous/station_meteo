#ifndef commandManager_h
#define commandManager_h

#include "stationMeteoVar.h"

String commands(String command)
{
  if (command.substring(0, 2).equals("<" + String(DHT22_SENSOR_ID)))
  {
    return dht->writeCommand(command.substring(2));
  }
  else if (command.substring(0, 2).equals(">" + String(DHT22_SENSOR_ID)))
  {
    return dht->readCommand(command.substring(2), DHT22_SENSOR_ID);
  }
  else if (command.substring(0, 2).equals("<" + String(BMP280_SENSOR_ID)))
  {
    return bmp->writeCommand(command.substring(2));
  }
  else if (command.substring(0, 2).equals(">" + String(BMP280_SENSOR_ID)))
  {
    return bmp->readCommand(command.substring(2), BMP280_SENSOR_ID);
  }
  else if (command.substring(0, 2).equals("<" + String(DS3231_SENSOR_ID)))
  {
    return rtc.writeCommand(command.substring(2));
  }
  else if (command.substring(0, 2).equals(">" + String(DS3231_SENSOR_ID)))
  {
    return rtc.readCommand(command.substring(2), DS3231_SENSOR_ID);
  }
  return "Commande inexistante1";
}

void commandsFromSerial()
{
  if (Serial.available())
  {
    String command = Serial.readStringUntil('\n');
    Serial.println(commands(command));
  }
}

void commandsFromBT()
{
  if (SerialBT.available() > 0)
  {
      String command = SerialBT.readStringUntil('\n');
      SerialBT.println(command);
      Serial.println(command);
      SerialBT.println(commands(command));
  }
}

#endif