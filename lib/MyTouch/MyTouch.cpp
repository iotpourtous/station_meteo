#include "Mytouch.h"

MyTouch::MyTouch(unsigned int max_count,
                 unsigned int threshold,
                 unsigned int delay,
                 unsigned int pin) : _max_count(max_count),
                                     _threshold(threshold),
                                     _delay(delay),
                                     _pin(pin){};

boolean MyTouch::checkTouchKey(void)
{
    unsigned long startTime = millis();
    int count = 0 ;
    boolean pressed = false;
    
    do
    {
        if (touchRead(_pin) < _threshold)
            count++;
        else
            count = 0;
        if (count == 3)
            pressed = true;
    } while ((count < 4) && (millis() < startTime + _delay));
    return pressed;
};

int MyTouch::touchCount(void)
{
    if (checkTouchKey())
    {
        if (_state == LOW)
        {
            if (++_counter > _max_count)
                _counter = 0;
        }
        _state = HIGH;
    }
    else
        _state = LOW;

    return _counter;
}