#include <3694.h>

#define setCCR_I() asm volatile("orc.b #0x80,CCR")

#define clearCCR_I() asm volatile("andc.b #0x7f,CCR")

#pragma interrupt
void int_timera(void){

}
