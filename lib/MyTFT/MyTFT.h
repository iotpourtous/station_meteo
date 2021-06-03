#ifndef myTFT_h
#define myTFT_h

#include <Arduino.h>

#include "TFT_eSPI.h"
#include <RTClib.h>

class MyTFT : public TFT_eSPI
{
private:
    unsigned int MAIN_SCREEN = TFT_DARKGREY;
    unsigned int TEMPERATURE_SCREEN = TFT_PURPLE;
    unsigned int HUMIDITY_SCREEN = TFT_BLUE;
    unsigned int PRESSURE_SCREEN = TFT_GREEN;
    unsigned int DATETIME_SCREEN = TFT_YELLOW;

    String FONT_24 = "Metal-Up-Your-Ear-24";
    String FONT_36 = "Metal-Up-Your-Ear-36";
    String FONT_48 = "Metal-Up-Your-Ear-48";
    String FONT_60 = "Metal-Up-Your-Ear-60";

    DateTime _currentDate = DateTime();
    float _currentTemperature = 0;
    float _currentHumidity = 0;
    unsigned int _currentPressure = 0;
    unsigned int _currentScreen = 10;

    void displayMainScreen(
        DateTime date,
        float temperature,
        float humidity,
        unsigned int pressure,
        boolean refreshDisplay);

    void displayTemperatureScreen(
        DateTime date,
        float temperature,
        boolean refreshDisplay);

    void displayHumidityScreen(
        DateTime date,
        float humidity,
        boolean refreshDisplay);

    void displayPressureScreen(
        DateTime date,
        unsigned int pressure,
        boolean refreshDisplay);

    void displayDateTimeScreen(
        DateTime date,
        String dayOfTheWeek,
        boolean refreshDisplay);

    void displayBackGround(unsigned int color, boolean refreshDisplay);
    void displayDateTime(DateTime date, unsigned int backgroundColor, boolean refreshDisplay);
    void displayData(unsigned int color, String testToDisplay);

public:
    void init(void);

    void display(
        DateTime date,
        float temperature,
        float humidity,
        unsigned int pressure,
        String dayOfTheWeek,
        unsigned int screen);
};

extern MyTFT myTFT;

#endif