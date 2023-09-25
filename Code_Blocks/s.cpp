#include<iostream>
using namespace std;
int m=10;
int main()
{
    int m=20;
    {
        int k=m;
        int m=30;
        cout<<"We are in inner block"<<endl;
        cout<<"k ="<<k<<endl;
        cout<<"m ="<<m<<endl;
        cout<<"::m ="<<::m<<endl;
    }
    cout<<"we are in outter block"<<endl;
    cout<<" m ="<<m<<endl;
    cout<<"::m ="<<::m<<endl;
    return 0;
}
