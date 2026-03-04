/*
 * KPD_prog.c
 *
 * Created: 9/25/2025 10:23:53 PM
 *  Author: HASSAN ARIF 
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"



u8 KPD_Data[4][4]=
{
	{1,2,3,'+'},
	{4,5,6,'-'},
	{7,8,9, '/'},
	{'c',0,'=','*'}
};  


 void KPD_voidInit(void){
	 
	 u8 ROW_Arr[4]={KPD_R0_PIN,KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN};
		 u8 COL_Arr[4]={KPD_C0_PIN,KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN};
 
  u8 loc_in=0 ;
  
  for (loc_in=0 ; loc_in< 4 ; loc_in++)
  {
	   /*init ROW  ---> INPUT /PULL UP */
	  
	  DIO_voidSetPinDir(KPD_ROW_PORT,ROW_Arr[loc_in],INPUT) ;
	  
	  DIO_voidSetPinVal(KPD_ROW_PORT,ROW_Arr[loc_in],HIGH)  ;
	  
	  /*init COL  --> OUTPUT / HIGH */
	  
	  DIO_voidSetPinDir(KPD_COL_PORT,COL_Arr[loc_in],OUTPUT) ;
	  DIO_voidSetPinVal(KPD_COL_PORT,COL_Arr[loc_in],HIGH)    ;
	  
  }
  
 
 
		 }
		 
		 
		 
	u8 KPD_u8GetKey(void){
		
		u8 ROW_Arr[4]={KPD_R0_PIN,KPD_R1_PIN,KPD_R2_PIN,KPD_R3_PIN} ;
		u8 COL_Arr[4]={KPD_C0_PIN,KPD_C1_PIN,KPD_C2_PIN,KPD_C3_PIN} ;
		
		u8 row=0 ,col=0 ;
		
		u8 val=0xff ;
		
		for (col=0 ; col<4;col++)
		{
			/*set col(n) ---> LOW */
			
			DIO_voidSetPinVal(KPD_COL_PORT,COL_Arr[col],LOW) ;
			
			for (row=0 ; row<4 ;row++)
			{
				
				if (DIO_u8ReadPinVal(KPD_ROW_PORT,ROW_Arr[row])==0)
				{
					while(DIO_u8ReadPinVal(KPD_ROW_PORT,ROW_Arr[row])==0) ;
					// get key
					val=KPD_Data[row][col] ;
					
					return val ;
					
					
					
				}
			}
			
			DIO_voidSetPinVal(KPD_COL_PORT,COL_Arr[col],HIGH) ;

		}
		
		
		return val ;
			}