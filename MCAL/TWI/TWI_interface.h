/*
 * TWI_interface.h
 *
 * Created: 11/22/2025 12:55:44 PM
 *  Author:HASSAN ARIF
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_



/*****************************************************************************
* Enum Name     : Err_status
* Description   : Represents possible error states for TWI operations
*****************************************************************************/
typedef enum {
	NOErr,                               // No error occurred
	StartConditionErr,                   // Error sending START condition
	RepeatedStartErr,                    // Error sending Repeated START condition
	MasterSendSlaveAddessWithWrtieErr,   // Error sending slave address with write
	MasterSendSlaveAddessWithReadErr,    // Error sending slave address with read
	MasterSendDataErr,                   // Error sending data from master
	MasterReciveDataErr,                 // Error receiving data by master
	SlaveACKOrNotACKErr                  // Error in slave ACK/NACK response
} Err_status;


/*============================== Master Functions ==============================*/

/*****************************************************************************
* Function Name : TWI_voidMasterInit
* Description   : Initializes TWI module in master mode
* Parameters    :
*   - copy_u8address : 7-bit master address (pass 0 for no address)
* Return        : void
*****************************************************************************/
void TWI_voidMasterInit(u8 copy_u8address);

/*****************************************************************************
* Function Name : TWI_Err_statusSendStartCondition
* Description   : Sends START condition on TWI bus
* Parameters    : void
* Return        : Err_status (success or error code)
*****************************************************************************/
Err_status TWI_Err_statusSendStartCondition(void);

/*****************************************************************************
* Function Name : TWI_Err_statusSendRepeatedStart
* Description   : Sends Repeated START condition on TWI bus
* Parameters    : void
* Return        : Err_status (success or error code)
*****************************************************************************/
Err_status TWI_Err_statusSendRepeatedStart(void);

/*****************************************************************************
* Function Name : TWI_Err_statusMasterSendSlaveAddessWithWrtie
* Description   : Sends slave address with write bit
* Parameters    :
*   - copy_u8address : 7-bit slave address
* Return        : Err_status (success or error code)
*****************************************************************************/
Err_status TWI_Err_statusMasterSendSlaveAddessWithWrtie(u8 copy_u8address);

/*****************************************************************************
* Function Name : TWI_Err_statusMasterSendSlaveAddessWithRead
* Description   : Sends slave address with read bit
* Parameters    :
*   - copy_u8address : 7-bit slave address
* Return        : Err_status (success or error code)
*****************************************************************************/
Err_status TWI_Err_statusMasterSendSlaveAddessWithRead(u8 copy_u8address);

/*****************************************************************************
* Function Name : TWI_Err_statusMasterSendData
* Description   : Sends one byte of data from master to slave
* Parameters    :
*   - copy_u8data : data byte to send
* Return        : Err_status (success or error code)
*****************************************************************************/
Err_status TWI_Err_statusMasterSendData(u8 copy_u8data);

/*****************************************************************************
* Function Name : TWI_Err_statusMasterReciveData
* Description   : Receives one byte of data from slave to master
* Parameters    :
*   - copy_u8data : pointer to variable to store received data
* Return        : Err_status (success or error code)
*****************************************************************************/
Err_status TWI_Err_statusMasterReciveData(u8 *copy_u8data);

/*****************************************************************************
* Function Name : TWI_voidSendStopCondition
* Description   : Sends STOP condition on TWI bus
* Parameters    : void
* Return        : void
*****************************************************************************/
void TWI_voidSendStopCondition(void);


/*============================== Slave Functions ==============================*/

/*****************************************************************************
* Function Name : TWI_voidSlaveInit
* Description   : Initializes TWI module in slave mode
* Parameters    :
*   - copy_u8address : 7-bit slave address
* Return        : void
*****************************************************************************/
void TWI_voidSlaveInit(u8 copy_u8address);

/*****************************************************************************
* Function Name : TWI_Err_statusSlaveACKOrNotACK
* Description   : Checks if slave sent ACK or NACK
* Parameters    : void
* Return        : Err_status (ACK or NACK status)
*****************************************************************************/
Err_status TWI_Err_statusSlaveACKOrNotACK(void);

/*****************************************************************************
* Function Name : TWI_u8SlaveReciveData
* Description   : Receives one byte of data in slave mode
* Parameters    : void
* Return        : u8 (received data byte)
*****************************************************************************/
u8 TWI_u8SlaveReciveData(void);



#endif /* TWI_INTERFACE_H_ */
