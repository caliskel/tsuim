#include <8051.h>

void main()
{
	int i;
	char xdata *ptr;
	char test, nabor;
	nabor = 0xFF;
	ptr = (char xdata *)0x0800;
	P1=0x0;
	for (i=0; i<1024;i++)
	{
		P1=0x2;
		*ptr=nabor;
		test=*ptr;
		if(test!=nabor)
		{
			P1=0x1;
			break;
		}
		ptr++;
		P1=0x0;
	}
	P1=0x4;
}
