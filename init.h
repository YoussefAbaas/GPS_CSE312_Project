#ifndef init
#define init

// header body...
#include "_TM4C123GH6PM.h"
#include "stdint.h"
void PortB_Init(void);
void PortA_Init(void);
void port_f_init(void);
void timer_init(void);

void PortB_Init()
{ // Data port
  volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= 0x02; // 1) B clock
  delay = 0x00000020;        // reading register adds a delay
  GPIO_PORTB_LOCK_R = 0x4C4F434B;
  GPIO_PORTB_CR_R = 0xFF;         // allow changes to PB7-0
  GPIO_PORTB_AMSEL_R = 0x00;      // 3) disable analog function
  GPIO_PORTB_PCTL_R = 0x00000000; // 4) GPIO clear bit PCTL
  GPIO_PORTB_DIR_R = 0xFF;        // 5) PB7-PB0 output
  GPIO_PORTB_AFSEL_R = 0x00;      // 6) no alternate function
  GPIO_PORTB_PUR_R = 0x00;        // disable pullup resistors
  GPIO_PORTB_DEN_R = 0xFF;        // 7) enable digital pins PA7-PA0
}
void PortA_Init()
{ //command port (PA5 for RS ,PA6 for R/W, PA7 for E)
  volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= 0x01;      // 1) A clock
  delay = 0x00000020;             // reading register adds a delay
  GPIO_PORTA_CR_R = 0xE0;         // allow changes to PA7-5
  GPIO_PORTA_AMSEL_R = 0x00;      // 3) disable analog function
  GPIO_PORTA_PCTL_R = 0x00000000; // 4) GPIO clear bit PCTL
  GPIO_PORTA_DIR_R = 0xE0;        // 5) PB7-PA5 output
  GPIO_PORTA_AFSEL_R = 0x00;      // 6) no alternate function
  GPIO_PORTA_PUR_R = 0x00;        // disable pullup resistors
  GPIO_PORTA_DEN_R = 0xE0;        // 7) enable digital pins PA7-PA0
}

void port_f_init()
{
  SYSCTL_RCGCGPIO_R |= 0X00000020;
  while ((SYSCTL_RCGCGPIO_R & 0X00000020) == 0)
  {
  };
  GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlock gpio reg
  GPIO_PORTF_CR_R = 0X1F;         //enable gpio port f control
  GPIO_PORTF_DIR_R = 0X0E;
  GPIO_PORTF_PUR_R = 0X11;
  GPIO_PORTF_DEN_R = 0X1F;
}

void timer_init()
{
  NVIC_ST_CTRL_R = 0;            // 1) disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x00FFFFFF; // 2) maximum reload value
  NVIC_ST_CURRENT_R = 0;         // 3) any write to CURRENT clears it
  NVIC_ST_CTRL_R = 0x00000005;   // 4) enable SysTick with core clock
}

#endif
