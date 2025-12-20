#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

//Initialize shadow for each lat
static uint8_t latA_shadow;
static uint8_t latB_shadow;
static uint8_t latC_shadow;
static uint8_t latD_shadow;
static uint8_t latE_shadow;

//ENUMS
typedef enum {
	GPIO_INPUT = 1,
	GPIO_OUTPUT = 0
} gpio_dir_t;

typedef enum{
	GPIO_LOW, //off
	GPIO_HIGH //on
} gpio_level_t;

typedef struct {
	volatile  uint8_t *tris;
	volatile uint8_t *lat;
	volatile uint8_t *port;
	uint8_t *shadow;//software mirror
	uint8_t pin;
}gpio_t;

#define GPIO_PIN_MASK(pin) (1U << (pin)) 

//PROTOTYPES
void gpio_init(gpio_t *p, gpio_dir_t dir);
void gpio_write(gpio_t *p, gpio_level_t level);
uint8_t gpio_read(gpio_t *p);
void gpio_toggle(gpio_t *p);
#endif
