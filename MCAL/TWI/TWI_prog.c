/*
 * TWI_prog.c
 *
 * Created: 11/22/2025 12:56:15 PM
 *  Author: HASSAN ARIF
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "TWI_interface.h"
#include "TWI_reg.h" 



void TWI_voidMasterInit(u8 copy_u8address) {
	
	/*set SCL freq : 400khz , With Fs = 16MHZ 
	 
	 TWBR = 12 
	
	*/
	TWBR_REG =12 ; 
	
	
	/*Set prescaler : 1 */
	
	CLR_BIT(TWSR_REG,0) ;
	CLR_BIT(TWSR_REG,1) ; 
	
	 if (copy_u8address !=0 )
	 {
		 TWAR_REG=copy_u8address <<1; 
	 }
	 else{
		 // DO nothing 
	 }
	
	/*Enable ACK */
	SET_BIT(TWCR_REG,6) ; 
	/*Enable TWI */
     SET_BIT(TWCR_REG,2) ; 
	
	
}

void TWI_voidSlaveInit( u8 copy_u8address) {
	       /* set slave address */
		 TWAR_REG=copy_u8address <<1; 
	    
	       /*Enable ACK */
	       SET_BIT(TWCR_REG,6) ;
	       /*Enable TWI */
	       SET_BIT(TWCR_REG,2) ;
	
	
	
}


Err_status TWI_Err_statusSendStartCondition(void) {
	
	Err_status LOc_Err=NOErr ; 
	
	  /* set start condition */
	
	  SET_BIT(TWCR_REG,5) ; 
	  
	  /*clr the interrupt flag to start the next operation  */
	
	   SET_BIT(TWCR_REG,7) ; 
	   
		while(GET_BIT(TWCR_REG,7)==0) ; 
		
		 if ((TWSR_REG&0xf8) != START_ACK)
		 {
			 LOc_Err = StartConditionErr ; 
			 
		 }
		  else {
			   // DO nothing 
		  }
		
	
	
	
	return LOc_Err ; 
	
	
}
Err_status TWI_Err_statusSendRepeatedStart(void) {
	
	Err_status LOc_Err=NOErr ;
	
	/* set start condition */
	
	SET_BIT(TWCR_REG,5) ;
	
	/*clr the interrupt flag to start the next operation  */
	
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if ((TWSR_REG&0xf8) != REP_START)
	{
		LOc_Err = RepeatedStartErr ;
		
	}
	else {
		// DO nothing
	}
	
	
	
	
	return LOc_Err ;

}

Err_status TWI_Err_statusMasterSendSlaveAddessWithWrtie(u8 copy_u8address) {
	
	
	Err_status LOc_Err=NOErr ;
	
	
	    /*set the 7 bit  S/A  on the bus  */
	   
	    TWDR_REG = copy_u8address<<1 ; 
	    CLR_BIT(TWDR_REG,0) ; 
		
		/*CLR Start condition */
	
	    CLR_BIT(TWCR_REG,5) ; 
		
	/*clr the interrupt flag to start the next operation  */
	
	SET_BIT(TWCR_REG,7) ;
	
	while(GET_BIT(TWCR_REG,7)==0) ;
	
	if ((TWSR_REG&0xf8) != SLAVE_ADD_AND_WR_ACK)
	{
		LOc_Err = MasterSendSlaveAddessWithWrtieErr ;
		
	}
	else {
		// DO nothing
	}
	
	
	return LOc_Err ;
	

}
Err_status TWI_Err_statusMasterSendSlaveAddessWithRead(u8 copy_u8address) {
	

Err_status LOc_Err=NOErr ;


/*set the 7 bit  S/A  on the bus  */

TWDR_REG = copy_u8address<<1 ;
CLR_BIT(TWDR_REG,0) ;

/*CLR Start condition */

SET_BIT(TWCR_REG,5) ;

/*clr the interrupt flag to start the next operation  */

SET_BIT(TWCR_REG,7) ;

while(GET_BIT(TWCR_REG,7)==0) ;

if ((TWSR_REG&0xf8) != SLAVE_ADD_AND_RR_ACK)
{
	LOc_Err = MasterSendSlaveAddessWithReadErr ;
	
}
else {
	// DO nothing
}


return LOc_Err ;
	
	
	
}


Err_status TWI_Err_statusMasterSendData(u8 copy_u8data) {

		Err_status LOc_Err=NOErr ;
		
		/*SEND DATA om bus */
		
		TWDR_REG =copy_u8data ; 
		
		/*clr the interrupt flag to start the next operation  */

		SET_BIT(TWCR_REG,7) ;

		while(GET_BIT(TWCR_REG,7)==0) ;

		if ((TWSR_REG&0xf8) != MASTER_WR_BYTE_ACK)
		{
			LOc_Err = MasterSendDataErr ;
			
		}
		else {
			// DO nothing
		}
		
		
		
		
		
		
		
		
		return LOc_Err ;
}
Err_status TWI_Err_statusMasterReciveData(u8 *copy_u8data) {
			Err_status LOc_Err=NOErr ;
				
			/*clr the interrupt flag to start the next operation  */

			SET_BIT(TWCR_REG,7) ;

			while(GET_BIT(TWCR_REG,7)==0) ;

			if ((TWSR_REG&0xf8) != MASTER_RD_BYTE_WITH_ACK)
			{
				LOc_Err = MasterReciveDataErr ;
				
			}
			else {
			
			  *copy_u8data = TWDR_REG ; 
			}
			
			
		return LOc_Err ;
		
			
}

void TWI_voidSendStopCondition(void) {
	
	/*send stop condition */
	
	SET_BIT(TWCR_REG,4) ; 
	
		/*clr the interrupt flag to start the next operation  */

		SET_BIT(TWCR_REG,7) ;
}





Err_status TWI_Err_statusSlaveACKOrNotACK() {
	
	Err_status LOc_Err=NOErr ;
			
		
		/*Enable ACK */
		SET_BIT(TWCR_REG,6) ;
		/*Enable TWI */
		SET_BIT(TWCR_REG,2) ;
			/*clr the interrupt flag to start the next operation  */

			SET_BIT(TWCR_REG,7) ;

			while(GET_BIT(TWCR_REG,7)==0) ;

			if ((TWSR_REG&0xf8) != SLAVE_ADD_RCVD_WD_REQ)
			{
				LOc_Err = SlaveACKOrNotACKErr ;
				
			}
			else {
				// DO nothing
			}
			
	
	
	
	
	
	
		return LOc_Err ;
	
}


u8 TWI_u8SlaveReciveData(void) {
	
		
		/*Enable ACK */
		SET_BIT(TWCR_REG,6) ;
		/*Enable TWI */
		SET_BIT(TWCR_REG,2) ;
		/*clr the interrupt flag to start the next operation  */

		SET_BIT(TWCR_REG,7) ;

		while(GET_BIT(TWCR_REG,7)==0) ;
		
		return TWDR_REG ; 
	
	
	
	
	
	
}
