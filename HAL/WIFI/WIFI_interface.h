/*
 * WIFI_interface.h
 *
 * Created: 12/21/2025 12:10:21 AM
 *  Author:HASSAN
 */ 
//This code is for DT-06 ESP made module

#ifndef WIFI_INTERFACE_H_
#define WIFI_INTERFACE_H_

/*****************************************************************************
* Function Name : WIFI_voidInit
* Description   : Initializes the WiFi module by setting up UART.
*                 Optionally sends AT test command to check module response.
* Parameters    : None
* Return        : void
*****************************************************************************/
void WIFI_voidInit();

/*****************************************************************************
* Function Name : WIFI_voidSendCommand
* Description   : Sends an AT command string from MCU to the WiFi module via UART.
* Parameters    :
*   - cmd : Pointer to null-terminated command string
* Return        : void
*****************************************************************************/
void WIFI_voidSendCommand(u8 *cmd);

/*****************************************************************************
* Function Name : WIFI_voidReceiveData
* Description   : Receives a single byte of data from the WiFi module via UART.
* Parameters    : None
* Return        : u8 (the received data byte)
*****************************************************************************/
u8 WIFI_voidReceiveData();

/*****************************************************************************
* Function Name : WIFI_u8SendData
* Description   : Sends a single byte of data from MCU to the WiFi module via UART.
* Parameters    :
*   - data : The data byte to be transmitted
* Return        : void
*****************************************************************************/
void WIFI_u8SendData(u8 data);

/*****************************************************************************
* Function Name : WIFI_u8CheckOK
* Description   : Checks if the WiFi module responded with "OK".
* Parameters    : None
* Return        : u8 (1 if "OK" received, 0 otherwise)
*****************************************************************************/
u8 WIFI_u8CheckOK();

/******************************************************************************
* Function Name : WIFI_u16ReceiveNumber
* Description   : Receives a multi-digit number from the WiFi module via UART.
*                 Converts ASCII characters ('0'–'9') into an integer value.
*                 Skips separators (':') and stops reading at newline/carriage return.
* Parameters    : None
* Return        : u16 (the parsed number, e.g., 90, 180)
*
* Example Usage :
*   Input stream : "S1:90\r\n"
*   Output       : 90
*
* Notes:
*   - This function performs a blocking read (waits until data is available).
*   - Only numeric digits are accumulated into the result.
*   - ':' characters are ignored.
*   - Reading stops when '\n' or '\r' is encountered.
*****************************************************************************/
u16 WIFI_u16ReceiveNumber();

#endif /* WIFI_INTERFACE_H_ */
