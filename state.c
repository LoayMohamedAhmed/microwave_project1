#include "lcd.h"
#include "state.h"
extern char input[1];

void Enter_Kilos()
{
	again:
	lcd_cmd(0X01);
	if(input[0]=='B')
	{
	  set_cursor(0,0); 
    lcd_print("chicken weight:");
		delay_ms(1000);
	}
	else if(input[0]=='C')
	{
		set_cursor(0,0); 
    lcd_print("Beaf weight:");
		delay_ms(1000);
	}
	set_cursor(1,8); 
	lcd_print("KG");
	set_cursor(1,7);
	kilos=keypad_getkey();
	delay_ms(700);
	lcd_write(kilos);
	delay_ms(1000);
}
