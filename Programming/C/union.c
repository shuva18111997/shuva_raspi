#include<stdio.h>
//unoin used the highest (data type)'s memory.
//and it will only store the last added variable's data.
typedef union abc
{
	int a;
	float f;
	char c;
	double b;
}u;

int main()
{
	u obj;
	obj.a = 2;
	obj.b = 98.4444;
	obj.f = 6.000000;		// six zero(s) are writen after float.
	obj.c = 'a';
	
	printf("a = %d\nf = %f\nb = %d\nc = '%c' ==> Correct value\n\n",obj.a,obj.f,obj.c,obj.b);
	// a = garbage value
	// b = garbage value
	// f = garbage value
	// c = 'a' ==> Correct value
	////////////////////////////////////////////////////////////////
	obj.f = 6.000000;		// six zero(s) are writen after float.
	obj.b = 98.4444;
	obj.c = 'a';
	obj.a = 2;
	
	printf("f = %f\nc = '%c'\nb = %d\na = %d ==> Correct value\n\n",obj.a,obj.f,obj.c,obj.b);
	// f = garbage value
	// b = garbage value
	// c = garbage value
	// a = 2 ==> Correct value
	////////////////////////////////////////////////////////////////
	printf("sizeof(obj) = %d\nsizeof(double) = %d",sizeof(obj),sizeof(double));
	//The maximum memory of union is 4. Because the double has 8 bytes.
	return 0;
}
