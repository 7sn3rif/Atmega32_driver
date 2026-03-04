/*
 * main.c
 * Project: Controlling a robotic arm via DT-06 WIFI module
 * Author : HASSAN ARIF
 * Date   : 24/12/2025
 */


#include "main.h"
#define F_CPU 16000000UL
#include <util/delay.h>


void AUTO_MODE(){
	// Sweep forward
	for (u8 a = 0; a <= 180; a++) {
		PCA9685_voidWriteAngle(0, a);
		_delay_ms(15);   // give servo time to move
	}

	// Sweep backward
	for (u8 a = 180; a > 0; a--) {
		PCA9685_voidWriteAngle(0, a);
		_delay_ms(15);
	}
	//a better auto mode will be with an ultra sonic and object sensor...etc
}
void MoveServoSmooth(u8 servoNum, u16 targetAngle){
	// current angle
	u8 current = PCA9685_u8ReadAngle(servoNum);
	
	if(current < targetAngle){
		for(u8 a = current + 1; a <= targetAngle; a++){
			PCA9685_voidWriteAngle(servoNum, a);
			_delay_ms(10);
		}
		} else {
		for(u8 a = current - 1; a >= targetAngle; a--){
			PCA9685_voidWriteAngle(servoNum, a);
			_delay_ms(10);
			if(a == 0) break; 
		}
	}
}

int main(void)
{
	WIFI_voidInit();
	PCA9685_voidInit();

	// Home position  1–4
	for(u8 i = 0; i < 4; i++){
		PCA9685_voidWriteAngle(i, 90);
		_delay_ms(10);
	}

	while(1)
	{
		u8 c = WIFI_voidReceiveData();

		if(c == 'S')
		{
			u8 servoNum = WIFI_voidReceiveData() - '0'; 
			u16 angle = WIFI_u16ReceiveNumber();       

			
			if(servoNum >= 1 && servoNum <= 4 && angle <= 180){
				MoveServoSmooth(servoNum - 1, angle);
				_delay_ms(10); 
			}
		}
		else if(c == 'A')
		{
			AUTO_MODE();
		}
		else
		{
			

			// do nothing
		}
}

}