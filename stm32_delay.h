#include "stm32f3xx.h"
/* --- Delay based on SysTick ---
 *
 * This lib uses SysTick as time base to generate delays.
 * delayInit() must be called every time the clock of the
 * system change. Please note the performance notes of this
 * lib below.
 *
 * When delayInit() is called, SysTick will be continuously
 * running. In low power applications this may be important
 * to know.
 *
 * Vinícius Müller Silveira - https://github.com/Vinimuller - 15/01/2020
 *
 * Perfomance notes of this lib running on stm32f334:
 * SysClock @ 72MHz:
 * - Delay_us(1) results in a 1.9uS delay
 * - Delay_us(5) results in a 5.3uS delay
 * - Delay_ms(1) results in a 1mS delay
 * - Delay_ms(5) results in a 5mS delay
 * SysClock @ 8MHz:
 * - Delay_us(1) results in a 5.3uS delay
 * - Delay_us(5) results in a 7.7uS delay
 * - Delay_us(50) results in a 50.8uS delay
 * - Delay_us(100) results in a 101.5uS delay
 * - Delay_ms(1) results in a 1mS delay
 * - Delay_ms(5) results in a 5mS delay
 */

#define DELAY_TICK_US 1000000   //Divisor factor to find how many ticks fits in 1uS
#define MIN_TICKS 40			//Min ticks that works without overloading the system

//Init SysTick and calculates the period
//of one tick.
void delayInit(void);

// Do delay for mSecs milliseconds
// max delay is 65535mS
void Delay_ms(const uint16_t mSecs);

// Do delay for uSecs microseconds
// max delay is 65535uS
void Delay_us(const uint16_t uSecs);

static uint8_t dF;
static int32_t ticks;
