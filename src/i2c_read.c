#include <stdint.h>
#include "i2c.h"

#define I2C1_CR1_START  (1<<8)
#define I2C1_CR1_STOP   (1<<9)

#define I2C1_SR1_SB    (1<<0) 
#define I2C1_SR1_TXE   (1<<7)
#define I2C1_SR1_BTF   (1<<2)
#define I2C1_SR1_ADDR  (1<<1)

#define SLAVE_ADDR  0x76

int i2c_read(uint8_t addr, uint8_t reg)
{
	uint8_t data;
	volatile uint32_t temp;
	//Wait until busy is free
	while (I2C1_SR2 & (1<<1));   // BUSY bit=0, means free else BUSY=1 means busy

	I2C1_CR1 |= I2C1_CR1_START;  //generate start bit, step-1
	//wait until the start bit is generated, when start bit is generated then SB is set to 1  
	while(!(I2C1_SR1 & I2C1_SR1_SB));  //Checking if SB=1 then we can write address, as bus is ready, step-2

	//Writing the slave address and shifting to 1 to add read/write bit. As address is from MSB to LSB last bit is read/write bit
	I2C1_DR = SLAVE_ADDR<<1; //step-3
	while(!(I2C1_SR1 & I2C1_SR1_ADDR)); //Checking if address is written and acknowledgement is received. If acknowledgement is received that means I2C_SR1_ADDR bit is set to 1. So it will wait for next byte //step-4
	
//Here we are clearing the I2C_SR1_ADDR bit to continue next further write or generate STOP condition 
	temp = I2C1_SR1; //Here reading SR1 first //step-5
	temp = I2C1_SR2;  //Here reading SR2 next. ADDR flag is now cleared
	(void)temp;	//The act of reading SR2 after SR1 clears the ADDR flag automatically

        I2C1_DR=reg;    //step -6 Write register address
	while(!(I2C1_SR1 & I2C1_SR1_TXE)); //Wait until data buffer is empty

        I2C1_CR1 |= I2C1_CR1_START; //Repeated start of the i2c
	while(!(I2C1_SR1 & I2C1_SR1_SB)); //Checking if SB=1 then we can write address, as bus is ready,step-6 

	I2C1_DR = (addr << 1)|1; //send slave address+read bit
	while(!(I2C1_SR1 & I2C1_SR1_ADDR));

	/*Disable ACK(single byte read)*/
	I2C1_CR1 &= ~(1<<10); //Ack=0;
	
	temp = I2C1_SR1;
    	temp = I2C1_SR2;
    	(void)temp;

	I2C1_CR1 |= I2C1_CR1_STOP; //set stop condition , step-10
	
	//wait for data
	while(!(I2C1_SR1 & (1<<6))); //RXNE
	data=I2C1_DR;     //Read data

	return data;
}


/* I2C Concept(bare-metal view)
 * Both read and write:
 * START
 * send slave address + W
 * send register address
 * RESTART
 * send slave address + R
 * Read data
 * STOP
 *
 * WRITE means:
 * START
 * Slave address+W
 * register address
 * Data byte
 * STOP
 *
 * READ means:
 * START
 * Slave address+W
 * Register address
 * RESTART
 * Slave address+R
 * Read data
 * STOP

###Write breakdown
Mapping to STM32 I2C registers:
START
ADDR+W
ADDR flag
reg addr
data
STOP

###Read breakdown
RESTART
ADDR+R
RXNE flag
read DR
STOP

###Read means:
START
SlaveAddr + W
ACK
Register address
ACK
REPEATED START
SlaveAddr + R
ACK
Read data
NACK
STOP
*/
