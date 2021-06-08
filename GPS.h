#ifndef GPS_H
#define GPS_H
// header body...
#include "_TM4C123GH6PM.h"
void UART0_Send(char *string);
void UART1_Send(char *string);
void UART1_readline(char *string);
void GPS_Raw(char *string);



void UART0_Send(char *string){
	while (*string)
	{
		while ((UART0_FR_R & 0x0020) !=0){}
		UART0_DR_R= *(string++);
	}
}
void UART1_Send(char *string){
	while (*string)
	{
		while ((UART0_FR_R & 0x0020) !=0){}
		UART1_DR_R= *(string++);
	}
}

void UART1_readline(char *string){
	char x;//int i=0;
	do {
			while(UART1_FR_R&0x010){}
			x = (UART1_DR_R & 0xFF);
			*(string++)= x;
			//if (x=='\n')  i++;
		 }
	while(x!='\n');
	*(string)='\0';
		
}
void GPS_Raw(char *string){

	do{
		UART1_readline(string);
	}
	while(string[3]!=string[4]);
	
	
}

#endif
