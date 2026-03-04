/*
 * Interruput_num.h
 *
 * Created: 10/10/2025 11:08:37 AM
 *  Author: HASSAN
 */ 


#ifndef INTERRUPUT_NUM_H_
#define INTERRUPUT_NUM_H_

#define ISR(__vector_NUM)           void __vector_NUM(void) __attribute__((signal));\
                                   void  __vector_NUM(void)



//Vector Table
#define _INT_0          __vector_1
#define _INT_1          __vector_2
#define _INT_2          __vector_3
#define TIMER2_COMP    __vector_4
#define TIMER2_OVF     __vector_5
#define TIMER1_CAPT    __vector_6
#define TIMER1_COMPA   __vector_7
#define TIMER1_COMPB   __vector_8
#define TIMER1_OVF     __vector_9
#define TIMER0_COMP    __vector_10
#define TIMER0_OVF     __vector_11
#define SPI_STC        __vector_12
#define USART_RXC      __vector_13
#define USART_UDRE     __vector_14
#define USART_TXC      __vector_15
#define ADC            __vector_16
#define EE_RDY         __vector_17
#define ANA_COMP       __vector_18
#define TWI            __vector_19
#define SPM_RDY        __vector_17


#endif /* INTERRUPUT_NUM_H_ */