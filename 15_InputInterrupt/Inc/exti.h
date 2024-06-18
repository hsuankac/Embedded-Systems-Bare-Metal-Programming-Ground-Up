/*
 * exti.h
 *
 *  Created on: Jun 5, 2024
 *      Author: hsuankai.chang
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f4xx.h"
void pc13_exit_init(void);

#define LINE13				(1U << 13)

#endif /* EXTI_H_ */
