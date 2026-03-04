/*
 * UART_reg.h
 *
 * Created: 11/15/2025 12:28:33 PM
 *  Author:HASSAN ARIF
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_


#define UDR_REG     (*(volatile u8*)0x2C) // USART I/O Data Register
#define UCSRA_REG   (*(volatile u8*)0x2B)  // USART Control and Status Register A
#define UCSRB_REG   (*(volatile u8*)0x2A)  // USART Control and Status Register B
#define UBRRL_REG   (*(volatile u8*)0x29)  // USART Baud Rate Register Low
#define UCSRC_REG   (*(volatile u8*)0x40)  // USART Control and Status Register C
#define UBRRH_REG   (*(volatile u8*)0x40)  // Same address as UCSRC, selected by URSEL bit



#endif /* UART_REG_H_ */