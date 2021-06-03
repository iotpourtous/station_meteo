#ifndef utils_h
#define utils_h

#include "stationMeteoVar.h"

void initialize(void)
{
    //Initialisation du Serial
    Serial.begin(SERIAL_BAUD);

    Serial.println("------------------------------------------------");
    Serial.println("Début initialisation");
    Serial.println("------------------------------------------------");

    //Initialisation de SPIFFS
    Serial.println("Début Initialisation SPIFFS");
    delay(125);
    if (!SPIFFS.begin())
    {
        Serial.println("SPIFFS initialisation failed!");
        while (1)
            yield();
    }
    Serial.println("Initialisation SPIFFS OK");
    Serial.println("------------------------------------------------");

    //Initialisation du bluetooth
    Serial.println("Début Initialisation bluetooth");
    delay(125);
    SerialBT.begin(BT_ACCESS_POINT);
    Serial.println("Initialisation bluetooth OK");
    Serial.println("------------------------------------------------");

    //Initialisation du DHT22
    Serial.println("Début Initialisation DHT22");
    delay(125);
    dht.begin();
    Serial.println("Initialisation DHT22 OK");
    Serial.println("------------------------------------------------");

    //Initialisation du BPM280
    Serial.println("Début Initialisation BPM280");
    delay(125);
    bmp.begin();
    Serial.println("Initialisation BPM280 OK");
    Serial.println("------------------------------------------------");

    //Initialisation du DS3231
    Serial.println("Début Initialisation DS3231");
    delay(125);
    rtc.begin();
    Serial.println("Initialisation DS3231 OK");
    Serial.println("------------------------------------------------");

    //Initialisation du ILI9341
    Serial.println("Début Initialisation ILI9341");
    delay(125);
    myTFT.init();
    Serial.println("Initialisation ILI9341 OK");
    Serial.println("------------------------------------------------");

    Serial.println("Fin initialisation");
    Serial.println("------------------------------------------------");

    tempsDate = millis();
    tempsSensor = millis();

    //collecte des données
    currentDate = rtc.now();
    currentTemperature = dht.temperature();
    currentHumidity = dht.humidity();
    currentPressure = bmp.pressure();
}

void readData(void)
{
    if ((millis() - tempsDate) > DELAY_DATE)
    {
        currentDate = rtc.now();

        tempsDate = millis();
    }

    if ((millis() - tempsSensor) > DELAY_SENSOR)
    {
        currentTemperature = dht.temperature();
        currentHumidity = dht.humidity();
        currentPressure = bmp.pressure();

        tempsSensor = millis();
    }
}

#endif