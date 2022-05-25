#include "lcd.h"
#include "state.h"
#include "keypad.h"
extern char input[1];
extern char kilos;
extern 	int m,k,j,i;

void Enter_Kilos()
{
	again:
	lcd_cmd(0X01);
	if(input[0]=='B')
	{
	  set_cursor(0,0); 
    lcd_print("Chicken Weight:");
		delay_ms(1000);
	}
	else if(input[0]=='C')
	{
		set_cursor(0,0); 
    lcd_print("Beaf Weight:");
		delay_ms(1000);
	}
	set_cursor(1,8); 
	lcd_print("KG");
	set_cursor(1,7);
	kilos=keypad_getkey();
	delay_ms(700);
	lcd_write(kilos);
	delay_ms(1000);
	
	if( kilos=='0') 

	{
			lcd_cmd(0X01);
			set_cursor(0,1);
			lcd_print("Invalid input ");
			delay_ms(2000);
			set_cursor(0,0);
			lcd_print("Please try again");
			delay_ms(1000);
			goto again;
	}
	return;

}
void GPIOF_Handler(){
	
	 int m,k,j,i;
	 if (GPIOF->MIS & 0x01) /* check if interrupt causes by PF0/SW2*/
	 {
		if((count_array[0]>='3'&&(count_array[1]>'0'||count_array[2]>'0'||count_array[3]>'0'))||
				(count_array[2]>='6')||(count_array[0]=='0'&&count_array[1]=='0'&&count_array[2]=='0'&&count_array[3]=='0'))
			{
				lcd_cmd(0x01);
				set_cursor(0,1);
				lcd_print("Invalid input!");
				delay_ms(1000);
				for(g=0;g<4;g++)
				{
					count_array1[g]='0';
				}
				goto end;
			}
		 
	 }
	  else if (GPIOF->MIS & 0x10)// check if interrupt causes by PF4/SW1 
		{
		
		}
		
for( m = count_array[0]-'0'; m>=0; m--){//Counting down the first digit in minutes
  
  for( k= count_array[1]-'0'; k>=0; k--){//Counting down the second digit in minutes
      
       for(j=count_array[2]-'0'; j>=0;j--){//Counting down the first digit in seconds
       
					for( i = count_array[3]-'0'; i>=0; i--){//Counting down the second digit in seconds
             set_cursor(1,6);
						 LCD_printInt(m);
             LCD_printInt(k);
             lcd_write(':');
             LCD_printInt(j);
             LCD_printInt(i);
						  while(GPIOD->DATA==0x00){
							 if(GPIOD->DATA==0x80){break;}//if door was opened
						 }
				     delay_ms(900);
			


						if(GPIO_PORTF_DATA_R ==0x0D) //if pause switch is pressed
				 { 
      while(GPIO_PORTF_DATA_R != 0x1C){
				GPIOD->DATA=0X40;
				GPIOF->DATA&=~0X0C;
        delay_ms(700);
				GPIOF->DATA|=0X0C;
				set_cursor(0,3);
        while(GPIO_PORTF_DATA_R==0X0D) // if pause switch is pressed again ->stop
        { 
          i=3;
          X=1;
          Y=1;
          W=1;
          Z=1;
          goto end;
        }
	GPIOF->DATA=0x00;
				i=3;
				X=1;
				Y=1;
				W=1;
				Z=1;
GPIO_PORTD_DATA_R=0X40;
	lcd_cmd(0X01);
	lcd_cmd(0x02);
	lcd_print("cooking Done");
}