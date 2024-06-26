/*
 * uart.h
 *
 *  Created on: Jun 3, 2024
 *      Author: hsuankai.chang
 */

#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include "stm32f4xx.h"

#define HIFCR_CTCIF6		(1U << 21)
#define HISR_TCIF6			(1U << 21)
#define SR_RXNE				(1U << 5)
void 	uart2_rx_interrupt_init(void);
void	uart2_rxtx_init(void);
void 	uart2_write(int ch);
char 	uart2_read(void);
void 	dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);

#endif /* UART_H_ */
