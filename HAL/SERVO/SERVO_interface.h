/*
 * SERVO_interface.h
 *
 * Created: 12/11/2025 4:53:13 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

void SERVO_voidInit(u8 copy_u8port,u8 copy_u8pin);// select PWMs pins 
void SERVO_voidSetAngle(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8angle);
void SERVO_MapAngle(u8 copy_u8port,u8 copy_u8pin,u8 InputVal, u8 MinInput , u8 MaxIput );
u8   SERVO_u8ReadAngle(u8 Servo_index);



#endif /* SERVO_INTERFACE_H_ */