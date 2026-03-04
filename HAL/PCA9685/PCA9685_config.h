/*
 * PCA9685_config.h
 *
 * Created: 12/23/2025 4:59:05 AM
 *  Author:HASSAN ARIF
 */ 


#ifndef PCA9685_CONFIG_H_
#define PCA9685_CONFIG_H_
/*PCA Address*/
#define PCA9685_ADDRESS   0x40






/* Core control registers */
#define PCA9685_MODE1_REG        0x00   // Mode register 1 (sleep, auto-increment, restart)
#define PCA9685_MODE2_REG        0x01   // Mode register 2 (output driver config)

/* Frequency control */
#define PCA9685_PRE_SCALE_REG    0xFE   // Prescaler for PWM frequency (sets refresh rate)

/* LED channel base addresses (each channel has 4 registers) */
#define PCA9685_LED0_ON_L        0x06   // LED0 ON low byte
#define PCA9685_LED0_ON_H        0x07   // LED0 ON high byte
#define PCA9685_LED0_OFF_L       0x08   // LED0 OFF low byte
#define PCA9685_LED0_OFF_H       0x09   // LED0 OFF high byte

/* Macros to compute LEDn register addresses */
#define PCA9685_LED_ON_L(n)      (0x06 + 4*(n))
#define PCA9685_LED_ON_H(n)      (0x07 + 4*(n))
#define PCA9685_LED_OFF_L(n)     (0x08 + 4*(n))
#define PCA9685_LED_OFF_H(n)     (0x09 + 4*(n))

/*angles*/
#define MAX_ANGLE 180
#define MIN_ANGLE 0
#define MIN_PUlSE 205
#define MAX_PUlSE 410




#endif /* PCA9685_CONFIG_H_ */