#include "ports_init.c"
#include "delay.c"

extern int k;
unsigned const char symbol[4][4] = {{ '1', '2',  '3', 'A'},      
                                    { '4', '5',  '6', 'B'},      
                                    { '7', '8',  '9', 'C'},      
                                    { '.', '0',  '#', 'D'}}; 
char keypad_getkey(void)
{
  while(1)
  {  
int i;
    for( i=0; i < 4; i++)                        
    {
			int j;
			k=i+4;
      GPIO_PORTA_DATA_R = (1U <<k);
      delay_ms(20);
      for(j = 0; j < 4; j++)                  
      {
        if((GPIO_PORTD_DATA_R & 0x0F) & (1U <<j))
          return symbol[j][i];
      }
    }
  }
}
