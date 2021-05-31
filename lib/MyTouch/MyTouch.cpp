#include "Mytouch.h"

MyTouch::MyTouch(unsigned int max_count,
                 unsigned int threshold,
                 unsigned int delay,
                 unsigned int pin) : _max_count(max_count),
                                     _threshold(threshold),
                                     _delay(delay),
                                     _pin(pin){};