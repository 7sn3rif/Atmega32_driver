/*
 * GI_prog.c
 *
 * Created: 9/27/2025 10:40:12 AM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "GI_reg.h"
#include "GI_interface.h"
void GI_voidEnable(){
	
	SET_BIT(SREG_REG,7);
	
	
	
}
void GI_voidDisable(){
	
	CLR_BIT(SREG_REG,7);
	
	
	
}