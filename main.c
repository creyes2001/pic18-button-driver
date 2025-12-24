#include <xc.h>
#include "button.h"
#include "gpio.h"
#define _XTAL_FREQ 20000000
#include "config.h"

gpio_t led = {
	.tris = &TRISD,
	.lat = &LATD,
	.port = &PORTD,
	.pin = 0
};

void __interrupt() isr(void)
{
	if(INTCONbits.INT0IF)
	{
		INTCONbits.INT0IF = 0;
		button_isr_handler();

	}
}

int main(){
	button_init();
	gpio_init(&led,GPIO_OUTPUT);


	while(1)
	{
		if(button_event_pending())
		{
			button_process();
			

			if(button_get_state() == BUTTON_PRESSED)
			{
				gpio_toggle(&led);
				__delay_ms(500);
			}
		}
	}

	return 1;
}
