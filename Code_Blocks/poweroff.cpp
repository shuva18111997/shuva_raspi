#include<stdlib.h>
#include<iostream>
using namespace std;
char s;
int main()
{   cout<<"ARE YOU WANNA SHOUTDOWN PC:";
    cin>>s;
    if(s=='Y'||s=='y')
    system("/sbin/poweroff");
}
