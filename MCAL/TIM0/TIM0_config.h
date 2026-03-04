/*
 * TIM0_config.h
 *
 * Created: 10/24/2025 11:28:40 AM
 * Author: HASSAN ARIF
 *
 * Description:
 *   This configuration file defines the selectable options for Timer0
 *   on the ATmega32 microcontroller. It includes mode selection,
 *   PWM mode selection, OCR value, and prescaler settings.
 */

#ifndef TIM0_CONFIG_H_
#define TIM0_CONFIG_H_

/*===========================================
  Timer0 Modes (used in TIM0_voidInit)
===========================================*/
#define OV_MODE       0   // Normal mode (Overflow)
#define CTC_MODE      1   // Clear Timer on Compare Match

/*===========================================
  PWM Modes (used in TIM0_voidPWM)
===========================================*/
#define FastPWM_MODE  2   // Fast PWM mode
#define P_C_PWM_MODE  3   // Phase Correct PWM mode

/*===========================================
  Output Compare Register Value
  Defines the OCR0 value for CTC or PWM duty cycle calculations
===========================================*/
#define OCR_VAL  250

/*===========================================
  Prescaler Options
  These values correspond to CS00–CS02 bits in TCCR0
===========================================*/
#define TIM0_8_PRESCALER      2   // clk/8
#define TIM0_64_PRESCALER     3   // clk/64
#define TIM0_256_PRESCALER    4   // clk/256
#define TIM0_1024_PRESCALER   5   // clk/1024

/*===========================================
  Selected Prescaler
  Choose one of the above prescaler macros
===========================================*/
#define TIM0_PRESCALER  TIM0_64_PRESCALER

#endif /* TIM0_CONFIG_H_ */
