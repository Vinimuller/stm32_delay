#include <stm32_delay.h>


// SysTick interrupt handler
void SysTick_Handler(void)
{
	if (TimingDelay != 0)
	{
		TimingDelay--;
	}else
	{
		SysTick->CTRL	= 0;
	}
}

// Do delay for mSecs milliseconds
void Delay_ms(uint32_t mSecs) {
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / DELAY_TICK_FREQUENCY_MS);
	TimingDelay = mSecs+1;
	while (TimingDelay != 0);
}

// Do delay for nSecs microseconds
void Delay_us(uint32_t uSecs) {
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / DELAY_TICK_FREQUENCY_US);
	TimingDelay = uSecs+1;
	while (TimingDelay != 0);
}
