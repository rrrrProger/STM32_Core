#include "stm32c031xx.h"
#include "usart.h"
#include "string.h"

static void usart_putc(const char ch, USART_TypeDef *usart){
      // wait for tx data register to be empty
      while (!(usart->ISR & USART_ISR_TXE_TXFNF))
            ;

      usart->TDR = 0xFFU & ch;

      while (usart->ISR & USART_ISR_TC == 0)
            ;
}

static void usart_puts(const char *ch, USART_TypeDef *usart){
      while (*ch){
            usart_putc(*ch, usart);
            ch++;
      }
}

void usart_config(USART_TypeDef *usart){
      usart->CR1 = 0;
      usart->CR2 = 0;

      usart->BRR = 0x68;

      usart->CR3 &= ~USART_CR3_SCEN;
      usart->CR3 &= ~USART_CR3_HDSEL;
      usart->CR3 &= ~USART_CR3_IREN;

      usart->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE_RXFNEIE | USART_CR1_UE;
}

void usart_write(const char *ch, USART_TypeDef *usart){
      usart_puts(ch, usart);
}

void usart_main(){

}