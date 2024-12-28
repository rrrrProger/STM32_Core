#ifndef USART_H

#include "stdint.h"
#include "stm32c031xx.h"

#define USART_H

void usart_config(USART_TypeDef *usart);
void usart_main(void);
void usart_write(const char *ch, USART_TypeDef *usart);

#endif