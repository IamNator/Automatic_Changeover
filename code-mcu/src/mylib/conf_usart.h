
#ifndef DRIVERS_H
#define DRIVERS_H


#include <avr/io.h>
#include <asf.h>
#include <util/delay.h>
#include <stdint.h>



 //* - Using USARTD0
 //* - Baudrate: 9600
 //* - Character length: 8 bit
 //* - Parity mode: Disabled
 //* - Stop bit: None
 //* - RS232 mode
 
 #define USART_SERIAL_WIFI                &USARTC0
 #define USART_SERIAL_BAUDRATE            9600                     //
 #define USART_SERIAL_CHAR_LENGTH         USART_CHSIZE_8BIT_gc
 #define USART_SERIAL_PARITY              USART_PMODE_DISABLED_gc  // USART_PMODE_EVEN_gc or  USART_PMODE_ODD_gc
 #define USART_SERIAL_STOP_BIT            false					   //true
 
  #define USART_SERIAL_SIM                 &USARTD0
  #define USART_SERIAL_BAUDRATE            9600
  #define USART_SERIAL_CHAR_LENGTH         USART_CHSIZE_8BIT_gc
  #define USART_SERIAL_PARITY              USART_PMODE_DISABLED_gc
  #define USART_SERIAL_STOP_BIT            false
  
  
   #define USART_SERIAL_COM                &USARTE0
   #define USART_SERIAL_BAUDRATE            9600
   #define USART_SERIAL_CHAR_LENGTH         USART_CHSIZE_8BIT_gc
   #define USART_SERIAL_PARITY              USART_PMODE_DISABLED_gc
   #define USART_SERIAL_STOP_BIT            false


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


//Enabling system port clocks
sysclk_enable_module(SYSCLK_PORT_C, PR_USART0_bm); //Enable USARTC0 clock
usart_init_rs232(USART_SERIAL_WIFI, &USART_WIFI); //Enable RS232 mode

sysclk_enable_module(SYSCLK_PORT_D, PR_USART0_bm); //Enable USARTD0 clock
usart_init_rs232(USART_SERIAL_WIFI, &USART_WIFI); //Enable RS232 mode

sysclk_enable_module(SYSCLK_PORT_E, PR_USART0_bm); //Enable USARTE0 clock
usart_init_rs232(USART_SERIAL_WIFI, &USART_WIFI); //Enable RS232 mode


//Declared variables
static volatile uint8_t received_byte;
typedef uint8_t bool;

void sendTextMessage(uint8_t phoneNum, char * textMessage);
void publishMQTTSIM(uint8_t ip, char * pubMessage);
void sendMQTTWIFI();



#endif

