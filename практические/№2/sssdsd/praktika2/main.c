#include <8051.h>

void main(){
	unsigned char i,j,num,vkl;
	unsigned char massiv[11] = {
		0xC0,
		0xF9,
		0xA4,
		0xB0,
		0x99,
		0x92,
		0x82,
		0xF8,
		0x80,
		0x90,
		0xFF
	};
	P2=massiv[10];
	P3=0x0;
	num=9;
	vkl=0;

	while(1){
		if(vkl==0){
			if(P3==0x1){vkl=1;}
			else{
				P2 = massiv[num];
				for(j=0;j<200;j++);
				num--;
				if(num>9){num=9;}
			}
		}
		
		if(vkl==1){
			if(P3==0x1){
				if(num>9){num=9;};
				P2=massiv[num];
				for(j=0;j<200;j++);
				P2=massiv[3];
				for(j=0;j<200;j++);
				num--;
			}
		}
	}
}
