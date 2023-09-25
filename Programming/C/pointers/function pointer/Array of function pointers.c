#include<stdio.h>

int add(int x, int y)
{
	return x+y;
}

int sub(int x, int y)
{
	return x-y;
}

int mul(int x, int y)
{
	return x*y;
}

int main()
{
	int res = -1;
	int ch, a, b;
	
	//Array of function pointers
	int (*funp[])(int, int) = {add, sub, mul};
	//funp[0] = add
	//funp[1] = sub
	//funp[2] = mul


	printf("Enter any 2 inputs\n");
	scanf("%d %d", &a, &b);

	printf("enter the operations 0.add, 1.sub, 2.mul\n");
	scanf("%d", &ch);


	res = funp[ch](a, b);
	printf("result of the selected operation is %d\n", res);
	
	return 0;
}








