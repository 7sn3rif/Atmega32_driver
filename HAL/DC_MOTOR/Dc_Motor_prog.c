/*
 * Dc_Motor_prog.c
 *
 * Created: 11/7/2025 10:41:32 AM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIM0/TIM0_config.h"
#include "../../MCAL/TIM0/TIM0_interface.h"
#include "Dc_Motor_config.h"
#include "Dc_Motor_interface.h"
void DC_Motor_voidInit(){
	DIO_voidSetPinDir(DC_Motor_Port,DC_Motor_IN1_Pin,OUTPUT);
	DIO_voidSetPinDir(DC_Motor_Port,DC_Motor_IN2_Pin,OUTPUT);
	DIO_voidSetPinDir(DC_Motor_Port,DC_Motor_IN3_Pin,OUTPUT);
	DIO_voidSetPinDir(DC_Motor_Port,DC_Motor_IN4_Pin,OUTPUT);
	DIO_voidSetPinDir(DC_Motor_Port,DC_Motor_EN_Pin,OUTPUT);
	
	
	
}
void DC_Motor_voidForward(u8 copy_u8_speed){
	TIM0_voidPWM(copy_u8_speed,FastPWM_MODE);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN1_Pin,HIGH);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN2_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN3_Pin,HIGH);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN4_Pin,LOW);
	
	
}
void DC_Motor_voidReverse(u8 copy_u8_speed){
	TIM0_voidPWM(copy_u8_speed,FastPWM_MODE);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN1_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN2_Pin,HIGH);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN3_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN4_Pin,HIGH);
	
	
}
void DC_Motor_voidRight(u8 copy_u8_speed){
	TIM0_voidPWM(copy_u8_speed,FastPWM_MODE);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN1_Pin,HIGH);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN2_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN3_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN4_Pin,LOW);
	
	
}
void DC_Motor_voidLeft(u8 copy_u8_speed){
	TIM0_voidPWM(copy_u8_speed,FastPWM_MODE);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN1_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN2_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN3_Pin,HIGH);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN4_Pin,LOW);

	
}
void DC_Motor_voidStop(u8 copy_u8_speed){
	TIM0_voidPWM(copy_u8_speed,FastPWM_MODE);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN1_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN2_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN3_Pin,LOW);
	DIO_voidSetPinVal(DC_Motor_Port,DC_Motor_IN4_Pin,LOW);

	
}