#include <3694.h>
#include "ltrc_lib.h"

void msecWait(unsigned long int lenght){
	
	volatile unsigned int i=0,j=0;

	for(j=0;lenght>j;j++){
		for(i=0;i<712;i++){
		}
	}

	return;
}


int main(void){
	
	IO.PMR1.BYTE&=0xe9;
	IO.PCR1|=0x06;

	initSCI3();

	while(1){
		
		IO.PDR1.BIT.B1=0;
		IO.PDR1.BIT.B2=0;
		msecWait(1000);
		SCI3printf("IO.PDR1.BIT.B1=%b IO.PDR1.BIT.B2=%b\n",IO.PDR1.BIT.B1,IO.PDR1.BIT.B2);

		IO.PDR1.BIT.B1=1;
		IO.PDR1.BIT.B2=0;
		msecWait(1000);
		SCI3printf("IO.PDR1.BIT.B1=%b IO.PDR1.BIT.B2=%b\n",IO.PDR1.BIT.B1,IO.PDR1.BIT.B2);
		IO.PDR1.BIT.B1=0;
		IO.PDR1.BIT.B2=1;
		msecWait(1000);
		SCI3printf("IO.PDR1.BIT.B1=%b IO.PDR1.BIT.B2=%b\n",IO.PDR1.BIT.B1,IO.PDR1.BIT.B2);
		IO.PDR1.BIT.B1=1;
		IO.PDR1.BIT.B2=1;
		msecWait(1000);
		SCI3printf("IO.PDR1.BIT.B1=%b IO.PDR1.BIT.B2=%b\n",IO.PDR1.BIT.B1,IO.PDR1.BIT.B2);
	}

}

