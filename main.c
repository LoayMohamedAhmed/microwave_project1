#include "lcd.h"
#include "headr.h"
#include "stdint.h"
#include "headr.h"

 
int k;
char count_array1[4];
char count_array[]={'0','0','0','0'};
char input[1];
char kilos;
int m,k,j,i,X;

int main()
{
	X=0; 
	Y=0;
	Z=0;
	W=0;
	
	intialisation_timer();
	Ports_Init ();
	interupt_init();
	init_lcd ();
	GPIOF->DATA=0x00;
	GPIOD->DATA=0x00;
	
}
