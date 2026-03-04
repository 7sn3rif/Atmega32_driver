/*
 * UART_interface.h
 *
 * Created: 11/15/2025 12:30:50 PM
 *  Author: HASSAN ARIF
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


/*****************************************************************************
* Function Name : UART_voidInit
* Description   : Initializes the UART module with predefined settings
*                 (baud rate, frame size, TX/RX enable).
* Parameters    : None
* Return        : void
*****************************************************************************/
void UART_voidInit();

/*****************************************************************************
* Function Name : UART_voidSendData
* Description   : Sends a single byte of data through UART.
* Parameters    :
*   - copy_u8data : The data byte to be transmitted
* Return        : void
*****************************************************************************/
void UART_voidSendData(u8 copy_u8data);

/*****************************************************************************
* Function Name : UART_u8ReciveData
* Description   : Receives a single byte of data through UART.
* Parameters    : None
* Return        : u8 (the received data byte)
*****************************************************************************/
u8 UART_u8ReciveData();


#endif /* UART_INTERFACE_H_ */