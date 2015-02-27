#include<stdio.h>
#include<conio.h>

void main()
{
	int sayi;
	printf("Iki basamakli bir sayi giriniz: "); scanf("%d",&sayi);
	
    if(sayi>9 && sayi<100){
	int birlik=sayi%10;
	int onluk=sayi/10;

	switch(onluk){
	case 1:printf("on");break;
	case 2:printf("yirmi");break;
	case 3:printf("otuz");break;
	case 4:printf("kirk");break;
	case 5:printf("elli");break;
	case 6:printf("altmis");break;
	case 7:printf("yetmis");break;
	case 8:printf("seksen");break;
	case 9:printf("doksan");break;
	}
	switch(birlik){
    case 1:printf(" bir");break;
	case 2:printf(" iki");break;
	case 3:printf(" uc");break;
	case 4:printf(" dort");break;
	case 5:printf(" bes");break;
	case 6:printf(" alti");break;
	case 7:printf(" yedi");break;
	case 8:printf(" sekiz");break;
	case 9:printf(" dokuz");break;
	}
	}
	else main();
	getch();
}
