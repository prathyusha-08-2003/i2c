#include <stdio.h>
#include "timer.h"

void delay(void)
{
    //Enabling clock for Timer 2
    RCC_APB1ENR_CLK |=(1<<0);  /*Setting the first bit to 1*/

    TIM2_CR1_addr = 0;
    TIM2_CNT_addr = 0;     /*setting the count to 0*/
    TIM2_SR_addr = 0;   /*clearing the status register*/

    TIM2_PSC_addr = 7199;    /*setting prescalet to 72 so it is 72Mhz clock*/
    TIM2_ARR_addr = 999;   /*for 1ms delay it runs from 0 to 999*/
  
    TIM2_CR1_addr |= (1<<0);  /*setting the CEN counter enable bit to count*/
     /*checking if the counting is done if it is 1 then it resets and this flag UIF is set*/
    while ((TIM2_SR_addr & 1)==0) 
    {  
      //   printf("Counting the tick:%d\n",i);
    } 
 //   printf("Time is elapsed\n"); 
    /*clear the flag so that next time if function is called it cannot take previous value*/
    TIM2_SR_addr &= ~(1<<0);
}

void delay_one()
{
   unsigned int i=0,j=0;
   for (i=0;i<10;i++)
   {
    for (j=0;j<60000;j++)
    {

    }
   }
    
}
