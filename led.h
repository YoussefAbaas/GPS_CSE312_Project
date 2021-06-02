#ifndef LED
#define LED

#include "TM4C123GH6PM.h"
#include "math.h"
#include "timer.h"
void green_led_on_off(double distance);

void green_led_on_off(double distance)
{
    if (distance >= 100) // if distanc 99.8 or 100.3 isequal to 100
    {
        delay(10);
        GPIO_PORT_DATA_R = 0x08;
    }
    else
    {
        delay(10);
        GPIO_PORT_DATA_R = 0x00;
    }
}

#endif
