#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "adc.h"
#include "systick.h"

#define	GPIOAEN						(1U << 0)
#define PIN5						(1U << 5)
#define LED_PIN						PIN5



int main()
{
	/*1. Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/*2. Set PA5 as output pin */
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &=~(1U << 11);

	uart2_rxtx_init();

	while(1)
	{
		printf("A second passed!! \n\r");
		GPIOA->ODR ^= LED_PIN;
		systickDelayMs(1000);
	}
}












