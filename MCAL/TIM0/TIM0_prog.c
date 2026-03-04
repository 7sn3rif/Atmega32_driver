#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/Interruput_num.h"
#include "TIM0_reg.h"
#include "TIM0_config.h"
#include "TIM0_interface.h"


void(*TIM0_PTR[2])(void) = {null};

void TIM0_voidInit(u8 copy_u8_mode){
	/*set prescaler */
	TCCR0_REG &= 0b11111000;
	TCCR0_REG |= TIM0_PRESCALER;

	switch(copy_u8_mode){
		case OV_MODE:
		/*select mode : normal mode */
		CLR_BIT(TCCR0_REG, 3);
		CLR_BIT(TCCR0_REG, 6);
		/*enable overflow interrupt */
		SET_BIT(TIMSK_REG, 0);
		break;

		case CTC_MODE:
		/*select mode : CTC mode */
		SET_BIT(TCCR0_REG, 3);
		CLR_BIT(TCCR0_REG, 6);
		/*enable overflow interrupt */
		SET_BIT(TIMSK_REG, 1);
		/*SET OCR_VAL*/
		OCR0_REG = OCR_VAL;
		break;
	}
}

void TIM0_voidSetCallBack(void(*ptr)(void), u8 copy_u8_mode){
	switch(copy_u8_mode){
		case OV_MODE:
		TIM0_PTR[0] = ptr;
		break;

		case CTC_MODE:
		TIM0_PTR[1] = ptr;
		break;
	}
}


ISR(TIMER0_OVF){
	TIM0_PTR[0]();
}

ISR(TIMER0_COMP){
	TIM0_PTR[1]();
}




void  TIM0_voidPWM(u8 copy_u8dc, u8 copy_u8mode){
	
	/*set prescaler */
	TCCR0_REG &= 0b11111000;
	TCCR0_REG |= TIM0_PRESCALER;
	   switch  (copy_u8mode){
	   /*fast pwm mode*/
	   case FastPWM_MODE:
	SET_BIT(TCCR0_REG, 3);
	SET_BIT(TCCR0_REG, 6); 
	/*non inverting mode*/
    SET_BIT(TCCR0_REG, 5);
    CLR_BIT(TCCR0_REG, 4); 
	/*set ocr_val
	dc = ocr / 2^res
	ocr = dc *2^res
res=8
ocr = dc*255/100*
	*/
	 OCR0_REG=copy_u8dc*2.55;
    break; 
	
	  case  P_C_PWM_MODE :
	CLR_BIT(TCCR0_REG, 3);
	SET_BIT(TCCR0_REG, 6);
	/*non inverting mode*/
	SET_BIT(TCCR0_REG, 5);
	CLR_BIT(TCCR0_REG, 4); 
/*set ocr_val
	dc = ocr / 2^res
	ocr = dc *2^res
res=8
ocr = dc*255/100*
	*/
	OCR0_REG=copy_u8dc*2.55;
    break;
	
	
	
	}
		
	
} 