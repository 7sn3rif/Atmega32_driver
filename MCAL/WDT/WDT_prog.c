/*
 * WDT_prog.c
 *
 * Created: 11/14/2025 12:38:45 PM
 *  Author: HASSAN ARIF
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"

#include "WDT_reg.h"
#include "WDT_interface.h"

void WDT_voidStart(u8 copy_u8time){
	/*select prescaler*/
	WDTCR_REG &= 0b11111000;
	WDTCR_REG |= WDT_PRESCALER;
	/*enable WDT*/
	CLR_BIT(WDTCR_REG,4);
	SET_BIT(WDTCR_REG,3);
}

void WDT_voidStop(){
	/*disable WDT*/
	WDTCR_REG |= (1<<4) | (1<<3);//write 1to the 2 bits
	
	CLR_BIT(WDTCR_REG,3);
	
	
}