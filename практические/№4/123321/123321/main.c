#include <8051.h>

void msec (int x) 
{	
	while(x-->0) 
	{
	TH0=(-10000)>>8;
	TL0=-10000;
	TR0=1;
	TF0=0;
	TR0=0;
	}
}

void main()
{
	int i;
	unsigned char array[7];
	TMOD=0x1;
	array[0]=0x0;
	array[1]=0x1;
	array[2]=0x2;
	array[3]=0x4+0x8;
	array[4]=0x10+0x20;
	array[5]=0x40;
	array[6]=0x80;
	P1=array[0];
	msec(2);
	for(i=1;i<9;i++)
	{
	P1=array[i];
	msec(100);
	}
	P1=0x0;
	while(1);
}
