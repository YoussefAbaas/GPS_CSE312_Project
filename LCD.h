#include "_TM4C123GH6PM.h"
#include "stdint.h"
#include "stdio.h"
#include "timer.h"


void lcd_command(char);
void lcd_init(void);
void lcd_data(char);
void lcd_strout(char *string);
void lcd_intout(uint16_t);
void lcd_clear(void);


void lcd_command(char command)
	{
		GPIO_PORTA_DATA_R = 0x00; // RS=R/W=E=0
		delay(1);
		GPIO_PORTB_DATA_R = command; 
		delay(1);
		/// enable 1 then 0 (high to low)
		GPIO_PORTA_DATA_R |= 0x80; //E=1
		delay(1);
		GPIO_PORTA_DATA_R |= 0x00;
		

	}
void lcd_init()
	{ 
		//delay(50);

		lcd_command(0x38); //8 bit
		delay(2);
		lcd_command(0x0F); // turn on display
		delay(2);
		lcd_command(0x01); // clear display screen 
		delay(2);
		lcd_command(0x02); // return cursor to home
		delay(2);
		lcd_command(0x0C); // cursor off
		//lcd_command(0x06); //increment cursor
		//delay(2);
}
void lcd_data(char data)
	{
		
		GPIO_PORTA_DATA_R = 0x20; //RS = 1, RW = 0 ,E=0
		delay(2);
		GPIO_PORTB_DATA_R= data ;
	/// enable 1 then 0 (high to low)
		delay(2);
		GPIO_PORTA_DATA_R |= 0x80; //E=1
		delay(2);
		GPIO_PORTA_DATA_R |= 0x00;
		delay(2);
		lcd_command(0x06); //increment cursor
}
void lcd_clear()
{
	lcd_command(0x01); //clear display and return home
	delay(2);
}
void lcd_strout(char *string)
	{
		uint16_t i;
		for(i=0;string[i]!=0;i++)
		{
			lcd_data(string[i]);
		}
	}
void lcd_intout(uint16_t distance)
	{
		char str[16];
		sprintf(str, "%d", distance);
		lcd_strout(str);
	}	
