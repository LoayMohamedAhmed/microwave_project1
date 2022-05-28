#include "lcd.h"
#include "headr.h"
#include "stdint.h"
#include "headr.h"
#include "state.h"
 
int k;
char count_array1[4]={'0','0','0','0'};
char count_array[4];
char input[1];
char kilos,decpart;
int m,k,j,i,X,Y,Z,W,g,sec;
int interpart;
int num;

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
	GPIO_PORTF_DATA_R=0x00;
	GPIO_PORTD_DATA_R=0x00;
	
	again:
	lcd_cmd(0x01);
	set_cursor(0,5);
	lcd_print("Hello");
	delay_ms(2000);
	set_cursor(0,2);
	lcd_print("I am Martha");
	delay_ms(2000);
	lcd_cmd(0x01);
	set_cursor(0,3);
	lcd_print("lets cook");
	delay_ms(2000);
	lcd_cmd(0x01);
	set_cursor(0,4);
	lcd_print("Please");
	delay_ms(1000);
	lcd_cmd(0x01);
	set_cursor(0,3);
	lcd_print("Enter mood");
  delay_ms(1000);
	set_cursor(1,4);
	input[0] = keypad_getkey();
	
	if(input[0]=='A'){ 
		lcd_cmd(0x01);
		set_cursor(0,4);
		lcd_print("Popcorn");
		delay_ms(500);
		cooking();
		}
	else if(input[0]=='B')
		{
		  lcd_cmd(0X01);
				set_cursor(0,0); 
			lcd_print("Enter Beaf weight");
			set_cursor(1,2); 
			lcd_print("in KG(1-9)");
			delay_ms(1000);
			Enter_Kilos();
			cooking();
		}
	
	else if(input[0]=='C')
		{
			lcd_cmd(0X01);
			set_cursor(0,0); 
      lcd_print("Chicken Weight ");
			delay_ms(500);
			set_cursor(1,1); 
			lcd_print("in KG(1-9)");
			delay_ms(1000);
		  Enter_Kilos();
			cooking();
		}	
		else if(input[0]=='D')
		{
			lcd_cmd(0x01);
			set_cursor(0,3);
			lcd_print("enter time");
			enter_counter();
		}
		else 
		{
			lcd_cmd(0X01);
			set_cursor(0,2);
			lcd_print("inavlid input");
			goto again;
   	}
}
