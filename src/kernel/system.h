#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "system.h"
#include "micro_types.h"

void uart0_send(char *msg);
void send_message(uint8_t *message, uint32_t count);

void system_clock_initialize(void);

void gpio_toggle(void);
void gpio_setup(void);


#endif //__SYSTEM_H