# stm32_delay
# --- Delay Function Based on SysTick ---
  This lib uses SysTick as time base to generate delays.
  delayInit() must be called every time the clock of the
  system change. Please check the performance notes of this
  lib below.
 
  When delayInit() is called, SysTick will be continuously
  running. In low power applications this may be important
  to know.
 
  Vinícius Müller Silveira - https://github.com/Vinimuller - 15/01/2020
 
  Perfomance notes of this lib running on stm32f334: (measured by toggling a gpio pin and analysing with an osciloscope)
  SysClock @ 72MHz:
  - Delay_us(1) results in a 1.9uS delay
  - Delay_us(5) results in a 5.3uS delay
  - Delay_ms(1) results in a 1mS delay
  - Delay_ms(5) results in a 5mS delay
  SysClock @ 8MHz:
  - Delay_us(1) results in a 5.3uS delay
  - Delay_us(5) results in a 7.7uS delay
  - Delay_us(50) results in a 50.8uS delay
  - Delay_us(100) results in a 101.5uS delay
  - Delay_ms(1) results in a 1mS delay
  - Delay_ms(5) results in a 5mS delay
