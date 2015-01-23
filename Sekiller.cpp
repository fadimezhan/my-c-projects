//~~FADÝME ÖZHAN~~
//Yildizlarla  Þekiller Çizdirir..
#include <stdio.h>
#include <stdlib.h>
#include<stdlib.h>
#include<conio.h>


void ucgen(void)
{
	system("cls");
	int i,j,boyut;
	printf("Ucgenin Boyutu:");scanf("%d",&boyut);
	for(i=1;i<=boyut;i++)
	{
		for(j=1;j<=i;j++)
			printf("*");
		    printf("\n");
	}
	printf("Devam etmek icin bir tusa basiniz.");
	getch();system("cls");
	

}


void kare()
{
	system("cls");
	int boyut,i,j;
	printf("Boyut:");scanf("%d",&boyut);
	for(i=1;i<=boyut;i++)
	{
		for(j=1;j<=boyut;j++)
			printf("*");
		    printf("\n");
	}
	printf("Devam etmek icin bir tusa basiniz.");
	getch();system("cls");

}


void dikdortgen(void)
{
	system("cls");
	int boy,en,i,j;
	printf("En:");scanf("%d",&en);
	printf("Boy:");scanf("%d",&boy);
	for(i=1;i<=boy;i++)//Boy sayisi kadar dödürür.
	{
		for(j=1;j<=en;j++)//Girilen en sayisi kadar yildiz yazar.
			printf("*");
		    printf("\n");
	}
	printf("Devam etmek icin bir tusa basiniz.");
	getch();system("cls");

}


void eskenardortgen(void)
{
	system("cls");
	basadon:
	int boyut,i,j,k;
	printf("Boyut:");scanf("%d",&boyut);
	
	if((boyut%2)==0)
		{	printf("Tek sayi giriniz.");
	      goto basadon;
	}
	else
	{for(i=0;i<(boyut+1)/2;i++)//Eskenardortgenin ust kýsmý icin girilen boyuta kadar döndürür.
	{
		for(j=0;j<((boyut-1)-2*i)/2;j++)//Bosluklari yazar.
			printf(" ");
		for(k=1;k<=(2*i)+1;k++)//Yildizlari yazar.
		printf("*");
		printf("\n");
		
	}
	for(i=0;i<=(boyut-1)/2;i++)//Eskenardortgenin alt kýsmý için döndürür.
	{
		for(j=0;j<i+1;j++)//Bosluklari yazar.
			printf(" ");
		for(k=0;k<((boyut-2)-2*i);k++)//Yildizlari yazar.
			printf("*");
		printf("\n");
	}
	}
	
	printf("Devam etmek icin bir tusa basiniz.");
		getch();system("cls");
		

}

void paralelkenar(void)
{
	system("cls");
	int boyut,i,j,k;
	printf("Boyut:");scanf("%d",&boyut);
	for(i=1;i<=boyut;i++)
	{
		for(j=1;j<=boyut-i;j++)
			printf(" ");
		for(k=1;k<=boyut;k++)	
			printf("*");
		    printf("\n");
	}
	printf("Devam etmek icin bir tusa basiniz.");
	getch();system("cls");

}


int main()
{
    programbasi:
	
	printf("1.Ucgen\n2.Kare\n3.Dikdortgen\n4.Eskenardortgen\n5.Paralelkenar\n0.Cikis\n");
	int secim,boyut;
	printf("secim:");scanf("%d",&secim);

	for(;;)
	{
		if(secim==0)
			break;
	switch(secim)
		{
	case 1: ucgen();goto programbasi;
	case 2: kare(); goto programbasi;
	case 3: dikdortgen();goto programbasi;
	case 4: eskenardortgen();goto programbasi;
	case 5: paralelkenar();goto programbasi;
	default:printf("Hatali bir secim yaptiniz..Seciminiz:"); scanf("%d",&secim);

			}

	}

  return 0;

}
	