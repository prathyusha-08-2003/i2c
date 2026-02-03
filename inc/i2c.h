#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

#define GPIOB  (*(volatile uint32_t*)0x40010C00)
#define RCC_CLK     (*(volatile uint32_t *)0x40021000)
#define AFIO    (*(volatile uint32_t *)0x40010000)

#define RCC_APB2ENR      (*(volatile uint32_t *)0x40021018) //GPIOB
#define RCC_APB1ENR      (*(volatile uint32_t *)0x4002101C)  //I2C
#define RCC_APB1RSTR  (*(volatile uint32_t *)0x40021010)

#define RCC_APB2_offset             0x18
#define RCC_APB1_offset             0x1C
#define RCC_APB1RSTR_offset         0x10

#define GPIO_CRL_off        0x00
#define GPIO_CRH_off        0x04
#define GPIO_IDR_off        0x08
#define GPIO_ODR_off        0x0C

#define GPIOB_CRL        (*(volatile uint32_t *)0x40010C00)
#define GPIOB_CRH        (*(volatile uint32_t *)0x40010C04)
#define GPIOB_IDR        (*(volatile uint32_t *)0x40010C08)
#define GPIOB_ODR        (*(volatile uint32_t *)0x40010C0C)

#define I2C1_Peripheral   (*(volatile uint32_t *)0x40005400)

#define I2C_CR1_off        0x00
#define I2C_CR2_off        0x04
#define I2C_CCR_off        0x1C
#define I2C_TRISE_off      0x20

#define I2C1_CR1        (*(volatile uint32_t *)0x40005400)
#define I2C1_CR2        (*(volatile uint32_t *)0x40005404)
#define I2C1_CCR        (*(volatile uint32_t *)0x4000541C)
#define I2C1_TRISE      (*(volatile uint32_t *)0x40005420)
#define I2C1_DR        (*(volatile uint32_t *)0x40005410)

#define I2C_SR1_off          0x14
#define I2C_SR2_off          0x18
#define I2C_DR               0x10

#define I2C1_SR1    (*(volatile uint32_t *)0x40005414)
#define I2C1_SR2    (*(volatile uint32_t *)0x40005418)
	
void i2c_gpio_init();
void i2c_config_init();
void i2c_write(uint8_t addr, uint8_t reg, uint8_t data);
int i2c_read(uint8_t addr, uint8_t reg);

#endif
