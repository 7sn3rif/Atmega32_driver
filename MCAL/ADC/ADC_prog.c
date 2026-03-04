/*
* ADC_prog.c
*
* Created: 10/17/2025 9:50:32 AM
* Author: HASSAN ARIF
*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"

#include "ADC_reg.h"
#include "ADC_interface.h"

void ADC_voidInit(){
	SET_BIT(ADMUX_REG,6);
	CLR_BIT(ADMUX_REG,7);
	ADCSRA_REG &= 0b11111000;
	ADCSRA_REG |= ADC_PRESCALER;
	SET_BIT(ADCSRA_REG,7);
}

u16 ADC_u16ReadChannel(u8 copy_u8channel){
	ADMUX_REG &= 0b11100000;
	ADMUX_REG |= copy_u8channel;
	SET_BIT(ADCSRA_REG,6);
	while(GET_BIT(ADCSRA_REG,4)==0);
	CLR_BIT(ADCSRA_REG,4);
	return ADC_REG;
}
