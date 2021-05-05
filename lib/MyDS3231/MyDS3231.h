#ifndef myDS3231_h
#define myDS3231_h

#include <iostream>
#include <exception>

#include <RTClib.h>

using namespace std;

class MyDS3231 : public RTC_DS3231
{
private:
    char _daysOfTheWeek[7][12] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "jeudi", "Vendredi", "Samedi"};
    boolean isNotIntValue(String data);

public:
    char *dayOfTheWeek();
    void year(uint16_t year);
    void month(uint16_t month);
    void day(uint16_t day);
    void hour(uint16_t hour);
    void minute(uint16_t minute);
    void second(uint16_t second);

    String readCommand(String command, int8_t sensorId);
    String writeCommand(String command);
};

extern MyDS3231 myDS3231;

#endif