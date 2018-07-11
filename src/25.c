#include <3694.h>
#include "ltrc_lib.h"

void setAN0(){
	AD.CSR.BIT.SCAN=0;
	AD.CSR.BIT.CKS=1;
	AD.CSR.BIT.CH=0;
}

void setAN1(){
	AD.CSR.BIT.SCAN=0;
	AD.CSR.BIT.CKS=1;
	AD.CSR.BIT.CH=1;
}

void main(void){

//	int a0=0, a1=0;
//
//	AD.ADCSR.BYTE|=0x19;
//	initSCI3();
//
//	while(1){
//		AD.ADCSR.BIT.ADST=1;
//		msecWait(1000);
//		do{
//			a0 = AD.ADDRA;
//			a1 = AD.ADDRB;
//		}while(AD.ADCSR.BIT.ADF==1);
//		AD.ADCSR.BIT.ADF=0;
//		SCI3printf("AN0 = %d , AN1 = %d\n",a0,a1);
//		AD.ADCSR.BIT.ADST=0;
//	}

	while(1){
		setAN0();
		AD.CSR.BIT.ADST=1;
		while(AD.CSR.BIT.ADST==1);
		a0=(AD.DRA>>6);
		setAN1();
		AD.CSR.BIT.ADST=1;
		while(AD.CSR.BIT.ADST==1);
		a0=(AD.DRB>>6);
		SCI3printf("AN0=%d, AN1=%d\n",a0,a1);
		msecWait(1000);
	}

	return;
}
