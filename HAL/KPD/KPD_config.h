/*
 * KPD_config.h
 *
 * Created: 9/25/2025 10:22:44 PM
 *  Author: HASSAN ARIF
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_
//kpd pins
//key bad rows (PB4->>PD7)
#define KPD_ROW_PORT  DIO_PORTB
   
#define   KPD_R0_PIN     DIO_PIN4
#define   KPD_R1_PIN     DIO_PIN5
#define   KPD_R2_PIN     DIO_PIN6
#define   KPD_R3_PIN     DIO_PIN7

   
   
   
//key bad colomuns (PD2->>PD5)
#define KPD_COL_PORT  DIO_PORTC


#define   KPD_C0_PIN     DIO_PIN4
#define   KPD_C1_PIN     DIO_PIN5
#define   KPD_C2_PIN     DIO_PIN6
#define   KPD_C3_PIN     DIO_PIN7


#endif /* KPD_CONFIG_H_ */