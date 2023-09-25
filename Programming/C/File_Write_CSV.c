#include<stdio.h>

main()
{
	FILE *fp;
	int arr[] = {10,20,30,40,50,60,70,80,90}, i;
	fp = fopen("Test.csv","a");
	fprintf(fp,"1,2,3,4,5,6,7,8,9");	//use "," for seperate Coloums
	fprintf(fp,"\n");
	/*					OR							*/
	for(i = 0; i < 9; i++)
	{
		fprintf(fp,"%d,",arr[i]);
	}
	
	fprintf(fp,"\nshuva\nsayantan\nrahul");	//use "," for seperate Rows
	fclose(fp);
}
