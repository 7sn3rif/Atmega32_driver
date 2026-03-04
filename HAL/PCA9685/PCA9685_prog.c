/*
 * PCA9685_prog.c
 *
 * Created: 12/23/2025 5:01:03 AM
 *  Author: HASSAN ARIF
 */

#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "PCA9685_config.h"
#include "PCA9685_interface.h"

static u8 Current_Angle[16] = {0};

void PCA9685_voidInit(void)
{
	/* TWI Init */
	TWI_voidMasterInit(0);

	/* MODE1: sleep = 1 (required before prescaler write) */
	u8 Mode1DataByte = 0x10;
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_MODE1_REG, Mode1DataByte);

	/* Prescaler for ~50Hz */
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_PRE_SCALE_REG, 121);

	/* MODE1: wake up + auto increment */
	CLR_BIT(Mode1DataByte, 4);   // sleep = 0
	SET_BIT(Mode1DataByte, 5);   // AI = 1
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_MODE1_REG, Mode1DataByte);

	_delay_us(500);

	/* MODE2: totem pole, update on STOP */
	u8 Mode2DataByte = 0x01;
	SET_BIT(Mode2DataByte, 2);   // OUTDRV = 1
	CLR_BIT(Mode2DataByte, 3);   // OCH = 0
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_MODE2_REG, Mode2DataByte);

	/* Restart */
	SET_BIT(Mode1DataByte, 7);
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_MODE1_REG, Mode1DataByte);

	_delay_ms(1);
}

void PCA9685_voidWriteAngle(u8 Channel, u8 Angle)
{
	f32 ratio = (Angle - MIN_ANGLE) * 1.0 / (MAX_ANGLE - MIN_ANGLE);

	u16 OFF_count = MIN_PUlSE +
	               (ratio * (MAX_PUlSE - MIN_PUlSE));

	u8 OFF_L = (u8)(OFF_count & 0xFF);
	u8 OFF_H = (u8)((OFF_count >> 8) & 0x0F);

	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_LED_ON_L(Channel),  0x00);
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_LED_ON_H(Channel),  0x00);
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_LED_OFF_L(Channel), OFF_L);
	PCA9685_WriteRegister(PCA9685_ADDRESS, PCA9685_LED_OFF_H(Channel), OFF_H);

	Current_Angle[Channel] = Angle;
}

void PCA9685_voidMapAngle(u8 Channel, u8 InputVal, u8 MinVal, u8 MaxVal)
{
	u8 Desired_Angle = 0;

	f32 ratio = (InputVal - MinVal) * 1.0 / (MaxVal - MinVal);
	Desired_Angle = MIN_ANGLE + (ratio * (MAX_ANGLE - MIN_ANGLE));

	PCA9685_voidWriteAngle(Channel, Desired_Angle);
	Current_Angle[Channel] = Desired_Angle;
}

u8 PCA9685_u8ReadAngle(u8 Channel)
{
	return Current_Angle[Channel];
}

Err_status PCA9685_WriteRegister(u8 slaveAddr, u8 regAddr, u8 data)
{
	Err_status status;

	status = TWI_Err_statusSendStartCondition();
	if (status != NOErr) return status;

	status = TWI_Err_statusMasterSendSlaveAddessWithWrtie(slaveAddr);
	if (status != NOErr) return status;

	status = TWI_Err_statusMasterSendData(regAddr);
	if (status != NOErr) return status;

	status = TWI_Err_statusMasterSendData(data);
	if (status != NOErr) return status;

	TWI_voidSendStopCondition();

	return NOErr;
}
