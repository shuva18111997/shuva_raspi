#include<stdio.h>

int main()
{
	unsigned int a = 1;
	char *c = (char*)&a;
	if(*c)
	{
		printf("Little Endian");
	}
	else
	{
		printf("Big Endian");
	}
}
