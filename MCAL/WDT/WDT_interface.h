/*
 * WDT_interface.h
 *
 * Created: 11/14/2025 12:38:22 PM
 *  Author: HASSAN ARIF
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_
/*prescalers*/
#define WDT_16k_PRESCALER    0
#define WDT_32k_PRESCALER    1
#define WDT_64k_PRESCALER    2
#define WDT_128k_PRESCALER   3
#define WDT_256k_PRESCALER   4
#define WDT_512k_PRESCALER   5
#define WDT_1028k_PRESCALER   6
#define WDT_2048k_PRESCALER   7


#define WDT_PRESCALER   WDT_16k_PRESCALER 

void WDT_voidStart(u8 copy_u8time);
void WDT_voidStop();



#endif /* WDT_INTERFACE_H_ */