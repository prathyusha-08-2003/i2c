/*
 * gpio_pc13.h
 *
 *  Created on: Dec 12, 2025
 *      Author: bokkala
 */

#ifndef _TIMER_H_
#define _TIMER_H_

#define RCC_CLK_addr              (*(volatile uint32_t *)0x40021000)
#define TIM2_BASE_addr            (*(volatile uint32_t *)0x40000000)     
#define RCC_APB1ENR_addr          (*(volatile uint32_t*)0x01C)

#define TIMx_CR1_offset                 (*(volatile uint32_t *)0x00)  /*Control register*/
#define TIMx_CNT_offset                 (*(volatile uint32_t *)0x24)  /*Counter register*/
#define TIMx_PSC_offset                 (*(volatile uint32_t *)0x28)  /*prescaler*/
#define TIMx_ARR_offset                 (*(volatile uint32_t *)0x2C)  /*auto reload return*/
#define TIMx_SR_offset                  (*(volatile uint32_t *)0x10)   /*status register*/

#define RCC_APB1ENR_CLK           (*(volatile uint32_t *)0x4002101C)
#define TIM2_CR1_addr             (*(volatile uint16_t *)0x40000000)  /*Control register*/
#define TIM2_CNT_addr             (*(volatile uint16_t *)0x40000024)  /*Counter register*/
#define TIM2_PSC_addr             (*(volatile uint16_t *)0x40000028)  /*prescaler*/
#define TIM2_ARR_addr             (*(volatile uint16_t *)0x4000002C)  /*auto reload return*/
#define TIM2_SR_addr              (*(volatile uint16_t *)0x40000010)   /*status register*/
#define TIM2_EGR_addr (*(volatile uint16_t *)0x40000014)

void delay();
void delay_one();

#endif 
