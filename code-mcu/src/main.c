/*
 * code-mcu.c
 *
 * Created: 7/18/2020 7:35:10 PM
 * Author : Nator Verinumbe
 */ 

#include <avr/io.h>
#include <asf.h>

#define LED0 IOPORT_CREATE_PIN(PORTB, 14)

int main(void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	
	//WDT->WDT_MR = WDT_MR_WDDIS;										//disable the watchdog				
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

