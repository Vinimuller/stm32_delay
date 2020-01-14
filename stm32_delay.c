#include "stm32_delay.h"

void delayInit(void)
{
	SystemCoreClockUpdate();
	SysTick->LOAD	= (SystemCoreClock / DELAY_TICK_FREQUENCY_US) - 1;
	SysTick->VAL	= 0;
	SysTick->CTRL	= SysTick_CTRL_CLKSOURCE_Msk |
			SysTick_CTRL_ENABLE_Msk;
}

// Do delay for mSecs milliseconds
void Delay_ms(uint32_t mSecs)
{
	while(mSecs)
	{
		Delay_us(1000);
		mSecs--;
	}
}

// Do delay for nSecs microseconds
void Delay_us(uint32_t uSecs)
{
	while(uSecs)
	{
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
		uSecs--;
	}
}
