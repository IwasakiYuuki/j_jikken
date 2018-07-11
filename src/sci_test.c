#include <3694.h>
#include <ltrc_lib.h>

int main(void){
	
	unsigned int i = 0;

	initSCI3();

	SCI3printf("\n-----------------------\n");
	while(1){
		SCI3printf("i=%5u	%04x	%016b\n",i,i,i);
		i++;
	}
}

