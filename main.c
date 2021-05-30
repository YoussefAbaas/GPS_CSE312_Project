
#include <stdint.h>
#include "TM4C123.h"

#define NVIC_ST_CTRL_R (*((volatile uint32_t *)0xE000E010)) 
#define NVIC_ST_RELOAD_R (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R (*((volatile uint32_t *)0xE000E018))
#define NVIC_ST_CURRENT_R (*((volatile uint32_t *)0xE000E018))

//--------------------------------required Functions------------------------
void init(void);				 // initialize function	
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







