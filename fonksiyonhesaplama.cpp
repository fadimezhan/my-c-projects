//f(x) fonksiyonunu hesaplayan program...
#include <stdio.h>
#include <conio.h>

void main(){
	int sayi,sonuc=1;
	char istek;
	printf("Bir sayi giriniz : ");scanf("%d",&sayi);
		for(int i=2;i<=sayi;i++){
			if(sayi>=10)
			  sonuc+=i;//sonuc=1+2+...+x
	        else if(0<=sayi<=9)
				sonuc*=i;//sonuc=x! 
			else
			   printf("Lütfen pozitif bir sayi girin ...");
		}
		printf("Sonuc : %d\n",sonuc);
		printf("Baska bir sayi daha girmek istiyor musunuz? (E/H) :");istek=getch();
		if(istek=='E'||istek=='e')
			main();
		else
			getch();
}

