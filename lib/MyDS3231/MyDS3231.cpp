#include "MyDS3231.h"

MyDS3231::MyDS3231(unsigned int sensorId, String formattedFormat) : _sensorId(sensorId),
                                                                    _formattedFormat(formattedFormat) {}

void MyDS3231::begin()
{
  Serial.begin(115200);

  if (!RTC_DS3231::begin())
  {
    Serial.println("Le RTF est introuvable. Vérifier votre câblage");
  }

  if (RTC_DS3231::lostPower())
  {
    Serial.println("RTC lost power, let's set the time!");
    RTC_DS3231::adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

String MyDS3231::dayOfTheWeek()
{
  return _daysOfTheWeek[now().dayOfTheWeek()];
}

String MyDS3231::executeCommand(String command)
{

  if (command.equals(READ_INFORMATIONS_COMMAND))
  {
    String retour = "------------------------------------\n";

    char buf[50];
    _formattedFormat.toCharArray(buf, 50);
    retour += "Date : " + (String)dayOfTheWeek() + " " + now().toString(buf) + "\n";
    retour += "------------------------------------";
    return retour;
  }
  else if (command.startsWith(YEAR_COMMAND))
  {
    int value = command.substring(YEAR_COMMAND.length()).toInt();
    if (value != 0 || (value == 0 && command.substring(YEAR_COMMAND.length()).startsWith("0")))
      adjust(DateTime(value, now().month(), now().day(), now().hour(), now().minute(), now().second()));
    return executeCommand(READ_INFORMATIONS_COMMAND);
  }
  else if (command.startsWith(MONTH_COMMAND))
  {
    int value = command.substring(MONTH_COMMAND.length()).toInt();
    if (value != 0 || (value == 0 && command.substring(MONTH_COMMAND.length()).startsWith("0")))
      adjust(DateTime(now().year(), value, now().day(), now().hour(), now().minute(), now().second()));
    return executeCommand(READ_INFORMATIONS_COMMAND);
  }
  else if (command.startsWith(DAY_COMMAND))
  {
    int value = command.substring(DAY_COMMAND.length()).toInt();
    if (value != 0 || (value == 0 && command.substring(DAY_COMMAND.length()).startsWith("0")))
      adjust(DateTime(now().year(), now().month(), value, now().hour(), now().minute(), now().second()));
    return executeCommand(READ_INFORMATIONS_COMMAND);
  }
  else if (command.startsWith(HOUR_COMMAND))
  {
    int value = command.substring(HOUR_COMMAND.length()).toInt();
    if (value != 0 || (value == 0 && command.substring(HOUR_COMMAND.length()).startsWith("0")))
      adjust(DateTime(now().year(), now().month(), now().day(), value, now().minute(), now().second()));
    return executeCommand(READ_INFORMATIONS_COMMAND);
  }
  else if (command.startsWith(MINUTE_COMMAND))
  {
    int value = command.substring(MINUTE_COMMAND.length()).toInt();
    if (value != 0 || (value == 0 && command.substring(MINUTE_COMMAND.length()).startsWith("0")))
      adjust(DateTime(now().year(), now().month(), now().day(), now().hour(), value, now().second()));
    return executeCommand(READ_INFORMATIONS_COMMAND);
  }
  else
  {
    String retour = "------------------------------------\n";
    retour += "Liste des commandes\n";
    retour += (String)_sensorId + READ_INFORMATIONS_COMMAND + " : Lit la date et l'heure formatées\n";
    retour += (String)_sensorId + YEAR_COMMAND + "XXXX : modifie l'année\n";
    retour += (String)_sensorId + MONTH_COMMAND + "XX : modifie le mois\n";
    retour += (String)_sensorId + DAY_COMMAND + "XX : modifie le jour\n";
    retour += (String)_sensorId + HOUR_COMMAND + "XX : modifie l'heure\n";
    retour += (String)_sensorId + MINUTE_COMMAND + "XX : modifie les minutes\n";
    retour += "------------------------------------\n";
    return retour;
  }
}
