#include "stm32_delay.h"

static uint8_t dF = 1;
static int32_t ticks = 0;

//Init SysTick
void delayInit(void)
{
	//Updates SystemCoreClock var
	//If using HSE, be sure that the function is returning the right value
	SystemCoreClockUpdate();

	//In order to improve accuracy, when using a system clock lower than 48MHz,
	//we will use MIN_TICKS as a time base. This means that one tick is equal
	//to dF microseconds. When system clock is greater or equal to 48MHz, one
	//tick equals to 1 microsecond.
	if(SystemCoreClock >= 48000000)
	{
		SysTick->LOAD	= (SystemCoreClock / DELAY_TICK_US) - 1;
		dF = 1;
	}
	else
	{
		SysTick->LOAD	= MIN_TICKS - 1; //Minimum value
		dF = MIN_TICKS / (SystemCoreClock / DELAY_TICK_US);
	}
	SysTick->VAL	= 0;
	//SysTick clock source is SYSCLK
	SysTick->CTRL	= SysTick_CTRL_CLKSOURCE_Msk |
			SysTick_CTRL_ENABLE_Msk;
}

// Do delay for mSecs milliseconds
// max delay is 65535mS
void Delay_ms(const uint16_t mSecs)
{
	ticks = mSecs * 1000 / dF; //Calculates the number of ticks
	while(ticks)
	{
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
		ticks--;
	}
}

// Do delay for uSecs microseconds
// max delay is 65535uS
void Delay_us(const uint16_t uSecs)
{
	ticks = uSecs / dF;//Calculates the number of ticks
	while(ticks)
	{
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
		ticks--;
	}
}
