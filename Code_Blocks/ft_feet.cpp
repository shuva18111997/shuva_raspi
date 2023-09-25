#include<iostream>
using namespace std;
class conv
{
    int ft;
    int inch;
    public :
void get()
{
    cout<<"Enter ft ";
    cin>>ft;
    cout<<"Enter inch ";
    cin>>inch;
    while(inch>=12){
    cout<<"ERROR"<<endl<<"Please Enter right data"<<endl<<"Enter inch ";
    cin>>inch;
    if(inch<12)
    break;
    }
}
conv sum(conv d1,conv d2)
{    conv a;
     a.ft=d1.ft+d2.ft;
     a.inch=d1.inch+d2.inch;
     int g=a.inch-12;
     if(g>=0)
     {
        a.ft=a.ft+1;
        a.inch=g;
     }
     return a;
}
void print()
{
    cout<<"sum is "<<ft<<" ft "<<inch<<" inch";
}
};
main()
{
    conv d1,d2,d3;
    d1.get();
    d2.get();
    d3=d3.sum(d1,d2);
    d3.print();
}
