#include<stdio.h>

#define JOIN(s1,s2) printf("%s = %s %s = %s\n",#s1,s1,#s2,s2)

int main()
{
	char *str1 = "shuva";
	char *str2 = "shaym";
	JOIN(str1, str2);
	return 0;
}
