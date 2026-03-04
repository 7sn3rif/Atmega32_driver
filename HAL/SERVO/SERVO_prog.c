/*
 * SERVO_prog.c
 *
 * Created: 12/11/2025 4:53:37 AM
 *  Author: LENOVO
 */ 
/*
 * SERVO_prog.c
 *
 * Created: 12/11/2025 4:53:37 AM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM0/TIM0_config.h"
#include "../../MCAL/TIM0/TIM0_interface.h"
#include "../../MCAL/TIM1/TIM1_config.h"
#include "../../MCAL/TIM1/TIM1_interface.h"
#include "Servo_config.h"
#include "SERVO_interface.h"

static  u8 current_angle[4]={0};//oc0,oc1a,oc1b,oc2

void SERVO_voidInit(u8 copy_u8port,u8 copy_u8pin){
	
	if (copy_u8port==DIO_PORTB&& copy_u8pin==DIO_PIN1)//oc0
	{
		DIO_voidSetPinDir(DIO_PORTB,DIO_PIN1,OUTPUT);
	}
	if (copy_u8port==DIO_PORTD&& copy_u8pin==DIO_PIN5)//oc1a
	{
		DIO_voidSetPinDir(DIO_PORTD,DIO_PIN5,OUTPUT);
		TIM1_voidFastPWM_ICR1();
	}
	if (copy_u8port==DIO_PORTD&& copy_u8pin==DIO_PIN4)//oc1b
	{
		DIO_voidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT);
		TIM1_voidFastPWM_ICR1();
	}
	if (copy_u8port==DIO_PORTD&& copy_u8pin==DIO_PIN7)//oc2
	{
		DIO_voidSetPinDir(DIO_PORTD,DIO_PIN7,OUTPUT);
	}
}




void SERVO_voidSetAngle(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8angle){
	
	float ratio = (copy_u8angle-MIN_ANGLE)*1.0/(MAX_ANGLE-MIN_ANGLE);

	if (copy_u8port==DIO_PORTB&& copy_u8pin==DIO_PIN1)//oc0)
	{
		u8 dc = MIN_DC + (ratio * (MAX_DC - MIN_DC));
		TIM0_voidPWM(dc, FastPWM_MODE);
		current_angle[0]=copy_u8angle;
	}
	if (copy_u8port==DIO_PORTD&& copy_u8pin==DIO_PIN5)//oc1a
	{ 
		u16 Ocr_val = MIN_OCR1 + (ratio * (MAX_OCR1 - MIN_OCR1));
		TIM1_voidSetOcrVal(Ocr_val);
		current_angle[1]=copy_u8angle;
	}
	if (copy_u8port==DIO_PORTD&& copy_u8pin==DIO_PIN4)//oc1b
	{ 
		u16 Ocr_val = MIN_OCR1 + (ratio * (MAX_OCR1 - MIN_OCR1));
		TIM1_voidSetOcr1B(Ocr_val);
		current_angle[2]=copy_u8angle;
	}
	//add oc2 when you write tim2 driver	
}



void SERVO_MapAngle(u8 copy_u8port,u8 copy_u8pin, u8 InputVal, u8 MinInput , u8 MaxInput ){
	u8 angle=0;
	float ratio = (InputVal - MinInput) * 1.0 / (MaxInput - MinInput);
	angle = MIN_ANGLE + (ratio * (MAX_ANGLE - MIN_ANGLE));

	SERVO_voidSetAngle(copy_u8port,copy_u8pin,angle);  
}



u8 SERVO_u8ReadAngle(u8 Servo_index){
	
	return current_angle[Servo_index];
}
