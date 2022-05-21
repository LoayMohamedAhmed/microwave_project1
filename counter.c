#include "headr.h"
#include "counter.h"
#include "lcd.h"
#include "keypad.h"
#include "stdint.h"


extern char count_array1[4];
extern char count_array[4];


void Reset_Timer()
	{
		int i;
		for(i=5;i<10;i++)
		{
			if (i==7)
			{
				set_cursor(1,i);
				lcd_write(':');
				continue;
			}
			set_cursor(1,i);
			lcd_print("0");
		}
	}

//void enter_counter()
//{
////	
//	    Reset_Timer();
// while(1)//X is the char returned from the keypad
// {
//    count_array1[0] = count_array1[1];
//    count_array1[1] = count_array1[2];
//    count_array1[2] = count_array1[3];
//    count_array1[3] = keypad_getkey();
//    delay_ms(700);
//    showEnteredTime();

//	for(g=0;g<4;g++)
//	{
//		count_array[g]=count_array1[g];
//	}
//	if(X==1)
//	{
//	  main();
//		break;
//	}
// }

//}
void showEnteredTime()
{

 set_cursor(1,5);
 lcd_write(count_array1[0]);
 lcd_write(count_array1[1]);
 lcd_write(':');
 lcd_write(count_array1[2]);
 lcd_write(count_array1[3]);
	delay_ms(500);

}

void interupt_init(){
	GPIO_PORTF_IS_R &= ~0x11;     //  PF4-PF1 are edge-sensitive

  GPIO_PORTF_IBE_R &= ~0x11;    //  PF4-PF1 are is not both edges

  GPIO_PORTF_IEV_R &= ~0x11;    //     PF4-PF1 are falling edge event

  GPIO_PORTF_ICR_R = 0x11;      //  clear flags

  GPIO_PORTF_IM_R |= 0x11;      //  arm interrupt on PF4-PF1 

  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // priority 5

  NVIC_EN0_R = 0x40000000;      // enable interrupt 30 in NVIC
}
