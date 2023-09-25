#include<stdio.h>

int i;

void increment(int i)
{
	i++;
}

int main()
{
	for(i = 0; i < 10; increment(i))
	{
		printf("running loop with i --> %d\n",i);
	}
	printf("i = %d\n",i);
	return 0;
}

//The output never comes because it will in infinite loop
