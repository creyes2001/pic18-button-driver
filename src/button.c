#include "button.h"
#include <xc.h>

static volatile uint8_t button_event_flag __attribute__((unused));

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
//TODO: logic
return 0;
}

void button_clear_event(void){
//TODO: logic
}
