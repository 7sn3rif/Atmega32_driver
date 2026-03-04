/*
 * RTOS_prog.c
 *
 * Created: 11/28/2025 10:48:56 AM
 *  Author: HASSAN ARIF
 */
#include "../LIB/STD_TYPE.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/TIM0/TIM0_config.h"
#include "../MCAL/TIM0/TIM0_interface.h"
#include "RTOS_interface.h"

Task_type Task_arr[Task_num] = {0};

  void RTOS_voidCreateTask(void(*task_ptr)(void), u16 perodicity, u8 priority){
	Task_arr[priority].periodicity=perodicity;
	Task_arr[priority].Task_fun=task_ptr;
	Task_arr[priority].Task_State=RESUME;
	
}

static void RTOS_voidScheduler(){
	static u16 count=0;
	u8 task_count=0;
	count++;
	for(task_count=0;task_count<Task_num;task_count++){
		if(Task_arr[task_count].Task_fun != 0 &&
		(count % Task_arr[task_count].periodicity) == 0 &&
		Task_arr[task_count].Task_State == RESUME){
			Task_arr[task_count].Task_fun();
		}
	}
}

void RTOS_voidStart(){
	TIM0_voidInit(CTC_MODE);
	TIM0_voidSetCallBack(RTOS_voidScheduler,CTC_MODE);
}


void RTOS_voidSuspendTask(u8 priority){
	Task_arr[priority].Task_State=SUSPEND;
	
}

void RTOS_voidResumeTask(u8 priority){
	Task_arr[priority].Task_State=RESUME;
	
}

void RTOS_voidDeleteTask(u8 priority){
	
	        Task_arr[priority].Task_fun = 0;
	        Task_arr[priority].Task_State = SUSPEND;
	        Task_arr[priority].periodicity = 0;
}