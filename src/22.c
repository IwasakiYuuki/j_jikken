#include <3694.h>
#include "ltrc_lib.h"

#define setCCR_I() asm volatile("orc.b #0x80,CCR")

#define clearCCR_I() asm volatile("andc.b #0x7f,CCR")

volatile unsigned long long int ledCount = 0;
volatile unsigned long long int mainCount = 0;
volatile int dutyRate1=0;
volatile int dutyRate2=0;

#pragma interrupt
void int_timera(void){
	setCCR_I();
	IRR1.BIT.IRRTA=0x0;
	ledCount++;
	
	if(ledCount<dutyRate1){
		IO.PDR1.BIT.B1=1;
	}else{
		IO.PDR1.BIT.B1=0;
	}
	if(ledCount<dutyRate2){
		IO.PDR1.BIT.B2=1;
	}else{
		IO.PDR1.BIT.B2=0;
	}
	if(ledCount>100)ledCount=0;

	clearCCR_I();
}

void msecWait(unsigned long int lenght){
	
	volatile unsigned int i=0,j=0;

	for(j=0;lenght>j;j++){
		for(i=0;i<712;i++){
		}
	}

	return;
}


int main(void){
	
	int buf=0;

	clearCCR_I();
	TA.TMA.BIT.CKSI=0x7;
	IENR1.BIT.IENTA=0x1;
	IO.PCR1|=0x6;
	initSCI3();
	
	while(1){
	dutyRate1=20;
	dutyRate2=90;
	SCI3printf("Duty LED1:%d LED2:%d\n",dutyRate1,dutyRate2);
	msecWait(3000);
	
	dutyRate1=50;
	dutyRate2=50;
	SCI3printf("Duty LED1:%d LED2:%d\n",dutyRate1,dutyRate2);
	msecWait(3000);
	
	dutyRate1=80;
	dutyRate2=10;
	SCI3printf("Duty LED1:%d LED2:%d\n",dutyRate1,dutyRate2);
	msecWait(3000);
	}
}
