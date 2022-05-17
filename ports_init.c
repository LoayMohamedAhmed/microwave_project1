#include "headr.h"
#include "stdint.h"

//intializing port B
void Ports_Init ()
 { 
	//intialization of LCD data pins (PB0-PB7)
	SYSCTL_RCGCGPIO_R |= 0x0000003B; //enable clock for port a.b,d,e
  while ((SYSCTL_PRGPIO_R&0x03B) == 0){};
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AMSEL_R = 0x00;
	GPIO_PORTB_AFSEL_R = 0x00; 
	GPIO_PORTB_PCTL_R = 0x00000000;
  GPIO_PORTB_PUR_R = 0x00;
	
	//intialization of LCD control pins (PB0-PB7)
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x3E;
	GPIO_PORTE_DIR_R = 0x0E;
	GPIO_PORTE_DEN_R = 0x3E;
	GPIO_PORTE_AMSEL_R = 0x00;
	GPIO_PORTE_AFSEL_R = 0x00;
	GPIO_PORTE_PCTL_R = 0x00000000;
  GPIO_PORTE_PUR_R = 0x00;
		
}
