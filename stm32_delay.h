#include "stm32l0xx.h"

/* --- Delay based in Timer ---
 * This is a delay library that uses a timer for its time base.
 *
 * Running this on systems at clockspeed = 32MHz gives you an error
 * of 5us when calling Delay_us() with an value lower than 100
 *
 * Vinícius Müller Silveira - https://github.com/Vinimuller - 30/05/28
 */

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
