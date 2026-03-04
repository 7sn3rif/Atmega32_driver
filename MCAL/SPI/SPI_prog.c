/*
 * SPI_prog.c
 *
 * Created: 11/21/2025 11:01:57 AM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../DIO/DIO_interface.h"
#include "SPI_reg.h"
#include "SPI_Interface.h"

void SPI_voidMasterInit(){
	
	DIO_voidSetPinDir(SPI_PORT,SS_PIN,OUTPUT);
	DIO_voidSetPinDir(SPI_PORT,SS2_PIN,OUTPUT);
	DIO_voidSetPinDir(SPI_PORT,SCK_PIN,OUTPUT);
	DIO_voidSetPinDir(SPI_PORT,MOSI_PIN,OUTPUT);
	DIO_voidSetPinDir(SPI_PORT,MISO_PIN,INPUT);
	
	
	
	/*Mater mode*/
	SET_BIT(SPCR_REG,4);
	
	CLR_BIT(SPCR_REG,3);
	CLR_BIT(SPCR_REG,2);
/*128*/
	SET_BIT(SPCR_REG,1);
	SET_BIT(SPCR_REG,0);
	
	SET_BIT(SPCR_REG,6);//set spe
}

void SPI_voidSlaveInit(){
	
	DIO_voidSetPinDir(SPI_PORT,SS_PIN,INPUT);
	DIO_voidSetPinDir(SPI_PORT,SS2_PIN,INPUT);
	DIO_voidSetPinDir(SPI_PORT,SCK_PIN,INPUT);
	DIO_voidSetPinDir(SPI_PORT,MOSI_PIN,INPUT);
	DIO_voidSetPinDir(SPI_PORT,MISO_PIN,OUTPUT);
	
	
	SET_BIT(SPCR_REG,6);//set spe
	CLR_BIT(SPCR_REG,4);
}
void SPI_voidMasterSendData(u8 copy_u8data){
	SPDR_REG = copy_u8data;
	while(GET_BIT(SPSR_REG,7)==0);
	
}
u8 SPI_voidSlaveReturnData (){
	
	while(GET_BIT(SPSR_REG,7)==0);
	return SPDR_REG;
}