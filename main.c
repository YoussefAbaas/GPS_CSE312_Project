
#include <stdint.h>
#include "TM4C123.h"


//--------------------------------required Functions------------------------
void init(void);				 // initialize function	(GPIOF->(PF3), GPIOA->(PA0-->PA7), GPIOB(PB0), Systick timer initialize)
void delay(uint8_t millisecond); //SysTick timer delay in 1 millisecond
void toggle_G_Led(void); // 100 meter indicator
void displayout(uint16_t distance);  // output calculated ditance at 3-digit 7-segment  (depends on 7seg connection)
uint16_t calculate_distance(uint16_t arr[],uint16_t index); // return distance between arr[0] and arr[index]

//--------------------------------------------------------------------------
int main(void)
{
	//init();
	

	while(1){//main loop
	
	}
	
}
//  ------------------------------implement Functions below------------------







