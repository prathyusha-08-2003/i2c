#include <stdio.h>
#include "gpio.h"
#include "uart.h"

void send_char(char c)
{
    //Reset value=0xC0
    while(!(MY_USART1->SR & USART1_SR_TXE)); //Trasmit Register is empty,Can transmit data //empty loop
    MY_USART1->DR=c;
}

void usart_init()
{

    RCC_APB2ENR_CLK |= (1<<14);  //Setting clock for usart1 
    RCC_APB2ENR_CLK |= (1<<2);  //setting clock for portA
    /*using PA9 usart tx and PA10 as usart rx pins*/

    GPIOA_CRH_off &= ~(0xF << 4);             //clearing the PA9
    GPIOA_CRH_off |=  (0xB << 4);             //setting to mode 11 output high speed and CNF to altenate and push pull  
     /*USART1 TX=alternate function output*/        /*USART1 RX=input floating or input pull up*/
    GPIOA_CRH_off &= ~(0xF << 8);             //clearing PA10
    GPIOA_CRH_off |= (0x4 << 8);            //setting to mode 01 as floating input and CNF 00
    
//    MY_USART1->BRR = 0x45; //working for 115200 baudrate
    MY_USART1->BRR = 0x341; //baudrate 9600
    MY_USART1->CR1 = 0;  //clear first
    MY_USART1->CR1 |= (1<<13); //Enable uart
    MY_USART1->CR1 |= (1<<3);  //Enable transmitter
    MY_USART1->CR1 |= (1<<2);  //ENble Receiver

} 


