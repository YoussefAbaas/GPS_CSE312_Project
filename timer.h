
#ifndef timer
#define timer

// header body...

#include "_TM4C123GH6PM.h"
#include "stdint.h"
void delay(uint32_t);
void delayMS(uint32_t delay);
	
void delay(uint32_t delay)
	{
	unsigned long i;
	for(i=0; i<delay; i++)
		{
			NVIC_ST_RELOAD_R = 50000-1; // number of counts
			NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
			while((NVIC_ST_CTRL_R&0x00010000)==0){ }
		}
	}
void delayMS(uint32_t delay)
	{
	unsigned long i;
	for(i=0; i<delay; i++)
		{
			NVIC_ST_RELOAD_R = 50-1; // number of counts
			NVIC_ST_CURRENT_R = 0; // any value written to CURRENT clears
			while((NVIC_ST_CTRL_R&0x00010000)==0){ }
		}
	}

#endif
