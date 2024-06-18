#include <stdint.h>
#include "stm32f4xx.h"

#define	GPIOAEN				(1U << 0)
#define UART2EN				(1U << 17)

#define CR1_TE				(1U << 3)
#define CR1_UE				(1U << 13)
#define SR_TXE				(1U << 7)

#define SYS_FREQ			(16000000)
#define APB1_CLK			SYS_FREQ

#define UART_BAUDRATE		(115200)

static void 		uart_set_baudrate(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate);
static uint16_t 	conpute_uart_bd(uint32_t periphclk, uint32_t baudrate);
void 				uart2_write(int ch);
void 				uart2_tx_init(void);

int main()
{
	uart2_tx_init();
	while(1)
	{
		uart2_write('Y');
	}
}

void uart2_tx_init(void)
{
	/*Configure the UART GPIO pin*/
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	/*Set PA2 mode to alternate function mode*/
	GPIOA->MODER &= ~(1U << 4);
	GPIOA->MODER |= (1U << 5);
	/*Set PA2 alternate function type to UART_TX (AF07)*/
	GPIOA->AFR[0] |= (1U << 8);
	GPIOA->AFR[0] |= (1U << 9);
	GPIOA->AFR[0] |= (1U << 10);
	GPIOA->AFR[0] &= ~(1U << 11);

	/*Configure UART module*/
	/*Enable click access to uart2*/
	RCC->APB1ENR |= UART2EN;
	/*Configure baudrate*/
	uart_set_baudrate(USART2, SYS_FREQ, UART_BAUDRATE);
	/*Configure the transfer direction*/
	USART2->CR1 = CR1_TE;
	/*Enable UART module*/
	USART2->CR1 |= CR1_UE;
}

void uart2_write(int ch)
{
	/*Make sure the transmit data register is empty*/
	while(!(USART2->SR & SR_TXE)){}
	/*Write to transmit data register*/
	USART2->DR = (ch & 0xFF);
}


static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t periphclk, uint32_t baudrate)
{
	USARTx->BRR = conpute_uart_bd(periphclk, baudrate);
}


static uint16_t conpute_uart_bd(uint32_t periphclk, uint32_t baudrate)
{
	return (periphclk + (baudrate/2U)) / baudrate;
}







