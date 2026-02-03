#include <stdio.h>
#include "i2c.h"

void i2c_gpio_init()
{
        //Enable clocks
	RCC_APB2ENR |=(1<<3); //Enabling clock for portB
	RCC_APB2ENR |= (1 << 0); //Enabling AFIO for routing
	RCC_APB1ENR |=(1<<21); //Enabling clock for i2c1 peripheral	

	//Configuring pins PB6 and PB7  as Alternal function, open drain,upto 50MHz
	//SCL(PB6) and SDA(PB7)  //CNF - 11 altenate function output open-drain
     		//Mode - output speed 10 2Mhz, 01 10Mhz, 11 50Mhz
	GPIOB_CRL &= ~((0xF<<24)|(0xF<<28)); //Clear older bits
	GPIOB_CRL |= ((0xB<<24)|(0xB<<28));  //setting bits

}

void i2c_config_init()
{
	RCC_APB1ENR |= (1<<21);
	//Reset and setting the i2c1 peripheral
	I2C1_CR1 |=  (1<<15);  //SWRST
        I2C1_CR1 &= ~(1<<15);	

//	RCC_APB1RSTR |= (1<<21); //Reset i2c peripheral
//	RCC_APB1RSTR &=~(1<<21);  //Release from reset

	//i2c config
	I2C1_CR1 &= ~(1<<0);  //PE=0
	I2C1_CR2 = 36; //APB1 frequency
	I2C1_CCR = 180;
	I2C1_TRISE = 37;
	I2C1_CR1 |= (1<<10);  //ACK=1
	I2C1_CR1 |= (1<<0);   //PE=1
}



