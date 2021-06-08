#include "_TM4C123GH6PM.h"
#include "stdint.h"
#include "stdio.h"
#include "timer.h"


void lcd_command(char);
void lcd_init(void);
void lcd_data(char);
void lcd_strout(char *string,uint8_t line,uint8_t index);
void lcd_intout(uint16_t distance,uint8_t line,uint8_t index);
void lcd_clear(void);


void lcd_command(char command)
	{
		GPIO_PORTA_DATA_R = 0x00; // RS=R/W=E=0
		delayMS(1000);
		GPIO_PORTB_DATA_R = command; 
		delayMS(1000);
		/// enable 1 then 0 (high to low)
		GPIO_PORTA_DATA_R |= 0x80; //E=1
		delayMS(50);
		GPIO_PORTA_DATA_R |= 0x00;
		delayMS(50);

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
		delayMS(50);
		GPIO_PORTB_DATA_R= data ;
	/// enable 1 then 0 (high to low)
		delayMS(50);
		GPIO_PORTA_DATA_R |= 0x80; //E=1
		delayMS(50);
		GPIO_PORTA_DATA_R |= 0x00;
		delayMS(50);
		lcd_command(0x06); //increment cursor
		delayMS(50);
}
void lcd_clear()
{
	lcd_command(0x01); //clear display and return home
	delayMS(1500);
}
void lcd_strout(char *string,uint8_t line,uint8_t index)
	{
		if (!line) lcd_command(128+index);
		else if(line==1) lcd_command(128+64+index);
		uint16_t i;
		for(i=0;string[i]!=0;i++)
		{
			lcd_data(string[i]);
		}
	}

void lcd_intout(uint16_t distance,uint8_t line,uint8_t index)
	{
		char str[9];
		
		if(distance<10){
			str[0]=(distance%10)+48;
			str[1]='\0';
		}
		else if (distance<100){
			
			str[0]=(distance%100/10)+48;
			str[1]=(distance%10)+48;
			str[2]='\0';
		}
		else{
			str[0]=(int)(distance%1000/100)+48;
			str[1]=(int)(distance%100/10)+48;
			str[2]=(int)(distance%10)+48;
			str[3]='\0';
		}
		//sprintf (str, "%f", distance);
		
		lcd_strout(str,line,index);
	}	
