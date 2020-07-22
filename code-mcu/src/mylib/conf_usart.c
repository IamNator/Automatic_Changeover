#include "mylib/conf_usart.h"


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


bool connectWIFI()
{
	bool ready = false;
	return ready;
}


void sendMQTTWIFI()
{
	
}


