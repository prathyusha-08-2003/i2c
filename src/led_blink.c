#include <stdint.h>
#include "gpio.h"
#include "timer.h"

/*Intializing clock, mode, CNF, port C*/
void gpio_init()
{
        //Enable Clock
        RCC_APB2ENR_CLK |= (1<<4);
        GPIOC_CRH &= ~(0xF << 20);  //clear bits for 20:23
        GPIOC_CRH |=  (0x1 << 20);  //setting bits 20:23 to mode 01 , CNF (push-pull)
}
