#include<stdio.h>

int main()
{
	char *ptr;
	char myString[] = "abcdefg";
	
	ptr = myString;
	
	ptr += 5;
	
	printf("%s", ptr);
	
	return 0;
}

//The Output of the String is --> fg.
