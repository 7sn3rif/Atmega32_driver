/*
 * EXTI_prog.c
 *
 * Created: 9/27/2025 11:42:26 AM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/Interruput_num.h"
#include "EXTI_reg.h"
#include "EXTI_interface.h"
  
  
  void (*EXTI0_ptr)()=null;
  void (*EXTI1_ptr)()=null;
  void (*EXTI2_ptr)()=null;
  
  
void EXTI_voidInit(u8 copy_u8sense, u8 copy_u8exti_num) {
	switch (copy_u8exti_num) {
		case INT_0:
		if (copy_u8sense == LOW_LEVEL) {
			CLR_BIT(MCUCR_REG, 0);
			CLR_BIT(MCUCR_REG, 1);
			} else if (copy_u8sense == ANY_LOGICAL_CHANGE) {
			SET_BIT(MCUCR_REG, 0);
			CLR_BIT(MCUCR_REG, 1);
			} else if (copy_u8sense == FALLING_EDGE) {
			CLR_BIT(MCUCR_REG, 0);
			SET_BIT(MCUCR_REG, 1);
			} else if (copy_u8sense == RISING_EDGE) {
			SET_BIT(MCUCR_REG, 0);
			SET_BIT(MCUCR_REG, 1);
		}
		break;

		case INT_1:
		if (copy_u8sense == LOW_LEVEL) {
			CLR_BIT(MCUCR_REG, 2);
			CLR_BIT(MCUCR_REG, 3);
			} else if (copy_u8sense == ANY_LOGICAL_CHANGE) {
			SET_BIT(MCUCR_REG, 2);
			CLR_BIT(MCUCR_REG, 3);
			} else if (copy_u8sense == FALLING_EDGE) {
			CLR_BIT(MCUCR_REG, 2);
			SET_BIT(MCUCR_REG, 3);
			} else if (copy_u8sense == RISING_EDGE) {
			SET_BIT(MCUCR_REG, 2);
			SET_BIT(MCUCR_REG, 3);
		}
		break;

		case INT_2:
		if (copy_u8sense == FALLING_EDGE) {
			CLR_BIT(MCUCSR_REG, 6);
			} else if (copy_u8sense == RISING_EDGE) {
			SET_BIT(MCUCSR_REG, 6);
		}
		break;
	}
}
  
  //EXTI0 funcs
  
   void EXTI0_voidEnable(void){
	  
	  SET_BIT(GICR_REG, 6); // Enable INT0
	 
  }
void EXTI0_voidDisable(void){
	
	CLR_BIT(GICR_REG, 6); // Enable INT1
	
}



//EXTI1 funcs

void EXTI1_voidEnable(void){
	
	SET_BIT(GICR_REG, 7); // Enable INT0
	
}
void EXTI1_voidDisable(void){
	
	CLR_BIT(GICR_REG, 7); // Enable INT1
	
}




//EXTI2 funcs

void EXTI2_voidEnable(void){
	
	SET_BIT(GICR_REG, 5); // Enable INT0
	
}
void EXTI2_voidDisable(void){
	
	CLR_BIT(GICR_REG, 5); // Enable INT1
	
}



// Call back app function
void EXTI_voidCallBack(void(*ptr)(void),u8 copy_u8exti_num){
	switch(copy_u8exti_num){
		case INT_0 : EXTI0_ptr=ptr; break;
		case INT_1 : EXTI1_ptr=ptr; break;
		case INT_2 : EXTI2_ptr=ptr; break;
		default : //do nothing 
		break;
		
		
		
	}
	
	
	
	
}







ISR(_INT_0){
	EXTI0_ptr();
	
}








ISR(_INT_1){
	EXTI1_ptr();
	
}







ISR(_INT_2){
	EXTI2_ptr();
	
}   