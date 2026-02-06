#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

/*======= RCC =======*/

//#define  RCC_CLK_BASE      0x40021000UL

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
}RCC_TypeDef;

extern volatile RCC_TypeDef* const RCC;
//#define RCC   ((RCC_TypeDef *) RCC_CLK_BASE)

/*===== GPIO =====*/
//#define    GPIOB_BASE       0x40010C00UL

typedef struct
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;

extern volatile GPIO_TypeDef* const GPIOB;
//#define GPIOB   ((GPIO_TypeDef *) GPIOB_BASE)

/*===== I2C =====*/

//#define   I2C1_BASE    0x40005400UL

typedef struct
{
    volatile uint32_t CR1;   // 0x00
    volatile uint32_t CR2;   // 0x04
    volatile uint32_t OAR1;  // 0x08
    volatile uint32_t OAR2;  // 0x0C
    volatile uint32_t DR;    // 0x10
    volatile uint32_t SR1;   // 0x14
    volatile uint32_t SR2;   // 0x18
    volatile uint32_t CCR;   // 0x1C
    volatile uint32_t TRISE; // 0x20
} I2C_TypeDef;

extern volatile I2C_TypeDef* const I2C1;
//#define I2C1   ((I2C_TypeDef *) I2C1_BASE)

/* ========== Bit definitions ========= */

#define I2C1_CR1_START   (1U << 8)
#define I2C1_CR1_STOP    (1U << 9)

#define I2C1_SR1_SB      (1U << 0)
#define I2C1_SR1_ADDR    (1U << 1)
#define I2C1_SR1_BTF     (1U << 2)
#define I2C1_SR1_TXE     (1U << 7)
#define I2C_CR1_ACK      (1U << 10)

/* ======= Function prototypes ======== */

#define AFIO    (*(volatile uint32_t *)0x40010000)
	
void i2c_gpio_init();
void i2c_config_init();
void i2c_write(uint8_t addr, uint8_t reg, uint8_t data);
int i2c_read(uint8_t addr, uint8_t reg);

#endif
