#include<stdio.h>

char data = 0x20;
unsigned char cnt = 0x80;

main()
{
	while(cnt)
	{
		if(data & cnt)
			printf("1");
		else
			printf("0");
		cnt = cnt >> 1;
	}
}

