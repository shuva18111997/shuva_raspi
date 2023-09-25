#include<stdio.h>

char *myFunc(char *ptr)
{
	ptr += 3;
	return ptr;
}

int main()
{
	char *x, *y;
	x = "Hello";
	y = myFunc(x);
	printf("y = %s\n", y);
	return 0;
}

//Output of the program is --> lo.
