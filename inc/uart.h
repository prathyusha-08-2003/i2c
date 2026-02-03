#ifndef UART_H_
#define UART_H_
/* Here  Each uint32_t is 4 Bytes*/
typedef struct
{
    volatile uint32_t SR;          // offset 0x00
    volatile uint32_t DR;          // offset 0x04
    volatile uint32_t BRR;         // offset 0x08
    volatile uint32_t CR1;         // offset 0x0C
    volatile uint32_t CR2;         // offset 0x10
    volatile uint32_t CR3;         // offset 0x14
    volatile uint32_t GTPR;        // offset 0x18

}USART_Regs;

#define MY_USART1  ((USART_Regs *)0x40013800)   //Here USART_Regs is a pointer pointing to the structure USART_Regs

/* So I use a -> operator to write value to the pointer and first pointer is pointing to */
/*This is a mask value.The value of this register is not known if it is 1 then we can write data if it is zero then it is busy in transmitting */

#define USART1_SR_TXE (1 << 7)  

void usart_init();
void send_char(char c);

#endif

