#include <3694.h>

#define setCCR_I() asm volatile("orc.b #0x80,CCR")

#define clearCCR_I() asm volatile("andc.b #0x7f,CCR")

volatile unsigned long long int ledCount = 0;
volatile unsigned long long int mainCount = 0;
int dutyRate1=0;
int dutyRate2=0;
int flag=1;


#pragma interrupt
void int_timera(void){
	setCCR_I();
	IRR1.BIT.IRRTA=0x0;
	ledCount++;
	mainCount++;

	if(mainCount<29298){
		dutyRate1=20;
		dutyRate2=90;
		flag=1;
	}else if(mainCount<(29298*2)){
		dutyRate1=50;
		dutyRate2=50;
		flag=2;
	}else{
		dutyRate1=80;
		dutyRate2=10;
		flag=3;
	}
	if(mainCount>(29298*3))mainCount=0;
	if(ledCount>100)ledCount=0;
	clearCCR_I();
}

int main(void){
	
	int buf=0;

	clearCCR_I();
	TA.TMA.BIT.CKSI=0x7;
	IENR1.BIT.IENTA=0x1;
	initSCI3();

	
	while(1){
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
		if(buf!=flag){
			SCI3printf("Duty Rate LED1:%d LED2:%d\n",dutyRate1,dutyRate2);
			buf=flag;
		}
	}
}

