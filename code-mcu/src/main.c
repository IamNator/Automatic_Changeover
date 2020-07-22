/*
 * code-mcu.c
 *
 * Created: 7/18/2020 7:35:10 PM
 * Author : Nator Verinumbe
 */

#include <avr/io.h>
#include <asf.h>
#include <util/delay.h>
#include <stdint.h>
#include "mylib/conf_usart.h"


//GPIO Pins
#define LED0 IOPORT_CREATE_PIN(PORTB, 14)

int main(void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	
	//WDT->WDT_MR = WDT_MR_WDDIS;									//disable the watchdog				
	ioport_init();													//call before using IOPORT service
	ioport_set_pin_dir(LED0,IOPORT_DIR_OUTPUT);						//LED pin set as output
	ioport_set_pin_level(LED0, IOPORT_PIN_LEVEL_HIGH);				//switch LED off
    
	/* Insert application code here, after the board has been initialized. */ 
    while (1) 
    {
		ioport_toggle_pin_level(LED0);
		delay_ms(1000);
    }
}





//SPI SLAVE






//#define card_rx PD0
//#define card_tx PD1
//#define card_rst PC0

void UART_init(uint16_t ubrr);
void UART_transmit(char data);
//uint8_t UART_receive(void);

//void SPI_init();
//uint8_t SPI_transceiver(uint8_t data);


//int main(void)
{
	UART_init(SMUBRR);
	//DDRC |= 0x01;

	//uint8_t transfer;
unsigned char Send_Array[34]={'A','F','R','W','C','J','K','L','E','U','I','E','O','C','V','D','W','R','W','T','G','R','Y','E','U','C','H','N','M','W','R'};
     
//     char Send[14] = "How are you?";

	while(1)
{

		int i =0;
		//while(!card_rx);
		for (i=0; i<12; i++)
		{
		UART_transmit(Send_Array[i]); 
		_delay_us(12);
		}

		//UART_transmit()
			
}	

	return 0;
}

/*
void SPI_init()
{	
	DDRB |= (1<<PB3)|(1<<PB5);
	SPCR |= (1<<SPE)|(1<<DORD)|(1<<MSTR)|(1<<CPHA); //Enable SPI, LSB first, SCK LOW: IDLE, Sample data at leading(first) edge of SCK, FOSC/4
}

uint8_t SPI_transceiver(uint8_t data)
{
	SPDR = data; //loads data into buffer
	while(!(SPSR & (1<<SPIF))); //waits untill transmission is complete
	return SPDR; //returns received data
}
*/





/*
void SPI_init()
{	
	DDRB |= (1<<PB4);
	SPCR |= (1<<SPE)|(1<<DORD)|(1<<MSTR)|(1<<CPHA); //Enable SPI, LSB first, SCK LOW: IDLE, Sample data at leading(first) edge of SCK, FOSC/4
}

uint8_t SPI_transceiver(uint8_t data)
{
	SPDR = data; //loads data into buffer
	while(!(SPSR & (1<<SPIF))); //waits untill transmission is complete
	return SPDR; //returns received data
}
*/
