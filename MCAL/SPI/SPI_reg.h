/*
 * SPI_reg.h
 *
 * Created: 11/21/2025 11:01:09 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_

#define SPDR_REG  *((volatile u8*)0x2F)
#define SPSR_REG  *((volatile u8*)0x2E)
#define SPCR_REG  *((volatile u8*)0x2D)

#endif /* SPI_REG_H_ */