/*
 * gpio.h
 *
 *  Created on: Dec 6, 2025
 *      Author: bokkala
 */

#ifndef GPIO_H_
#define GPIO_H_

#define GPIOA_addr           (*(volatile uint32_t *)0x40010800)
//#define GPIOB                (*(volatile uint32_t *)0x40010C00)
#define GPIOC                (*(volatile uint32_t *)0x40011000)
#define RCC_CLK              (*(volatile uint32_t *)0x40021000)     

#define RCC_APB2_off        0x018 
#define GPIO_CRL_off        0x00
#define GPIO_CRH_off        0x04
#define GPIO_IDR_off        0x08
#define GPIO_ODR_off        0x0C

#define RCC_APB2ENR_CLK      (*(volatile uint32_t *)0x40021018)
#define GPIOC_CRH        (*(volatile uint32_t *)0x40011004)
#define GPIOC_ODR        (*(volatile uint32_t *)0x4001100C)

#define GPIOA_CRH_off        (*(volatile uint32_t *)0x40010804)   //0x40010800 + 0x04

void gpio_init();

#endif /* GPIO_PC13_H_ */
