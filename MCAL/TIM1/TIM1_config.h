/*
 * TIM1_config.h
 *
 * Created: 11/8/2025 10:20:23 AM
 *  Author: HASSAN ARIF
 */ 


#ifndef TIM1_CONFIG_H_
#define TIM1_CONFIG_H_

/*defne the prescaler*/
#define TIM1_8_PRESCALER    2
#define TIM1_64_PRESCALER    3
#define TIM1_256_PRESCALER    4
#define TIM1_1024_PRESCALER    5

//select your prescaler
#define TIM1_PRESCALER  TIM1_64_PRESCALER
  
  
  //select top val
  
  #define TOP_val   40000



#endif /* TIM1_CONFIG_H_ */