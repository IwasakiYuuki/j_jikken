#include <3694.h>

int main(void){
	IO.PMR1.BYTE&=0xe9;
	IO.PCR1|=0x06;

	while(1){
		IO.PDR1.BIT.B1=1;
		msecWait(1);

		IO.PDR1.BIT.B1=0;
		msecWait(1);
	}
}

void msecWait(unsigned int lenght){
	
	volatile unsigned int i=0,j=0;

	for(j=0;lenght>j;j++){
		for(i=0;i<712;i++){
		}
	}

	return;
}
