#include "button.h"
#include <xc.h>

#define DEBOUNCE_DELAY_MS 20

static volatile uint8_t button_event_flag = 0;
static button_state_t button_state __attribute__((unused));

void button_init(void){ 
TRISBbits.RB0 = 1;//config button pin as input
INTCONbits.GIE = 1;//enable global interrupts
INTCONbits.INT0IE = 1;//enable INT0	
INTCON2bits.INTEDG0 = 1;//edge rising
INTCONbits.INT0IF = 0;//clear flag
}

void button_isr_handler(void){
//TODO: logic
}

uint8_t button_event_pending(void){
	return button_event_flag;
}

void button_clear_event(void){
	button_event_flag = 0; 
}

void button_process(void){
//TODO:logic
}

button_state_t button_get_state(void){
//TODO:logic
}
