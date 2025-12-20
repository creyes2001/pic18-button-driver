#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

typedef enum{
	BUTTON_PRESSED,	// pull-up in hardware
	BUTTON_RELEASED //
}button_state_t;

void button_init(void);
void button_isr_handler(void);
uint8_t button_event_pending(void);
void button_clear_event(void);

#endif

