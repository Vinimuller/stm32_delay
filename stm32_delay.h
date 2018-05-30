#include "stm32l0xx.h"

#define DELAY_TICK_FREQUENCY_US 1000000   /* = 1MHZ -> microseconds delay */
#define DELAY_TICK_FREQUENCY_MS 1000   	  /* = 1kHZ -> milliseconds delay */
#define TIMER					TIM6
#define MULTIPLIER_FACTOR		16
/*
 *   Declare Functions
 */
extern void Delay_ms(uint32_t mSecs);
extern void Delay_us(uint32_t uSecs);
extern void delayInit(void);
