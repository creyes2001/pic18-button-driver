#include <xc.h>
#include "button.h"
#include "gpio.h"
#define __XTAL_FREQ 20000000

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

	return 1;
}
