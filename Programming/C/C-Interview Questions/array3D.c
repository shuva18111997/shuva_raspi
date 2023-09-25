#include<stdio.h>

int testarray[3][2][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int main()
{
	printf("%d", testarray[2][1][0]);
	return 0;
}

//Output of the program is --> 11.
//########################################################
/*#include<stdio.h>

int arr[3][2][2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

int i, j, k;

int main()
{
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 2; j++)
		{
			for(k = 0; k < 2; k++)
			{
				printf("%d\t",arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
*/
//Output of the program is --> 
/*
1       2
3       4

5       6
7       8

9       10
11      12
*/

//########################################################