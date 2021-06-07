
#include <stdint.h>
#include "TM4C123.h"
#include <stdio.h>
<<<<<<< HEAD
#include <math.h>
#define PI 3.142857
#define R 6371000 // earth radius

//--------------------------------required Functions------------------------
void init(void);				 // initialize function	(GPIOF->(PF3), GPIOA->(PA0-->PA7), GPIOB(PB0), Systick timer initialize)
void delay(uint8_t millisecond); //SysTick timer delay in 1 millisecond
void toggle_G_Led(void);		 // 100 meter indicator
void displayout(float distance); // output calculated ditance at 3-digit 7-segment  (depends on 7seg connection)
// return distance between arr[0] and arr[index]
struct point
{
	int16_t latitude_deg;
	int16_t latitude_min;
	int16_t latitude_sec;
	int16_t longitude_deg;
	int16_t longitude_min;
	int16_t longitude_sec;
};
struct point get_coordinates(char rawData[]) {}
double calculate_distance(struct point point1, struct point point2, double *distance)
{
	double phi_1 = (point1.latitude_deg + (double)(point1.latitude_min + (double)point1.latitude_sec / 60) / 60) * (PI / 180);
	double phi_2 = (point2.latitude_deg + (double)(point2.latitude_min + (double)point2.latitude_sec / 60) / 60) * (PI / 180);

	double lamda_1 = (point1.longitude_deg + (double)(point1.longitude_min + (double)point1.longitude_sec / 60) / 60) * (PI / 180);
	double lamda_2 = (point2.longitude_deg + (double)(point2.longitude_min + (double)point2.longitude_sec / 60) / 60) * (PI / 180);
	double delta_phi = (phi_1 - phi_2);
	double delta_lamda = lamda_1 - lamda_2;

	double a = sin(delta_phi / 2) * sin(delta_phi / 2) + cos(phi_1) * cos(phi_2) * sin(delta_lamda / 2) * sin(delta_lamda / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	*distance = *distance + c * R;
	return *distance;
}
=======
#include "init.h"
#include "timer.h"
#include "LCD.h"
#include "led.h"
#include "dataTransformation.h"




>>>>>>> 099f10ed91820b8a7e431933be84fb46dce6aec7

//--------------------------------------------------------------------------
int main(void)
{
	//init();
<<<<<<< HEAD

	while (1)
	{ //main loop
=======
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
	
>>>>>>> 099f10ed91820b8a7e431933be84fb46dce6aec7
	}
}
<<<<<<< HEAD
//  ------------------------------implement Functions below------------------
=======
>>>>>>> 099f10ed91820b8a7e431933be84fb46dce6aec7
