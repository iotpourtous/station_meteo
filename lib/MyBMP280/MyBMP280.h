#ifndef myBMP280_h
#define myBMP280_h

#include <iostream>
#include <exception>

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

using namespace std;

class MyBMP280 : public Adafruit_BMP280
{
private:
    uint8_t _addr;
    float _pressureOffset;
    float _pressureFromEvent();

    String LIST_COMMAND = "C";

    boolean isNotIntValue(String data);

public:
    MyBMP280(uint8_t addr, float pressureOffset = 0.0);
    bool begin(void);
    float pressureOffset() { return _pressureOffset; }
    void pressureOffset(float pressureOffset) { _pressureOffset = pressureOffset; }
    int pressure();

    String readCommand(String command, int8_t sensorId);
    String writeCommand(String command);
};

extern MyBMP280 myBMP280;

#endif
