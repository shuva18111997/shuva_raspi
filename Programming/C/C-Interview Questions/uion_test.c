#include<stdio.h>

union un{
	short int i;
	char ch[2];
};

int main()
{
	union un o;
	o.ch[0] = 2;
	o.ch[1] = 5;
	printf("%d %d %d\n",o.ch[0], o.ch[1], o.i);
	printf("0x%x 0x%x 0x%x\n",o.ch[0], o.ch[1], o.i);
	printf("\nsizeof(o) = %d",sizeof(short int));
	return 0;
}
