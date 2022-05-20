#include "lcd.h"
#include "headr.h"
#include "stdint.h"

void lcd_write(u8 data)
{
	GPIO_PORTB_DATA_R=data;
	GPIO_PORTE_DATA_R=0X0A;
	delay_ms(1);
	GPIO_PORTE_DATA_R=0X01;
	delay_ms(50);
	
	return;
}



//void set_cursor(unsigned int x,unsigned int y) // where x is the row and y is the colum of the LCD Xrang(0-1) Yrang(1-16)
//{
//	int i;
//  if (x==0)
//	{ lcd_cmd(0X80); //access the first line of the LCD
//    delay_ms(2);
//	}
//  else
//	{
//	  lcd_cmd(0XC1); // access the Second line of the LCD
//    delay_ms(2);
//	}

//  for(i=0;i<y;i++)
//  {
//    lcd_cmd(0X14);
//    delay_ms(2);
//  }
//}

void lcd_cmd(u8 cmd)
{
	GPIO_PORTB_DATA_R=cmd;
	
	GPIO_PORTE_DATA_R=0X08;
	delay_ms(1);
	GPIO_PORTE_DATA_R=0;
	delay_ms(50);
	
	return;
}


void init_lcd (void)              
{
	//to Set function
	lcd_cmd(0x38);
	delay_ms(1);

	//to Set Entry Mode 
	lcd_cmd(0x06);
	delay_ms(1);
	
	//to Display ON OFF Control
	lcd_cmd(0x0F);
	delay_ms(1);
	
	
	//to Clear Display
	lcd_cmd(0x01);
	delay_ms(2);
	
	
	//to Return Home
	lcd_cmd(0x02);
	delay_ms(2);
	
	
	return;
}

