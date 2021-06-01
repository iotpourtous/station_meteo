#ifndef myTFT_h
#define myTFT_h

#include <Arduino.h>

#include "TFT_eSPI.h"
#include "SPI.h"
#include <RTClib.h>

class MyTFT : public TFT_eSPI
{
private:
    typedef enum
    {
        DARKGREY_SCREEN = (TFT_DARKGREY),
        TEMPERATURE_SCREEN = (TFT_PURPLE),
        HUMIDITY_SCREEN = (TFT_BLUE),
        PRESSURE_SCREEN = (TFT_GREEN),
        DATETIME_SCREEN = (TFT_YELLOW)
    } color_type_t;

    DateTime _currentDate = DateTime();
    float _currentTemperature = 0;
    float _currentHumidity = 0;
    unsigned int _currentPressure = 0;
    unsigned int _currentScreen = 10;

    void afficheEcran0(
        DateTime date,
        float temperature,
        float humidity,
        unsigned int pressure);

    void afficheEcran1(
        DateTime date,
        float temperature);

    void afficheEcran2(
        DateTime date,
        float humidity);

    void afficheEcran3(
        DateTime date,
        unsigned int pressure);

    void afficheEcran4(
        DateTime date,
        String dayOfTheWeek);

    void drawBackGround(unsigned int color);
    void afficheHeure(DateTime date, unsigned int backgroundColor);

public:
    void init(void);

    void affiche(
        DateTime date,
        float temperature,
        float humidity,
        unsigned int pressure,
        String dayOfTheWeek,
        unsigned int screen);
};

extern MyTFT myTFT;

#endif