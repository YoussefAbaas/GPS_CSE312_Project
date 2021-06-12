
#include <stdint.h>
#include "TM4C123.h"
#include "_TM4C123GH6PM.h"
#include <stdio.h>
#include "init.h"
#include "timer.h"
#include "LCD.h"
#include "led.h"
#include "GPS.h"
#include "dataTransformation.h"

void UART0_Send(char *string);
void UART1_Send(char *string);
void UART0_Receive(char *string);
void UART1_Receive(char *string);







//--------------------------------------------------------------------------
int main(void)
{
//initializeations here
		
		timer_init();
		PortA_Init();
		PortB_Init();
		PortF_Init();
		UART0_Init();
		UART1_Init();
		lcd_init();
		char rawline[]="";
		double distance=0;
		struct point P1,P2;
		delay(500);
		do{
				GPS_Raw(rawline);
				P1= get_coordinates(rawline);
				//lcd_intout(P1.is_vaild,0,15);
				lcd_strout("Waiting GPS ...",0,0);
			}
			while(!P1.is_vaild);
		lcd_clear();
		lcd_strout("GPS Ready!",0,3);
		lcd_strout("SW2 ---> start",1,1);
		while((GPIO_PORTF_DATA_R&0x01)!=0){}
		lcd_clear();
		lcd_strout("Distance(m):",0,0);
		lcd_intout((uint16_t)distance,1,0);
		// first point after press start	
		GPS_Raw(rawline);
		P1= get_coordinates(rawline);
		UART0_Send(rawline);

	while(1){//main loop
		do{
			delay(1000);
			GPS_Raw(rawline);																// receive GPS rawdata from UART1
			P2 = get_coordinates(rawline);						// parsing rawdata to Coordinates point;
			}
			while(!P2.is_vaild);	// check if the point is valid
		double tempdist = calculate_distance(P1,P2);							// calculate distance and add it to var distance
		if (tempdist>=5){
		distance+=tempdist;
		UART0_Send(rawline);															// send rawdata to PC through UART0
		lcd_intout((uint16_t)distance,1,0);
		green_led_on_off(distance);
		P1=P2;
		}
		

	}
	
}
