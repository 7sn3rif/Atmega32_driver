/*
 * LED.h
 *
 * Created: 9/11/2025 6:55:44 PM
 *  Author:HASSAN ARIF
 */ 


#ifndef LED_H_
#define LED_H_

/*****************************************************************************
* Function Name : LED_voidOn
* Description   : Turns the LED on by setting the pin HIGH
*****************************************************************************/
void LED_voidOn (u8 copy_u8_port,u8 copy_u8pin);
/*****************************************************************************
* Function Name : LED_voidOff
* Description   : Turns the LED off by setting the pin LOW
*****************************************************************************/
void LED_voidOff(u8 copy_u8_port, u8 copy_u8_pin);
/*****************************************************************************
* Function Name : LED_voidToggle
* Description   : Toggles the current state of the LED
*****************************************************************************/
void LED_voidToggle(u8 copy_u8_port, u8 copy_u8_pin);
#endif /* LED_H_ */