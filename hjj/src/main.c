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


#define LED   2 //P0_2

void SysTick_Handler(void)
{
//	printf("%d\n",STCURR);
    LPC_GPIO0->FIOPIN ^= (1<<LED); /* Toggle the LED1 (P2_0) */
}

int main (void)
{

	SYSTICK_init();
    LPC_GPIO0->FIODIR |= (1<<LED);            /* Configure the Led Pin as Output */
    LPC_GPIO0->FIOCLR |= (1<<LED);

    while(1)
    {
    		Systick_Wait10ms(100);
    		LPC_GPIO0->FIOPIN ^= (1<<LED);
    }
}

//#define OUTPUT   2
//#define INPUT    3
//
//
//// TODO: insert other include files here
//
//// TODO: insert other definitions and declarations here
//
//void isr()
//{
//	LED_toggle(port0, OUTPUT);
//}
//
//void SysTick_Handler()
//{
//	isr();
//	printf("Inside\n");
//}
//
//
//int main(void) {
//
//	SYSTICK_enable_1ms_interrupts();
//
//	set_direction(INPUT, port0, input);
//	set_direction(OUTPUT, port0, output);
//
//	clear_pin(port0, INPUT);
//	clear_pin(port0, OUTPUT);
//
//    while(1) {
//
////    	printf("%d\n", SystemCoreClock);
////
////    	if((LPC_GPIO0->FIOPIN &(1<<INPUT)))
////		{
////    		clear_pin(port0, OUTPUT);
////		}
////    	else{
////    		set_pin(port0, OUTPUT);
////    	}
//
//    }
//    return 0 ;
//}
