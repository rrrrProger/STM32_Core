#include "blinky.h"
#include "stm32c031xx.h"

void blink(int timeout){
    RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;

    GPIOA->ODR ^= GPIO_ODR_OD5;

    for (int i = 0; i < timeout; i++){
        ;
    }
}