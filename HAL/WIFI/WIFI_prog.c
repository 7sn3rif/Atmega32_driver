/*
 *WIFI_prog.c
 *
 * Created: 12/21/2025 12:10:45 AM
 *  Author: HASSAN
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/UART/UART_reg.h"
#include "../../MCAL/UART/UART_interface.h"
#include "WIFI_interface.h"
  /*dt-06 wifi module*/
void WIFI_voidInit(){
	UART_voidInit();
	_delay_ms(2000);   // DT06 boot time
	/*WIFI_voidSendCommand("AT\r\n");
	 _delay_ms(1000);
	WIFI_u8CheckOK();*/ //if i not using the arduino ide code for flashing dt06
	
}
void WIFI_voidSendCommand(u8 *cmd){
	 while (*cmd != '\0') {
		 UART_voidSendData(*cmd);
		cmd++;//i will not use this in main.c
	 }
}


u8 WIFI_voidReceiveData(){
	u8 Data = UART_u8ReciveData();
	return Data;
	
}




u8 WIFI_u8CheckOK(){
	
	u8 OK=0;
	u8 state = 0;

	while(1){
		OK = UART_u8ReciveData();

		if(OK == 'O' && state == 0){
			state = 1;
		}
		else if(OK == 'K' && state == 1){
			return 1;   // OK received
		}
		else{
			state = 0;// iwill not use this in main.c
		}
	}
}


  
void WIFI_u8SendData(u8 data){
	UART_voidSendData(data);
} 

u16 WIFI_u16ReceiveNumber() {
	u16 number = 0;
	char c;

	while (1) {
		c = UART_u8ReciveData(); // blocking read

		if (c >= '0' && c <= '9') {
			number = number * 10 + (c - '0'); // shift and add digit
			} else if (c == '\n' || c == '\r'|| c == '#') {
			break; // end of number
			} else if (c == ':') {
			continue; // skip separator
		}
	}

	return number; // e.g., 90, 180
}
