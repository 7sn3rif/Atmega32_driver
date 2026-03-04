/*
 * TWI_reg.h
 *
 * Created: 11/22/2025 12:56:00 PM
 *  Author: HASSAN ARIF
 */ 


#ifndef TWI_REG_H_
#define TWI_REG_H_



#define TWBR_REG     *((volatile  u8*)0x20)
#define TWSR_REG     *((volatile  u8*)0x21)
#define TWCR_REG     *((volatile  u8*)0x56)
#define TWAR_REG     *((volatile  u8*)0x22)
#define TWDR_REG     *((volatile  u8*)0x23)

// TWI Codes 


#define START_ACK                             0x08   /* start has been send */
#define REP_START                             0x10   /* repeated start*/
#define SLAVE_ADD_AND_WR_ACK                  0x18   /*MASTER transmit (slave address +write request  */
#define SLAVE_ADD_AND_RR_ACK                  0x40  /*MASTER transmit (slave address +write request  */
#define MASTER_WR_BYTE_ACK                    0x28   /*MASTER transmit Data ack  */
#define MASTER_RD_BYTE_WITH_ACK               0x50   /*MASTER  recive data with ack  */
#define MASTER_RD_BYTE_WITH_NACK              0x58   /*MASTER  recive data with ack  */
#define SLAVE_ADD_RCVD_RD_REQ                 0xA8   /* MEANS that slave address is received with read request  */
#define SLAVE_ADD_RCVD_WD_REQ                 0x60   /* MEANS that slave address is received with Write request  */
#define SLAVE_DATA_RECEIVED                   0x80  /* MEANS that data byte is recevied */
#define SLAVE_BYTE_TRANSMITTIED               0xB8  /* MEANS that data byte  are transmitted  */




#endif /* TWI_REG_H_ */