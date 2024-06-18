#include <stdio.h>
#include <stdint.h>
#include "uart.h"


int main()
{
	uart2_tx_init();
	while(1)
	{
		printf("Hello from STM32F4....\n\r");
	}
}












