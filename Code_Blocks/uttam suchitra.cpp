/*Uttam suchitra Flim song "Ei Poth jodi Na ses hoy kamon hoto Tumi bolo to"*/
#include<iostream>
using namespace std;
int poth=1;
void delay(int a);
int main(){
	cout<<"Ei poth jodi na ses hoy"<<endl<<"Tabe??"<<endl;
	cout<<"Kamon Hoto Tumi Bolo To"<<endl;
	delay(5000);
do
{
	if(poth!=0){
		cout<<"Uttam:Na Tumi Bolo"<<endl;
		delay(2000);
	}	
	cout<<"Suchitra:Na Tumi Bolo"<<endl;
	cout<<"\t\t\t\tpoth akhono "<<poth<<"km"<<endl;
	delay(2000);
	poth++;
}while(true);
return 0;
}
void delay(int time){
	for(int i=0;i<time;i++){
		for(int j=0;j<1227;j++){
			for(int p=0;p<100;p++){
			}
		}
	}
}
