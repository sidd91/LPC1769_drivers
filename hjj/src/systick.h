/*
 * systick.h
 *
 *  Created on: Jul 2, 2019
 *      Author: siddharthchawla
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>
#include <stdbool.h>

//initialize systick timer
bool SYSTICK_init();

//This function will enable the default 10ms interrupts
bool SYSTICK_init_with_interrupts();

//wait for delayUnits*10ms
//input - delayUnits
//Output - N/A
void Systick_Wait10ms(uint32_t delayUnits);




#endif /* SYSTICK_H_ */
