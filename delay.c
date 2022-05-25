
#include "headr.h"
#include "stdint.h"

void delay_micro(int n)  //Delay function in Micro Seconds
{

		int i,j;

		for(i=0;i<n;i++)

		for(j=0;j<3;j++){}

}


void intialisation_timer()
{
  NVIC_ST_CTRL_R =0;
  NVIC_ST_RELOAD_R =0xFFFFFFFF;
  NVIC_ST_CURRENT_R =0;
  NVIC_ST_CTRL_R =0X00000005;
}



void wait_10ms(int delay)
{
  NVIC_ST_RELOAD_R=delay-1;
  NVIC_ST_CURRENT_R =0;
  while((NVIC_ST_CTRL_R&0X00010000)==0);
}


void delay_ms(int delay)
{
  int i;
  for(i=0;i<delay;i++)
  {
    wait_10ms(16000);
  }
}
	
//void delay_ms(int t) // Milli seconds delay function
//{
//	int i;
//	int j;
//	for(i=0 ; i<t ; i++)
//	{
//		for(j=0; j<3180; j++)
//		{
//			
//		}
//	}
//}

