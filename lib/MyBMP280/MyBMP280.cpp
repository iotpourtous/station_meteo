#include "MyBMP280.h"

MyBMP280::MyBMP280(
    uint8_t addr, float pressureOffset) : Adafruit_BMP280(&Wire),
                                          _addr(addr),
                                          _pressureOffset(pressureOffset) {}

bool MyBMP280::begin()
{
  return Adafruit_BMP280::begin(_addr);
}

float MyBMP280::_pressureFromEvent()
{
  sensors_event_t event;
  Adafruit_BMP280::getPressureSensor()->getEvent(&event);
  return event.pressure;
}

int MyBMP280::pressure()
{
  return (int)round(_pressureFromEvent() + _pressureOffset);
}

boolean MyBMP280::isNotIntValue(String data)
{
  return data.toInt() == 0 && data.charAt(0) != '0';
}

String MyBMP280::writeCommand(String command)
{
  if (command.startsWith("O"))
  {

    String data = command.substring(1);
    if (isNotIntValue(data))
    {
      return "Commande incorrecte";
    }
    pressureOffset(data.toInt());
    return "OK";
  }
  return "Commande inexistante";
}

String MyBMP280::readCommand(String command, int8_t sensorId)
{
  if (command.equals(LIST_COMMAND))
  {
    String retour = "------------------------------------\n";
    retour += "Liste des commandes\n";
    retour += "'>" + String(sensorId) + "C' : Liste des commandes\n";
    retour += "'>" + String(sensorId) + "P' : Lit la pression\n";
    retour += "'>" + String(sensorId) + "O' : Lit l'offset de pression\n";
    retour += "'>" + String(sensorId) + "I' : Lit les infos du capteur de pression\n";
    retour += "'<" + String(sensorId) + "OXX.XX' : modifie l'offset de pression\n";
    retour += "------------------------------------";
    return retour;
  }
  else if (command.equals("P"))
  {
    return (isnan(pressure()))
               ? "P:lecture de la préssion impossible"
               : "P:" + String((int)round(pressure())) + "hPa";
  }
  else if (command.equals("O"))
  {
    return "O:" + String(pressureOffset()) + "hPa";
  }
  else if (command.equals("I"))
  {
    sensor_t sensor;
    Adafruit_BMP280::getPressureSensor()->getSensor(&sensor);
    String retour = "------------------------------------\n";
    retour + "capteur de pression Sensor\n";
    retour += "Nom: " + String(sensor.name) + "\n";
    retour += "Version:  " + String(sensor.version) + "\n";
    retour += "Identifiant:   " + String(sensor.sensor_id) + "\n";
    retour += "Delay minimun:   " + String(sensor.min_delay / 1000) + "Ms\n";
    retour += "Valeur Max:   " + String(sensor.max_value) + "hPa\n";
    retour += "Valeur Min:   " + String(sensor.min_value) + "hPa\n";
    retour += "Resolution:  " + String(sensor.resolution) + "hPa\n";
    retour += "------------------------------------";
    return retour;
  }
  else
  {
    return "Commande inexistante";
  }
}