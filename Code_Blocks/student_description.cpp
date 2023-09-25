#include<iostream>
using namespace std;
struct student
{
char name[20];
int roll,age;
float murks;
void take(){
cout<<"enter name :"<<endl;
cin>>name;
cout<<"Enter roll :"<<endl;
cin>>roll;
cout<<"Enter age :"<<endl;
cin>>age;
cout<<"Enter murks :"<<endl;
cin>>murks;
}
void put(){
cout<<"NOw the OUTPUT Result\n";
cout<<"Name :"<<name<<endl;
cout<<"Roll :"<<roll<<endl;
cout<<"age :"<<age<<endl;
cout<<"Murks :"<<murks<<endl;
}
};
int main(){
student stu[3];
int i=0;
int j=2;
for(i=0;i<j;i++){
stu[i].take();
}
for(i=0;i<j;i++){
stu[i].put();
cout<<endl;
}
}
