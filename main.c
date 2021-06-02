
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
	PortA_Init();
	PortB_Init();
	PortF_Init();
	lcd_init();
	uint16_t x =0;
	
	while(1){//main loop
		
		lcd_intout(x);
		x+=10;
		green_led_on_off(x);
		delay(500);  // 500ms
	
	}
	
}
//  ------------------------------implement Functions below------------------







