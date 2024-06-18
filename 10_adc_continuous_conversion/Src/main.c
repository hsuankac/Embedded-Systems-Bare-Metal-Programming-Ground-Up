#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "adc.h"

uint32_t sensor_value;

int main()
{
	uart2_rxtx_init();
	pa1_adc_init();
	start_conversion();

	while(1)
	{
		sensor_value = adc_read();
		printf("Sensor value is: %ld\n\r", sensor_value);
	}
}












