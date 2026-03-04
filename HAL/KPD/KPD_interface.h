/*
 * KPD_interface.h
 *
 * Created: 9/25/2025 10:23:19 PM
 * Author: HASSAN ARIF
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

/*===============================================
  Keypad Function Prototypes
===============================================*/

/*****************
* Function Name : KPD_voidInit
* Description   : Initializes the keypad by setting row pins as outputs and
*                 column pins as inputs with pull-up resistors enabled.
*                 This prepares the keypad matrix for scanning.
* Parameters    : void
* Return        : void
*****************/
void KPD_voidInit(void);

/*****************
* Function Name : KPD_u8GetKey
* Description   : Scans the keypad matrix to detect a key press.
*                 Returns the ASCII value or mapped code of the pressed key.
*                 If no key is pressed, returns a predefined idle value (e.g. 0xFF).
* Parameters    : void
* Return        : u8 - The value of the pressed key or idle indicator.
*****************/
u8 KPD_u8GetKey(void);

#endif /* KPD_INTERFACE_H_ */