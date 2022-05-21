#include "lcd.h"
#include "headr.h"
#include "stdint.h"
#include "stdio.h"

//For printing a character on the LCD
//void lcd_write(u8 data)
//{
//	GPIO_PORTB_DATA_R=data;
//	GPIO_PORTE_DATA_R=0X0A;
//	delay_ms(1);
//	GPIO_PORTE_DATA_R=0X01;
//	delay_ms(50);
//	
//	return;
//}


//For printing a string on the LCD
void lcd_print(u8 *str)  
 {
	int		i=0;
	while(str[i]!='\0')
	{
		lcd_write(str[i]);
		i++;
		
	}
	
	delay_ms(100);
	
	return;
}

void lcd_cmd(u8 cmd)
{
	GPIO_PORTB_DATA_R=cmd;
	
	GPIO_PORTE_DATA_R=0X08;
	delay_ms(1);
	GPIO_PORTE_DATA_R=0;
	delay_ms(50);
	
	return;
}

void set_cursor(unsigned int x,unsigned int y)	// where x is the row and y is the colum of the LCD Xrange(0-1) Yrange(0-15)
{
	int i;
  if (x==0)
	{ lcd_cmd(0X80);															//access the first line of the LCD
    delay_ms(2);
	}
  else
	{
	  lcd_cmd(0XC1);															// access the Second line of the LCD
    delay_ms(2);
	}

  for(i=0;i<y;i++)
  {
    lcd_cmd(0X14);
    delay_ms(2);
  }
}



//Initialization of the LCD
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

//For printing integer numbers on the LCD
void LCD_printInt(int no)
{
	int i = 0;
  char toprint[4] = {0};
  sprintf(toprint, "%d", no);
  while(toprint[i] != '\0')
  {
    lcd_write(toprint[i]);
    i++;
  }
}

