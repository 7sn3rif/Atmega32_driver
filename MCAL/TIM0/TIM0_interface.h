/*
 * TIM0_interface.h
 *
 * Created: 10/24/2025 10:38:50 AM
 * Author: Hassan Arif
 *
 * Description:
 *   This header file provides the interface for Timer0 driver functions
 *   on the ATmega32 microcontroller. It includes initialization for
 *   Normal/CTC modes, callback registration for interrupts, and PWM
 *   generation in Phase Correct / Fast PWM modes.
 */

#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_

/*****************************************************************************
* Function Name : TIM0_voidInit
* Description   : Initializes Timer0 in a specific mode
* Parameters    :
*   - copy_u8_mode : Timer0 mode
*                   Options:
*                     • OV_MODE       ? Normal (Overflow)
*                     • CTC_MODE      ? Clear Timer on Compare Match
* Return        : void
*****************************************************************************/
void TIM0_voidInit(u8 copy_u8_mode);

/*****************************************************************************
* Function Name : TIM0_voidSetCallBack
* Description   : Registers a callback function to be executed on Timer0 events
* Parameters    :
*   - ptr         : Pointer to user-defined function
*   - copy_u8_mode: Event type (Overflow or Compare Match)
* Return        : void
*****************************************************************************/
void TIM0_voidSetCallBack(void (*ptr)(void), u8 copy_u8_mode);

/*****************************************************************************
* Function Name : TIM0_voidPWM
* Description   : Generates a PWM signal on Timer0
* Parameters    :
*   - copy_u8dc   : Duty cycle (0 to 100%)
*   - copy_u8mode : PWM mode
*                   Options:
*                     • FastPWM_MODE  ? Fast PWM
*                     • P_C_PWM_MODE  ? Phase Correct PWM
*                   + Output mode (Non-inverting / Inverting)
* Return        : void
*****************************************************************************/
void TIM0_voidPWM(u8 copy_u8dc, u8 copy_u8mode);

#endif /* TIM0_INTERFACE_H_ */
