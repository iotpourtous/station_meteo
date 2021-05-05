#ifndef myTFT_h
#define myTFT_h

#include <Arduino.h>

#include "TFT_eSPI.h"
#include "SPI.h"
#include <RTClib.h>

class MyTFT : public TFT_eSPI
{
private:
public:
    void init();

    void afficheHeure(DateTime heure, String dayOfTheWeek = "", boolean full = false);

    void afficheTemperature(String temperature, boolean full = false);

    void afficheHumidite(String humidite, boolean full = false);

    void affichePression(String pressure, boolean full = false);

    void afficheHeader(DateTime currentDate);

    void afficheEcranAccueil(
        DateTime currentDate,
        float currentTemperature,
        float currentHumidity,
        int currentPressure);
};

extern MyTFT myTFT;
/*
void init();

void afficheHeure(DateTime heure, String dayOfTheWeek = "", boolean full = false);

void afficheTemperature(String temperature, boolean full = false);

void afficheHumidite(String humidite, boolean full = false);

void affichePression(String pressure, boolean full = false);

void afficheHeader(DateTime currentDate);

void afficheEcranAccueil(
    DateTime currentDate,
    float currentTemperature,
    float currentHumidity,
    int currentPressure);
*/
#endif