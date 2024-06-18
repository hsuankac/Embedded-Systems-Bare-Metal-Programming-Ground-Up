/*
 * tim.c
 *
 *  Created on: Jun 4, 2024
 *      Author: hsuankai.chang
 */
#include "stm32f4xx.h"

#define TIM2EN			(1U << 0)
#define CR1_CEN		(1U << 0)

void tim2_1hz_init(void)
{
	/*Enable clock access to TIM2*/
	RCC->APB1ENR |= TIM2EN;

	/*Set the pre-scalar value*/
	TIM2->PSC = 16000 - 1;			//16000000 / 1600 = 10000
	/*Set the auto-reload value*/
	TIM2->ARR = 10000 - 1;			//10000 / 10000 = 1
	/*Clear the timer counter*/
	TIM2->CNT = 0;
	/*Enable the timer*/
	TIM2->CR1 = CR1_CEN;
}
