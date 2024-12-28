#include "main.h"
#include "usart.h"
#include "stm32c031xx.h"
#include <stdint.h>

void main(void){
    RCC->IOPENR  |= RCC_IOPENR_GPIOAEN;
    RCC->APBENR1 |= RCC_APBENR1_USART2EN;
    RCC->APBENR1 |= RCC_APBENR1_PWREN;

    GPIOA->MODER =  0xffffffff;
    GPIOA->MODER =  0xebffffaf;

    GPIOA->AFR[0] = 0;
    GPIOA->AFR[0] = GPIO_AFRL_AFSEL2_0 | GPIO_AFRL_AFSEL3_0;


    char buf[] = "zxxzzxxzxzxzxz12";

    usart_config(USART2);



    for (int i = 0; i < 3; i++){
        usart_write(buf, USART2);
    }

    while (1){

    }
}