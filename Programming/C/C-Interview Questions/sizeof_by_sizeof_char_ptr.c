#include<stdio.h>

int main()
{
	char *a[] = {"Shuva", "Romita", "mitali", "priyadarshini"};
	
	printf("%d", sizeof(a)/sizeof(char*));
	return 0;
}

//The Output is --> 4.
//Which is the Column number of the array.
