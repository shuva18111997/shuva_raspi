#include<stdio.h>

char ***p;

int main()
{
	printf("[%d],[%d],[%d],[%d]",sizeof(p),sizeof(*p),sizeof(**p),sizeof(***p));
	return 0;
}

//The Output is --> [8],[8],[8],[1].
