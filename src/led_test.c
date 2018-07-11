#include <3694.h>

int main(void){
	IO.PMR1.BYTE&=0xe9;
	IO.PCR1|=0x06;

	IO.PDR1.BIT.B1=1;
	IO.PDR1.BIT.B2=0;
}
