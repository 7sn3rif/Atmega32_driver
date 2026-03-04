/*
 * EXTI_interface.h
 *
 * Created: 9/27/2025 11:43:30 AM
 * Author: HASSAN ARIF
 */ 

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*===============================================
  External Interrupt Control Macros
===============================================*/

/* Interrupt sources */
#define  INT_0   0
#define  INT_1   1
#define  INT_2   2

/* Sense control options */
#define  LOW_LEVEL          0
#define  ANY_LOGICAL_CHANGE 1
#define  FALLING_EDGE       2
#define  RISING_EDGE        3

/*===============================================
  External Interrupt Function Prototypes
===============================================*/

/*****************
* Function Name : EXTI_voidInit
* Description   : Initializes a specific external interrupt with the desired
*                 sense control (trigger condition).
* Parameters    : copy_u8sense    - Sense control option (LOW_LEVEL, ANY_LOGICAL_CHANGE,
*                                   FALLING_EDGE, RISING_EDGE)
*                 copy_u8exti_num - Interrupt number (INT_0, INT_1, INT_2)
* Return        : void
*****************/
void EXTI_voidInit(u8 copy_u8sense, u8 copy_u8exti_num);

/*****************
* Function Name : EXTI0_voidEnable
* Description   : Enables external interrupt 0 (INT0).
* Parameters    : void
* Return        : void
*****************/
void EXTI0_voidEnable(void);

/*****************
* Function Name : EXTI0_voidDisable
* Description   : Disables external interrupt 0 (INT0).
* Parameters    : void
* Return        : void
*****************/
void EXTI0_voidDisable(void);

/*****************
* Function Name : EXTI1_voidEnable
* Description   : Enables external interrupt 1 (INT1).
* Parameters    : void
* Return        : void
*****************/
void EXTI1_voidEnable(void);

/*****************
* Function Name : EXTI1_voidDisable
* Description   : Disables external interrupt 1 (INT1).
* Parameters    : void
* Return        : void
*****************/
void EXTI1_voidDisable(void);

/*****************
* Function Name : EXTI2_voidEnable
* Description   : Enables external interrupt 2 (INT2).
* Parameters    : void
* Return        : void
*****************/
void EXTI2_voidEnable(void);

/*****************
* Function Name : EXTI3_voidDisable
* Description   : Disables external interrupt 2 (INT2).
* Parameters    : void
* Return        : void
*****************/
void EXTI3_voidDisable(void);

/*****************
* Function Name : EXTI_voidCallBack
* Description   : Registers a callback function to be executed when the
*                 specified external interrupt occurs.
* Parameters    : ptr            - Pointer to the callback function
*                 copy_u8exti_num - Interrupt number (INT_0, INT_1, INT_2)
* Return        : void
*****************/
void EXTI_voidCallBack(void(*ptr)(void), u8 copy_u8exti_num);

#endif /* EXTI_INTERFACE_H_ */
