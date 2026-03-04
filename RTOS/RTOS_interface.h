/*
 * RTOS_interface.h
 *
 * Created: 11/28/2025 10:48:17 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_
 
 #define Task_num 3
 #define RESUME   1
 #define SUSPEND  0
 
 
 
 typedef struct {
	void (*Task_fun)(void);
	u16 periodicity;
	u8  Task_State;

	
	} Task_type;
	void RTOS_voidStart();
	void RTOS_voidCreateTask(void(*task_ptr)(void), u16 perodicity, u8 priority);
	void RTOS_voidResumeTask(u8 priority);
	void RTOS_voidSuspendTask(u8 priority);
	void RTOS_voidDeleteTask(u8  priority);




#endif /* RTOS_INTERFACE_H_ */