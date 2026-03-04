/*
 * TIM1_reg.h
 *
 * Created: 11/8/2025 10:17:05 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef TIM1_REG_H_
#define TIM1_REG_H_


#define TCCR1A_REG      *((volatile  u8*)0x4F)
#define TCCR1B_REG      *((volatile  u8*)0x4E)
#define OCR1A_REG       *((volatile  u16*)0x4A) // OCR1AH_REG + OCR1AL_REG
#define OCR1B_REG       *((volatile  u16*)0x48) // OCR1BH_REG + OCR1BL_REG
#define ICR1_REG        *((volatile  u16*)0x46) // ICRL_REG + ICRH_REG
#define TIFR_REG        *((volatile  u8*)0x58)
#define TCNT1_REG       *((volatile  u16*)0x4C)
#define TIMSK_REG       *((volatile  u8*)0x59)


#endif /* TIM1_REG_H_ */