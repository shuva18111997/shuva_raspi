#include<stdio.h>

int main()
{
	int y[4] = {6, 7, 8, 9};
	
	int *ptr = y + 2;
	
	printf("%d", ptr[1]);
	return 0;
}

//The Output is --> 9.
