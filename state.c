#include "lcd.h"
#include "headr.h"
#include "stdint.h"
#include "state.h"
#include "keypad.h"
extern char input[1];
extern char kilos;
extern 	int m,k,j,i,X,Y,Z,W;

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
void GPIOF_Handler()
{
	
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
      delay_ms(900);
          
    while(GPIOD->DATA==0x00)
{
  if(GPIOD->DATA==0x80){break;}
}

    if(GPIO_PORTF_DATA_R ==0x0D){
      while(GPIO_PORTF_DATA_R != 0x1C){
				GPIOD->DATA=0X40;
				GPIOF->DATA&=~0X0C;
        delay_ms(700);
				GPIOF->DATA|=0X0C;
				set_cursor(0,3);
        while(GPIO_PORTF_DATA_R==0X0D)
        { 
					
          i=3;
          X=1;
          Y=1;
          W=1;
          Z=1;
          goto end;
        }
          
        
        
      }
			GPIOD->DATA=0x00;
  }
     
         }
       count_array[3]='9';
       }
    count_array[2] = '5';
     }
  count_array[1] = '9';
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
      while(i)
  { 
		GPIOF->DATA =0X02;
		GPIO_PORTD_DATA_R=0X40;
    delay_ms(200);
    GPIOF->DATA =0X04;
    delay_ms(200);
    GPIOF->DATA =0X08;
		GPIO_PORTD_DATA_R=0X00;
    delay_ms(200);
    GPIOF->DATA =0X00;
     set_cursor(0,5);
    i--;
    
  }
   
    /* clear the interrupt flag */
  end:
    GPIO_PORTF_ICR_R|= 0x01;
//	   Reset_Timer();
    }

	else if (GPIOF->MIS & 0x10)// check if interrupt causes by PF4/SW1 
		{
		  lcd_cmd(0x01);
      Reset_Timer();
      count_array1[0]='0';
      count_array1[1]='0';
      count_array1[2]='0';
      count_array1[3]='0';
      GPIOF->ICR |= 0x10;
		}
 }

void cooking() 
{
	if(input[0]=='A')  					//Popcorn
	{
	
		count_array[0]='0';
		count_array[1]='1';
		count_array[2]='0';
		count_array[3]='0';				//1 minute
		lcd_cmd(0X01);
	  set_cursor(0,2); 
    lcd_print("push switch 2 to start...");
	while(1)
	{
		if(Z==1)
		{
			main();
		}
	}
    }
	
	else if(input[0]=='B') 					//Beaf
	{
		 num = 0.5*(kilos-'0'); 			/*for calculating the time needed in minutes for every weight*/
     interpart = (int)num; 				/*for getting the integer part of the time*/
     decpart = num - interpart; 	/*for separating of the decimal part from the integer part*/ 
     sec = (int)(decpart*60); 		/*converting the decimal part into seconds*/
  	
     count_array[0] = '0';
     count_array[1] = interpart + '0';
     count_array[2] = '0' + (sec/10);
     count_array[3] = '0';
		 lcd_cmd(0X01);
	   set_cursor(0,2); 
     lcd_print("push switch 2 to start...");
	while(1)
		{
			if(Y==1)
			{
				main();
			}
		}
		
	}
	else if(input[0]=='C')
	{
		   if (kilos <'5'){
			  count_array[0] = '0';
				count_array[1] = '0';
				count_array[2] = kilos;
				count_array[3] = ((kilos-'0')*2)+'0';
			}
			else if (kilos == '5'){
				
				count_array[0] = '0';
				count_array[1] = '1';
				count_array[2] = '0';
				count_array[3] = '0';
			}
			else if (kilos>'5'){
				
				count_array[0] = '0';
				count_array[1] = '1';
				count_array[2] = ((kilos-'0')-5)+'0';
				count_array[3] = (((kilos-'0')-5)*2)+'0';
				 
			}
		lcd_cmd(0X01);
	  set_cursor(0,2); 
    lcd_print("push switch 2 to start...");
		
		while(1)
		{
			if(W==1)
			{
			main();
			}
		}
  }	
