#include "stm32_delay.h"

uint16_t pscMs;
uint16_t pscUs;


void delayInit(void)
{
	//Update SystemCoreClock var with clock value
	SystemCoreClockUpdate();

	//Timer configuration.
	RCC->APB1ENR	|= RCC_APB1ENR_TIM6EN; //Enable peripheral clock timer at RCC->APB1ENR register

	TIMER->CR1		= TIM_CR1_OPM | TIM_CR1_URS | TIM_CR1_ARPE;
	TIMER->CR2		= 0;

	pscMs	= (SystemCoreClock/DELAY_TICK_FREQUENCY_MS /MULTIPLIER_FACTOR) - 1;
	pscUs	= (SystemCoreClock/DELAY_TICK_FREQUENCY_US /MULTIPLIER_FACTOR) - 1;
}

// Do delay for mSecs milliseconds
void Delay_ms(uint32_t mSecs)
{
	TIMER->SR 		&= ~TIM_SR_UIF;
	TIMER->PSC		= pscMs;
	TIMER->ARR		= mSecs * MULTIPLIER_FACTOR;

	TIMER->EGR		|= TIM_EGR_UG;
	TIMER->CR1		|= TIM_CR1_CEN;
	while (!(TIMER->SR & TIM_SR_UIF));
}

// Do delay for nSecs microseconds
void Delay_us(uint32_t uSecs)
{
	TIMER->SR 		&= ~TIM_SR_UIF;
	TIMER->PSC		= pscUs;
	TIMER->ARR		= uSecs * MULTIPLIER_FACTOR;

	TIMER->EGR		|= TIM_EGR_UG;
	TIMER->CR1		|= TIM_CR1_CEN;
	while (!(TIMER->SR & TIM_SR_UIF));
}
