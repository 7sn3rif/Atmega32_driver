/*
 * Dc_Motor_interface.h
 *
 * Created: 11/7/2025 10:41:00 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_
void DC_Motor_voidInit();

void DC_Motor_voidForward(u8 copy_u8_speed);

void DC_Motor_voidReverse(u8 copy_u8_speed);

void DC_Motor_voidRight(u8 copy_u8_speed);

void DC_Motor_voidLeft(u8 copy_u8_speed);

void DC_Motor_voidStop(u8 copy_u8_speed);





#endif /* DC_MOTOR_INTERFACE_H_ */