/*
 * LiquidCrystal.c
 *
 *  Created on: Jul 7, 2019
 *      Author: siddharthchawla
 */


#include "systick.h"
#include "LPC17xx.h"
#include "LiquidCrystal.h"

typedef struct{
	uint8_t EN,
	RS,
	D7,
	D6,
	D5,
	D4;
}LCD_typedef;

typedef union{
    	uint32_t databus;
    	struct{
    		uint32_t b0_7 : 8,
    		          b8 : 1,
					  b9:1, //not used
    		          b10_12 : 3,
    		          b13_31 : 19;
    	};

    }LCDBUS_typedef;

static LCDBUS_typedef LCDBUS;
static LCD_typedef LCD;

#define FOUR_BIT_MODE		   32
#define FUNCTION_SET_2LINES    40
#define DISPLAY_ON_CURSOR_ON  15
#define ENTRYMODE             6

static void write_first_nibble(char in)
{
	LPC_GPIO2->FIOCLR |= (0x1D <<8);
	LCDBUS.b8 = ((in >>4) & 1);
	LCDBUS.b10_12 = ((in >>5) & 0x7);
	LPC_GPIO2->FIOSET |= LCDBUS.databus;
}

static void clear_bits()
{
	LCDBUS.b8 = 0x0;
	LCDBUS.b10_12 = 0x0;
}

void set_mode(mode m)
{
		int i= 60;
		clear_pin(port0, LCD.RS);
			//wait for 60ns address set up time
		while(i--);
		set_pin(port0, LCD.EN);

		//first nibble
		write_first_nibble(FUNCTION_SET_2LINES);

		i =50; while(i--);   // delay of 500ns for Datasetup time and hold time
		clear_pin(port0, LCD.EN);
		clear_bits();

		i =50; while(i--);
}

static void write_second_nibble(char in)
{
	LPC_GPIO2->FIOCLR |= (0x1D <<8);
	LCDBUS.b8 = ((in) & 1);
	LCDBUS.b10_12 = ((in >> 1) & 0x7);
	LPC_GPIO2->FIOSET |= LCDBUS.databus;
}

static void write_LCD_config(char in)
{

	int i= 60;
	clear_pin(port0, LCD.RS);
		//wait for 60ns address set up time
	while(i--);
	set_pin(port0, LCD.EN);

	//first nibble
	write_first_nibble(in);
	printf("%2x %2x %2x\n", LCDBUS.b8, LCDBUS.b10_12, ((in >>4) & 0x0D));

	i =50; while(i--);   // delay of 500ns for Datasetup time and hold time
	clear_pin(port0, LCD.EN);
	clear_bits();

	i= 500;while(i--);

	set_pin(port0, LCD.EN);
	write_second_nibble(in);

	i= 500;while(i--);
	clear_pin(port0, LCD.EN);
	clear_bits();

	i =50;
	while(i--);
}


void init_LCD(uint8_t EN, uint8_t RS, uint8_t D7, uint8_t D6, uint8_t D5, uint8_t D4)
{

	LCD.EN = EN;
	LCD.RS = RS;
	LCD.D7 = D7;
	LCD.D6 = D6;
	LCD.D5 = D5;
	LCD.D4 = D4;

	port PORT = port0;
	port PORT2 = port2;
	set_direction(EN, port0, output);
	set_direction(RS, port0, output);
	set_direction(D7, port2, output);
	set_direction(D6, port2, output);
	set_direction(D5, port2, output);
	set_direction(D4, port2, output);

	LPC_GPIO2->FIOCLR |= 0xffffffff;     // Make all the Port pins as low


	LCDBUS.databus = 0xFFFFFFFF;
	LCDBUS.b8 = 0;
	LCDBUS.b10_12 = 0;

	set_mode(FOUR_BIT_MODE);
	write_LCD_config((char)FUNCTION_SET_2LINES);
	write_LCD_config((char)DISPLAY_ON_CURSOR_ON);
	write_LCD_config(ENTRYMODE);

}



void write_LCD(char in)
{
	    int i= 60;
		set_pin(port0, LCD.RS);
			//wait for 60ns address set up time
		while(i--);
		set_pin(port0, LCD.EN);

		//first nibble
		write_first_nibble(in);
		printf("%2x %2x %2x\n", LCDBUS.b8, LCDBUS.b10_12, ((in >>4) & 0x0D));

		i =50; while(i--);   // delay of 500ns for Datasetup time and hold time
		clear_pin(port0, LCD.EN);
		clear_bits();

		i= 500;while(i--);

		set_pin(port0, LCD.EN);
		write_second_nibble(in);

		i= 500;while(i--);
		clear_pin(port0, LCD.EN);
		clear_bits();

		i =50;
		while(i--);

}

