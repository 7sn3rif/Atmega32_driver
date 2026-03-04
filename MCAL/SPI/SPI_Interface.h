/*
 * SPI_Interface.h
 *
 * Created: 11/21/2025 11:01:35 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#define SPI_PORT  DIO_PORTB
#define MISO_PIN  DIO_PIN6
#define MOSI_PIN  DIO_PIN5
#define SS_PIN    DIO_PIN4
#define SCK_PIN   DIO_PIN7
#define SS2_PIN   DIO_PIN3




void SPI_voidMasterInit();
void SPI_voidSlaveInit();
void SPI_voidMasterSendData(u8 copy_u8data);
u8 SPI_voidSlaveReturnData();



#endif /* SPI_INTERFACE_H_ */