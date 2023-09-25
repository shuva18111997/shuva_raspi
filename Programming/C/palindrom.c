#include<stdio.h>

int main()
{
	int num = 0, n = 0, rev = 0;
	printf("Enter a number ");
	scanf("%d", &num);
	n = num;
	while(n != 0)
	{
		rev = (rev * 10) + (n % 10);
		n /= 10;
	}
	(rev==num) ? printf("The number is a palindrom number.") : printf("The number is not a palindrom number.");
	return 0;
}
