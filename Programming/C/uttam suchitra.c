/*Uttam suchitra Flim song "Ei Poth jodi Na ses hoy kamon hoto Tumi bolo to"*/
#include<stdio.h>

int poth=1;
void delay(int a);

int main(){
	printf("Ei poth jodi na ses hoy\nTabe??\n");
	printf("Kamon Hoto Tumi Bolo To\n");
	delay(5000);
do
{
	if(poth!=0){
		printf("Uttam:Na Tumi Bolo\n");
		delay(2000);
	}	
	printf("Suchitra:Na Tumi Bolo\n");
	printf("\t\t\t\tpoth akhono %dkm\n",poth);
	delay(2000);
	poth++;
}while(1);
return 0;
}
void delay(int time){
	int i, j, k;
	for(i = 0; i < time; i++){
		for(j = 0; j < 1227; j++){
			for(k = 0; k < 100; k++){
			}
		}
	}
}
