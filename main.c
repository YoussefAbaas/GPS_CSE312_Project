
#include <stdint.h>
#include "TM4C123.h"
#include <stdio.h>
#include "init.h"
#include "timer.h"
#include "LCD.h"
#include "led.h"
#include "dataTransformation.h"





//--------------------------------------------------------------------------
int main(void)
{
	//init();
	timer_init();
	PortA_Init();
	PortB_Init();
	PortF_Init();
	lcd_init();
	uint16_t x =0;
	bool flag=0;
	
	while(1){//main loop
		
		lcd_intout(x);
		green_led_on_off(x);
		if (x>125) flag=1;
		if (!flag) x+=25;
		else x-=25;
		delay(500);  // 500ms
		lcd_clear();
	
	}
	
}
