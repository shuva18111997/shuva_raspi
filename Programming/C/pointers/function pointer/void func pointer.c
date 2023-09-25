#include<stdio.h>

#define ptr 1

void func_ptr1(int a)
{
	printf("\nfunc_ptr 1 %d",a);
}

void func_ptr2(int a)
{
	printf("\nfunc_ptr 2 %d",a);
}

void func(void (*fun_ptr1)(), void (*fun_ptr2)())
{
	fun_ptr1();
	fun_ptr2();
}

int main()
{
	func(func_ptr1, func_ptr2);
	return 0;
}






