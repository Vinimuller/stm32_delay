#include "stm32f3xx.h"
/* --- Delay based in Timer ---
 * This is a delay library that uses a timer for its time base.
 *
 * Running this on systems at clockspeed = 32MHz gives you an error
 * of 5us when calling Delay_us() with an value lower than 100
 *
 * Vinícius Müller Silveira - https://github.com/Vinimuller - 30/05/28
 *
 * Perfomance notes of this lib:
 * SysClock @ 72MHz:
 * - Delay_us(1) results in a 1.9uS delay
 * - Delay_us(5) results in a 5.3uS delay
 * - Delay_ms(1) results in a 1mS delay
 * - Delay_ms(5) results in a 5mS delay
 * SysClock @ 8MHz:
 * - Delay_us(1) results in a 15.4uS delay
 * - Delay_us(5) results in a 38.4uS delay
 * - Delay_ms(1) results in a 6mS delay
 * - Delay_ms(5) results in a 30mS delay
 */

#define DELAY_TICK_FREQUENCY_US 1000000   /* = 1MHZ -> microseconds delay */
/*
 *   Declare Functions
 */
void Delay_ms(uint32_t mSecs);
void Delay_us(uint32_t uSecs);
void delayInit(void);
