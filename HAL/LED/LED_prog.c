/*
 * LED.c
 *
 * Created: 9/11/2025 6:53:57 PM
 *  Author: HASSAN ARIF
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LED_interface.h"
void LED_voidOn(u8 copy_u8_port, u8 copy_u8pin) {
	DIO_voidSetPinDir(copy_u8_port, copy_u8pin, OUTPUT);  // Set pin as output
	DIO_voidSetPinVal(copy_u8_port, copy_u8pin, HIGH);    // Turn LED on
}

void LED_voidOff(u8 copy_u8_port, u8 copy_u8pin) {
	DIO_voidSetPinDir(copy_u8_port, copy_u8pin, OUTPUT);  // Set pin as output
	DIO_voidSetPinVal(copy_u8_port, copy_u8pin, LOW);     // Turn LED off
}

void LED_voidToggle(u8 copy_u8_port, u8 copy_u8_pin) {
	DIO_voidSetPinDir(copy_u8_port, copy_u8_pin, OUTPUT);  
	DIO_voidTogglePinVal(copy_u8_port, copy_u8_pin);      // Toggle LED state
}

