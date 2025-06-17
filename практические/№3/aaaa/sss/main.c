#include <8051.h>

void write(unsigned char ch)
{
	P0 = ch;
	P2 = 0x3;
	P2 = 0x2;
}
void main()
{
	unsigned int dlina=11;
	unsigned char *tekst="hello world";
	unsigned int i,j,k;
	P0=0x38;
	P2=0x1;
	P2=0x0;
	for (i=0;i<dlina;i+=2){
	P0=0x80+j;
	P2=0x1;
	P2=0x0;
	write(tekst[i]);
	for(k=0;k<1500;k++);
	if(tekst[i+1]!='\0'){
		P0=0xC0+j;
		P2=0x1;
		P2=0x0;
		write(tekst[i+1]);
		for(k=0;k<1500;k++);
	}
	j++;
	}
	while(1);
}
