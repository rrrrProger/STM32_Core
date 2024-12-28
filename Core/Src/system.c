#include "stm32c031xx.h"

#define VECT_TAB_OFFSET  0x0U

void SystemInit(void){
#ifdef VECT_TAB_SRAM
    SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET;
#else
    SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET;
#endif
}