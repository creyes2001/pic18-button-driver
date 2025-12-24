#include <xc.h>
#include "button.h"
#include "gpio.h"
#define __XTAL_FREQ 20000000

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
		button_isr_handler();
		INTCONbits.INT0IF = 0;
	}
}

int main(){
	button_init();
	gpio_init(&led,GPIO_OUTPUT);


	while(1)
	{
		button_process();

		if(button_get_state() == BUTTON_PRESSED)
		{
			gpio_toggle(&led);
		}
		
	}

	return 1;
}
