/*
===============================================================================
 Name        : hjj.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include "led.h"
#include "systick.h"
#include "LiquidCrystal.h"


#define LED   2 //P0_2

void SysTick_Handler(void)
{
//	printf("%d\n",STCURR);
    LPC_GPIO0->FIOPIN ^= (1<<LED); /* Toggle the LED1 (P2_0) */
}

//SYSTICK_init();
//    LPC_GPIO0->FIODIR |= (1<<LED);            /* Configure the Led Pin as Output */
//    LPC_GPIO0->FIOCLR |= (1<<LED);
//
//
//    while(1)
//    {
//    		Systick_Wait10ms(100);
//    		LPC_GPIO0->FIOPIN ^= (1<<LED);
//    }

#define SwitchPinNumber 11
#define LedPinNumber    0


int main (void)
{

	LPC_GPIO2->FIOCLR = 0xffffffff;     // Make all the Port pins as high

	init_LCD(2, 3, 12, 11, 10, 8);

	char name[] = "Siddharth Chawla CMPE";

	for(int i=0; name[i]; i++)
		write_LCD(name[i]);



	while(1){
	}

}

