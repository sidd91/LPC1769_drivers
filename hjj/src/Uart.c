//
//
//
//#include "Uart.h"
//#include "LPC17xx.h"
//
////LPC
////UART 2
////TXD2 P0.10 J2-40
////RXD2 p0.11 J2-41
//
////UART3 P0.0 TXD3/SDA1 j2-9
////      P0.1 RXD3/SCL1 j2-10
//
//
//#define UART2_CLKSEL  0x00010000  // CCLK
//#define UART3_CLKSEL  0x00040000  // CCLK
//#define UART2_PCONP   0x01000000
//#define UART3_PCONP   0x02000000
//#define ENABLE_FIFO   0x1
//#define RDA_INT       0x2
//#define THRE_INT      0x1
//
//
////static void (*UART_ISR)();
//
//static typedef union{
//	uint8_t LCR;
//	struct{
//		uint32_t
//				word_length:2,
//				stop_bit :1,
//				parity_bit:1,
//				parity_select:2,
//				break_control:2,
//				DLAB:1 = 1;  //Divisor latch access bit
//	};
//}UART_LCR_config;
//
//static LPC_UART_TypeDef const *UARTRegBase_reg[2] = {(LPC_UART_TypeDef*)(LPC_UART2_BASE), (LPC_UART_TypeDef*)(LPC_UART3_BASE)};
//static LPC_UART_TypeDef *	mpUARTRegBase;
//
//static void setbaudrate(uint32_t baudrate)
//{
//	uint32_t pclk = SystemCoreClock ; 					//UART clock divider  = 1
//	UART_LCR_config *lcr_val = &(mpUARTRegBase -> LCR);
//
//	lcr_val->DLAB =1; 		//enable DLAB to access DLL and DLM
//	{
//	    uint16_t dlm_dll = pclk /((16*baudrate) + 0.5);
//	    mpUARTRegBase ->DLL = dlm_dll;
//	    mpUARTRegBase ->DLM = (dlml_dll >> 8);
//	}
//
//	//disable DLAB and set word_length =8
//	lcr_val->LCR = 3;
//
//}
//
//void UART_init(UART port, uint32_t baudrate)
//{
//
//	if(port == UART2)
//	{
//		LPC_SC->PCONP |= UART2_PCONP;
//		LPC_SC->PCLKSEL1 |= UART2_CLKSEL;     // set the peripheral clock
//		LPC_PINCON->PINSEL0 |= (0x05 << 19); // Enable RXD2 and TXD2
//		NVIC_EnableIRQ(UART2_IRQn);
//		openFlag++;
//	}
//	else if(port == UART3)
//	{
//		LPC_SC->PCONP |= UART3_PCONP;
//		LPC_SC->PCLKSEL1 |= UART3_CLKSEL;
//		LPC_PINCON->PINSEL0 |= (0xA);       //Enable TXD3 and RXD3
//		NVIC_EnableIRQ(UART3_IRQn);
//		openFlag++;
//	}
//	mpUARTRegBase = UARTRegBase_reg[port];  //
//	mpUARTRegBase -> FCR = ENABLE_FIFO;
//	mpUARTRegBase -> IER |= (3<<0);   //Enable RBR and THR interrupt for the port
//
//	setbaudrate(baudrate);
//
//	//Enable interrupts on the port
//}
//
//void UART_ISR()
//{
//	uint32_t interrupt_reason = ((mpUARTRegBase -> IIR) & 0xE);
//	switch(interrupt_reason)
//	{
//	  case(RDA_INT):
//			  get_data();
//			  break;
//
//	  case(THRE_INT):
//			  send_data();
//			  break;
//
//	}
//}
//
//static char get_data()
//{
//	char data;
//	if(mpUARTRegBase -> LSR & 1)
//	{
//		data = mpUARTRegBase -> RBR;
//	}
//	return data;
//}
//
//static void send_data(char data)
//{
//	if((mpUARTRegBase -> LSR & (1 << 5)))
//	{
//		mpUARTRegBase -> THR = data;
//	}
//}
//
////Wait for new serial input
//char UART_InChar(void)
//{
//	return get_data();
//}
//
////Output 8-bit or a char to serial port
//void UART_OutChar(char letter)
//{
//	send_data(letter);
//}
//
//
//
