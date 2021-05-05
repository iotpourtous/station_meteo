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
    int _addr;
    int _sensorId;

    sensor_t _pressureSensor;

    float _pressureOffset;

    String READ_INFORMATIONS_COMMAND = "i";
    String READ_PRESSURE_SENSOR_INFORMATION_COMMAND = "ip";
    String PRESSURE_OFFSET_COMMAND = "po";

public:
    MyBMP280(int addr, int sensorId);
    void begin(void);
    float pressureOffset() { return _pressureOffset; }
    void pressureOffset(float pressureOffset) { _pressureOffset = pressureOffset; }
    int pressure();

    String executeCommand(String command);
};

extern MyBMP280 myBMP280;

#endif
