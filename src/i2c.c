#include <stdio.h>
#include "i2c.h"

volatile RCC_TypeDef* const RCC = (volatile RCC_TypeDef* const)0x40021000;
volatile GPIO_TypeDef* const GPIOB = (volatile GPIO_TypeDef* const)0x40010C00;
volatile I2C_TypeDef* const I2C1 = (volatile I2C_TypeDef* const)0x40005400;

void i2c_gpio_init()
{
        //Enable clocks
	RCC->APB2ENR |=(1<<3); //Enabling clock for portB
	RCC->APB2ENR |=(1<< 0); //Enabling AFIO for routing
	RCC->APB1ENR |=(1<<21); //Enabling clock for i2c1 peripheral	

	//Configuring pins PB6 and PB7  as Alternal function, open drain,upto 50MHz
	//SCL(PB6) and SDA(PB7)  //CNF - 11 altenate function output open-drain
     		//Mode - output speed 10 2Mhz, 01 10Mhz, 11 50Mhz
	GPIOB->CRL &= ~((0xF<<24)|(0xF<<28)); //Clear older bits
	GPIOB->CRL |= ((0xB<<24)|(0xB<<28));  //setting bits

}

void i2c_config_init()
{
	RCC->APB1ENR |= (1<<21);
	//Reset and setting the i2c1 peripheral
	I2C1->CR1 |=  (1<<15);  //SWRST
        I2C1->CR1 &= ~(1<<15);	

//	RCC_APB1RSTR |= (1<<21); //Reset i2c peripheral
//	RCC_APB1RSTR &=~(1<<21);  //Release from reset

	//i2c config
	I2C1->CR1 &= ~(1<<0);  //PE=0
	I2C1->CR2 = 36; //APB1 frequency
	I2C1->CCR = 180;
	I2C1->TRISE = 37;
	I2C1->CR1 |= (1<<10);  //ACK=1
	I2C1->CR1 |= (1<<0);   //PE=1
}



