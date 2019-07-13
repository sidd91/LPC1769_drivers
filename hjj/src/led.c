/*
 * led.c
 *
 *  Created on: Jun 27, 2019
 *      Author: siddharthchawla
 */


#include "led.h"



static PIN p1;



//array of pointers to
//will this take small space than LPC_GPIO_TypeDef gpio_config[5];
static LPC_GPIO_TypeDef *gpio_config[5] = {LPC_GPIO0, LPC_GPIO1, LPC_GPIO2, LPC_GPIO3, LPC_GPIO4};

void set_mode(mode);

void init_as_gpio(uint8_t pin){

	if(pin <= 31 && pin >= 0)
		p1.pin_num = pin;
	else
		return; // the value of the pin is not valid simply return
}

void set_direction(uint8_t pin_num, port port, direction dir){

	if(dir == input)
	{
		//set the pin as input
		gpio_config[port]->FIODIR &= ~(1 << pin_num);
	}

	if(dir == output)
	{
		//set the pin as output
		gpio_config[port]->FIODIR |= (1 << pin_num);
	}
}

void set_pin(port port, uint8_t pin_num){

	//set the bit
	gpio_config[port]->FIOSET |= (1 << pin_num);

}

void clear_pin(port port, uint8_t pin_num){

	//clear the bit
	gpio_config[port]->FIOCLR |= (1 << pin_num);
}

bool get_pin(port port, uint8_t pin_num){

	return (gpio_config[port]->FIOPIN & (1<<pin_num));
}

void LED_toggle(port port, uint8_t pin_num)
{
	gpio_config[port]->FIOPIN ^= (1 << pin_num);
}
