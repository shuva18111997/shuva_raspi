#include<stdio.h>

#define MAX_USER_COUNT	2

struct User_Node
{
	char name[8];					//rename it to "char user_name[8]";
	char psw[8];					//rename it to "char user_pw[8]";
	char access[8];
};

main()  
{  
    struct User_Node user_arr[MAX_USER_COUNT];
    int i = 0;
    while(i < MAX_USER_COUNT)
    {
    	printf("Enter the name, psw, and access:");
    	scanf("%s %s %s",user_arr[i].name, user_arr[i].psw, user_arr[i].access);
    	i++;
	}
    printf("Printing the details....\n");
    i = 0;
    while(i < MAX_USER_COUNT)
    {
    	printf("%s %s %s\n",user_arr[i].name, user_arr[i].psw, user_arr[i].access);
    	i++;
	}
}  
