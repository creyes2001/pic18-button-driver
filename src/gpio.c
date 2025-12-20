#include "gpio.h"

void gpio_init(gpio_t *p, gpio_dir_t dir){
	if(dir == GPIO_OUTPUT){
		*p->tris = 0; //pin as output
	}
	else{
		*p->tris = 1; //pin as input
	}
}

void gpio_write(gpio_t *p, gpio_level_t level){
	if(level == GPIO_HIGH){
		*p->shadow |= GPIO_PIN_MASK(p->pin); //RMW(read-modify-write) on software
	}
	else
	{
		*p->shadow &= ~GPIO_PIN_MASK(p->pin); //RMW(read-modify-write) on software
	}
	*p->lat = *p->shadow; //write lat from shadow
}

uint8_t gpio_read(gpio_t *p){
	return ((*p->port & GPIO_PIN_MASK(p->pin)) != 0U);
}
	
void gpio_toggle(gpio_t *p){
	*p->shadow ^= GPIO_PIN_MASK(p->pin); //RMW on software
	*p->lat = *p->shadow; //write lat from shadow
}
