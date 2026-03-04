/*
 * lCD_prog.c
 *
 * Created: 9/13/2025 9:31:38 AM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"

#define F_CPU 16000000UL
#include <util/delay.h>
 
 
 
 
 
 
 static void LCD_voidSHD(u8 copy_u8data){  //  1101  0011  // DATA>>4
	 
	 u8 loc_arr[4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN} ;
	 
	 u8 loc_in=0 ;
	 
	 for (loc_in=0 ; loc_in< 4 ;loc_in++)
	 {
		 DIO_voidSetPinVal(LCD_DPORT,loc_arr[loc_in],GET_BIT(copy_u8data,loc_in)) ;
		 
		 
	 }
	 
 }
 
 
 static void LCD_voidSendEnablePulse(){
	 DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,HIGH) ;
	 _delay_ms(2) ;
	 DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,LOW) ;
	 
 }

 
 
 



void LCD_voidInit(void) {
	
	_delay_ms(40) ;
	
	#if LCD_MODE == LCD_8BITMODE
	/*send command ( Function set ) */
	LCD_voidSendCommand(0x38) ;
	#elif LCD_MODE ==LCD_4BITMODE
	
	LCD_voidSHD(0b0010) ;
	LCD_voidSendEnablePulse() ;
	LCD_voidSHD(0b0010) ;
	LCD_voidSendEnablePulse() ;
	LCD_voidSHD(0b1000) ;
	LCD_voidSendEnablePulse() ;
	#endif
	
	LCD_voidSendCommand(0x0C) ;
	
	/* send clr command  */
	
	LCD_voidSendCommand(1) ;
	
	
	
}

void LCD_voidSendCommand( u8 copy_u8command){
	/*set rs to low --> send command*/
	
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,LOW ) ;
	
	/*set rw to low ---> to write */
	
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW);
	
	/*send command */
	#if LCD_MODE == LCD_8BITMODE
	/*SEND data */
	
	DIO_voidSetPortVal(LCD_DPORT,copy_u8command) ;
	// enable pin
	LCD_voidSendEnablePulse() ;
	#elif LCD_MODE ==LCD_4BITMODE
	LCD_voidSHD(copy_u8command>>4) ;
	LCD_voidSendEnablePulse() ;
	LCD_voidSHD(copy_u8command) ;
	LCD_voidSendEnablePulse() ;
	#endif
}

void LCD_voidSendData( u8 copy_u8data) {
	
	
	/*set rs to high --> send data */
	
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,HIGH ) ;
	
	/*set rw to low ---> to write */
	
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW);
	
	#if LCD_MODE == LCD_8BITMODE
	/*SEND data */
	
	DIO_voidSetPortVal(LCD_DPORT,copy_u8data) ;
	// enable pin
	LCD_voidSendEnablePulse() ;
	#elif LCD_MODE ==LCD_4BITMODE
	LCD_voidSHD(copy_u8data>>4) ;
	LCD_voidSendEnablePulse() ;
	LCD_voidSHD(copy_u8data) ;
	LCD_voidSendEnablePulse() ;
	#endif
	
	
	
}
   
   
   void LCD_voidSendString(char *str){
	   
	    while (*str != '\0') {
		    LCD_voidSendData(*str);
	   str++;
   }
   }
   
   
   
   void LCD_voidSendNumber(u32 copy_u32num) {
	   s8 i=0 ;
	   u8 array[10] ;
	   if (copy_u32num ==0) {
		   LCD_voidSendData('0') ;
		   return ;
	   }
	   for (i=0 ; copy_u32num !=0 ; i++) {
		   array[i]=copy_u32num % 10 +48 ;
		   copy_u32num /=10 ;
	   }
	   i-- ;
	   while( i >=0){
		   LCD_voidSendData(array[i]) ;
		   i-- ;
	   }
   }

 void LCD_voidGoToxy(u8 copy_u8x , u8 copy_u8y) {
	 u8 ddram_address = copy_u8x+(copy_u8y*0x40);
	 SET_BIT(ddram_address,7);
	 LCD_voidSendCommand(ddram_address);
	 
	 
	 
 }
   
   
 void LCD_voidDrawData(u8 copy_u8pattern, u8 *copy_u8data, u8 copy_u8x , u8 copy_u8y )
 {
	 u8 copy_u8cgramAdress = copy_u8pattern*8;
	   /* Cgram address*/
	    copy_u8cgramAdress = copy_u8pattern*8;
	   /*set cgram*/
	  CLR_BIT(copy_u8cgramAdress,7);
	    SET_BIT(copy_u8cgramAdress,6);
	   LCD_voidSendCommand(copy_u8cgramAdress);
	   for(u8 i=0;i<8;i++){
		   
		   LCD_voidSendData(copy_u8data[i]);
		   /*display by DDRAM*/
	   }
		   LCD_voidGoToxy(copy_u8x,copy_u8y);
		   LCD_voidSendData(copy_u8pattern);
		   
		   
		   
	   }
	   
	   void LCD_voidSendRealNumber(f32 copy_f32realnumber){
		   // Handle negative numbers
		   if(copy_f32realnumber < 0){
			   LCD_voidSendData('-');
			   copy_f32realnumber = -copy_f32realnumber;
		   }

		   // Integer and fractional parts
		   u32 int_part = (u32)copy_f32realnumber;
		   f32 fraction = copy_f32realnumber - (f32)int_part;
		   u32 frac_part = (u32)((fraction * 100) + 0.5f); // rounded to 2 decimals

		   // Fix floating overflow like 3.999 -> 4.00
		   if(frac_part >= 100){
			   frac_part = 0;
			   int_part++;
		   }

		   // Send integer part
		   LCD_voidSendNumber(int_part);
		   LCD_voidSendData('.');

		   // Handle leading zero (e.g. 3.05)
		   if(frac_part < 10){
			   LCD_voidSendData('0');
		   }

		   // Send fractional part
		   LCD_voidSendNumber(frac_part);
	   }

	   
	   
	   
	   
   
   