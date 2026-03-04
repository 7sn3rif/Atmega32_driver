/*
 * UART_prog.c
 *
 * Created: 11/15/2025 12:31:45 PM
 *  Author: HASSAN ARIF
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"

#include "UART_reg.h"
#include "UART_interface.h"



void UART_voidInit(){
	
	u8 temp =0;//u can use 0b00000 to make the cmnd in one line 
    SET_BIT(temp,7);
	SET_BIT(temp,1);
	SET_BIT(temp,2);
	UCSRC_REG =temp;
	//now set baud rate 
	UBRRL_REG =103;//9600
	// ENABLE TX & RX
	SET_BIT(UCSRB_REG,3);
	SET_BIT(UCSRB_REG,4);
}





void UART_voidSendData(u8 copy_u8data){
UDR_REG =copy_u8data;
while(GET_BIT(UCSRA_REG,5)==0);

}



u8 UART_u8ReciveData(){
	while(GET_BIT(UCSRA_REG,7)==0);
	return UDR_REG;
	
}
