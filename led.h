#ifndef LED
#define LED

#include "_TM4C123GH6PM.h"
#include "math.h"
#include "timer.h"

void green_led_on_off(double distance);

void green_led_on_off(double distance)
{
    if (distance >= 100) 
    {
        delay(10);
        GPIO_PORTF_DATA_R = 0x08;
    }
    else
    {
        delay(10);
        GPIO_PORTF_DATA_R = 0x00;
    }
}

#endif
