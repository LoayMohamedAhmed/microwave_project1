#include "headr.h"
#include "counter.h"
#include "lcd.h"
#include "keypad.h"


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
