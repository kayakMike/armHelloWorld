#ifndef __UARTCOM_H
#define __UARTCOM_H
#include "micro_types.h"

#define UART0 0
#define UART2 2

//uart0 debug
void ucom_sendString      (uint8_t port, uint8_t *msg);
void ucom_sendMessage     (uint8_t port, uint8_t *msg, uint32_t len);
void ucom_initializePort  (uint8_t port);

#endif //__UARTCOM_H
