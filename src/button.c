#include "button.h"
#include "gpio.h"
#include <xc.h>

#define DEBOUNCE_DELAY_MS 20

static volatile uint8_t button_event_flag = 0;
static button_state_t button_state = 0;
gpio_t button = {
	.tris = &TRISB,
	.lat = &LATB,
	.port = &PORTB,
	.pin = 0
};


void button_init(void){ 
gpio_init(&button, GPIO_INPUT);//config button pin as input
INTCONbits.GIE = 1;//enable global interrupts
INTCONbits.INT0IE = 1;//enable INT0	
INTCON2bits.INTEDG0 = 1;//edge rising
INTCONbits.INT0IF = 0;//clear flag
}

void button_isr_handler(void){
	button_event_flag = 1;
}

uint8_t button_event_pending(void){
	return button_event_flag;
}

void button_clear_event(void){
	button_event_flag = 0; 
}

void button_process(void){
	if(button_event_flag)
	{
		button_clear_event();

		//crude debounce delay
		for(volatile uint16_t i = 0; i < 3000; i++)
		{
			__asm("nop");
		}

		//confirm button still pressed
		if(gpio_read(&button) == 0)
		{
			button_state = BUTTON_PRESSED;
		}
		else
		{
			button_state = BUTTON_RELEASED;
		}
	}
}


button_state_t button_get_state(void){
	return button_state;
}
