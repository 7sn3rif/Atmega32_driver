/*
 * ADC_interface.h
 *
 * Created: 10/17/2025 9:20:48 AM
 *  Author: LENOVO
 */ 

/*
 * ADC_interface.h
 *
 * Created: 10/17/2025 9:50:32 AM
 * Author: HASSAN ARIF
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/*===============================================
  ADC Prescaler Configuration
===============================================*/

/*****
* Description   : Prescaler options for dividing the system clock
*                 to set the ADC conversion speed.
* Notes         : Higher division = slower conversion but more stable.
*****/
#define ADC_2_PRESCALER    1
#define ADC_4_PRESCALER    2
#define ADC_8_PRESCALER    3
#define ADC_16_PRESCALER   4
#define ADC_32_PRESCALER   5
#define ADC_64_PRESCALER   6
#define ADC_128_PRESCALER  7

/*****
* Description   : User-defined macro to select the active prescaler.
*                 This controls ADC conversion speed.
*****/
#define ADC_PRESCALER ADC_128_PRESCALER

/*===============================================
  ADC Input Channel Definitions
===============================================*/

/*****
* Description   : ADC channel selection macros.
*                 Each corresponds to a physical analog input pin.
*****/
#define ADC0 0b00000000 
#define ADC1 0b00000001
#define ADC2 0b00000010
#define ADC3 0b00000011
#define ADC4 0b00000100 
#define ADC5 0b00000101 
#define ADC6 0b00000110 
#define ADC7 0b00000111 

/*===============================================
  ADC Function Prototypes
===============================================*/

/*****
* Function Name : ADC_voidInit
* Description   : Initializes the ADC module by selecting reference voltage,
*                 setting the prescaler, and enabling the ADC.
* Parameters    : void
* Return        : void
*****/
void ADC_voidInit(void);

/*****
* Function Name : ADC_u16ReadChannel
* Description   : Reads the analog value from the specified ADC channel.
*                 Starts conversion, waits for completion, and returns result.
* Parameters    : copy_u8channel - ADC channel macro (ADC0 to ADC7)
* Return        : u16 - 10-bit digital value representing the analog input
*****/
u16 ADC_u16ReadChannel(u8 copy_u8channel);

#endif /* ADC_INTERFACE_H_ */