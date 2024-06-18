#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "adc.h"

uint32_t sensor_value;
static void adc_callback(void);

int main()
{
	uart2_rxtx_init();
	pa1_adc_interrupt_init();
	start_conversion();

	while(1)
	{
	}
}


static void adc_callback(void)
{
	sensor_value = ADC1->DR;
	printf("Sensor value is: %ld\n\r", sensor_value);
}


void ADC_IRQHandler(void)
{
	/*Check for EOC in SR*/
	if(ADC1->SR & SR_EOC)
	{
		/*Clear EOC*/
		ADC1->SR &= ~SR_EOC;

		/*Do something*/
		adc_callback();
	}
}











