/*
 * TIM1_prog.c
 *
 * Created: 11/8/2025 10:18:25 AM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/Interruput_num.h"
#include "TIM1_reg.h"
#include "TIM1_config.h"
#include "TIM1_interface.h"


void TIM1_voidFastPWM_ICR1(){
	//select prescaler
	TCCR1B_REG &=0b11111000;
	TCCR1B_REG |=TIM1_PRESCALER  ;
	//select mode
	CLR_BIT(TCCR1A_REG,0);
	SET_BIT(TCCR1A_REG,1);
	SET_BIT(TCCR1B_REG,3);
	SET_BIT(TCCR1B_REG,4);
	//non inverting mode
	CLR_BIT(TCCR1A_REG,6);
	SET_BIT(TCCR1A_REG,7);
	//set top val
	ICR1_REG=TOP_val; }
	
	
	
	void TIM1_voidSetOcrVal(u16 copy_u16val) {
		//set OCR VAl
		OCR1A_REG=copy_u16val;
		
	}
	
	
	void TIM1_voidSetOcr1B(u16 copy_u16val) {
		OCR1B_REG = copy_u16val;
	}
	
	void TIM1_voidOverFlowInit(){
		//select prescaler
		TCCR1B_REG &=0b11111000;
		TCCR1B_REG |=TIM1_PRESCALER  ;
		//select mode OF mode
		CLR_BIT(TCCR1A_REG,0);
		CLR_BIT(TCCR1A_REG,1);
		CLR_BIT(TCCR1B_REG,3);
		CLR_BIT(TCCR1B_REG,4);
		
	}
	
	
	
	u16 TIM1_u16voidReadVal(){
		return TCNT1_REG;
			
	}
	
	
	
void TIM1_voidReset(){
	TCNT1_REG=0x0000;	
		
	}
	
