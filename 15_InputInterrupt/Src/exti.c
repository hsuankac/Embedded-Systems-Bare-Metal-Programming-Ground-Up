/*
 * exti.c
 *
 *  Created on: Jun 5, 2024
 *      Author: hsuankai.chang
 */

#include "exti.h"
#define GPIOCEN			(1U << 2)
#define SYSCFGEN		(1U << 14)

void pc13_exit_init(void)
{
	/*Disable global interrupt*/
	__disable_irq();

	/*Enable clock access for GPIOC*/
	RCC->AHB1ENR |= GPIOCEN;

	/*Set PC13 as input*/
	GPIOC->MODER &= ~(1U << 26);
	GPIOC->MODER &= ~(1U << 27);

	/*Enable clock access to SYSCFG*/
	RCC->APB2ENR |= SYSCFGEN;

	/*Select PORTC for EXTI13*/
	SYSCFG->EXTICR[3] |= (1U << 5);

	/*Un-mask EXTI13*/
	EXTI->IMR |= (1U << 13);

	/*Select falling edge trigger*/
	EXTI->FTSR |= (1U << 13);

	/*Enable EXTI line in NVIC*/
	NVIC_EnableIRQ(EXTI15_10_IRQn);

	/*Enable global interrupt*/
	__enable_irq();
}
