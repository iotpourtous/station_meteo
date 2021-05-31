#ifndef myTouch_h
#define myTouch_h

#include <Arduino.h>

using namespace std;

class MyTouch
{
private:
    unsigned int _counter = 0;
    unsigned int _state = LOW;
    unsigned int _max_count;
    unsigned int _threshold;
    unsigned int _delay;
    unsigned int _pin;

    boolean checkTouchKey(void);

public:
    MyTouch(unsigned int max_count,
            unsigned int threshold,
            unsigned int delay,
            unsigned int pin);

    int manageCheck();
};

extern MyTouch myTouch;

#endif