/*
 * TIM1_interface.h
 *
 * Created: 11/8/2025 10:17:42 AM
 * Author: HASSAN ARIF
 *
 * Description:
 *   This header file provides the interface for Timer1 driver functions
 *   on the ATmega32 microcontroller. It includes initialization for
 *   overflow mode, Fast PWM using ICR1, OCR value setting, counter
 *   reading, and reset functionality.
 */

#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

/*****************************************************************************
* Function Name : TIM1_voidFastPWM_ICR1
* Description   : Configures Timer1 for Fast PWM mode using ICR1 as TOP
* Parameters    : void
* Return        : void
*****************************************************************************/
void TIM1_voidFastPWM_ICR1(void);

/*****************************************************************************
* Function Name : TIM1_voidSerOcrVal
* Description   : Sets the OCR1A/OCR1B value for PWM duty cycle or compare match
* Parameters    :
*   - copy_u16val : 16-bit value to load into OCR1x register
* Return        : void
*****************************************************************************/
void TIM1_voidSetOcrVal(u16 copy_u16val);

/*****************************************************************************
* Function Name : TIM1_voidOverFlowInit
* Description   : Initializes Timer1 in Normal (Overflow) mode
* Parameters    : void
* Return        : void
*****************************************************************************/
void TIM1_voidOverFlowInit(void);

/*****************************************************************************
* Function Name : TIM1_u16voidReadVal
* Description   : Reads the current value of the Timer1 counter (TCNT1)
* Parameters    : void
* Return        : u16 (current counter value)
*****************************************************************************/
u16 TIM1_u16voidReadVal(void);

/*****************************************************************************
* Function Name : TIM1_voidReset
* Description   : Resets the Timer1 counter (TCNT1) to zero
* Parameters    : void
* Return        : void
*****************************************************************************/
void TIM1_voidReset(void);
//***************************************************************************/
void TIM1_voidSetOcr1B(u16 copy_u16val);

#endif /* TIM1_INTERFACE_H_ */
