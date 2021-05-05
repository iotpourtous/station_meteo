#include "MyDS3231.h"

char *MyDS3231::dayOfTheWeek()
{
  return _daysOfTheWeek[now().dayOfTheWeek()];
}
void MyDS3231::year(uint16_t year)
{
  adjust(DateTime(year, now().month(), now().day(), now().hour(), now().minute(), now().second()));
}
void MyDS3231::month(uint16_t month)
{
  adjust(DateTime(now().year(), month, now().day(), now().hour(), now().minute(), now().second()));
}
void MyDS3231::day(uint16_t day)
{
  adjust(DateTime(now().year(), now().month(), day, now().hour(), now().minute(), now().second()));
}
void MyDS3231::hour(uint16_t hour)
{
  adjust(DateTime(now().year(), now().month(), now().day(), hour, now().minute(), now().second()));
}
void MyDS3231::minute(uint16_t minute)
{
  adjust(DateTime(now().year(), now().month(), now().day(), now().hour(), minute, now().second()));
}
void MyDS3231::second(uint16_t second)
{
  adjust(DateTime(now().year(), now().month(), now().day(), now().hour(), now().minute(), second));
}

boolean MyDS3231::isNotIntValue(String data)
{
  return data.toInt() == 0 && data.charAt(0) != '0';
}

String MyDS3231::writeCommand(String command)
{
  if (command.startsWith("Y"))
  {
    String data = command.substring(1);
    if (isNotIntValue(data))
    {
      return "Commande incorrecte";
    }
    year(data.toInt());
    return "OK";
  }
  else if (command.startsWith("M"))
  {
    String data = command.substring(1);
    if (isNotIntValue(data))
    {
      return "Commande incorrecte";
    }
    month(data.toInt());
    return "OK";
  } 
  else if (command.startsWith("D"))
  {
    String data = command.substring(1);
    if (isNotIntValue(data))
    {
      return "Commande incorrecte";
    }
    day(data.toInt());
    return "OK";
  }
  else if (command.startsWith("H"))
  {
    String data = command.substring(1);
    if (isNotIntValue(data))
    {
      return "Commande incorrecte";
    }
    hour(data.toInt());
    return "OK";
  }
  else if (command.startsWith("m"))
  {
    String data = command.substring(1);
    if (isNotIntValue(data))
    {
      return "Commande incorrecte";
    }
    minute(data.toInt());
    return "OK";
  }
  return "Commande inexistante";
}

String MyDS3231::readCommand(String command, int8_t sensorId)
{
  if (command.equals("C"))
  {
    String retour = "------------------------------------\n";
    retour += "Liste des commandes\n";
    retour += "'>" + String(sensorId) + "C' : Liste des commandes\n";
    retour += "'<" + String(sensorId) + "Y' : modifie l'année\n";
    retour += "'<" + String(sensorId) + "M' : modifie le mois\n";
    retour += "'<" + String(sensorId) + "D' : modifie le jour\n";
    retour += "'<" + String(sensorId) + "H' : modifie l'heure\n";
    retour += "'<" + String(sensorId) + "m' : modifie les minutes\n";
    retour += "'>" + String(sensorId) + "T' : Lit la date et l'heure formatées\n";
    retour += "------------------------------------\n";
    return retour;
  }
  else if (command.equals("T"))
  {
    char formattedFormat[25] = "DD/MM/YYYY hh:mm:ss";
    return "T:" + String(now().toString(formattedFormat));
  }
  else
  {
    return "Commande inexistante";
  }
}