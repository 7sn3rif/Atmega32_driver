/*
 * PCA9685_interface.h
 *
 * Created: 12/23/2025 4:58:38 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef PCA9685_INTERFACE_H_
#define PCA9685_INTERFACE_H_

/*****************************************************************************
* Function Name : PCA9685_voidInit
* Description   : Initializes the PCA9685 PWM driver over I2C (TWI).
*                 Configures MODE1, MODE2, prescaler, and enables auto-increment.
* Parameters    : None
* Return        : void
*****************************************************************************/
void PCA9685_voidInit();

/*****************************************************************************
* Function Name : PCA9685_voidWriteAngle
* Description   : Writes a specific servo angle to a given channel.
* Parameters    :
*   - Channel : Servo channel (0–15)
*   - Angle   : Desired angle in degrees
* Return        : void
*****************************************************************************/
void PCA9685_voidWriteAngle(u8 Channel, u8 Angle);

/*****************************************************************************
* Function Name : PCA9685_voidMapAngle
* Description   : Maps an input value range to a servo angle range.
* Parameters    :
*   - Channel  : Servo channel (0–15)
*   - InputVal : Input value to be mapped
*   - MinVal   : Minimum input value
*   - MaxVal   : Maximum input value
* Return        : void
*****************************************************************************/
void PCA9685_voidMapAngle(u8 Channel, u8 InputVal, u8 MinVal, u8 MaxVal);

/*****************************************************************************
* Function Name : PCA9685_u8ReadAngle
* Description   : Reads the last written angle for a given channel.
* Parameters    :
*   - Channel : Servo channel (0–15)
* Return        : u8 (the stored angle value)
*****************************************************************************/
u8 PCA9685_u8ReadAngle(u8 Channel);

/*****************************************************************************
* Function Name : PCA9685_WriteRegister
* Description   : Writes a single byte to a PCA9685 register via I2C.
* Parameters    :
*   - slaveAddr : PCA9685 I2C address
*   - regAddr   : Register address
*   - data      : Data byte to be written
* Return        : Err_status (NOErr if successful, error code otherwise)
*****************************************************************************/
Err_status PCA9685_WriteRegister(u8 slaveAddr, u8 regAddr, u8 data);

#endif /* PCA9685_INTERFACE_H_ */
