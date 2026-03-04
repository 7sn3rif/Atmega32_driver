/*
 * DIO_interface.h
 *
 * Created: 9/6/2025 10:42:29 AM
 * Author: HASSAN ARIF
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*===============================
  Direction Definitions for Pins
================================*/
#define OUTPUT 1   // Configure pin as output
#define INPUT  0   // Configure pin as input

/*===============================
  Value Definitions for Pins
================================*/
#define HIGH   1   // Set pin to high voltage level
#define LOW    0   // Set pin to low voltage level

/*===============================
  Port Identifiers
================================*/
#define DIO_PORTA 0  // Port A
#define DIO_PORTB 1  // Port B
#define DIO_PORTC 2  // Port C
#define DIO_PORTD 3  // Port D

/*===============================
  Pin Identifiers (0 to 7)
================================*/
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/*===============================
  Function Prototypes
================================*/

/*****************************************************************************
* Function Name : DIO_voidSetPinDir
* Description   : Sets the direction of a specific pin (INPUT or OUTPUT)
* Parameters    : 
*   - copy_u8_port: Port ID (DIO_PORTA to DIO_PORTD)
*   - copy_u8pin : Pin ID (DIO_PIN0 to DIO_PIN7)
*   - copy_u8dir : Direction (INPUT or OUTPUT)
* Return        : void
*****************************************************************************/
void DIO_voidSetPinDir(u8 copy_u8_port, u8 copy_u8pin, u8 copy_u8dir);

/*****************************************************************************
* Function Name : DIO_voidSetPinVal
* Description   : Sets the value of a specific pin (HIGH or LOW)
* Parameters    : 
*   - copy_u8_port: Port ID
*   - copy_u8pin : Pin ID
*   - copy_u8val : Value (HIGH or LOW)
* Return        : void
*****************************************************************************/
void DIO_voidSetPinVal(u8 copy_u8_port, u8 copy_u8pin, u8 copy_u8val);

/*****************************************************************************
* Function Name : DIO_voidTogglePinVal
* Description   : Toggles the current value of a specific pin
* Parameters    : 
*   - copy_u8_port: Port ID
*   - copy_u8pin : Pin ID
* Return        : void
*****************************************************************************/
void DIO_voidTogglePinVal(u8 copy_u8_port, u8 copy_u8pin);

/*****************************************************************************
* Function Name : DIO_u8ReadPinVal
* Description   : Reads the current value of a specific pin
* Parameters    : 
*   - copy_u8_port: Port ID
*   - copy_u8pin : Pin ID
* Return        : u8 (HIGH or LOW)
*****************************************************************************/
u8 DIO_u8ReadPinVal(u8 copy_u8_port, u8 copy_u8pin);

/*****************************************************************************
* Function Name : DIO_voidSetPortDir
* Description   : Sets the direction of all pins in a port
* Parameters    : 
*   - copy_u8_port: Port ID
*   - copy_u8dir : Direction (INPUT or OUTPUT)
* Return        : void
*****************************************************************************/
void DIO_voidSetPortDir(u8 copy_u8_port, u8 copy_u8dir);

/*****************************************************************************
* Function Name : DIO_voidSetPortVal
* Description   : Sets the value of all pins in a port
* Parameters    : 
*   - copy_u8_port: Port ID
*   - copy_u8val : Value (8-bit value for all pins)
* Return        : void
*****************************************************************************/
void DIO_voidSetPortVal(u8 copy_u8_port, u8 copy_u8val);

#endif /* DIO_INTERFACE_H_ */
