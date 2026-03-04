/*
 * LCD_config.h
 *
 * Created: 9/13/2025 9:30:32 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



#if  LCD_MODE  == LCD_8BITMODE
// lcd data port
#define LCD_DPORT    DIO_PORTA

#elif LCD_MODE == LCD_4BITMODE
// LCD 4_ BIT MODE

#define  LCD_DPORT  DIO_PORTA

#define LCD_D4_PIN  DIO_PIN3
#define LCD_D5_PIN  DIO_PIN4
#define LCD_D6_PIN  DIO_PIN5
#define LCD_D7_PIN  DIO_PIN6

#endif

// LCD control pins
#define  LCD_CPORT    DIO_PORTA

#define LCD_RS_PIN    DIO_PIN1
#define LCD_RW_PIN    DIO_PIN0
#define LCD_EN_PIN    DIO_PIN2




#endif /* LCD_CONFIG_H_ */