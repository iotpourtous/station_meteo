#ifndef myTFT_h
#define myTFT_h

#include <Arduino.h>

#include "TFT_eSPI.h"
#include "SPI.h"
#include <RTClib.h>

class MyTFT : public TFT_eSPI
{
private:
    DateTime _currentDate = DateTime();
    float _currentTemperature = 0;
    float _currentHumidity = 0;
    int _currentPressure = 0;
    int _currentScreen = -1;

    void afficheEcran0(
        DateTime date,
        float temperature,
        float humidity,
        int pressure);

    void afficheEcran1(
        DateTime date,
        float temperature);

    void afficheEcran2(
        DateTime date,
        float humidity);

    void afficheEcran3(
        DateTime date,
        int pressure);

    void afficheEcran4(
        DateTime date,
        String dayOfTheWeek);

public:
    void init(void);

    void affiche(
        DateTime date,
        float temperature,
        float humidity,
        int pressure,
        String dayOfTheWeek,
        int screen);
};

extern MyTFT myTFT;

#endif