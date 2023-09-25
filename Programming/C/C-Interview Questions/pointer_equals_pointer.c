#include<stdio.h>

int main()
{
	char *p = "abc";
	char *q = "abc123";
	while(*p = *q)
	{
		printf("%c %c\n", *p, *q);
	}
	return 0;
}

//The Output is --> Segmentation Fault.
