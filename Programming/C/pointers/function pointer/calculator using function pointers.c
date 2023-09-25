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
	//function pointer with syntax as int ret type and 2 int args
	int (*funp)(int, int); 

	printf("Enter any 2 inputs\n");
	scanf("%d %d", &a, &b);

	printf("enter the operations 1.add, 2.sub, 3.mul\n");
	scanf("%d", &ch);

	switch(ch)
	{

		case 1:
			funp = add;
			break;
		case 2:
			funp = sub;
			break;
		case 3:
			funp = mul;
			break;
		default:
			printf("enter a valid input\n");
	}

	res = funp(a, b);
	printf("result of the selected operation is %d\n", res);
	
	/*funp = add;
	res = funp(2, 3);
	printf("Result of add is %d\n", res);

	funp = sub;
	res = funp(2, 3);
	printf("Result of sub is %d\n", res);

	funp = mul;
	res = funp(2, 3);
	printf("Result mul is %d\n", res);*/

	return 0;
}








