// Where is the led connected?
// Port: A
// Pin:	 5
#include <stdint.h>

#define PERIPH_BASE 				(0x40000000UL)
#define AHB1PERIPH_OFFSET			(0x20000UL)
#define	AHB1PERIPH_BASE				(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define	GPIOA_OFFSET				(0x0000UL)	//0x0000 0000
#define GPIOA_BASE					(AHB1PERIPH_BASE + GPIOA_OFFSET)
#define	RCC_OFFSET					(0x3800UL)
#define	RCC_BASE					(AHB1PERIPH_BASE + RCC_OFFSET)
#define	GPIOAEN						(1U << 0)
#define PIN5						(1U << 5)
#define LED_PIN						PIN5
#define __IO						volatile

typedef struct
{
    __IO uint32_t MODER;			/*GPIO port mode register*/
    __IO uint32_t DUMMY[4];
    __IO uint32_t ODR;				/*GPIO port output type register*/
}GPIO_TypeDef;

typedef struct
{
	__IO uint32_t DUMMY[12];
	__IO uint32_t AHB1ENR;
}RCC_TypeDef;

#define RCC							((RCC_TypeDef*)RCC_BASE)
#define GPIOA						((GPIO_TypeDef*)GPIOA_BASE)


int main()
{
	/*1. Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/*2. Set PA5 as output pin */
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &=~(1U << 11);

	while(1)
	{
		GPIOA->ODR ^= LED_PIN;
		for(int i = 0; i < 100000; i++);
	}
}












