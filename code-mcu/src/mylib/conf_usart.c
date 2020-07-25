#include "mylib/conf_usart.h"
#include <asf.h>

//Defining USART parameters

static usart_rs232_options_t USART_WIFI = {
	.baudrate = USART_SERIAL_BAUDRATE,
	.charlength = USART_SERIAL_CHAR_LENGTH,
	.paritytype = USART_SERIAL_PARITY,
	.stopbits = USART_SERIAL_STOP_BIT
};

static usart_rs232_options_t USART_SIM = {
	.baudrate = USART_SERIAL_BAUDRATE,
	.charlength = USART_SERIAL_CHAR_LENGTH,
	.paritytype = USART_SERIAL_PARITY,
	.stopbits = USART_SERIAL_STOP_BIT
};

static usart_rs232_options_t USART_COM = {
	.baudrate = USART_SERIAL_BAUDRATE,
	.charlength = USART_SERIAL_CHAR_LENGTH,
	.paritytype = USART_SERIAL_PARITY,
	.stopbits = USART_SERIAL_STOP_BIT
};


void USARTS_inits(void)
{
	
	//Enabling system port clocks
	sysclk_enable_module(SYSCLK_PORT_C, PR_USART0_bm); //Enable USARTC0 clock
	usart_init_rs232(USART_SERIAL_WIFI, &USART_WIFI); //Enable RS232 mode

	sysclk_enable_module(SYSCLK_PORT_D, PR_USART0_bm); //Enable USARTD0 clock
	usart_init_rs232(USART_SERIAL_SIM, &USART_SIM); //Enable RS232 mode

	sysclk_enable_module(SYSCLK_PORT_E, PR_USART0_bm); //Enable USARTE0 clock
	usart_init_rs232(USART_SERIAL_COM, &USART_COM); //Enable RS232 mode

}


void sendTextMessage(uint8_t phoneNum, char * textMessage)
{
	received_byte = usart_getchar(USART_SERIAL_SIM);//receive byte
	usart_putchar(USART_SERIAL_WIFI, received_byte); //send byte
}


void publishMQTTSIM(uint8_t ip, char * pubMessage)
{
	received_byte = usart_getchar(USART_SERIAL_SIM);//receive byte
	usart_putchar(USART_SERIAL_WIFI, received_byte); //send byte
}


bool connectWIFI(const unsigned char * SSID, const unsigned char * password)
{
	bool ready = false;
	return ready;
}


void sendMQTTWIFI(uint8_t ip, char * pubMessage)
{
}


