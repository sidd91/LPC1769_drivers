/*
 * led.h
 *
 *  Created on: Jun 27, 2019
 *      Author: siddharthchawla
 */

#ifndef LED_H_
#define LED_H_

#include "LPC17xx.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	uint8_t pin_num;
}PIN;

typedef enum{
	port0,
	port1,
	port2,
	port3,
	port4
}
port;

typedef enum {
	input =0,
	output = 1
}direction;

//initialization the pin as gpio
void init_as_gpio(uint8_t pin);

//set direction of the pin
void set_direction(uint8_t pin_num, port port, direction dir);

//set the pin
void set_pin(port port, uint8_t pin_num);

//clear the pin
void clear_pin(port port, uint8_t pin_num);

//if pin is set or not
bool get_pin(port port,uint8_t pin_num);

void LED_toggle(port port, uint8_t pin_num);




#endif /* LED_H_ */
