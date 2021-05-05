#include "MyBMP280.h"

MyBMP280::MyBMP280(
    int addr,
    int sensorId) : Adafruit_BMP280(&Wire),
                    _addr(addr),
                    _sensorId(sensorId),
                    _pressureOffset(0)
{
  Adafruit_BMP280::getPressureSensor()->getSensor(&_pressureSensor);
}

void MyBMP280::begin()
{
  if (!Adafruit_BMP280::begin(_addr))
  {
    Serial.println("Le capteur BMP280 est introuvable. Vérifier votre câblage");
    while (1)
      yield();
  }
}

int MyBMP280::pressure()
{
  sensors_event_t event;
  Adafruit_BMP280::getPressureSensor()->getEvent(&event);;

  return (int)(event.pressure + _pressureOffset);
}

String MyBMP280::executeCommand(String command)
{

  if (command.equals(READ_INFORMATIONS_COMMAND))
  {
    String retour = "------------------------------------\n";
    retour += "Pression : ";
    retour += (isnan(pressure()))
                  ? "lecture de la pression impossible"
                  : (String)pressure() + "hPa ";
    retour += "(offset :" + (String)pressureOffset() + ")\n";
    retour += "------------------------------------";
    return retour;
  }
  else if (command.equals(READ_PRESSURE_SENSOR_INFORMATION_COMMAND))
  {
    String retour = "------------------------------------\n";
    retour + "capteur de pression Sensor\n";
    retour += "Nom: " + (String)_pressureSensor.name + "\n";
    retour += "Version:  " + (String)_pressureSensor.version + "\n";
    retour += "Identifiant:   " + (String)_pressureSensor.sensor_id + "\n";
    retour += "Delay minimun:   " + (String)(_pressureSensor.min_delay / 1000) + "Ms\n";
    retour += "Valeur Max:   " + (String)_pressureSensor.max_value + "hPa\n";
    retour += "Valeur Min:   " + (String)_pressureSensor.min_value + "hPa\n";
    retour += "Resolution:  " + (String)_pressureSensor.resolution + "hPa\n";
    retour += "------------------------------------";
    return retour;
  }
  if (command.startsWith(PRESSURE_OFFSET_COMMAND))
  {
    float value = command.substring(PRESSURE_OFFSET_COMMAND.length()).toFloat();
    if (value != 0 || (value == 0 && command.substring(2).startsWith("0")))
      pressureOffset(value);
    return executeCommand(READ_INFORMATIONS_COMMAND);
  }
  else
  {
    String retour = "------------------------------------\n";
    retour += "Liste des commandes\n";
    retour += (String)_sensorId + READ_INFORMATIONS_COMMAND + " : Affiche la pression\n";
    retour += (String)_sensorId + READ_PRESSURE_SENSOR_INFORMATION_COMMAND + " : Affiche les infos du capteur de pression\n";
    retour += (String)_sensorId + PRESSURE_OFFSET_COMMAND + "[XX.XX] : modifie l'offset de la pression si XX.XX est présent et affiche la pression\n";
    retour += "------------------------------------";
    return retour;
  }
}