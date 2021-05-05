#ifndef myDS3231_h
#define myDS3231_h

#include <iostream>
#include <exception>

#include <RTClib.h>

using namespace std;

class MyDS3231 : public RTC_DS3231
{
private:
    int _sensorId;
    String _formattedFormat;

    String READ_INFORMATIONS_COMMAND = "i";
    String YEAR_COMMAND = "y";
    String MONTH_COMMAND = "m";
    String DAY_COMMAND = "d";
    String HOUR_COMMAND = "h";
    String MINUTE_COMMAND = "M";


    String _daysOfTheWeek[7] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "jeudi", "Vendredi", "Samedi"};
    boolean isNotIntValue(String data);

public:
    MyDS3231(int sensorId, String formattedFormat);
    void begin(void);
    String dayOfTheWeek();

    String executeCommand(String command);
};

extern MyDS3231 myDS3231;

#endif