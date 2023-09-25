#include<stdio.h>

int main()
{
	int x[] = {1, 2, 3, 4, 5, 6};
	int *ptr;
	ptr = x + 4;
	
	printf("%d", *ptr);
	
	return 0;
}

//The Output is --> 5.
