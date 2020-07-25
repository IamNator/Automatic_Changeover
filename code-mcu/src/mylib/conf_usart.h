#pragma once

#ifndef CONF_USART_H
#define CONF_USART_H

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
  
  
   #define USART_SERIAL_COM                 &USARTE0
   #define USART_SERIAL_BAUDRATE            9600
   #define USART_SERIAL_CHAR_LENGTH         USART_CHSIZE_8BIT_gc
   #define USART_SERIAL_PARITY              USART_PMODE_DISABLED_gc
   #define USART_SERIAL_STOP_BIT            false



void USARTS_inits(void); //initialize UART functions



//variables
static volatile uint8_t received_byte;
//#define bool uint8_t;


//custom functions
void sendTextMessage(uint8_t phoneNum, char * textMessage); //send string textMessage one char at a time to phoneNum
void publishMQTTSIM(uint8_t ip, char * pubMessage); //Publish data to cloud MQTT through GPRS/3G network
bool connectWIFI(const unsigned char * SSID, const unsigned char * password); //returns true when wifi is  connected to a wifi network
void sendMQTTWIFI(uint8_t ip, char * pubMessage);



#endif

