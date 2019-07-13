/*
 * LiquidCrystal.h
 *
 *  Created on: Jul 6, 2019
 *      Author: siddharthchawla
 */

#ifndef LIQUIDCRYSTAL_H_
#define LIQUIDCRYSTAL_H_

#include "led.h"
#include <stdint.h>

typedef enum{
	mode4_bit,
	mode8_bit
}mode;

// write LCD 4bit form
//input: pin numbers to be used for driving LCD
//output: None   but can be bool if I
void init_LCD(uint8_t EN, uint8_t RS, uint8_t D7, uint8_t D6, uint8_t D5, uint8_t D4);

void clear_LCD();

void set_function_LCD();

// write LCD 4bit
//input: character to be written
//output: None
void write_LCD(char in);



#endif /* LIQUIDCRYSTAL_H_ */
