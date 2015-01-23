//Mukemmel Sayi Bulma

#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void main(){
	int sayi1,sayi2,tambolen=0;
	printf("1.sayiyi girin: ");scanf("%d",&sayi1);
	printf("2.sayiyi girin: ");scanf("%d",&sayi2);
	for(int i=sayi1;i<=sayi2;i++){
		tambolen=0;
		for(int j=1;j<i;j++){
			if(i%j==0)
				tambolen+=j;
		}
		if(tambolen==i)
			printf("%d",i);
	}   
	getch();
}