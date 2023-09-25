#include<stdio.h>

#define a 10


int main()
{
	printf("%d..",a);
	foo();
	printf("%d",a);
	return 0;
}

void foo()
{
	#undef a
	#define a 50
}

//Output of the program is --> 10..10

