/*
 * Uart.h
 *
 *  Created on: Jul 1, 2019
 *      Author: siddharthchawla
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
static int openFlag = 0;
typedef enum {
	UART2,
	UART3
}UART;

//IER, IIR, FCR, LCR, LSR

//Initialization UART
void UART_init(UART port, uint32_t baudrate);

//Wait for new serial input
char UART_InChar(void);

//Wait for a sequence of serial port input
void UART_InString(char *buffer, uint16_t maxSize);


//Input unsigned decimal
uint32_t UART_InUDec(void);

//Output 8-bit or a char to serial port
void UART_OutChar(char letter);

//Out sequence of byees to serial port
void UART_OutString(char *buffer);

//Output decimal to serial port
void UART_OutUDec(uint32_buffer);



#endif /* UART_H_ */
