/*
 * ADC_reg.h
 *
 * Created: 10/16/2025 11:38:45 PM
 *  Author:HASSAN ARIF
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_



/**ADC REGISTERS*/

#define ADMUX_REG    (*((volatile u8*)0x27))
#define ADCSRA_REG   (*((volatile u8*)0x26))
#define ADC_REG      (*((volatile u16*)0x24))//adch+adcl

#define SFIOR_REG    (*((volatile u8*)0x50))   // for auto trigger source


#endif /* ADC_REG_H_ */