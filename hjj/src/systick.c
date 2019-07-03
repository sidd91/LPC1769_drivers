/*
 * systick.c
 *
 *  Created on: Jul 2, 2019
 *      Author: siddharthchawla
 */


#include "LPC17xx.h"

#define STCTRL   *((unsigned volatile int*) 0xE000E010)
#define STRELOAD *((unsigned volatile int*) 0xE000E014)
#define VAL   *((unsigned volatile int*) 0xE000E018)
#define STCALIB  *((unsigned volatile int*) 0xE000E01C)

#define SYSTICK_ENABLE   0
#define TICKINT          1
#define CLKSOURCE        2

#define RELOAD_1MS       99999
#define RELOAD_10MS     999999

//initialize systick timer with default timer of 10ms
uint8_t SYSTICK_init()
{
    STCTRL = 0; //disable SysTick
    STRELOAD = (SystemCoreClock/100) -1 ;
    VAL = 0;
    STCTRL = 5; //enable systick and clocksource = cpu clock

    return 1;
}

//This function will enable the default 10ms interrupts
uint8_t SYSTICK_init_with_interrupts()
{
	STCTRL = 0;
	STCTRL |= (1<<TICKINT);
	SYSTICK_init();

	return 1;
}

void Systick_Wait10ms(uint32_t delayUnits)
{
	if((STCTRL & (3 << 0)) == 0x1)         //check if the interrupt is off and the systick is enable
	{
		for(int i=0; i< delayUnits; i++)
			{
				VAL = 0;
				while((SysTick->CTRL & 0x00010000) == 0);
			}
	}
}




